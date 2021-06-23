#include "HtmlElement.h"
#include <iostream>


std::string HtmlElement::getAbsoluteUrl(std::string& notAbsoluteUrl, const std::string& domain, std::string effectiveUrl)
{
    if(notAbsoluteUrl[0] != '/' && effectiveUrl[effectiveUrl.size() - 1] != '/')
    {
        //std::cout << "first case effective url = " << effectiveUrl  << "     notAbsoluteUrl" << notAbsoluteUrl << "\n";
        size_t sizeOfEffectiveUrl = effectiveUrl.size() - 1;

        while(effectiveUrl[sizeOfEffectiveUrl] != '/')
        {
            effectiveUrl.resize(effectiveUrl.size() - 1);
        }

        //std::cout << "first case AbsoluteUrl= " << effectiveUrl + notAbsoluteUrl << "\n";
        return effectiveUrl + notAbsoluteUrl;
    }
    else if(notAbsoluteUrl[0] != '/' && effectiveUrl[effectiveUrl.size() - 1] == '/')
    {
         //std::cout << "second case effective url = " << effectiveUrl  << "     notAbsoluteUrl" << notAbsoluteUrl << "\n";
         //std::cout << "second case AbsoluteUrl= " << effectiveUrl + notAbsoluteUrl << "\n";
        return effectiveUrl + notAbsoluteUrl;
    }
    else if(notAbsoluteUrl[0] == '/' && effectiveUrl[effectiveUrl.size() - 1] == '/' ||
            notAbsoluteUrl[0] == '/' && effectiveUrl[effectiveUrl.size() - 1] != '/')
    {
        //std::cout << "\nthird case domain = " << domain  << "     notAbsoluteUrl" << notAbsoluteUrl << "\n";
        //std::cout << "third case AbsoluteUrl= " << domain + notAbsoluteUrl << "\n";
        return domain + notAbsoluteUrl;
    }
    
    //return "Error in function getAbsoluteUrl\n";
    return "ERROR:" + notAbsoluteUrl;
}


HtmlElement::HtmlElement(GumboNode* Node) : HtmlNode(Node) {}

bool HtmlElement::isElement()
{
    return true;
}

bool HtmlElement::isTagA() const
{
    if(node->v.element.tag == GUMBO_TAG_A)
    {
        return true;
    }
    return false;
}

bool HtmlElement::isTagText() const
{
    if(node->v.element.tag != GUMBO_TAG_SCRIPT && node->v.element.tag != GUMBO_TAG_STYLE)
    {
        return true;
    }
    return false;
}

bool HtmlElement::isTagDescription() const
{
    if(node->v.element.tag == GUMBO_TAG_META)
    {
        return true;
    }
    return false;
}

bool HtmlElement::isTagTitle() const
{
    if(node->v.element.tag == GUMBO_TAG_TITLE)
    {
        return true;
    }
    return false;
}

std::string HtmlElement::getAttribute(const std::string& name)
{
    GumboAttribute* attribute = gumbo_get_attribute(&node->v.element.attributes, name.c_str());

    if(attribute == nullptr)
    {
        return "";
    }
    return std::string(attribute->value);
}

std::string HtmlElement::getText()
{
    std::string text = "";

    GumboVector* children = &node->v.element.children;

    for(size_t i = 0; i < children->length; ++i) 
    {
        auto child = static_cast<GumboNode*>(children->data[i]); // WARNING
        
        if(child->type == GUMBO_NODE_TEXT)
        {
            text += child->v.text.text;
        }
    }
    return text;
}