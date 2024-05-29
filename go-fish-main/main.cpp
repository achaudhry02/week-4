#include "Deck.h"
#include "DeckStack.h"

using namespace std;


int main() {

    DeckStack stack(52);
    stack.displayDeck();
    stack.peek();
    stack.pop();
    stack.displayDeck();
    stack.peek();

//    Deck deck;
//    pass pointers of vector<Card> to methods
//    Deck::displayDeck(&deck.sortedCards);
//    deck.popCardTop(&deck.sortedCards);
//
//    deck.shuffleDeck(&deck.sortedCards);
//    Deck::displayDeck(&deck.shuffledCards);
//    deck.popCardTop(&deck.shuffledCards);
    char drawMore;
    do {
        cout << "\nDo you want to draw another card? (y/n): ";
        cin >> drawMore;

        if (drawMore == 'y' || drawMore == 'Y') {
            stack.pop();
            stack.displayDeck();
            stack.peek();
        }
        else if (drawMore == 'n' || drawMore == 'N') {
            cout << "No more cards will be drawn.\n";
        }
        else {
            cout << "Invalid input. Please enter 'y' or 'n'.\n";
        }
    } while (drawMore != 'n' && drawMore != 'N');

    return 0;
}
