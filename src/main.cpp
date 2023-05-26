#include <iostream>
#include <memory>

#include "database.h"
#include "time_service.h"
#include "domain/energy_object.h"
#include "domain/transport_object.h"

int main()
{
	std::unique_ptr<database> db = std::make_unique<database>();

	energy_object p;
	p.name = "Power plant";
	p.power_consumption = 0;
	p.water_consumption = 0;
	p.wastewater_volume = 0;
	p.power_output = 0;
	
	transport_object t;
	t.name = "Bus stop";
	t.power_consumption = 0;
	t.water_consumption = 0;
	t.wastewater_volume = 0;
	t.daily_traffic = 0;
	t.average_daily_traffic_intensity = 0;

	db->add_object(p);
	db->add_object(t);

	db->fetch_data();

	return 0;
}