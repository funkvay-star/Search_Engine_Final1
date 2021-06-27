#ifndef DATA_BASE_DOCUMENT_REPOSITORY
#define DATA_BASE_DOCUMENT_REPOSITORY

#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include "DocumentEntry.h"

class DataBaseDocumentRepository
{
private:
    sql::Connection* connection;
    sql::Driver* driver;
    sql::Statement* statement;
    sql::PreparedStatement* prepStatment;
    sql::ResultSet *res;

public:
    void Init(const std::string& host, const std::string& username, const std::string& password, const std::string& schema);

    void save(const DocumentEntry& entry);

    std::optional<DocumentEntry> getByUrl(const std::string& Url);

    std::vector<DocumentEntry> getAll();

    ~DataBaseDocumentRepository();
};

#endif
