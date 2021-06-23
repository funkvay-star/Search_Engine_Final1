#include "HtmlDocument.h"


// std::string HtmlDocument::getAbsoluteUrl(std::string& notAbsoluteUrl, const std::string& domain, std::string effectiveUrl)
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

HtmlDocument::HtmlDocument(const std::string& Url) : url(Url), output(nullptr) {}

bool HtmlDocument::parse()
{
  this->output = gumbo_parse(this->url.c_str());
  return true;
}


void HtmlDocument::visitElements(std::function<void(HtmlElement)> visitor)
{
    this->visitElement(output->root, visitor);
}

void HtmlDocument::visitElement(GumboNode* node, std::function<void(HtmlElement)> visitor)
{
    if(node->type != GUMBO_NODE_ELEMENT)
    {
        return;
    }

    visitor(HtmlElement(node));

    
  GumboVector* children = &node->v.element.children;
  for (unsigned int i = 0; i < children->length; ++i) 
  {
    visitElement(static_cast<GumboNode*>(children->data[i]), visitor);
  }
}

HtmlDocument::~HtmlDocument()
{
  if(this->output != nullptr)
  {
    gumbo_destroy_output(&kGumboDefaultOptions, this->output);
  }
}