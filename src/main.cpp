#include <iostream>
#include <memory>

#include "database.h"
#include "client.h"
#include "time_service.h"
#include "domain/energy_object.h"
#include "domain/transport_object.h"

int main()
{
	std::unique_ptr<database> db = std::make_unique<database>();
	std::unique_ptr<client> cl = std::make_unique<client>(db.get());
	cl->menu();

	return 0;
}