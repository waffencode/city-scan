#ifndef DATA_INTERFACE_H
#define DATA_INTERFACE_H

#include <vector>
#include "database.h"

class data_interface
{
public:
    data_interface(database* db) : _db(db) { }
    void request(std::string url);
    void write_callback(std::string data);
    std::vector<std::string> read_link();
    void request_all();
    static size_t write_data(char *ptr, size_t size, size_t nmemb, std::string* data);
    
private:
    database* _db;
};

#endif