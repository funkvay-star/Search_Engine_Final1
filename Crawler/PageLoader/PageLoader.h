#ifndef PAGE_LOADER_H
#define PAGE_LOADER_H


#include <string>
#include "LoadResult.h"

//for C function to find substring in string
#include <stdlib.h> // used in PageLoader.cpp
#include <string.h> // used in PageLoader.cpp


class PageLoader
{
private:
    static size_t function_helper(char* buffer, size_t itemsize, size_t nitems, void* ignorethis);

public:
    PageLoader() = default;

    LoadResult get_data(const std::string& url);

    //LoadResult get_info_by_url(const std::string& url);
};


#endif
