project(cards)

set(includes includes/ ../utils/)
set(sources src/cards_common.cpp
            src/Cards.cpp
            src/Deck.cpp
)

add_library(${PROJECT_NAME} ${sources})
target_include_directories(${PROJECT_NAME} PUBLIC ${includes} ${common_includes_dir})
target_link_libraries(${PROJECT_NAME} PUBLIC utils)
