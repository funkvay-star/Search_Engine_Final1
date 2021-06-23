#ifndef DOCUMENT_ENTRY
#define DOCUMENT_ENTRY

#include <string>
#include <ctime>

class DocumentEntry
{
private:
    std::string url;
    std::string title;
    std::string description;
    std::string text;
    std::time_t lastTime;

public:
    DocumentEntry();
    DocumentEntry(const std::string& url, const std::string& title, 
    const std::string& description, const std::string& text, std::time_t lastTime);

    std::string getUrl();
    std::string getTitle();
    std::string getDescription();
    std::string getText();
    std::time_t getTime();
};

#endif
