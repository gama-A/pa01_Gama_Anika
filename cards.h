//cards.h
//Gama Aristondo, Anika 
//All class declarations go here

#ifndef CARDS_H
#define CARDS_H

#include <iostream>
#include <string>

using namespace std;

class Card {
public:
    string suit;
    string value;
    Card *next;
    Card(string s, string v);
    // Card constructor

    bool operator==(Card const& a);
    // equality overload operator

    friend ostream& operator<<(ostream& os, const Card& c) {
        os << c.suit << " " << c.value;
        return os;
    }
    // print overload
};

class CardList {

public:
    CardList();
    // card hand constructor

    ~CardList();
    // card hand destructor
    
    void setName(string name);
    // Pre: CardList has no name set
    // Post: sets the name of the card list

    Card* getCardDeck() const;
    // returns the pointer node to the deck (helpful in the game implementation and findCard

    string getName() const;
    // Pre: CardList has a name
    // Post: returns of the name of the player with that deck

    int findCard(Card& c);
    // Pre: CardList is a valid list (if not returns 0) and c is a reference to a card
    // Post: returns the index of the card, 0 if not in deck

    void append(Card& c);
    // Pre: CardList can be empty or not, c is a valid card
    // Post: appends the card c to the end of the CardList

    void remove(int index);
    // Pre: CardList is not empty and index is greater than 0
    // Post: removes the card at the given index

    void clear();
    // clears list at the end

    friend ostream& operator<<(ostream& os, const CardList& cards) {
        Card *c;
        c = cards.deck;
        while(c){
            os << *c << endl;
            c = c->next;
        }
        return os;
    }
    // print overload for card list (helps with tests too)
   
private:
    Card *deck;
    string player;
};

#endif

// Use this file to define all your classes and public functions
// You should design your program with OOP prinicples using classes
// An example of class design would be having Card, CardList and Player as Classes.
// Card represent Node in your LinkedList which has some data in it
// CardList can be your LinkedList Class which has operations such as append, remove etc
// Player class represents your game player
// Think about the public functions that should be part of each class. (All public function need to be tested in unit testing)
// One of the important functions is search / find which is essential for players to find cars in their opponent's "hand"
// Make sure you overload the desired operators
// This is not the fixed design. We are not expecting exactly 3 classes. You can do with less or more.
// Important thing to consider is abstraction.
