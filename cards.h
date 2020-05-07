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

    bool findCard(Card& c);
    // returns true if card exists in deck, false if not

    void append(Card& c);
    // add card to the end hand of the player
    // If the card hand is empty the card is added first

    void remove(Card& c);
    // removes card in the list, used with function find Card

    void clear();
    // clears list at the end

    friend ostream& operator<<(ostream& os, const CardList& cards) {
        Card *c;
        c = cards.deck;
        while(c){
            os << c << endl;
            c = c->next;
        }
        return os;
    }
    // print overload for card list (helps with tests too)
   
private:
    Card *deck;
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
