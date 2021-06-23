#ifndef DOCUMENT_EXTRACTOR
#define DOCUMENT_EXTRACTOR

#include "../HTMLDocument/HtmlDocument.h"
#include <vector>


class DocumentExtractor
{
private:
    //std::string getAbsoluteUrl(std::string& notAbsoluteUrl, const std::string& domain, std::string effectiveUrl);

public:
    DocumentExtractor() = default;
    std::vector<std::string> extractDocument(HtmlDocument& doc, const std::string& domain, std::string effectiveUrl);
};

#endif
