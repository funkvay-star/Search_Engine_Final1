project(LinkRepository)

add_library(
    LinkRepository SHARED

    LinkEntry.h
    LinkEntry.cpp

    LinkRepository.h
    LinkRepository.cpp

    LinkStatus.h

    DataBaseLinkRepository.h
    DataBaseLinkRepository.cpp
)

target_link_libraries(LinkRepository -lmysqlcppconn)