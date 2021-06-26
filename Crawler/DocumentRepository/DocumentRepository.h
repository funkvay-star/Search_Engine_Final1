#ifndef DOCUMENT_REPOSITORY
#define DOCUMENT_REPOSTIROY

#include "DocumentEntry.h"
#include <vector>
#include <optional>
#include "DataBaseDocumentRepository.h"

class DocumentRepository
{
private:
    std::vector<DocumentEntry> document;

public:
    std::vector<DocumentEntry> getAll();

    void save(DocumentEntry& entry);

    std::optional<DocumentEntry> getByUrl(const std::string& Url);

    //////////

    std::vector<DocumentEntry> getAllDB();

    void saveDB(const DocumentEntry& entry);

    std::optional<DocumentEntry> getByUrlDB(const std::string& Url);
};

#endif
