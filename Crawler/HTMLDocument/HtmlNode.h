#ifndef HTML_NODE_H
#define HTML_NODE_H
#include <gumbo.h>

class HtmlNode
{
protected:
    GumboNode* node;
public:
    HtmlNode(GumboNode* Node);
    virtual bool isElement();
};

#endif
