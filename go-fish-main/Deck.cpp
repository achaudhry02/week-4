#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <time.h>
#include "Deck.h"
#include "Card.h"

using namespace std;

// for testing purposes
void Deck::displayDeck(vector<Card> *cards) {
    cout << "_____DISPLAY DECK_____" << '\n';
    // print individual cards in deck
    for (int i = 0; i < 52; i++)
    {
        // dereference pointer to access its elements
        cout << (*cards)[i].getValue() << " of " << (*cards)[i].getSuit() << '\n';
    }
}

// using the Fisher–Yates shuffle algorithm
// every permutation of array element equally likely
// rand() works here but is a subpar random number generator
void Deck::shuffleDeck(vector<Card> *cards) {
    cout << "_____SHUFFLE_____" << '\n';
    int s = cards->size();
    // Copied cards to shuffled cards, this way we shuffle a deck that's not constantly changing. -Gage Miller
    shuffledCards = *cards;

    // use current time as seed for random number generation
    srand(time(0));
    for (int i = s - 1; i > 0 - 1; --i)
    {
        int r = rand() % (s - 1);
        swap(shuffledCards[i], shuffledCards[r]);
        shuffledCards[i] = (*cards)[i];
    }
}

// because deck is face down, the card on top is actually the last element in vector
Card Deck::popCardTop(vector<Card> *cards) {
    cout << "_____TOP CARD____" << '\n';
        Card top_card = cards->back();
        cout << "Card on top: " << top_card.getValue() << " of " << top_card.getSuit() << '\n';
        return top_card;
}