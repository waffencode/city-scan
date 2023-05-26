#ifndef ENERGY_OBJECT_H
#define ENERGY_OBJECT_H

#include <format>
#include <string>

#include "infrastructure_object.h"

class energy_object : public infrastructure_object
{
public:
    energy_object() { type = "energy"; }

    double power_consumption;
    double water_consumption;
    double wastewater_volume;

    double power_output;
    
    std::string get_data_string()
    {
        std::string data = std::vformat("\"power_consumption\": {}, \"water_consumption\": {}, \"wastewater_volume\": {}, \"power_output\": {}", 
            std::make_format_args(power_consumption, water_consumption, wastewater_volume, power_output));
        return data;
    }
};

#endif