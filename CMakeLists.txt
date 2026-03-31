cmake_minimum_required (VERSION 3.10)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project (LitRedHood)

add_subdirectory(external)

file (GLOB_RECURSE SOURCE_FILES litredhood/src/*.cpp)

add_executable (LitRedHood  ${SOURCE_FILES})

target_include_directories(LitRedHood PRIVATE litredhood/src)
target_link_libraries(LitRedHood PRIVATE litredhood::external)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET LitRedHood PROPERTY CXX_STANDARD 20)
endif()

