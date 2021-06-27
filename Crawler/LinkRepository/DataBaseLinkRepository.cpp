#include "DataBaseLinkRepository.h"
#include <iostream>

void DataBaseLinkRepository::Init(const std::string& host, const std::string& username, const std::string& password, const std::string& schema)
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

void DataBaseLinkRepository::save(const LinkEntry& webSite)
{
    try
    {
        int Status;
        if(webSite.getStatus() == LinkStatus::ERROR)
        {
            Status = 2;
        }
        else if(webSite.getStatus() == LinkStatus::SUCCESS)
        {
            Status = 1;
        }
        else if(webSite.getStatus() == LinkStatus::WAITING)
        {
            Status = 0;
        }


        prepStatment = connection->prepareStatement("SELECT * FROM LinkRepository");
        res = prepStatment->executeQuery();

        while(res->next())
        {
            if(res->getString("url") == webSite.getUrl())
            {
                prepStatment = connection->prepareStatement("UPDATE LinkRepository SET `domain`=(?), `status`=(?) WHERE `url`=(?)");
                prepStatment->setString(1, webSite.getDomain());
                prepStatment->setInt(2, Status);
                prepStatment->setString(3, webSite.getUrl());
                prepStatment->executeQuery();
                return;
                //("UPDATE WebSite SET `homepage`=(?) WHERE id=(?)");
            }
        }
        delete prepStatment;
        delete res;

        prepStatment = connection->prepareStatement("insert into LinkRepository(domain, url, status) values(?,?,?)");
        prepStatment->setString(1, webSite.getDomain());
        prepStatment->setString(2, webSite.getUrl());
        prepStatment->setInt(3, Status);
        prepStatment->executeQuery();
    }
    catch (sql::SQLException& e)
    {
        std::cerr << e.what() << '\n';
        
        return;
    }
}

std::vector<LinkEntry> DataBaseLinkRepository::getAll()
{
    std::vector<LinkEntry> answer;
    try
    {
        prepStatment = connection->prepareStatement("SELECT * FROM LinkRepository");
        res = prepStatment->executeQuery();

        while(res->next())
        {   
            /*std::string domain;
            std::string url;
            int status;
            std::time_t crawleTime;
            domain = res->getString("domain");
            url = res->getString("url");
            crawleTime = res->getInt("updated");
            */

            int Status = res->getInt("status");

            LinkStatus statusLinkStatus;
            if(Status == 2)
            {
                statusLinkStatus = LinkStatus::ERROR;
            }
            else if (Status == 1)
            {
                statusLinkStatus = LinkStatus::SUCCESS;
            }
            else if (Status == 0)
            {
                statusLinkStatus = LinkStatus::WAITING;
            }

            //std::cout << "DataBaseLinkRepository getAllDB going to push \n";
            answer.push_back(LinkEntry(res->getString("url"), res->getString("domain"), statusLinkStatus, res->getInt("updated")));
        }
        return answer;
    }
    catch(sql::SQLException& e)
    {
        std::cerr << e.what() << '\n';
    }
    return answer;
}


std::vector<LinkEntry> DataBaseLinkRepository::getByInformation(const std::string& domain, const LinkStatus& status, int count)
{
    std::vector<LinkEntry> answer;
    try
    {
        prepStatment = connection->prepareStatement("SELECT * FROM LinkRepository");
        res = prepStatment->executeQuery();

        while(res->next() && answer.size() < count)
        {
            int Status = res->getInt("status");

            if(Status == int(status) && res->getString("domain") == domain)
            {
                LinkEntry saver(res->getString("url"), res->getString("domain"), status, res->getInt("updated"));

                answer.push_back(saver);
            }
        }
        return answer;
    }
    catch(sql::SQLException& e)
    {
        std::cerr << e.what() << '\n';
    }
    return answer;
}

std::optional<LinkEntry> DataBaseLinkRepository::getByUrl(const std::string& Url)
{
    try
    {
        prepStatment = connection->prepareStatement("SELECT * FROM LinkRepository");
        res = prepStatment->executeQuery();

        while(res->next())
        {
            std::string url = res->getString("url");

            if(res->getString("url") == Url)
            {
                //std::cout << "url-> " << url << "              Url-> " << Url << "\n";

                int Status = res->getInt("status");

                LinkStatus statusLinkStatus;
                if(Status == 2)
                {
                    statusLinkStatus = LinkStatus::ERROR;
                }
                else if (Status == 1)
                {
                    statusLinkStatus = LinkStatus::SUCCESS;
                }
                else if (Status == 0)
                {
                    statusLinkStatus = LinkStatus::WAITING;
                }

                return std::make_optional(LinkEntry(res->getString("url"), res->getString("domain"), statusLinkStatus, res->getInt("updated")));
            }
        }
    }
    catch(sql::SQLException& e)
    {
        std::cerr << e.what() << '\n';
    }
    //return std::make_optional(LinkEntry("a", "b", LinkStatus::ERROR, 0));

    return {};
}

DataBaseLinkRepository::~DataBaseLinkRepository()
{
    driver->threadEnd();
    connection->close();

    delete connection;
    delete prepStatment;
    delete res;
}