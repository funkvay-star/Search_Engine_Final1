#include "LinkEntry.h"
#include <iostream>


LinkEntry::LinkEntry()
    : lastUpdate{}, url{}, domain{}, status{} 
{

}

LinkEntry::LinkEntry(const std::string& Url, const std::string& Domain, const LinkStatus& Status, const time_t& LastUpdate)
    : url(Url), domain(Domain), status(Status), lastUpdate(LastUpdate) 
{
    /*if(Status == LinkStatus::ERROR)
    {
        std::cout << "LINK_ENTRY  status -> "  << Url << "  ERROR";
    }
    else if(Status == LinkStatus::SUCCESS)
    {
        std::cout << "LINK_ENTRY  status ->" << Url << "  SUCCESS";
    }
    else if(Status == LinkStatus::WAITING)
    {
        std::cout << "LINK_ENTRY  status ->" << Url << "  WAITING";
    }
    std::cout << "\n\n";
    */
} 
LinkEntry::LinkEntry(const std::string& Url, const std::string& Domain, const LinkStatus& Status)
    : url(Url), domain(Domain), status(Status)
{

} 



std::string LinkEntry::getUrl() const
{
    return this->url;
}

std::string LinkEntry::getDomain() const
{
    return this->domain;
}

LinkStatus LinkEntry::getStatus() const
{
    return this->status;
}

time_t LinkEntry::getTime() const
{
    return this->lastUpdate;
}

void LinkEntry::changeUrl()
{
    //url = "NOT_VALID";
}