#include <format>
#include <iostream>

#include "database.h"
#include "time_service.h"

const std::string URL = "mysqlx://root@127.0.0.1";

database::database()
{
    try
    {
        std::cout << "Creating session on " << URL << " ..." << std::endl;
        _session = std::make_unique<mysqlx::Session>(URL);
        std::cout << "Session accepted" << std::endl;
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

database::~database()
{ 
    _session->close();
}

mysqlx::Collection database::get_collection()
{
    mysqlx::Schema sch = _session->getSchema("test", false);
    return sch.createCollection("c1", true);
}

void database::add_object(infrastructure_object& object)
{
    try
    {
        mysqlx::Collection collection = get_collection();
        const mysqlx::Result add = collection.add(get_insert_string(object)).execute();
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

mysqlx::DocResult database::fetch_data()
{
    try
    {
        mysqlx::Collection collection = get_collection();
        mysqlx::DocResult docs = collection.find().execute();
        return docs;
    }
    catch (const mysqlx::Error &err)
	{
		std::cout << "ERROR: " << err << std::endl;
		return mysqlx::DocResult();
	}
	catch (std::exception &ex)
	{
		std::cout << "STD EXCEPTION: " << ex.what() << std::endl;
		return mysqlx::DocResult();
	}
	catch (const char *ex)
	{
		std::cout << "EXCEPTION: " << ex << std::endl;
		return mysqlx::DocResult();
	}
}

mysqlx::DocResult database::fetch_data(std::string query)
{
    try
    {
        mysqlx::Collection collection = get_collection();
        mysqlx::DocResult docs = collection.find(query).execute();
        return docs;
    }
    catch (const mysqlx::Error &err)
	{
		std::cout << "ERROR: " << err << std::endl;
		return mysqlx::DocResult();
	}
	catch (std::exception &ex)
	{
		std::cout << "STD EXCEPTION: " << ex.what() << std::endl;
		return mysqlx::DocResult();
	}
	catch (const char *ex)
	{
		std::cout << "EXCEPTION: " << ex << std::endl;
		return mysqlx::DocResult();
	}
}

void database::add_raw_data(const std::string& data)
{
	const mysqlx::DbDoc entity(data);

	const std::string type(entity["type"]);
	
	if (type == "energy")
	{
		energy_object temp;
        temp.name = entity["name"].get<std::string>();
        temp.type = type;
        temp.power_consumption = entity["power_consumption"];
		temp.water_consumption = entity["water_consumption"];
		temp.wastewater_volume = entity["wastewater_volume"];
		temp.power_output = entity["power_output"];
		add_object(temp);
	}
	else if (type == "water")
	{
		water_object temp;
		temp.name = entity["name"].get<std::string>();
		temp.type = type;
		temp.power_consumption = entity["power_consumption"];
		temp.water_consumption = entity["water_consumption"];
		temp.wastewater_volume = entity["wastewater_volume"];
		temp.wastewater_input_pressure = entity["wastewater_input_pressure"];
		temp.wastewater_input_volume_daily = entity["wastewater_input_volume_daily"];
		temp.water_output_pressure = entity["water_output_pressure"];
		temp.water_output_volume_daily = entity["water_output_volume_daily"];
		add_object(temp);
	}
	else if (type == "transport")
	{
		transport_object temp;
        temp.name = entity["name"].get<std::string>();
        temp.type = type;
		temp.power_consumption = entity["power_consumption"];
		temp.water_consumption = entity["water_consumption"];
		temp.wastewater_volume = entity["wastewater_volume"];
		temp.daily_traffic = entity["daily_traffic"].get<int64_t>();
		temp.average_daily_traffic_intensity = entity["average_daily_traffic_intensity"];
		add_object(temp);
	}
}

std::string database::get_insert_string(infrastructure_object& object)
{
    const std::string data = std::vformat(R"("name": "{}", "type": "{}", "timestamp": "{}", {})", std::make_format_args(object.name, object.type, time_service::get_current_timestamp(), object.get_data_string()));
    return "{" + data + "}";
}