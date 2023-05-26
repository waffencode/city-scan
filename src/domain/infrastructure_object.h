#ifndef INFRASTRUCTURE_OBJECT_H
#define INFRASTRUCTURE_OBJECT_H

#include <string>

class infrastructure_object
{
public:
    std::string name;
    std::string type;
    
    virtual std::string get_data_string() { return ""; }
};

#endif 