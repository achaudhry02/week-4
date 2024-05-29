cmake_minimum_required(VERSION 3.26)
project(go_fish)

set(CMAKE_CXX_STANDARD 20)

add_executable(go_fish main.cpp
        Deck.cpp
        Deck.h
        Card.cpp
        Card.h
        DeckStack.cpp
        DeckStack.h)
