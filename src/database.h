#include <string>

class database
{
public:
    database();

private:
    void make_generic_query(std::string);
    void make_select_query(std::string);
    void make_insert_query(std::string);
    void make_update_query(std::string);
    void make_delete_query(std::string);
};