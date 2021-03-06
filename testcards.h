// testcards.h
//Authors: Gama Aristondo, Anika
//All test declarations go here

// This is not exhaustive list of tests. You can remove / edit tests if it doesn't suit your design but you should definitelty add more
// You should test all possible cornere cases of your public functions

#ifndef TESTCARDS_H
#define TESTCARDS_H

#include <iostream>

using namespace std;
void runAll();
void test_constructor();
void test_name();
void test_append();
void test_getCard();
void test_card();
void test_cout();
void test_destructor();
void test_remove();
void test_search();


// Test for creating CardList
void test_constructor_empty();

// Tests for setting and getting name
void test_setter_and_getter_name();

// Tests for appending Cards
void test_append_empty_list();
void test_append_single_element_list();

// Tests for getting the first deck card
void test_getCardDeck();

// Test cases for card boolean
void test_card_operator_double_true();
void test_card_operator_double_false();
void test_card_operator_suit();
void test_card_operator_value();

// Tests for card and card list cout
void test_card_cout();
void test_cardlist_cout();

// Test for destructor
void test_destructor_clear();

// Test for removing card from deck
void test_remove_center_card();
void test_remove_first_card();
void test_remove_last_card();

// Test for finding card
void test_card_found();
void test_card_not_found();

void START_TEST(string testname){
  cout<<"-----Start "<<testname<<"-----"<<endl;
}

void END_TEST(string testname) {
  cout<<"-----End "<<testname<<"-----"<<endl;
}

void assertEquals(string expected, string actual, string testDescription){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}

void assertEquals(int expected, int actual, string testDescription){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}

void assertEqualsCard(Card* expected, Card* actual, string testDescription){
  if (*expected == *actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}

void assertEqualsBool(bool expected, bool actual, string testDescription){
  if (expected == actual) {
    cout<<"PASSED"<<endl;
  } else {
    cout<<"   FAILED: "<< testDescription << endl << "   Expected: "<< expected << " Actual: " << actual << endl;
  }
}

#endif
