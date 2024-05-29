#ifndef GO_FISH_CARD_H
#define GO_FISH_CARD_H

#include <string>
#include <utility>

using namespace std;

class Card {
private:
    string value;
    string suit;

public:
    Card() : value(""), suit(""){}; // Default constructor
    Card(string value, string suit) : value(std::move(value)), suit(std::move(suit)){};

    string getValue() {
        return value;
    }

    string getSuit() {
        return suit;
    }
};


#endif //GO_FISH_CARD_H
