#include <iostream>
#include <fstream>
#include <string>
#include "cards.h"

using namespace std;

int main(int argv, char** argc){
  if(argv != 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail()){
    cout << "Could not open file " << argc[1];
    return 1;
  }

  if (cardFile2.fail()){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  // Create two objects of the class you defined 
  // to contain two sets of cards in two input files

  // Read each file and store cards
  while (getline (cardFile1, line) && (line.length() > 0)){
      CardList player1;
      Card add(line[0],line[2]);
      player1.append(add);
      player1.setName("Alice");
  }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
      CardList player2;
      Card add(line[0],line[2]);
      player2.append(add);
      player2.setName("Bob");
  }
  cardFile2.close();

  int gameStatus = 2;
  while (gameStatus > 0){
      Card *p1, *p2;
      int turnCounter = 0;
      if(turnCounter % 2 == 0){
          p1 = player1.getCardDeck();
          for(p1; p1->next != NULL; p1 = p1->next){
              int result;
              result = player2.findCard(*p1);
              if(result != 0){
                  player2.remove(result);
                  cout << player1.getName() << " picked matching card " << *p1 << endl;
                  player1.remove(player1.findCard(*p1));
                  // STUB
              }
          }
          if(result == 0){
              gameStatus = gameStatus - 1;
          }
          turnCounter = turnCounter + 1;
      }
      else {
          p2 = player2.getCardDeck();
          for(p2; p2->next != NULL; p2 = p2->next){
              int result;
              result = player1.findCard(*p2);
              if(result != 0){
                  player1.remove(result);
                  cout << player2.getName() << " picked matching card " << *p2 << endl;
                  player2.remove(player2.findCard(*p2));
                  // Stub
              }
          }
          if(result == 0){
              gameStatus = gameStatus - 1;
          }
          turnCounter = turnCounter + 1;
      }
  }
  
  cout << endl;
  cout << player1.getName() <<"'s cards:\n" << player1 << player2.getName() <<"'s cards:\n" << player2;

  return 0;
}
