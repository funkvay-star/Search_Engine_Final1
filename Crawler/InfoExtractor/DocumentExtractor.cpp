#include "DocumentExtractor.h"
#include <iostream>


// std::string DocumentExtractor::getAbsoluteUrl(std::string& notAbsoluteUrl, const std::string& domain, std::string effectiveUrl)
// {
//     if(notAbsoluteUrl[0] != '/' && effectiveUrl[effectiveUrl.size() - 1] != '/')
//     {
//         size_t sizeOfEffectiveUrl = effectiveUrl.size() - 1;

//         while(effectiveUrl[sizeOfEffectiveUrl] != '/')
//         {
//             effectiveUrl.resize(effectiveUrl.size() - 1);
//         }

//         // https://rau.am/contacts/  phone = https://rau.am/contatcs/phone

//         return effectiveUrl + notAbsoluteUrl;
//     }
//     else if(notAbsoluteUrl[0] != '/' && effectiveUrl[effectiveUrl.size() - 1] == '/')
//     {
//         return effectiveUrl + notAbsoluteUrl;
//     }
//     else if(notAbsoluteUrl[0] != '/' && effectiveUrl[effectiveUrl.size() - 1] == '/' ||
//             notAbsoluteUrl[0] != '/' && effectiveUrl[effectiveUrl.size() - 1] != '/')
//     {
//         return domain + notAbsoluteUrl;
//     }
// }

std::vector<std::string> DocumentExtractor::extractDocument(HtmlDocument& doc, const std::string& domain,
                                                            std::string effectiveUrl)
{
    std::vector<std::string> text;

    
    doc.visitElements([&text, domain, effectiveUrl](HtmlElement elem)
    {
        if(!elem.isTagA())
        {
            return;
        }

        auto href = elem.getAttribute("href");
        
        //size_t foundHttps = href.find("https:");

        if(href.find("://") == std::string::npos && !href.empty() && href.find("Tel") == std::string::npos &&
            href[0] != '#' && href.find("pdf") == std::string::npos)
        {
            href = elem.getAbsoluteUrl(href, domain, effectiveUrl);
        }

        /*if(href[0] == 'T' && href[1] == 'e' && href[2] == 'l' || href[0] == '#')
        {
            href = '\0';
        }*/

        //std::cout << "\n - >" << href << "\n";
        if(href.size() > 0)
        {
            text.push_back(href);
        }
    });
    //std::cout << "\n Size of text- >" << text.size() << "\n";
    return text;
}