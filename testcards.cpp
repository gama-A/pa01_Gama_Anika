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
  test_append();
  test_destructor();
  test_remove();
  test_search();
}

void test_card(){
  START_TEST("test_card");
  test_card_operator_double_true();
  test_card_operator_double_false();
  END_TEST("test_card");
}

void test_constructor(){
  START_TEST("test_constructor");
  test_constructor_empty();
  END_TEST("test_constructor");
}

void test_append(){
  START_TEST("test_append");
  test_append_empty_list();
  test_append_single_element_list();
  END_TEST("test_append");

}

void test_destructor(){
  START_TEST("test_destructor");
  test_destructor_clear();
  END_TEST("test_destructor");
}

void test_remove(){
  START_TEST("test_remove");
  test_remove_center_card();
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
  Card c1("d", "9");
  Card c2("d", "9");
  bool result = (c1 == c2);
  assertEqualsBool(true, result, "test_card_operator_double_true");
}

void test_card_operator_double_false(){
  Card c1("d", "9");
  Card c2("s", "a");
  bool result = (c1 == c2);
  assertEqualsBool(false, result, "test_card_operator_double_false");
}

// Test for creating a CardList
void test_constructor_empty(){
  CardList hand1;
  cout << hand1;
}

// Tests for the append function
void test_append_empty_list(){
  Card c1("h","2");
  CardList hand1;
  hand1.append(c1);
  cout << hand1 << endl;
}

void test_append_single_element_list(){ 
  string testname = "Case 2: testing non-empty list";
  Card c1("h","2");
  Card c2("s","a");
  Card c3("d","5");
  CardList hand1;
  hand1.append(c1);
  hand1.append(c2);
  hand1.append(c3);
  cout << hand1 << endl;
}

// Tests destructors clear function
void test_destructor_clear(){
  Card c1("h","2");
  Card c2("s","a");
  Card c3("d","5");
  CardList hand1;
  hand1.append(c1);
  hand1.append(c2);
  hand1.append(c3);
  hand1.clear();
  cout << "    RUN IN Valgrind FOR Destructor    ";
}

void test_remove_center_card(){
  Card c1("c", "5");
  Card c2("d","7");
  Card c3("h","q");
  CardList hand1;
  hand1.append(c1);
  hand1.append(c2);
  cout << hand1 << endl;
}

void test_card_found(){
  Card c1("s", "6");
  Card c2("h", "6");
  CardList hand1; 
  hand1.append(c1); 
  hand1.append(c2);
  bool result = hand1.findCard(c2);
  assertEqualsBool(true, result, "test_card_found");
}

void test_card_not_found(){
  Card c1("s","6");
  Card c2("h","6");
  Card c3("d","9");
  CardList hand1;
  hand1.append(c1);
  hand1.append(c3);
  bool result = hand1.findCard(c2);
  assertEqualsBool(false, result, "test_card_not_found");
}


