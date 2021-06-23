#ifndef WEB_REPOSITORY
#define WEB_REPOSITORY

#include <vector>
#include "WebSite.h"
#include "DataBaseWebSite.h"

class WebRepository
{
private:
    std::vector<WebSite> source;

public:
    std::vector<WebSite> getAll();

    void save(const WebSite& website);

    //////////

    std::vector<WebSite> getAllDB();

    void saveDB(const WebSite& website);
};

#endif
