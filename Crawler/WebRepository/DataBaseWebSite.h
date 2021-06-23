#ifndef DATA_BASE_WEB_SITE
#define DATA_BASE_WEB_SITE

#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include "WebSite.h"


class DataBaseWebSite
{
private:
    sql::Connection* connection;
    sql::Driver* driver;
    sql::Statement* statement;
    sql::PreparedStatement* prepStatment;
    sql::ResultSet *res;

public:
    void Init(const std::string& host, const std::string& username, const std::string& password, const std::string& schema);
    
    void save(const WebSite& webSite);

    std::vector<WebSite> getAll();
};

#endif
