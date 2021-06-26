project(DocumentRepository)

add_library(
    DocumentRepository SHARED

    DocumentEntry.h
    DocumentEntry.cpp

    DocumentRepository.h
    DocumentRepository.cpp

    DataBaseDocumentRepository.h
    DataBaseDocumentRepository.cpp
)

target_link_libraries(DocumentRepository -lmysqlcppconn)