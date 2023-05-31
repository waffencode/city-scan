#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <mysqlx/xdevapi.h>

#include "domain/infrastructure_object.h"
#include "domain/energy_object.h"
#include "domain/water_object.h"
#include "domain/transport_object.h"

class database
{
public:
    database();
    ~database();
    void add_object(infrastructure_object& object);
    void add_raw_data(const std::string& data);
    mysqlx::DocResult fetch_data();
    mysqlx::DocResult fetch_data(std::string query);

private:
    mysqlx::Collection get_collection();
    static std::string get_insert_string(infrastructure_object& object);

    std::unique_ptr<mysqlx::Session> _session;
};

#endif