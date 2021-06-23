#include "LinkRepository.h"
#include <algorithm>
#include <iostream>

std::vector<LinkEntry> LinkRepository::getAll()
{
    std::vector<LinkEntry> get_all;

    for(auto it : source)
    {
        get_all.push_back(it);
    }

    return get_all;
}

std::vector<LinkEntry> LinkRepository::getByInformation(const std::string& domain, const LinkStatus& status, int count)
{
    std::vector<LinkEntry> linkSource;

    for(auto link : source)
    {
        if(count == 0)
        {
            break;
        }

        //std::cout << "getDomainLink: " << link.getDomain() << " getUrlLink:" << link.getUrl() << "\n";

        if(link.getDomain() == domain && link.getStatus() == status)
        {
            //std::cout << "in push_back()\n";
            linkSource.push_back(link);
            --count;
        }
    }
    return linkSource;
}

//ORIGINAL FUNCTION
void LinkRepository::save(const LinkEntry& entry)
{
    for(int i = 0; i < source.size(); ++i)
    {
        if(source[i].getUrl() == entry.getUrl())
        {
            source[i] = entry;
            return;
        }
    }

    source.push_back(entry);
    std::cout << "source size after save: " << source.size() << "\n";
    std::cout << entry.getUrl();

    if(entry.getStatus() == LinkStatus::ERROR)
    {
        std::cout << "  ERROR\n";
    }
    else if(entry.getStatus() == LinkStatus::SUCCESS)
    {
        std::cout << "  SUCCESS\n";
    }
    else if(entry.getStatus() == LinkStatus::WAITING)
    {
        std::cout << "  WAITING\n";
    }
}



std::optional<LinkEntry> LinkRepository::getByUrl(const std::string& Url)
{
    for(int i = 0; i < source.size(); ++i)
    {
        if(source[i].getUrl() == Url)
        {
            return std::make_optional(source[i]);
        }
    }

    return {};
}

size_t LinkRepository::source_size()
{
    return source.size();
}

/////////////////////

std::vector<LinkEntry> LinkRepository::getAllDB()
{
    DataBaseLinkRepository LinkDB;

    LinkDB.Init("tcp://127.0.0.1:3306", "root", "password", "SearchEngineSchemas");

    std::cout << "LinkRepository::getAllDB\n";

    return LinkDB.getAll();
}

std::vector<LinkEntry> LinkRepository::getByInformationDB(const std::string& domain, const LinkStatus& status, int count)
{
    DataBaseLinkRepository LinkDB;

    LinkDB.Init("tcp://127.0.0.1:3306", "root", "password", "SearchEngineSchemas");

    return LinkDB.getByInformation(domain, status, count);
}

void LinkRepository::saveDB(const LinkEntry& entry)
{
    DataBaseLinkRepository LinkDB;

    LinkDB.Init("tcp://127.0.0.1:3306", "root", "password", "SearchEngineSchemas");

    LinkDB.save(entry);
}

std::optional<LinkEntry> LinkRepository::getByUrlDB(const std::string& Url)
{
    DataBaseLinkRepository LinkDB;

    LinkDB.Init("tcp://127.0.0.1:3306", "root", "password", "SearchEngineSchemas");

    return LinkDB.getByUrl(Url);
}
