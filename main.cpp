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
      // STUB
  }


  return 0;
}
