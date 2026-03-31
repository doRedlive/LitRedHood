add_library(glad STATIC ${CMAKE_CURRENT_LIST_DIR}/glad/src/glad.c)
add_library(glad::glad ALIAS glad)
target_include_directories(glad PUBLIC ${CMAKE_CURRENT_LIST_DIR}/glad/include)
target_link_libraries(litredhood_external INTERFACE glad::glad)
