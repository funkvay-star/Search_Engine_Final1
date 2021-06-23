#ifndef LINK_REPOSITORY
#define LINK_REPOSITORY

#include "LinkEntry.h"
#include <vector>
#include <optional>
#include "DataBaseLinkRepository.h"

class LinkRepository
{
private:
    std::vector<LinkEntry> source;

public:
    std::vector<LinkEntry> getAll();

    std::vector<LinkEntry> getByInformation(const std::string& domain, const LinkStatus& status, int count);

    void save(const LinkEntry& entry);

    std::optional<LinkEntry> getByUrl(const std::string& Url);

    size_t source_size();


    //////////////////////////

    std::vector<LinkEntry> getAllDB();

    std::vector<LinkEntry> getByInformationDB(const std::string& domain, const LinkStatus& status, int count);

    void saveDB(const LinkEntry& entry);

    std::optional<LinkEntry> getByUrlDB(const std::string& Url);
};

#endif
