#ifndef GO_FISH_DECK_H
#define GO_FISH_DECK_H

#include <string>
#include <vector>
#include "Card.h"

using namespace std;

class Deck {
public:
    vector<Card> sortedCards;
    vector<Card> shuffledCards;

    Deck() {
        string value[13] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
        string suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

        // concatenate two arrays of value + suit together
        for(const auto & x : value) {
            for (const auto &y : suit) {
                Card card = Card(x, y);
                sortedCards.push_back(card);
            }
        }
    }

    static void displayDeck(vector<Card> *cards);
    void shuffleDeck(vector<Card> *cards);
    Card popCardTop(vector<Card> *cards);

    // TODO
    void dealCards();
};


#endif //GO_FISH_DECK_H
