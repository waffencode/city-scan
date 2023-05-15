#include <iostream>
#include <memory>

#include "database.h"
#include "client.h"

int main(int argc, const char *argv[])
{
	std::unique_ptr<database> db = std::make_unique<database>();
	std::unique_ptr<client> cl = std::make_unique<client>(db);

	cl->init();
}