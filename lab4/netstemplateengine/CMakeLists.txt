
project(simpletemplateengine)

set(HEDEAR_FILES SimpleTemplateEngine.h)
set(SOURCE_FILES SimpleTemplateEngine.cpp)

add_library(libsimpletemplateengine STATIC ${SOURCE_FILES} ../netsjson/SimpleJson.cpp ../netsjson/SimpleJson.h ../netsjson/main.cpp)
target_include_directories(libsimpletemplateengine PUBLIC .)

add_executable(simpletemplateengine ${SOURCE_FILES} main.cpp)

target_link_libraries(simpletemplateengine libsimpletemplateengine)

