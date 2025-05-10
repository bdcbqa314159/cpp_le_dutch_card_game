project(work)

set(includes ./ ../libraries/utils/)

add_executable(work main.cpp)
target_include_directories(work PUBLIC ${includes})
target_link_libraries(work utils)
