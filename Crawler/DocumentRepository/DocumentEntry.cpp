#include "DocumentEntry.h"

DocumentEntry::DocumentEntry() : url(), title(), description(), text(), lastTime() {}

DocumentEntry::DocumentEntry(const std::string& Url, const std::string& Title, 
    const std::string& Description, const std::string& Text, std::time_t LastTime) //there is not const and & for LastTime because of error
    : url(Url), title(Title), description(Description), text(Text), lastTime(LastTime) {}

std::string DocumentEntry::getUrl()
{
    return url;
}

std::string DocumentEntry::getTitle()
{
    return title;
}

std::string DocumentEntry::getDescription()
{
    return description;
}

std::string DocumentEntry::getText()
{
    return text;
}

std::time_t DocumentEntry::getTime()
{
    return lastTime;
}