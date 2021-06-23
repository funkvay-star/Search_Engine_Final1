project(InfoExtractor)

add_library(
    InfoExtractor SHARED

    DocumentExtractor.h
    DocumentExtractor.cpp

    InformationExtractor.h
    InformationExtractor.cpp

    InformationSaver.h
    InformationSaver.cpp
)

target_link_libraries(InfoExtractor)