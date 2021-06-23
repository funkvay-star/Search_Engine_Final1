#ifndef INFORMATION_EXTRACTOR
#define INFORMATION_EXTRACTOR

#include "../HTMLDocument/HtmlDocument.h"
#include "InformationSaver.h"

class InformationExtractor
{
public:
    InformationSaver extractInformation(HtmlDocument& doc);
};

#endif
