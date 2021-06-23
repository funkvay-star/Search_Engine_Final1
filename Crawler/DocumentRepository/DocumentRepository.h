#ifndef DOCUMENT_REPOSITORY
#define DOCUMENT_REPOSTIROY

#include "DocumentEntry.h"
#include <vector>
#include <optional>

class DocumentRepository
{
private:
    std::vector<DocumentEntry> document;

public:
    std::vector<DocumentEntry> getAll();

    void save(DocumentEntry& entry);

    std::optional<DocumentEntry> getByUrl(const std::string& Url);
};

#endif