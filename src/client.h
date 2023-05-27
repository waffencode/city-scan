#ifndef CLIENT_H
#define CLIENT_H

#include "database.h"

class client
{
public:
    client(database* db) : _db(db) { }
    
    void menu();
    void m_show();
    void m_editData();
    void m_clearData();
    void m_offer();
    void m_showDatabase();
    void m_addNewData();
    void m_aboutProgram();

private:
    database* _db;
};

#endif