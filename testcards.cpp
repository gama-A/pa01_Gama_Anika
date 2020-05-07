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
  test_equal();
  test_destructor();
  test_remove();
  test_search();
}

void test_card(){
  START_TEST("test_card");
  test_card_bool1();
  test_card_bool2();
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

void test_equal(){
  START_TEST("test_equal");
  test_equal_empty_list();
  test_equal_single_element_list();
  END_TEST("test_equal");

}

void test_append_empty_list(){
  Card c1 = new Card("h","2");
  Card *p = c1;
  CardList hand1;
  hand1.append(c1);
  assertEqualsCard(*p, hand1, "test_append_empty_list");
}

void test_append_single_element_list(){ 
  string testname = "Case 2: testing non-empty list";
  Card c1 = new Card("h","2");
  Card c2 = new Card("s","a");
  CardList hand1; 
  hand1.append(c1);
  hand1.append(c2);
  //assertEqualsCard(c2, hand1.head, "test_append_single_element_list");
  //head1.head needs to be changed to the second element from CardList (aka c2)
}
void test_equal_empty_list(){ 
  string testname = "case 0: [], []";
  LinkedList l1, l2;
  assertEquals(l1.head,l2.head);
}

void test_equal_single_element_list(){
  string testname = "case 1: {'h 10'}, {'h 10'}";
  Card c1 = new Card ("h", "10"); 
  Card c2 = new Card ("h", "10"); 
  CardList hand1;
  hand1.append(c1); 
  CardList hand2;
  hand2.append(c2);
  assertEqualsCard(hand1.head, hand2.head, "test_equal_single_element_list"); 
}

void test_card_operator_double_equal(){
  Card c1 = new Card ("d", "9");
  Card c2 = new Card ("d", "9");
  assertEqualsCard(c1, c2, "test_card_operator_double_equal");

}

void test_remove(){
  Card c1 = new Card("c", "5");
  CardList hand1;
  hand1.append(c1);
  hand1.remove(c1);
  Card c2 = new Card("c" "7");
  hand1.append(c2);
  assertEqualsCard(c2, hand1.head, "test_remove");
}

void test_search(){
  /*  
  Card c1 = new Card("s", "6");
  Card c2 = new Card("h", "6");
  CardList hand1; 
  hand1.append(c1); 
  hand1.append(c2);
  */ 
}
