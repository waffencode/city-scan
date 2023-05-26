#ifndef WATER_OBJECT_H
#define WATER_OBJECT_H

#include "infrastructure_object.h"

class water_object : public infrastructure_object
{
public:
    water_object() { type = "water"; }

    double power_consumption;
    double water_consumption;
    double wastewater_volume;

    double water_output_pressure;
    double water_output_volume_daily;

    double wastewater_input_pressure;
    double wastewater_input_volume_daily;

    std::string get_data_string()
    {
        std::string data = std::vformat("\"power_consumption\": {}, \"water_consumption\": {}, \"wastewater_volume\": {}, \"water_output_pressure\": {}, \"water_output_volume_daily\": {}, \"wastewater_input_pressure\": {}, \"wastewater_input_volume_daily\": {}", 
            std::make_format_args(power_consumption, water_consumption, wastewater_volume, water_output_pressure, water_output_volume_daily, wastewater_input_pressure, wastewater_input_volume_daily));
        return data;
    }
};

#endif