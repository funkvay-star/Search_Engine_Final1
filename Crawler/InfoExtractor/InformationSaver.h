#ifndef INFORMATION_SAVER
#define INFORMATION_SAVER

#include <iostream>
#include <string>

//#include "/home/funkvay/Search_Engine/Crawler/HTMLDocument/HtmlDocument.h"
#include "../HTMLDocument/HtmlDocument.h"
#include <vector>

class InformationSaver
{
private:
    std::string title;
    std::string description;
    std::string text;

public:
    InformationSaver();
    InformationSaver(const std::string& title, const std::string& description, 
    const std::string& text);

    std::string getTitle();
    std::string getDescription();
    std::string getText();
};

#endif
