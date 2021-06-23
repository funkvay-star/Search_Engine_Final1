#include "WebSite.h"
#include <iostream>

WebSite::WebSite()
    :   domain{}, homePage{}, crawleTime{}
{

}

WebSite::WebSite(const std::string& Domain, const std::string& HomePage, const std::time_t& Time)
{
    this->domain = Domain;
    this->homePage = HomePage;
    this->crawleTime = Time;

    //std::cout << domain << "  " << Domain;
}

std::string WebSite::getDomain() const
{
    return this->domain;
}

std::string WebSite::getHomePage() const
{
    return this->homePage;
}

std::time_t WebSite::getCrawleTime() const
{
    return this->crawleTime;
}