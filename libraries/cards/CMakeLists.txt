project(cards)

set(includes includes/)
set(sources src/cards_common.cpp
            src/Cards.cpp
)

add_library(${PROJECT_NAME} ${sources})
target_include_directories(${PROJECT_NAME} PUBLIC ${includes} ${common_includes_dir})
