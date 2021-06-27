#include "DocumentRepository.h"

std::vector<DocumentEntry> DocumentRepository::getAll()
{
    return document;
}

std::optional<DocumentEntry> DocumentRepository::getByUrl(const std::string& url)
{
    for(size_t i = 0; i < document.size(); ++i)
    {
        if(document[i].getUrl() == url)
        {
            return std::make_optional(document[i]);
        }
    }
    return {};
}

void DocumentRepository::save(DocumentEntry& entry)
{
    for(size_t i = 0; i < document.size(); ++i)
    {
        if(entry.getUrl() == document[i].getUrl())
        {
            document[i] = entry;
            return;
        }
    }
    document.push_back(entry);
}

////////////////////

std::vector<DocumentEntry> DocumentRepository::getAllDB()
{
    DataBaseDocumentRepository DocDB;

    DocDB.Init("tcp://127.0.0.1:3306", "root", "password", "SearchEngineSchemas");

    auto answer = DocDB.getAll();

    //DocDB.~DataBaseDocumentRepository();

    return answer;
}

std::optional<DocumentEntry> DocumentRepository::getByUrlDB(const std::string& url)
{
    DataBaseDocumentRepository DocDB;

    DocDB.Init("tcp://127.0.0.1:3306", "root", "password", "SearchEngineSchemas");

    auto answer = DocDB.getByUrl(url);

    //DocDB.~DataBaseDocumentRepository();

    return answer;
}

void DocumentRepository::saveDB(const DocumentEntry& entry)
{
    DataBaseDocumentRepository DocDB;

    DocDB.Init("tcp://127.0.0.1:3306", "root", "password", "SearchEngineSchemas");

    DocDB.save(entry);

    //DocDB.~DataBaseDocumentRepository();
}