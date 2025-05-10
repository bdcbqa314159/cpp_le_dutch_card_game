project(cards)

set(includes ./ ../libraries/utils/)

add_executable(symbols main.cpp)
target_include_directories(symbols PUBLIC ${includes})
target_link_libraries(symbols utils)
