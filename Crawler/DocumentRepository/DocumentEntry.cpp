#include "DocumentEntry.h"

DocumentEntry::DocumentEntry() : url(), title(), description(), text(), lastTime() {}

DocumentEntry::DocumentEntry(const std::string& Url, const std::string& Title, 
    const std::string& Description, const std::string& Text, std::time_t LastTime) //there is not const and & for LastTime because of error
    : url(Url), title(Title), description(Description), text(Text), lastTime(LastTime) {}

DocumentEntry::DocumentEntry(const std::string& Url, const std::string& Title, 
    const std::string& Description, const std::string& Text) //there is not const and & for LastTime because of error
    : url(Url), title(Title), description(Description), text(Text) {}

std::string DocumentEntry::getUrl() const
{
    return url;
}

std::string DocumentEntry::getTitle() const
{
    return title;
}

std::string DocumentEntry::getDescription() const
{
    return description;
}

std::string DocumentEntry::getText() const
{
    return text;
}

std::time_t DocumentEntry::getTime() const
{
    return lastTime;
}