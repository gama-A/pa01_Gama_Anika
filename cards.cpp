//cards.cpp
//Authors: Gama Aristondo, Anika
//Implementation of the classes defined in cards.h

#include "cards.h"
#include <string>
#include <iostream>

using std::cout;
// Constructor (card)
Card::Card(string s, string v){
    suit = s;
    value = v;
    next = NULL;
}

// Card equality operator
bool Card::operator==(Card const& a){
    if((a.suit == this->suit) && (a.value == this->value)){
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
        if (*p == c){
            return true;
        }
        p = p->next;
    }
    return false;
}

// appends card to the card hand
void CardList::append(Card& c) {
    Card *p;
    p = deck;
    while(p) {
        p = p->next;
    }
    Card* n = new Card(c.suit, c.value);
    p = n;
}

// removes card in the list
void CardList::remove(Card& c) {
    Card *p, *q;
    p = deck;
    q = deck;
    while(!(*p == c)){
        p = p->next;
    }
    if(p->next == NULL){
        delete p;
        return;
    }else {
        if(p == deck){
            q = q->next;
            delete p;
            deck = q;
        }else {
            while(q->next != p){
                q = q->next;
            }
            q->next = p->next;
            delete p;
        }
    }
}

// clears list of cards
void CardList::clear() {
    Card *p = deck;
    Card *q;
    q = p;
    while(p) {
        p = p->next;
        delete q;
        q = p;
    }
}

