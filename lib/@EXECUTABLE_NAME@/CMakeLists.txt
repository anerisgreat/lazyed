#TODO: Edit library name
project(@EXECUTABLE_NAME@)

set(${PROJECT_NAME}_INCLUDE_DIR
    "${PROJECT_SOURCE_DIR}/include")

add_executable(${PROJECT_NAME}
    src/@SOURCE_NAME@.cxx
    )

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${${PROJECT_NAME}_INCLUDE_DIR}
    PRIVATE
    ${CMAKE_BINARY_DIR}
    )

target_link_libraries(${PROJECT_NAME}
    #PUBLIC
    #@OTHER_LIBRARY@
    )

