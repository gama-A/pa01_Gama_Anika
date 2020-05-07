//cards.cpp
//Authors: Gama Aristondo, Anika
//Implementation of the classes defined in cards.h

#include "cards.h"
#include <string>
#include <iostream>

using std::cout;
// Constructor (card)
Card::Card(char s, char v){
    suit = s;
    value = v;
    next = NULL;
}

// Card equality operator
bool Card::Card operator==(Card& a){
    if((a.suit == suit) && (a.value == value)){
        return true;
    }
    return false;
}

// Constructor (list/deck)
CardList::CardList(){
    deck = NULL;
}

// Destructor
CardList::~CardList(){
    clear();
}

// returns true if card is in the list, false if not
bool CardList::findCard(Card& c) {
    Card *p = deck;
    while(p){
        if (p == c){
            return true;
        }
        p = p->next;
    }
    return false;
}

// appends card to the card hand
void CarList::append(Card& c) {
    Card *p = deck;
    if(!p) {
        Card add = new Card(c);
        p = add;
    }
    else {
        p = p->next;
        p.append(c);
    }
}

// removes card in the list
void CardList::remove(Card& c) {
    Card *p = deck;
    Card *q = deck;
    if(p == c){
        if(p->next != NULL){
            delete p;
            deck = q;
            return;
        }else {
            q = q->next;
            delete p;
            deck = q;
            return;
        }
    }else {
        p = p->next.remove(c);
    }
}

// clears list of cards
void clear() {
    Card *p, *q;
    p = deck;
    q = p
    while(p) {
        p = p->next;
        delete q;
        q = p;
    }
}

