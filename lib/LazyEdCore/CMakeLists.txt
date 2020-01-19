project(LazyEdCore)

set(${PROJECT_NAME}_INCLUDE_DIR
    "${PROJECT_SOURCE_DIR}/include")

add_library(${PROJECT_NAME}
    src/LazyEdCore.cxx
    )

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${${PROJECT_NAME}_INCLUDE_DIR}
    PRIVATE
    ${CMAKE_BINARY_DIR}
    )

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    LazyPool
    )

