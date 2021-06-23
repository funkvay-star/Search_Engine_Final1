#ifndef HTML_DOCUMENT_H
#define HTML_DOCUMENT_H
#include <string>
#include <functional>
#include "HtmlElement.h"
#include "gumbo.h"

class HtmlDocument
{
private:
    std::string url;
    GumboOutput* output;
    
    void visitElement(GumboNode* node, std::function<void(HtmlElement)> visitor);
    std::string getAbsoluteUrl(std::string& notAbsoluteUrl, const std::string& domain, std::string effectiveUrl);
public:

    HtmlDocument(const std::string& Url);
    bool parse();
    void visitElements(std::function<void(HtmlElement)> visitor);
    
    //void visitElements(HtmlElement elem);
    ~HtmlDocument();
};

#endif
