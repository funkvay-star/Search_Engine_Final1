cmake_minimum_required(VERSION 3.0)

project("Crawler")

set(CMAKE_CXX_STANDARD 17)

include_directories("PageLoader")
include_directories("HTMLDocument")
include_directories("InfoExtractor")
include_directories("LinkRepository")
include_directories("WebRepository")
include_directories("DocumentRepository")

add_executable(${PROJECT_NAME} Crawler.cpp)

add_subdirectory(PageLoader)
add_subdirectory(HTMLDocument)
add_subdirectory(InfoExtractor)
add_subdirectory(LinkRepository)
add_subdirectory(WebRepository)
add_subdirectory(DocumentRepository)

set_target_properties(PageLoader PROPERTIES
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/PageLoader/libPageLoader.so"
)

set_target_properties(HTMLDocument PROPERTIES
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/HTMLDocument/libHTMLDocument.so"
)

set_target_properties(InfoExtractor PROPERTIES
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/InfoExtractor/libInfoExtractor.so"
)

set_target_properties(LinkRepository PROPERTIES
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/LinkRepository/libLinkRepository.so"
)

set_target_properties(WebRepository PROPERTIES
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/WebRepository/libWebRepository.so"
)

set_target_properties(DocumentRepository PROPERTIES
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/DocumentRepository/libDocumentRepository.so"
)



target_link_libraries(${PROJECT_NAME} PageLoader HTMLDocument InfoExtractor LinkRepository 
                                      WebRepository DocumentRepository)