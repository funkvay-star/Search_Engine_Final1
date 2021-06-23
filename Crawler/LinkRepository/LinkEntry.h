#ifndef LINK_ENTRY
#define LINK_ENTRY

#include <ctime>
#include <string>

#include "LinkStatus.h"

class LinkEntry
{
private:
    time_t lastUpdate;
    std::string url;
    std::string domain;
    LinkStatus status;

public:
    LinkEntry();

    LinkEntry(const std::string& Url, const std::string& Domain, const LinkStatus& Status, const time_t& LastUpdate);

    LinkEntry(const std::string& Url, const std::string& Domain, const LinkStatus& Status);

    std::string getUrl() const;
    std::string getDomain() const;

    LinkStatus getStatus() const;
    time_t getTime() const;

    void changeUrl();

};


#endif
