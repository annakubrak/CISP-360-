//cisp360catcotcapAnnaKubrak
//Anna Kubrak, CISP 360
//03/24/24

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cctype>
using namespace std;

//Function Prototypes
// Speciﬁcation C3 – Three Functions 
void programGreeting();
int intPrompt(string a, int b);
string stringPrompt(string a, string b);
int objectPrompt();
void lowCase(string& object);
void tempMenu();
void tempFprompt(int choice);
bool ValFlo(float ftemp);
float f2c(float ftemp);
float f2k(float ftemp);
float f2r(float ftemp);
void allTempTable();
void choiceOne(float ftemp);
void choiceTwo(float ftemp);
void choiceThree(float ftemp);
void allScaleConvertTable(float ftemp);

//Definitions for displaying function in yellow 
const string YELLOW = "\033[33m"; //yellow because orange is not available
const string RESET = "\033[0m"; //reset to white

int objCode; 

//Main Function
int main() {
  
// Speciﬁcation B1 – Display Function Activity
cout << YELLOW << "Program Start\n" << "Function main() Started\n" << "Function program Greeting Started\n" << RESET << endl;
  programGreeting();
cout << YELLOW << "\nFunction objectPrompt() Started\n" << RESET << endl;
  objectPrompt();
cout << YELLOW << "Function tempMenu() Started\n" << RESET << endl;
  tempMenu();
}

//Program Greeting 
void programGreeting() {
  //welcome message
  cout << "Welcome to the Cat, Cot, Cap Temperature Calculator" << endl;
  //name as author
  cout << "Author: Anna Kubrak" << endl;
  //system date 
  time_t currentTime = time(nullptr);
  tm* localTime = localtime(&currentTime);
  char buffer[50];
  strftime(buffer, sizeof(buffer), "%B %d, %Y", localTime);
  cout << "System Date: " << buffer << endl;
}


// Speciﬁcation B3 - Overloaded Prompt Functions 
int intPrompt(string a, int b) {
  int value;
  cout << a;
  cin >> value;
  return value;
}

float floatPrompt(string a, float b) {
  float value;
  cout << a;
  cin >> value;
  return value;
}

string stringPrompt(string a, string b) {
   string value;
  cout << a;
  cin >> value;
  return value;
}


//prompt client for name of object to convert
int objectPrompt() {
 do { cout << "Enter the object you want to convert the temperature for: ";
  string object;
  cin >> object; //make case insensitive
  cout << endl;

  cout << YELLOW << "Function objectPrompt() Started\n" << RESET << endl;
  lowCase(object);
     
  // Speciﬁcation C1 – Only Valid Words
  objCode = 0;
      if (object == "cat") {
        objCode = 1;
       }  
        else if (object == "cot" ) { //for cot
          objCode = 2;
        } 
        else if (object == "cap") { //for cap
          objCode = 3;
        }
        else {
          objCode = 0; 
          cout << "\033[1;31mThe object you entered is not valid. Please enter a valid object.\033[0m\n" << endl;
        }
      } while (objCode == 0);
  
        return objCode;
}

void lowCase(string& object) { //for case insensitivity
  for (int i = 0; i < object.length(); i++) {
    object[i] = tolower(object[i]);
  } 
}


// Speciﬁcation C2 – Select Temp Scale Menu 
//display a menu where they can choose the temp scale to convert to Celsius, Kelvin, Rankine, or All
void tempMenu() {
  cout << "Temperature Scale Menu" << endl;
  cout << "----------------------" << endl;
  cout << "Press 1 to convert to Celsius" << endl;
  cout << "Press 2 to convert to Kelvin" << endl;
  cout << "Press 3 to convert to Rankine" << endl;
  cout << "Press 4 to convert to all" << endl;

//prompt to choose an option
  int choice;
  do {
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;

    //validate option
    if (choice < 1 || choice > 4) {
      cout << "\033[1;31mThe choice you entered is not valid. Please enter a valid choice.\033[0m\n" << endl;
    } 
  } while (choice < 1 || choice > 4);

  cout << YELLOW << "\nFunction tempFprompt() Started" << RESET << endl;
  tempFprompt(choice);
  
  
}


//prompt for objects current temperature in farenheit 
void tempFprompt(int choice) {
  cout << YELLOW << "Function allTempTable() Started\n" << RESET << endl;
  allTempTable();
  
  float ftemp;
  do{
    cout << "\nEnter the object's temperature in Fahrenheit: "; 
    cin >> ftemp;
    cout << endl;
  
  cout << YELLOW << "\nFunction ValFlo() Started\n" << RESET << endl;
  ValFlo(ftemp);
  //if ValFlo() returns false it will loop and reprompt until ValFlo returns true
  if (!ValFlo(ftemp)) {
    cout << "\033[1;31mThe temperature you entered is invalid. Please enter a valid temperature.\033[0m\n" << endl;
  }  
  } while (!ValFlo(ftemp)); 

  switch (choice) {
    case 1: 
      cout << YELLOW << "Function choiceOne() Started\n" << RESET << endl;
      choiceOne(ftemp);
      break;
    
    case 2: 
      cout << YELLOW << "Function choiceTwo() Started\n" << RESET << endl;
      choiceTwo(ftemp);
      break;
    
    case 3: 
      cout << YELLOW << "Function choiceThree() Started\n" << RESET << endl;
      choiceThree(ftemp);
      break;
    
    case 4: 
      cout << YELLOW << "Function allScaleConvertTable() Started\n" << RESET << endl;
      allScaleConvertTable(ftemp); 
      break;
  }
}

// Speciﬁcation B2 – Valid Temps Only 
//check to see if it's in the proper range
bool ValFlo(float ftemp) {
  float tolerance;
  tolerance = 0.2;
  switch(objCode) {
    case 1: //cat
      if (ftemp < 86.0 - 0.2 || ftemp > 102.0 + 0.2) {
        return false;
      } break;

    case 2: //cot 
      if (ftemp < 54.0 - 0.2 || ftemp > 80.0 + 0.2) {
        return false;
      } break;

    case 3: //cap
      if (ftemp < 72.0 - 0.2 || ftemp > 88.0 + 0.2) {
        return false;
      } break;
  }
  
return true;
  
}

//Conversion Functions
float f2c(float ftemp) { //converts farenheit to celsius
  float ctemp;
  return ctemp = (ftemp - 32) * 5/9;
}

float f2k(float ftemp) { //converts farenheit to kelvin
  float ktemp;
  return ktemp = ftemp + 273.15;
}
 
float f2r(float ftemp) { //convrts to rankine
  float rtemp; 
  return rtemp = ftemp + 459.67;
}

//display converted value 
// Specification A1 - All Temps Table
void allTempTable() {
  cout << YELLOW << "Funtion f2c() Started\n" << "Function f2k() Started\n" << "Function f2r() Started\n" << RESET << endl;
  cout << fixed << setprecision(3);
  cout << "ALLOWABLE TEMPERATURES FOR OBJECTS" << endl;
  cout << "---------------------------------------------------------------------------------------" << endl;
  cout << "Object" << setw(14) << "Farenheit" << setw(16) << "Celsius" << setw(20) << "Kelvin" << setw(22) << "Rankine" << endl;
  cout << "---------------------------------------------------------------------------------------" << endl;
  cout << setw(20) << "Low  High" << setw(18) << "Low  High" << setw(21) << "Low  High" << setw(21) << "Low  High" << endl;
  cout << "---------------------------------------------------------------------------------------" << endl;
  cout << "Cat" << setw(19) << "86.0  102.0" << setw(13) << f2c(86) << "  " << f2c(102) <<  setw(14) << f2k(86) << "  " << f2k(102) << setw(12) << f2r(86) << "  " << f2r(102) <<  endl;
  cout << "---------------------------------------------------------------------------------------" << endl;
  cout << "Cot" << setw(18) << "54.0  80.0" << setw(14) << f2c(54) << "  " << f2c(80) <<  setw(14) << f2k(54) << "  " << f2k(80) << setw(12) << f2r(54) << "  " << f2r(80) <<  endl;
  cout << "---------------------------------------------------------------------------------------" << endl;
  cout << "Cap" << setw(18) << "72.0  88.0" << setw(14) << f2c(72) << "  " << f2c(88) <<  setw(14) << f2k(72) << "  " << f2k(88) << setw(12) << f2r(72) << "  " << f2r(88) <<  endl;
  cout << "---------------------------------------------------------------------------------------" << endl;
}

void choiceOne(float ftemp) {
  cout << YELLOW << "Funtion f2c() Started\n" << RESET << endl;
  cout << "Object: "; 
  switch (objCode) {
    case 1: cout << "Cat\n" << endl; break;
    case 2: cout << "Cot\n" << endl; break;
    case 3: cout << "Cap\n" << endl; break;
  }
  cout << "Farenheit Temperature: " << ftemp << "\n" << endl;
  cout << "The objects temperature in Celsius is: " << f2c(ftemp) << "\n" << endl;
}

void choiceTwo(float ftemp) {
  cout << YELLOW << "Function f2k() Started\n" << RESET << endl;
  cout << "Object: "; 
  switch (objCode) {
    case 1: cout << "Cat\n" << endl; break;
    case 2: cout << "Cot\n" << endl; break;
    case 3: cout << "Cap\n" << endl; break;
  }
  cout << "Farenheit Temperature: " << ftemp << "\n" << endl;
  cout << "The objects temperature in Kelvin is: " << f2c(ftemp) << "\n" << endl;
}

void choiceThree(float ftemp) {
  cout << YELLOW << "Function f2r() Started\n" << RESET << endl;
  cout << "Object: "; 
  switch (objCode) {
    case 1: cout << "Cat\n" << endl; break;
    case 2: cout << "Cot\n" << endl; break;
    case 3: cout << "Cap\n" << endl; break;
  }
  cout << "Farenheit Temperature: " << ftemp << "\n" << endl;
  cout << "The objects temperature in Rankine is: " << f2c(ftemp) << "\n" << endl;
}

// Specification A2 - All Temp Conversion
void allScaleConvertTable(float ftemp) {
  cout << YELLOW << "Funtion f2c() Started" << endl; 
  cout << "Function f2k() Started" << endl; 
  cout << "Function f2r() Started\n" << RESET << endl;
  
  cout << "ALL SCALE CONVERSIONS" << endl;
  cout << "---------------------" << endl;
  cout << "Object: "; 
    switch (objCode) {
      case 1: cout << "Cat\n" << endl; break;
      case 2: cout << "Cot\n" << endl; break;
      case 3: cout << "Cap\n" << endl; break;
    }
  cout << "Temperature: " << ftemp << "\n" << endl;

  cout << "Farenheit" << setw(15) << "Celsius" << setw(15) << "Kelvin" << setw(15) << "Rankine" << endl;
  cout << "---------------------------------------------------------" << endl;
  cout << ftemp << setw(17) << f2c(ftemp) << setw(20) << f2k(ftemp) << setw(14) << f2r(ftemp) << endl;
}

/* Commented sample run:

Program Start
Function main() Started
Function program Greeting Started

Welcome to the Cat, Cot, Cap Temperature Calculator
Author: Anna Kubrak
System Date: March 25, 2024

Function objectPrompt() Started

Enter the object you want to convert the temperature for: cAt

Function objectPrompt() Started

Function tempMenu() Started

Temperature Scale Menu
----------------------
Press 1 to convert to Celsius
Press 2 to convert to Kelvin
Press 3 to convert to Rankine
Press 4 to convert to all
Enter your choice: 4


Function tempFprompt() Started
Function allTempTable() Started

Funtion f2c() Started
Function f2k() Started
Function f2r() Started

ALLOWABLE TEMPERATURES FOR OBJECTS
---------------------------------------------------------------------------------------
Object     Farenheit         Celsius              Kelvin               Rankine
---------------------------------------------------------------------------------------
           Low  High         Low  High            Low  High            Low  High
---------------------------------------------------------------------------------------
Cat        86.0  102.0       30.000  38.889       359.150  375.150     545.670  561.670
---------------------------------------------------------------------------------------
Cot        54.0  80.0        12.222  26.667       327.150  353.150     513.670  539.670
---------------------------------------------------------------------------------------
Cap        72.0  88.0        22.222  31.111       345.150  361.150     531.670  547.670
---------------------------------------------------------------------------------------

Enter the object's temperature in Fahrenheit: 86


Function ValFlo() Started

Function allScaleConvertTable() Started

Funtion f2c() Started
Function f2k() Started
Function f2r() Started

ALL SCALE CONVERSIONS
---------------------
Object: Cat

Temperature: 86.000

Farenheit        Celsius         Kelvin        Rankine
---------------------------------------------------------
86.000           30.000             359.150       545.670


*/
