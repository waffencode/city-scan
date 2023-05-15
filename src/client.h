#include "database.h"

class client
{
public:
    client(database* db);
    void init();

private:
    database* _db;
};