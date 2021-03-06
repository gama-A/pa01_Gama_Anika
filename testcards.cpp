// This file should contain unit tests for all the 
// public interfaces of the classes that you implement

#include "cards.h"
#include "testcards.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){
  runAll();
  return 0;
}

void runAll(){
  test_card();
  test_constructor();
  test_name();
  test_cout();
  test_append();
  test_getCard();
  test_destructor();
  test_remove();
  test_search();
}

void test_card(){
  START_TEST("test_card");
  test_card_operator_double_true();
  test_card_operator_double_false();
  test_card_operator_suit();
  test_card_operator_value();
  END_TEST("test_card");
}

void test_cout(){
  START_TEST("test_cout");
  test_card_cout();
  test_cardlist_cout();
  END_TEST("test_cout");
}

void test_constructor(){
  START_TEST("test_constructor");
  test_constructor_empty();
  END_TEST("test_constructor");
}

void test_name(){
  START_TEST("test_name");
  test_setter_and_getter_name();
  END_TEST("test_name");
}

void test_append(){
  START_TEST("test_append");
  test_append_empty_list();
  test_append_single_element_list();
  END_TEST("test_append");

}

void test_getCard(){
  START_TEST("test_getCard");
  test_getCardDeck();
  END_TEST("test_getCard");
}

void test_destructor(){
  START_TEST("test_destructor");
  test_destructor_clear();
  END_TEST("test_destructor");
}

void test_remove(){
  START_TEST("test_remove");
  test_remove_center_card();
  test_remove_first_card();
  test_remove_last_card();
  END_TEST("test_remove");
}

void test_search(){
  START_TEST("test_search");
  test_card_found();
  test_card_not_found();
  END_TEST("test_search");
}

// Tests for card boolean
void test_card_operator_double_true(){
  Card c1("s", "a");
  Card c2("s", "a");
  bool result = (c1 == c2);
  assertEqualsBool(true, result, "test_card_operator_double_true");
}

void test_card_operator_double_false(){
  Card c1("s", "a");
  Card c2("h", "q");
  bool result = (c1 == c2);
  assertEqualsBool(false, result, "test_card_operator_double_false");
}

void test_card_operator_suit(){
  Card c1("s","a");
  Card c2("d","a");
  bool result = (c1 == c2);
  assertEqualsBool(false, result, "test_card_operator_suit");
}

void test_card_operator_value(){
  Card c1("s","a");
  Card c2("s","j");
  bool result = (c1 == c2);
  assertEqualsBool(false, result, "test_card_operator_value");
}

// tests << overload on card and card list
void test_card_cout(){
  string testname = "Case 1: card cout overload\n";
  Card c1("s","a");
  cout << testname;
  cout << c1 << endl;
}

void test_cardlist_cout(){
  string testname = "Case 2: cardList cout overload\n";
  Card c1("s","a");
  Card c2("h","q");
  Card c3("c","k");
  CardList hand1;
  hand1.append(c1);
  hand1.append(c2);
  hand1.append(c3);
  cout << testname << hand1;
}

// Test for creating a CardList
void test_constructor_empty(){
  CardList hand1;
  cout << hand1 << "If blank, constructor works\n";
}

// Tests for setting and getting the name of player
void test_setter_and_getter_name(){
  CardList hand1;
  hand1.setName("Alice");
  assertEquals("Alice", hand1.getName(), "test_setter_and_getter");
}

// Tests for the append function
void test_append_empty_list(){
  string testname = "Case 1: testing empty card list\n";
  Card c1("s","a");
  CardList hand1;
  hand1.append(c1);
  cout << testname << hand1;
}

void test_append_single_element_list(){ 
  string testname = "Case 2: testing non-empty card list\n";
  Card c1("s","a");
  Card c2("h","q");
  Card c3("c","k");
  CardList hand1;
  hand1.append(c1);
  hand1.append(c2);
  hand1.append(c3);
  cout << testname << hand1;
}

// Tests for getting the first card in the deck
void test_getCardDeck(){
  Card c1("s","a");
  Card c2("h","q");
  Card *n = new Card("s","a");
  CardList hand1;
  hand1.append(c1);
  hand1.append(c2);
  assertEqualsCard(n, hand1.getCardDeck(), "test_getCardDeck");
  delete n;
}

// Tests destructors clear function
void test_destructor_clear(){
  Card c1("s","a");
  Card c2("h","q");
  Card c3("c","k");
  CardList hand1;
  hand1.append(c1);
  hand1.append(c2);
  hand1.append(c3);
  hand1.clear();
  cout << "    RUN IN Valgrind FOR Destructor   \n";
}

// Tests remove function
void test_remove_center_card(){
  string testname = "Case 1: removing center card\n";
  Card c1("s", "a");
  Card c2("h","q");
  Card c3("c","k");
  CardList hand1;
  hand1.append(c1);
  hand1.append(c2);
  hand1.append(c3);
  cout << testname << "BEFORE: \n" << hand1;
  hand1.remove(2);
  cout << "AFTER: \n" << hand1;
}

void test_remove_first_card(){
  string testname = "Case 2: remove the first card\n";
  Card c1("s","a");
  Card c2("h","q");
  Card c3("c","k");
  CardList hand1;
  hand1.append(c1);
  hand1.append(c2);
  hand1.append(c3);
  cout << testname << "BEFORE: \n" << hand1;
  hand1.remove(1);
  cout << "AFTER: \n" << hand1;
}

void test_remove_last_card(){
  string testname = "Case 3: remove the last card\n";
  Card c1("s","a");
  Card c2("h","q");
  Card c3("c","k");
  CardList hand1;
  hand1.append(c1);
  hand1.append(c2);
  hand1.append(c3);
  cout << testname << "BEFORE: \n" << hand1;
  hand1.remove(3);
  cout << "AFTER: \n" << hand1;
}

// Tests for finding card
void test_card_found(){
  Card c1("s", "a");
  Card c2("h", "q");
  Card c3("c", "k");
  Card *n = new Card("h","q");
  CardList hand1;
  hand1.append(c1);
  hand1.append(c2);
  hand1.append(c3);
  assertEquals(2, hand1.findCard(*n), "test_card_found");
  delete n;
}

void test_card_not_found(){
  Card c1("s","a");
  Card c2("h","q");
  Card c3("c","k");
  Card *n = new Card("d","0");
  CardList hand1;
  hand1.append(c1);
  hand1.append(c2);
  hand1.append(c3);
  assertEquals(0, hand1.findCard(*n), "test_card_not_found");
  delete n;
}


