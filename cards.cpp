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
    player = "";
}

// Destructor
CardList::~CardList(){
    clear();
}

// sets the name of the player
void CardList::setName(string name){
    player = name;
}

// returns the starting node of the card deck
Card* CardList::getCardDeck() const{
    return deck;
}

// returns the name of the player with the deck
string CardList::getName() const{
    return player;
}

// returns true if card is in the list, false if not
int CardList::findCard(Card& c) {
    Card *p = deck;
    int count = 0;
    while(p){
        if (*p == c){
            count = count + 1;
            return count;
        }
        p = p->next;
        count = count + 1;
    }
    count = 0;
    return count;
}

// appends card to the card hand
void CardList::append(Card& c) {
    Card *p;
    p = deck;
    Card* n = new Card(c.suit, c.value);
    if(!p){
        deck = n;
        return;
    }
    while(p->next){
        p = p->next;
    }
    p->next = n;
    return;
}

// removes card in the list
void CardList::remove(int index) {
    Card *p, *q;
    p = deck;
    q = deck;
    if(index == 1){
        q = q->next;
        delete p;
        deck = q;
        return;
    }
    int i = 1;
    while(i < index){
        p = p->next;
        i++;
    }
    while(q->next != p){
        q = q->next;
    }
    q->next = p->next;
    delete p;
}

// clears list of cards
void CardList::clear() {
    Card *p;
    while(deck){
        p = deck->next;
        delete deck;
        deck = p;
    }
}

