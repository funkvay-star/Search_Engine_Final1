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

/*
int main()
{
    DocumentRepository docRep;

    docRep.saveDB(DocumentEntry("URL.HEHH", "TITLE CHIKI BRIKI", "Description kuku", "TEXT kak TEXT"));
    docRep.saveDB(DocumentEntry("URL.HEHH1", "TITLE CHIKI BRIKI1", "Description kuku1", "TEXT kak TEXT1"));
    docRep.saveDB(DocumentEntry("ULRRRR", "TIKI", "kuku", "TEXEXT"));

    for(auto it : docRep.getAllDB())
    {
        //std::cout << it.getUrl() << "    " << it.getText() << "\n";
    }

    if(docRep.getByUrlDB("ULRRRR").has_value())
    {
        std::cout << "has value";
    }
}
*/

int main()
{
    WebRepository webrep;

    std::time_t currentTime{};

    PageLoader pageLoader;

    DocumentExtractor linkExtractor;

    InformationExtractor informationExtractor;

    std::map<std::string, InformationSaver> webSaver;

    WebSite w("rau.am", "https://rau.am/", time(&currentTime));
    //WebSite w("rau.am", "https://en.wikipedia.org/wiki/Armenia", time(&currentTime));
    webrep.saveDB(w);

    w.getDomain();
    

    LinkRepository linkRepository;
    DocumentRepository documentRepository;
    
    for(auto& website : webrep.getAllDB())
    {

        linkRepository.saveDB(LinkEntry(website.getHomePage(), website.getDomain(), LinkStatus::WAITING, time(&currentTime)));         

        while(true)
        {
            //std::cout << "main.cpp While true\n";
            auto links = linkRepository.getByInformationDB(website.getDomain(), LinkStatus::WAITING, 1);

            if(links.empty())
            {
                //std::cout << "number of links: " << links.size();
                break;
            }


            for(auto& link : links)
            {
                //std::cout << "main.cpp links  " << link.getUrl() << "\n";
                if(link.getUrl() == "NOT_VALID" || link.getStatus() == LinkStatus::ERROR)
                {
                    continue;
                }

                auto loadResult = pageLoader.get_data(link.getUrl());

                //std::cout << "getErrorCode " << loadResult.getErrorCode() << "\n";

                if(loadResult.getErrorCode() == -5)
                {
                    linkRepository.saveDB(LinkEntry(link.getUrl(), website.getDomain(), LinkStatus::ERROR, time(&currentTime)));

                    continue;
                }
                
                
                if(loadResult.getStatus() < 200 || loadResult.getStatus() >= 300)
                {
                    linkRepository.saveDB(LinkEntry(link.getUrl(), website.getDomain(), LinkStatus::ERROR, time(&currentTime)));
                    continue;
                }

                
                HtmlDocument document((*(loadResult.getBody().get())));
                std::string effectiveUrl = loadResult.getEffectiveUrl();
            
                std::vector<std::string> extractLinks;
                
                document.parse();
                    

                try
                {
                    extractLinks = linkExtractor.extractDocument(document, w.getDomain(), effectiveUrl);
                }
                catch(std::length_error e)
                {
                    //std::cout << "\n e ="  <<e.what();
                    //std::cout << "\n\n\nSOS\n\n\n";
                }

                //std::cout << "Extract links size " << extractLinks.size() << "\n";

                for(const std::string& newLink : extractLinks)
                {
                    if(linkRepository.getByUrlDB(newLink).has_value())
                    {
                        //std::cout << "line 185 " << newLink << "\n";
                        continue;
                    }
                    
                    size_t indexOfDomain = newLink.find(website.getDomain());
                    if(indexOfDomain != std::string::npos)
                    {
                        LinkEntry trash(newLink, website.getDomain(), LinkStatus::WAITING, time(&currentTime));

                        linkRepository.saveDB(trash);
                    }
                }
                
                auto documentInformation = informationExtractor.extractInformation(document);

                //webSaver[link.getUrl()] = documentInformation;
                //documentRepository.saveDB();

                DocumentEntry documentEntry(link.getUrl(), documentInformation.getTitle(), documentInformation.getDescription(), documentInformation.getText());

                documentRepository.saveDB(documentEntry);

                //std::cout << "linkRepository size 201 line \'" << linkRepository.getAllDB().size() << "\'\n";
                linkRepository.saveDB(LinkEntry(link.getUrl(), link.getDomain(), LinkStatus::SUCCESS, time(&currentTime)));
                //std::cout << "linkRepository size 203 line \'" << linkRepository.getAllDB().size() << "\'\n";
            }
        }
        
        webrep.saveDB(WebSite(website.getDomain(), website.getHomePage(), time(&currentTime)));
    }
}