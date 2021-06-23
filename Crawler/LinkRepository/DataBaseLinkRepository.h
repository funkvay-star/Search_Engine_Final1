#ifndef DATA_BASE_LINK_REPOSITORY
#define DATA_BASE_LINK_REPOSITORY

#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include "LinkEntry.h"


class DataBaseLinkRepository
{
private:
    sql::Connection* connection;
    sql::Driver* driver;
    sql::Statement* statement;
    sql::PreparedStatement* prepStatment;
    sql::ResultSet *res;

public:
    void Init(const std::string& host, const std::string& username, const std::string& password, const std::string& schema);
    
    void save(const LinkEntry& webSite);

    std::vector<LinkEntry> getAll();

    std::vector<LinkEntry> getByInformation(const std::string& domain, const LinkStatus& status, int count);

    std::optional<LinkEntry> getByUrl(const std::string& Url);
};

#endif
