#include <stdlib.h>

#include "InformationSaver.h"

InformationSaver::InformationSaver() : title(), description(), text() {}

InformationSaver::InformationSaver(const std::string& Title, const std::string& Description, 
    const std::string& Text) : title(Title), description(Description), text(Text) {}

std::string InformationSaver::getTitle()
{
    return title;
}

std::string InformationSaver::getDescription()
{
    return description;
}

std::string InformationSaver::getText()
{
    return text;
}
