#include "WebRepository.h"

std::vector<WebSite> WebRepository::getAll()
{
    return source;
}

void WebRepository::save(const WebSite& website)
{
    for(int i = 0; i < source.size(); ++i)
    {
        if(source[i].getDomain() == website.getDomain())
        {
            source[i] = website;
            return;
        }
    }

    source.push_back(website);
}



///////////////////////////////////////////////


std::vector<WebSite> WebRepository::getAllDB()
{
    DataBaseWebSite WebDB;

    WebDB.Init("tcp://127.0.0.1:3306", "root", "password", "SearchEngineSchemas");

    source = WebDB.getAll();

    //WebDB.~DataBaseWebSite();

    return source;
}

void WebRepository::saveDB(const WebSite& website)
{
    DataBaseWebSite WebDB;

    WebDB.Init("tcp://127.0.0.1:3306", "root", "password", "SearchEngineSchemas");

    WebDB.save(website);

    //WebDB.~DataBaseWebSite();

    //std::string query = "SELECT id FROM SearchEngineSchemas ORDER BY id ASC";

    //WebDB.MakeRequest();

    //res = pstmt->executeQuery();

  // Fetch in reverse = descending order!
  //res->afterLast();
  //while (res->previous())
    // cout << "\t... MySQL counts: " << res->getInt("id") << endl;
  //delete res;
}