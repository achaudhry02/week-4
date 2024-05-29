#ifndef GO_FISH_DECKSTACK_H
#define GO_FISH_DECKSTACK_H

#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>    // Include for rand()
#include <ctime>      // Include for time()
#include "Card.h"

using namespace std;

class DeckStack {
public:
    int topIndex;
    vector<Card> deckOfCards;

    DeckStack(int s) : topIndex(-1) {
        deckOfCards.reserve(52);

        string value[13] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
        string suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

        for (const auto &x : value) {
            for (const auto &y : suit) {
                Card card = Card(x, y);
                deckOfCards.push_back(card);
            }
        }
        topIndex = deckOfCards.size() - 1;

        // Initialize random seed
        srand(static_cast<unsigned int>(time(0)));
    }

    void displayDeck() {
        cout << "_____DISPLAY DECK STACK_____" << '\n';
        for (int i = 0; i < deckOfCards.size(); i++) {
            cout << deckOfCards[i].getValue() << " of " << deckOfCards[i].getSuit() << ", ";
        }
    }

    void push(const Card& i) {
        cout << "_____PUSH_____" << '\n';
        deckOfCards.push_back(i);
        topIndex = deckOfCards.size() - 1;
        cout << "Element pushed: " << deckOfCards[topIndex].getValue() << " of " << deckOfCards[topIndex].getSuit() << ", topIndex value: " << topIndex << ", Actual stack size: " << deckOfCards.size() << '\n';
    }

    void pop() {
        cout << "_____POP_____" << '\n';
        if (!deckOfCards.empty()) {
            // Randomly select an index to pop
            int randomIndex = rand() % deckOfCards.size();
            Card temp = deckOfCards[randomIndex];
            deckOfCards.erase(deckOfCards.begin() + randomIndex);
            topIndex = deckOfCards.size() - 1;
            cout << "Element popped: " << temp.getValue() << " of " << temp.getSuit() << ", randomIndex value: " << randomIndex << ", Actual stack size: " << deckOfCards.size() << '\n';
        } else {
            cout << "The deck is empty, cannot pop.\n";
        }
    }

    void drawCards(int numCards, vector<Card>& drawnCards) {
        cout << "_____DRAW CARDS_____" << '\n';
        if (numCards > deckOfCards.size()) {
            cout << "Not enough cards in the deck to draw " << numCards << " cards.\n";
            return;
        }

        for (int i = 0; i < numCards; i++) {
            int randomIndex = rand() % deckOfCards.size();
            Card temp = deckOfCards[randomIndex];
            drawnCards.push_back(temp);
            deckOfCards.erase(deckOfCards.begin() + randomIndex);
        }

        topIndex = deckOfCards.size() - 1;
        cout << numCards << " cards drawn, topIndex value: " << topIndex << ", Actual stack size: " << deckOfCards.size() << '\n';
    }

    void peek() {
        cout << '\n';
        cout << "_____TOP CARD_____" << '\n';
        if (!deckOfCards.empty()) {
            cout << "Last element: " << deckOfCards.back().getValue() << " of " << deckOfCards.back().getSuit() << "\n";
        } else {
            cout << "The deck is empty.\n";
        }
    }
};

#endif //GO_FISH_DECKSTACK_H
