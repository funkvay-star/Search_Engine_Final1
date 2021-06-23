#include "HtmlNode.h"

HtmlNode::HtmlNode(GumboNode* Node) : node(Node) {} 

bool HtmlNode::isElement()
{
    return node->type == GUMBO_NODE_ELEMENT;
}