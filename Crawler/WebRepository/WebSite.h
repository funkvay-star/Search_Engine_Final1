#ifndef WEB_SITE
#define WEB_SITE

#include <string>
#include <vector>
#include <ctime>

class WebSite
{
private:
    std::string domain;
    std::string homePage;
    std::time_t crawleTime;

public:
    WebSite();

    WebSite(const std::string& Domain, const std::string& HomePage, const std::time_t& Time);

    std::string getDomain() const;
    std::string getHomePage() const;
    std::time_t getCrawleTime() const;
};

#endif
