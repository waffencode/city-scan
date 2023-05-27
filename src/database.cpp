#include <iostream>
#include <format>

#include "database.h"

static const std::string URL = "mysqlx://root@127.0.0.1";

database::database()
{
    std::cout << "Creating session on " << URL << " ..." << std::endl;
    _session = std::make_unique<mysqlx::Session>(URL);
    std::cout << "Session accepted" << std::endl;
}

database::~database()
{ 
    _session->close();
}

mysqlx::Collection database::get_collection()
{
    mysqlx::Schema sch = _session->getSchema("test");
    return sch.createCollection("c1", true);
}

void database::add_object(infrastructure_object& object)
{
    try
    {
        mysqlx::Collection collection = get_collection();
        mysqlx::Result add = collection.add(get_insert_string(object)).execute();
        std::list<mysqlx::string> ids = add.getGeneratedIds();
            for (mysqlx::string id : ids)
                std::cout << "- added doc with id: " << id << std::endl;
    }
    catch (const mysqlx::Error &err)
	{
		std::cout << "ERROR: " << err << std::endl;
		return;
	}
	catch (std::exception &ex)
	{
		std::cout << "STD EXCEPTION: " << ex.what() << std::endl;
		return;
	}
	catch (const char *ex)
	{
		std::cout << "EXCEPTION: " << ex << std::endl;
		return;
	}
}

void database::fetch_data()
{
    try
    {
        mysqlx::Collection collection = get_collection();
        mysqlx::DocResult docs = collection.find().execute();
        for (mysqlx::DbDoc entity : docs)
        {
            for (mysqlx::Field fld : entity)
            {
                std::cout << " field `" << fld << "`: " << entity[fld] << std::endl;
            }
        }
    }
    catch (const mysqlx::Error &err)
	{
		std::cout << "ERROR: " << err << std::endl;
		return;
	}
	catch (std::exception &ex)
	{
		std::cout << "STD EXCEPTION: " << ex.what() << std::endl;
		return;
	}
	catch (const char *ex)
	{
		std::cout << "EXCEPTION: " << ex << std::endl;
		return;
	}
}

std::string database::get_insert_string(infrastructure_object& object) const
{
    std::string data = std::vformat("\"name\": \"{}\", \"type\": \"{}\", \"timestamp\": \"{}\", {}", std::make_format_args(object.name, object.type, time_service::get_current_timestamp(), object.get_data_string()));
    return "{" + data + "}";
}