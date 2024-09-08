//cisp360CurrencyConverterAnnaKubrak.cpp
//Anna Kubrak, CISP 360
//03/03/2024

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

// Speciﬁcation B1 - Three Functions 
//Function Prototypes
void programGreeting();
void mainMenu();
void reverseMenu();
int inputPrompt();
double usdYen(double amount);
double usdEuro(double amount);
double usdPound(double amount);
double yenUsd(double amount);
double euroUsd(double amount);
double poundUsd(double amount);
void endOfProgram();
void amountErrorText();
void optionErrorText();

//Constant Conversions
const double USD_YEN = 150.48;
const double USD_EURO = 0.92;
const double USD_POUND = 0.79;

//Main function: calls program greeting and main menu
int main() {
  programGreeting();
  mainMenu();
  endOfProgram();

}

//Program Greeting
void programGreeting() {
  cout << "Welcome to the Currency Converter." << endl;
  cout << "Convert between USD, Yen, Euro, or British Pound.\n" << endl;
}

// Speciﬁcation C1 - Main Menu
//If user aks for options 1-5 program executes them, if user asks for option 5, program calls the reverse menu function
void mainMenu() {
  cout << "MAIN MENU" << endl;
  cout << "---------" << endl;
  cout << "Option 1: USD -> Yen" << endl;
  cout << "Option 2: USD -> Euro" << endl;
  cout << "Option 3: USD -> British Pound" << endl;
  cout << "option 4: Convert All" << endl; // Speciﬁcation B3 - Convert All
  cout << "Option 5: Flip Conversion\n" << endl;

  cout << "Choose an option: ";
  int choice;
  cin >> choice;
  cout << endl;

  // Specification A2 - Valid Menu Selection only
  if(choice < 1 || choice > 5) {
    optionErrorText();
  }
  
    if (choice == 1) {
      double amount = inputPrompt();
      cout << "\n$" << amount << " converted to Yen is ¥" << usdYen(amount) << ". \n" << endl;
    }
    if (choice == 2) {
      double amount = inputPrompt();
      cout << "\n$" << amount << " converted to Euro is €" << usdEuro(amount) << ". \n" << endl;
    }
    if (choice == 3) {
      double amount = inputPrompt();
      cout << "\n$" << amount << " converted to British Pound is £" << usdPound(amount) << ". \n" << endl; 
    }
    if (choice == 4) {
      double amount = inputPrompt();
      cout << "\n\n" << endl;

      cout << "USD" << setw(11) << "Yen" << setw(14) << "Euro" << setw(13) << "Pound" << endl;
      cout << "------------------------------------------------" << endl;
      cout << "$" << amount << setw(10) << "¥" << usdYen(amount) << setw(9) << "€" << usdEuro(amount) << setw(10) << "£" << usdPound(amount) << endl; 
    }
    if (choice == 5) {
      reverseMenu();
    } 
}

// Speciﬁcation C2 - Reverse Menu 
void reverseMenu() {
  cout << "\nREVERSE CONVERSIONS" << endl;
  cout << "-------------------" << endl;
  cout << "Option 1: Yen -> USD" << endl;
  cout << "Option 2: Euro -> USD" << endl;
  cout << "Option 3: British Pound -> USD" << endl;
  cout << "Option 4: Convert All" << endl; // Speciﬁcation B3 - Convert All
  cout << "Option 5: Quit w/o Conversion\n" << endl;

  cout << "Choose an option: ";
  int choice;
  cin >> choice;
  cout << endl;

  // Specification A2 - Valid Menu Selection only
  if(choice < 1 || choice > 5) {
    optionErrorText();
  }

    if (choice == 1) {
      double amount = inputPrompt();
      cout << "\n¥" << amount << " converted to USD is $" << yenUsd(amount) << ". \n" << endl;
    }
    if (choice == 2) {
      double amount = inputPrompt();
      cout << "\n€" << amount << " converted to USD is $" << euroUsd(amount) << ". \n" << endl;
    }
    if (choice == 3) {
      double amount = inputPrompt();
      cout << "\n£" << amount << " converted to USD is $" << poundUsd(amount) << ". \n" << endl;
    }
    if (choice == 4) {
      double amount = inputPrompt();
      cout << "Currency" << setw(15) << "in USD" << endl;
      cout << "-----------------------------------" << endl;
      cout << "¥" << amount << setw(15) << "$" << yenUsd(amount) << endl;
      cout << "€" << amount << setw(15) << "$" << euroUsd(amount) << endl;
      cout << "£" << amount << setw(15) << "$" << poundUsd(amount) << endl;
    }
  if (choice == 5) {
    cout << "\nProgram Ended." << endl;
    exit(0);
  }
}


// Speciﬁcation C3 - Input Prompt Function
//Asks user to enter the amount they want to convert and if it is a valid amount it returns the amount. If it is not a valid amount program calls the error function and terminates the program
int inputPrompt() {
  cout << "\nEnter the amount you want to convert: ";
  double amount;
  cin >> amount;
  cout << "\n" << endl;
  
  // Specification A1 - Sanity Check
  if(amount < 0 || amount > 100000) {
    amountErrorText();
  }
  else if( amount > 0 || amount <= 100000) {
    return amount;
  }
  return 0;
}

// Speciﬁcation B2 - Conversion Function(s)  
double usdYen(double amount) {
  return amount * USD_YEN;
}

double usdEuro(double amount) {
  return amount * USD_EURO;
}

double usdPound(double amount) {
  return amount * USD_POUND;
}

double yenUsd(double amount) {
  return amount / USD_YEN;
}

double euroUsd(double amount) {
  return amount / USD_EURO;
}

double poundUsd(double amount) {
  return amount / USD_POUND;
} 

void endOfProgram() {
  cout << "\nWould you like to convert again? yes or no" << endl;
  string option;
  cin >> option;
  cout << "\n\n" << endl;
  
  if(option == "yes") {
    main();
  }
  if(option == "no") {
    cout << "\nProgram Ended." << endl;
    exit(0);
  }
}

// Specification A3 - Red Error Text
//Error text for when user enters an invalid amount
void amountErrorText() {
  cout << "\n\033[1;31mInvalid input. Amount enetered is too big or too small.\033[0m\n" << endl;
  cout << "Program Ended" << endl;
  exit(0);
}
//Error text for when user enters an invalid option in the menu
void optionErrorText() {
  cout << "\n\033[1;31mInvalid input. Option entered is not valid.\033[0m\n" << endl;
  cout << "Program Ended" << endl;
  exit(0);
}

/* 
Sample run of conversions:
Welcome to the Currency Converter.
Convert between USD, Yen, Euro, or British Pound.

MAIN MENU
---------
Option 1: USD -> Yen
Option 2: USD -> Euro
Option 3: USD -> British Pound
option 4: Convert All
Option 5: Flip Conversion

Choose an option: 5


REVERSE CONVERSIONS
-------------------
Option 1: Yen -> USD
Option 2: Euro -> USD
Option 3: British Pound -> USD
Option 4: Convert All
Option 5: Quit w/o Conversion

Choose an option: 4


Enter the amount you want to convert: 100


Currency         in USD
-----------------------------------
¥100              $0.66454
€100              $108.696
£100              $126.582

Would you like to convert again? yes or no
yes



Welcome to the Currency Converter.
Convert between USD, Yen, Euro, or British Pound.

MAIN MENU
---------
Option 1: USD -> Yen
Option 2: USD -> Euro
Option 3: USD -> British Pound
option 4: Convert All
Option 5: Flip Conversion

Choose an option: 4


Enter the amount you want to convert: 100





USD        Yen          Euro        Pound
------------------------------------------------
$100        ¥15048      €92        £79

Would you like to convert again? yes or no
no




Program Ended.

//sample runs of user entering an invalid option
Welcome to the Currency Converter.
Convert between USD, Yen, Euro, or British Pound.

MAIN MENU
---------
Option 1: USD -> Yen
Option 2: USD -> Euro
Option 3: USD -> British Pound
option 4: Convert All
Option 5: Flip Conversion

Choose an option: 6


Invalid input. Option entered is not valid.

Program Ended


//Sample run of a user entering an invalid amount

Welcome to the Currency Converter.
Convert between USD, Yen, Euro, or British Pound.

MAIN MENU
---------
Option 1: USD -> Yen
Option 2: USD -> Euro
Option 3: USD -> British Pound
option 4: Convert All
Option 5: Flip Conversion

Choose an option: 1


Enter the amount you want to convert: 19282038373



Invalid input. Amount enetered is too big or too small.

Program Ended
*/
