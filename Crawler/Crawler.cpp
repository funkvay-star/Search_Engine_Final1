#include "PageLoader/PageLoader.h"
#include "PageLoader/LoadResult.h"
#include "WebRepository/WebRepository.h"
#include "InfoExtractor/DocumentExtractor.h"
#include "InfoExtractor/InformationExtractor.h"
#include "LinkRepository/LinkRepository.h"
#include "LinkRepository/LinkEntry.h"
#include "LinkRepository/LinkRepository.h"
#include "LinkRepository/LinkStatus.h"
#include "DocumentRepository/DocumentRepository.h"
#include "HTMLDocument/HtmlDocument.h"
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <map>



/*
int main()
{
    WebRepository webrep;

     std::time_t currentTime{};

    //webrep.saveDB(WebSite("rau.am", "homepage.lol", time(&currentTime)));

    LinkRepository link;

    link.saveDB(LinkEntry("rau.am/kuksfu", "rau.dom", LinkStatus::WAITING));
    link.saveDB(LinkEntry("rau.am/kukufa", "rau.dom", LinkStatus::ERROR));
    link.saveDB(LinkEntry("rau.am/kukuizi", "rau.dom", LinkStatus::ERROR));
    link.saveDB(LinkEntry("rau.am/kukui", "rau.dom", LinkStatus::SUCCESS));
    link.saveDB(LinkEntry("rau.am/ku", "rau.dom", LinkStatus::ERROR));
    link.saveDB(LinkEntry("rau.am/k", "rau.dom", LinkStatus::SUCCESS));
    link.saveDB(LinkEntry("mami", "rau.dom", LinkStatus::ERROR));
    link.saveDB(LinkEntry("KEKE", "rau.dom", LinkStatus::SUCCESS));
    link.saveDB(LinkEntry("Halivudik", "rau.dom", LinkStatus::WAITING));
    link.saveDB(LinkEntry("HaviBudik", "rau.dom", LinkStatus::WAITING));
    link.saveDB(LinkEntry("LLL", "rau.dom", LinkStatus::WAITING));



    //link.saveDB(LinkEntry("url.am", "domain.am", LinkStatus::WAITING));

    for(auto it : link.getAllDB())
    {
        std::cout << it.getUrl() << "           " << it.getDomain() << "\n";
    }

    std::cout << "\n\n\n\n\n";


    if(link.getByUrlDB("rau.am/k").has_value())
    {
        std::cout << "has value";
    }
    else
    {
        std::cout << "there is no value";
    }

    std::cout << "\n\n\n\n\n";

    for(auto it : link.getByInformationDB("rau.dom", LinkStatus::SUCCESS, 2))
    {
        std::cout << it.getUrl() << "           " << it.getDomain() << "\n";
    }
}
*/