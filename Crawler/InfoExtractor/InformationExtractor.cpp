#include "InformationExtractor.h"

InformationSaver InformationExtractor::extractInformation(HtmlDocument& doc)
{
    std::string title;
    std::string description;
    std::string text;

    doc.visitElements([&title, &description, &text](HtmlElement elem)
    {
        if(elem.isTagText())
        {
            text += elem.getText();
        }

        if(elem.isTagDescription())
        {
            description += elem.getText();
        }

        if(elem.isTagTitle())
        {
            title += elem.getText();
        }
    });

    return InformationSaver(title, description, text);
}