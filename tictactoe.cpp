//cisp360TicTacToeAnnaKubrak.cpp
//Cisp 360, Anna Kubrak
//05/05/24
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

//Function Prototypes
void programGreeting();
void instructions(ofstream &outputFile, const char* buffer);
void displayBoard(int boardSpot[]);
void game(ofstream &outputFile, const char* buffer);
bool checkWin(int boardSpot[], int player);
bool checkTie(int boardSpot[]);


int main() {
  // Speciﬁcation C3 - Function Activity to Disk
  ofstream outputFile;
   outputFile.open("log.txt");

  time_t currentTime = time(nullptr);
  tm* localTime = localtime(&currentTime);
  char buffer[80];
  strftime(buffer, 80, "%m/%d/%Y %I:%M:%S %p", localTime);

   outputFile<<buffer<<"programGreeting Called";
  programGreeting();


  // Speciﬁcation B1 - Start Menu 
    cout << "GAME MENU:" << std::endl;
    cout << "1. Explain Game\n";
    cout << "2. Play\n";
    cout << "3. Quit\n";

    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    cout << endl;

  // Speciﬁcation B2 - Valid Menu Choices 
  while(choice < 1 || choice > 3) {
    cout << "Invalid choice. Please enter a valid choice (1-3): " << std::endl;
    cin >> choice;
  }

  if(choice == 3){
    cout << "Goodbye!" << endl;
    return 0;
  }
  
  if(choice == 1) {
     outputFile<<buffer<<"insrtuctions Called";
    instructions(outputFile, buffer);
  }

  if(choice == 2) {
    game(outputFile, buffer);

    // Specification A2 - Play Again Option
    cout << "\nWould you like to play again? (y/n):";
    char choice;
    cin >> choice;
    cout << "\n\n" << std::endl;

    if(choice == 'y') {
      game(outputFile, buffer);
    }

    if(choice == 'n'){
      std::cout << "Goodbye!" << std::endl;
    }
  }
}

//Program Greeting
void programGreeting() {
  cout << "Wecome to Tic Tac Toe!";
  cout << "\n\n" << endl;
}

void instructions(ofstream &outputFile, const char* buffer){
  cout << "Game Instructions: " << endl;
  cout << "This is a two player game. You will be X the computer will be O. The first player to get three of their symbols in a row wins." << endl;

  cout << "\n\n" << endl;
  
  cout << "Would you like to play now? (y/n): ";
  char yn;
  cin >> yn;
  if(yn == 'n') {
    cout << "Program terminated." << endl;
    exit(0);
  } 
  if(yn == 'y') {
    cout << "Let's play!" << endl;
    cout << "\n\n" << endl;
    outputFile<<buffer<<"game Called";
    game(outputFile, buffer);
  }
}

void displayBoard(int boardSpot[]){
  // Speciﬁcation C2 - Simple Display
  //displaying tic tac toe table
  cout << "|\t   \t|\t   \t|\t   \t|" << endl;
  cout << "|\t" << boardSpot[1] << "\t|\t" << boardSpot[2] <<  "\t|\t" << boardSpot[3] << "\t|" << endl;
  cout << "|\t   \t|\t   \t|\t   \t|" << endl;
  cout << "-------------------------" << endl;
  cout << "|\t   \t|\t   \t|\t   \t|" << endl;
  cout << "|\t" << boardSpot[4] << "\t|\t" << boardSpot[5] <<  "\t|\t" << boardSpot[6] << "\t|" << endl;
  cout << "|\t   \t|\t   \t|\t   \t|" << endl;
  cout << "-------------------------" << endl;
  cout << "|\t   \t|\t   \t|\t   \t|" << endl;
  cout << "|\t" << boardSpot[7] << "\t|\t" << boardSpot[8] <<  "\t|\t" << boardSpot[9] << "\t|" << endl;
  cout << "|\t   \t|\t   \t|\t   \t|" << endl;

    
}

void game(ofstream &outputFile, const char* buffer) {
  
  //array to keep track of board
  int boardSpot[10] = {0}; 

  // Speciﬁcation C1 - Random Start 
    srand(time(0));
    int player = rand() % 2 + 1;
    if(player == 1){
    cout << "You will go first.\n" << endl;
     }
    if(player == 2){
    cout << "The computer will go first.\n" << endl;
    }
  
    outputFile<<buffer<<"displayBoard called";
    displayBoard(boardSpot);

  int playerMove;
  int compMove;

  
  while (!checkWin(boardSpot, player) && !checkTie(boardSpot)) {
    if (player == 1) {
    cout << "Player " << player << "'s turn. Enter your move (1-9): ";
    cin >> playerMove;

    // Speciﬁcation B3 – Range Check Move 
    // Specification A1 - Open Moves Only Check
    while (playerMove < 1 || playerMove > 9 || boardSpot[playerMove] == 'X' || boardSpot[playerMove] == 'O') {
      cout << "Invalid move. Enter again: ";
      cin >> playerMove;
    }

    boardSpot[playerMove] = 'X';

  }

  else if(player == 2){
    cout << "Computer's turn." << endl;
    compMove = rand() % 9 + 1;
    do {
      compMove = rand() % 9 + 1;
    } while(boardSpot[compMove] == 'X' || boardSpot[compMove] == 'O');
    cout << "Computer chose " << compMove << endl;
    boardSpot[compMove] = 'O';
  }
    outputFile<<buffer<<"displayBoard called";
    displayBoard(boardSpot);

    player = (player == 1) ? 2 : 1;

    
    if (checkWin(boardSpot, player)) {
      cout << "Player " << player << " wins!" << endl;
      break;
    } else if (checkTie(boardSpot)) {
      cout << "It's a tie!" << endl;
      break;
    }
  }
}

bool checkWin(int boardSpot[], int player) {
     return ((boardSpot[1] == boardSpot[2] && boardSpot[2] == boardSpot[3] && boardSpot[3] == player) || 
             (boardSpot[4] == boardSpot[5] && boardSpot[5] == boardSpot[6] && boardSpot[6] == player) || 
             (boardSpot[7] == boardSpot[8] && boardSpot[8] == boardSpot[9] && boardSpot[9] == player) ||
             (boardSpot[1] == boardSpot[4] && boardSpot[4] == boardSpot[7] && boardSpot[7] == player) || 
             (boardSpot[2] == boardSpot[5] && boardSpot[5] == boardSpot[8] && boardSpot[8] == player) || 
             (boardSpot[3] == boardSpot[6] && boardSpot[6] == boardSpot[9] && boardSpot[9] == player) || 
             (boardSpot[1] == boardSpot[5] && boardSpot[5] == boardSpot[9] && boardSpot[9] == player) || 
             (boardSpot[3] == boardSpot[5] && boardSpot[5] == boardSpot[7] && boardSpot[7] == player));  
 }

 bool checkTie(int boardSpot[]) {
   for(int i=1; i<10; i++) {
     if(boardSpot[i] != 'X' && boardSpot[i] != 'O')
       return false;
   }
   return true;
 }



// Specification A3 - Games Played Counter


/* Commented Sample Run:
Wecome to Tic Tac Toe!


GAME MENU:
1. Explain Game
2. Play
3. Quit
Enter your choice: 2

You will go first.

|       |       |       |
|   0   |   0   |   0   |
|       |       |       |
-------------------------
|       |       |       |
|   0   |   0   |   0   |
|       |       |       |
-------------------------
|       |       |       |
|   0   |   0   |   0   |
|       |       |       |
Player 1's turn. Enter your move (1-9): 1
|       |       |       |
|   88  |   0   |   0   |
|       |       |       |
-------------------------
|       |       |       |
|   0   |   0   |   0   |
|       |       |       |
-------------------------
|       |       |       |
|   0   |   0   |   0   |
|       |       |       |
Computer's turn.
Computer chose 6
|       |       |       |
|   88  |   0   |   0   |
|       |       |       |
-------------------------
|       |       |       |
|   0   |   0   |   79  |
|       |       |       |
-------------------------
|       |       |       |
|   0   |   0   |   0   |
|       |       |       |
Player 1's turn. Enter your move (1-9): 2
|       |       |       |
|   88  |   88  |   0   |
|       |       |       |
-------------------------
|       |       |       |
|   0   |   0   |   79  |
|       |       |       |
-------------------------
|       |       |       |
|   0   |   0   |   0   |
|       |       |       |
Computer's turn.
Computer chose 5
|       |       |       |
|   88  |   88  |   0   |
|       |       |       |
-------------------------
|       |       |       |
|   0   |   79  |   79  |
|       |       |       |
-------------------------
|       |       |       |
|   0   |   0   |   0   |
|       |       |       |
Player 1's turn. Enter your move (1-9): 4
|       |       |       |
|   88  |   88  |   0   |
|       |       |       |
-------------------------
|       |       |       |
|   88  |   79  |   79  |
|       |       |       |
-------------------------
|       |       |       |
|   0   |   0   |   0   |
|       |       |       |
Computer's turn.
Computer chose 7
|       |       |       |
|   88  |   88  |   0   |
|       |       |       |
-------------------------
|       |       |       |
|   88  |   79  |   79  |
|       |       |       |
-------------------------
|       |       |       |
|   79  |   0   |   0   |
|       |       |       |
Player 1's turn. Enter your move (1-9): 6
Invalid move. Enter again: 7
Invalid move. Enter again: 8
|       |       |       |
|   88  |   88  |   0   |
|       |       |       |
-------------------------
|       |       |       |
|   88  |   79  |   79  |
|       |       |       |
-------------------------
|       |       |       |
|   79  |   88  |   0   |
|       |       |       |
Computer's turn.
Computer chose 9
|       |       |       |
|   88  |   88  |   0   |
|       |       |       |
-------------------------
|       |       |       |
|   88  |   79  |   79  |
|       |       |       |
-------------------------
|       |       |       |
|   79  |   88  |   79  |
|       |       |       |
Player 1's turn. Enter your move (1-9): 3
|       |       |       |
|   88  |   88  |   88  |
|       |       |       |
-------------------------
|       |       |       |
|   88  |   79  |   79  |
|       |       |       |
-------------------------
|       |       |       |
|   79  |   88  |   79  |
|       |       |       |
It's a tie!

Would you like to play again? (y/n):n



Goodbye!




*/
