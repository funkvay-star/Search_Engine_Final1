#include "DataBaseWebSite.h"

void DataBaseWebSite::Init(const std::string& host, const std::string& username, const std::string& password, const std::string& schema)
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

void DataBaseWebSite::save(const WebSite& webSite)
{
    try
    {
        prepStatment = connection->prepareStatement("SELECT * FROM WebSite");
        res = prepStatment->executeQuery();

        while(res->next())
        {
            if(res->getString("domain") == webSite.getDomain())
            {
                std::string idString = res->getString("id");
                prepStatment = connection->prepareStatement("UPDATE WebSite SET `homepage`=(?) WHERE `id`=(?)");
                //std::cout << "UPDATE WebSite SET \'domain\' = \'" + webSite.getDomain() + "\', \'homepage\' = \'" + webSite.getHomePage() + "\' WHERE (\'id\' = \'" + idString +  "\')";
                prepStatment->setString(1, webSite.getHomePage());
                prepStatment->setString(2, idString);
                prepStatment->executeUpdate();
                return;
            }
        }
        delete prepStatment;
        delete res;

        prepStatment = connection->prepareStatement("insert into WebSite(domain, homepage) values(?,?)");
        prepStatment->setString(1, webSite.getDomain());
        prepStatment->setString(2, webSite.getHomePage());
        prepStatment->executeQuery();
    }
    catch (sql::SQLException& e)
    {
        std::cerr << e.what() << '\n';
        
        return;
    }
}

std::vector<WebSite> DataBaseWebSite::getAll()
{
    std::vector<WebSite> answer;
    try
    {
        prepStatment = connection->prepareStatement("SELECT * FROM WebSite");
        res = prepStatment->executeQuery();

        while(res->next())
        {
            /*
            std::string domain;
            std::string homepage;
            std::time_t crawleTime;

            domain = res->getString("domain");
            homepage = res->getString("homepage");
            crawleTime = res->getInt("updated");
            */

            WebSite saver(res->getString("domain"), res->getString("homepage"), res->getInt("updated"));

            answer.push_back(saver);
        }
    }
    catch(sql::SQLException& e)
    {
        std::cerr << e.what() << '\n';
    }
    return answer;
}

DataBaseWebSite::~DataBaseWebSite()
{
    driver->threadEnd();
    connection->close();

    delete connection;
    delete prepStatment;
    delete res;
}