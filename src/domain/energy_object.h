#ifndef ENERGY_OBJECT_H
#define ENERGY_OBJECT_H

#include "infrastructure_object.h"
#include <string>

class energy_object : public infrastructure_object
{
public:
    double voltage;
    
    std::string get_data_string()
    {
        return R"("voltage": )" + std::to_string(voltage) + R"()";
    }
};

#endif