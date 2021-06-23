#ifndef HTML_ELEMENT_H
#define HTML_ELEMENT_H
#include "HtmlNode.h"
#include <string>
#include <gumbo.h>

class HtmlElement : HtmlNode
{
private:
   // GumboNode* node;
public:
    HtmlElement(GumboNode* Node);
    bool isElement() override; // always returns true cuz it's always element (cuz we are in
    // HtmlElement.h) not just Node
    bool isTagA() const;
    bool isTagTitle() const;
    bool isTagText() const;
    bool isTagDescription() const;
    

    std::string getAbsoluteUrl(std::string& notAbsoluteUrl, const std::string& domain, std::string effectiveUrl);
    std::string getAttribute(const std::string& name);
    std::string getText();
};

#endif
