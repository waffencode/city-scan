#ifndef TRANSPORT_OBJECT_H
#define TRANSPORT_OBJECT_H

#include "infrastructure_object.h"

class transport_object : public infrastructure_object
{
public:
    transport_object() { type = "transport"; }

    double power_consumption;   
    double water_consumption;
    double wastewater_volume;

    unsigned long int daily_traffic;
    double average_daily_traffic_intensity;

    std::string get_data_string()
    {
        std::string data = std::vformat("\"power_consumption\": {}, \"water_consumption\": {}, \"wastewater_volume\": {}, \"daily_traffic\": {}, \"average_daily_traffic_intensity\": {}", 
            std::make_format_args(power_consumption, water_consumption, wastewater_volume, daily_traffic, average_daily_traffic_intensity));
        return data;
    }
};

#endif