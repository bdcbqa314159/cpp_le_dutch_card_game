project(work)

set(includes ./ ../libraries/utils/ ../libraries/cards/)

add_executable(work main.cpp)
target_include_directories(work PUBLIC ${includes})
target_link_libraries(work utils)

add_executable(cards_test cards_test.cpp)
target_include_directories(cards_test PUBLIC ${includes})
target_link_libraries(cards_test utils cards)

add_executable(deck_test deck_test.cpp)
target_include_directories(deck_test PUBLIC ${includes})
target_link_libraries(deck_test utils cards)
