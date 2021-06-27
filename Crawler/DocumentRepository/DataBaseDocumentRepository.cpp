#include "DataBaseDocumentRepository.h"
#include <iostream>

void DataBaseDocumentRepository::Init(const std::string& host, const std::string& username, const std::string& password, const std::string& schema)
{
    try
    {
        driver = get_driver_instance();
        connection = driver->connect(host, username, password);
        connection->setSchema(schema);
        statement = connection->createStatement();
    }
    catch (sql::SQLException& e)
    {
        std::cerr << e.what();
    }
}

void DataBaseDocumentRepository::save(const DocumentEntry& entry)
{
    try
    {
        prepStatment = connection->prepareStatement("SELECT * FROM DocumentRepository");
        res = prepStatment->executeQuery();

        while(res->next())
        {
            if(res->getString("url") == entry.getUrl())
            {
                prepStatment = connection->prepareStatement("UPDATE DocumentRepository SET `title`=(?), `description`=(?), `text`=(?) WHERE `url`=(?)");
                prepStatment->setString(1, entry.getTitle());
                prepStatment->setString(2, entry.getDescription());
                prepStatment->setString(3, entry.getText());
                prepStatment->setString(4, entry.getUrl());
                prepStatment->executeQuery();
                return;
                //("UPDATE WebSite SET `homepage`=(?) WHERE id=(?)");
            }
        }
        delete prepStatment;
        delete res;

        prepStatment = connection->prepareStatement("insert into DocumentRepository(title, description, text, url) values(?,?,?,?)");
        prepStatment->setString(1, entry.getTitle());
        prepStatment->setString(2, entry.getDescription());
        prepStatment->setString(3, entry.getText());
        prepStatment->setString(4, entry.getUrl());
        prepStatment->executeQuery();
    }
    catch (sql::SQLException& e)
    {
        std::cerr << e.what() << '\n';
        
        return;
    }
}

std::optional<DocumentEntry> DataBaseDocumentRepository::getByUrl(const std::string& Url)
{
    try
    {
        prepStatment = connection->prepareStatement("SELECT * FROM DocumentRepository");
        res = prepStatment->executeQuery();
        

        while(res->next())
        {
            std::string url = res->getString("url");

            if(res->getString("url") == Url)
            {
                return std::make_optional(DocumentEntry(res->getString("url"), res->getString("title"), res->getString("description"),
                res->getString("text"), res->getInt("updated")));
            }
        }
    }
    catch(sql::SQLException& e)
    {
        std::cerr << e.what() << '\n';
    }

    return std::make_optional(DocumentEntry());
}

std::vector<DocumentEntry> DataBaseDocumentRepository::getAll()
{
    std::vector<DocumentEntry> answer;
    try
    {
        prepStatment = connection->prepareStatement("SELECT * FROM DocumentRepository");
        res = prepStatment->executeQuery();

        while(res->next())
        { 
            answer.push_back(DocumentEntry(res->getString("url"), res->getString("title"), res->getString("description"),
                res->getString("text"), res->getInt("updated")));
        }
        return answer;
    }
    catch(sql::SQLException& e)
    {
        std::cerr << e.what() << '\n';
    }
    return answer;
}

DataBaseDocumentRepository::~DataBaseDocumentRepository()
{
    driver->threadEnd();
    connection->close();

    delete connection;
    delete prepStatment;
    delete res;
}