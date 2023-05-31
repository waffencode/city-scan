#ifndef CLIENT_H
#define CLIENT_H

#include "database.h"
#include "data_interface.h"

class client
{
public:
    client(database* db, data_interface* di) : _db(db), _data_interface(di) { }
    
    void menu();
    void m_show();
    void m_editData();
    void m_clearData();
    void m_offer();
    void m_showDatabase();
    void m_addNewData();
    void m_aboutProgram();

    void write_link(std::string link);

private:
    database* _db;
    data_interface* _data_interface;
};

#endif