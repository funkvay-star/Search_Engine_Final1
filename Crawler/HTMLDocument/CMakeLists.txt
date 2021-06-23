project(HTMLDocument)

add_library(
    HTMLDocument SHARED

    HtmlDocument.h 
    HtmlDocument.cpp

    HtmlElement.h 
    HtmlElement.cpp

    HtmlNode.h 
    HtmlNode.cpp
)

target_link_libraries(HTMLDocument -lgumbo)