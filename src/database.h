#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <mysqlx/xdevapi.h>
#include "domain/infrastructure_object.h"

class database
{
public:
    database();
    ~database();
    void add_object(infrastructure_object& object);
    void fetch_data();

private:
    mysqlx::Collection get_collection();
    std::string get_insert_string(infrastructure_object& object) const;

    std::unique_ptr<mysqlx::Session> _session;
};

#endif