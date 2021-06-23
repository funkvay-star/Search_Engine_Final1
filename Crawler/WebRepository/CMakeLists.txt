project(WebRepository)

add_library(
    WebRepository SHARED

    WebRepository.h
    WebRepository.cpp

    WebSite.h
    WebSite.cpp

    DataBaseWebSite.h
    DataBaseWebSite.cpp
)

target_link_libraries(WebRepository -lmysqlcppconn)