#include <iostream>
#include <memory>

#include "database.h"
#include "domain/energy_object.h"

int main()
{
	std::unique_ptr<database> db = std::make_unique<database>();

	return 0;
}