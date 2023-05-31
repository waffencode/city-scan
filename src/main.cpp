#include <iostream>
#include <memory>

#include "database.h"
#include "data_interface.h"
#include "client.h"
#include "domain/energy_object.h"
#include "domain/transport_object.h"

int main()
{
	std::unique_ptr<database> db = std::make_unique<database>();
	std::unique_ptr<data_interface> di = std::make_unique<data_interface>(db.get());
	std::unique_ptr<client> cl = std::make_unique<client>(db.get(), di.get());
	cl->menu();

	return 0;
}