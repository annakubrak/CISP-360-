//cisp360EhRayAnnaKubrak.cpp
//04/14/24, CISP 360
//Anna Kubrak

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <fstream>
#include <stack>
using namespace std;

//Function Prototypes
void programGreeting();
void displayArray(int integerArray[], int size, float floatArray[]);
void sumArrays(int intergerArray[], int SIZE, float floatArray[]);
void minMaxArrays(int intergerArray[], int SIZE, float floatArray[]);
bool integerValueHunt(int intergerArray[], int SIZE);
void integerValueHuntResults(bool foundInteger, int intergerArray[], int SIZE);
bool floatValueHunt(int SIZE, float floatArray[]);
void floatValueHuntResults(bool foundFloat, float floatArray[], int SIZE);
void reverseIntegerArray(int integerArray[], int SIZE);
void reverseFloatArray(float floatArray[], int SIZE);
void integerElementShift(int integerArray[], int SIZE);
void floatElementShift(float floatArray[], int SIZE);
int randomInt(int min, int max);
void singletonPattern();

int main() {
  programGreeting();
  
  ofstream outputFile;
  outputFile.open("log.txt");

  const int SIZE = 10;
  int integerArray[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  float floatArray[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1};

  time_t currentTime = time(nullptr);
  tm* localTime = localtime(&currentTime);
  char buffer[80];
  strftime(buffer, 80, "%m/%d/%Y %I:%M:%S %p", localTime);

  outputFile<<buffer<<"displayArray Called";
  displayArray(integerArray, SIZE, floatArray);
  outputFile<<buffer<<"sumArrays Called";
  sumArrays(integerArray, SIZE, floatArray);
  outputFile<<buffer<<"minMaxArrays Called";
  minMaxArrays(integerArray, SIZE, floatArray);
  outputFile<<buffer<<"integerValueHunt Called";
  bool foundInteger = integerValueHunt(integerArray, SIZE);
  outputFile<<buffer<<"integerValueHuntResults Called";
  integerValueHuntResults(foundInteger, integerArray, SIZE);
  outputFile<<buffer<<"floatValueHunt Called";
  bool foundFloat = floatValueHunt(SIZE, floatArray);
  outputFile<<buffer<<"floatValueHuntResults Called";
  floatValueHuntResults(foundFloat, floatArray, SIZE);
  outputFile<<buffer<<"reverseIntegerArray Called";
  reverseIntegerArray(integerArray, SIZE);
  outputFile<<buffer<<"reverseFloatArray Called";
  reverseFloatArray(floatArray, SIZE);
  outputFile<<buffer<<"integerElementShift Called";
  integerElementShift(integerArray, SIZE);
  outputFile<<buffer<<"floatElementShift Called";
  floatElementShift(floatArray, SIZE);
  outputFile<<buffer<<"singletonPattern Called";
   void singletonPattern();
  outputFile.close();

  // Specification A2 - Implement a Stack
  stack<int> s;

  for (int i = 1; i <= 15; i++) {
    s.push(i);
  }
  cout << "\n\nStack elements: ";
  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
  return 0;
}

//Program Greeting
void programGreeting() {
  cout << "Welcome to the program Ray!\n\n" << endl;
}

// Speciﬁcation C1 – Display Array 
void displayArray(int integerArray[], int SIZE, float floatArray[]) {

  cout << "The Integer Array is: " << endl;
  for (int i = 0; i < SIZE; i++)
    cout << integerArray[i] << " ";
  cout << endl;
  cout << "\n\n" << endl;
  cout << "The Float Array is: " << endl;
  for (int i = 0; i < SIZE; i++)
    cout << floatArray[i] << " ";

  cout << "\n\n" << endl;
}

 // Speciﬁcation C2 – Sum
void sumArrays(int integerArray[], int SIZE, float floatArray[]) {
  
  int total = 0;
  for (int count = 0; count < SIZE; count++)
    total += integerArray[count];
  cout << "\nThe sum of the integers in the integer array is: " << total << endl;

  float total2 = 0;
  for (int count = 0; count < SIZE; count++)
    total2 += floatArray[count];
  cout << "\nThe sum of the floats in the float array is: " << total2 << endl;

}


//Speciﬁcation C3 – Min and Max 
void minMaxArrays(int integerArray[], int SIZE, float floatArray[]) {
  int count, highestInteger, lowestInteger;
  highestInteger = integerArray[0];
  for (count = 1; count < SIZE; count++) {
    if (integerArray[count] > highestInteger)
      highestInteger = integerArray[count];
  }

  lowestInteger = integerArray[0];
  for (count = 1; count < SIZE; count++) {
    if (integerArray[count] < lowestInteger)
      lowestInteger = integerArray[count];
  }
  cout << "\nThe highest value in the integer array is: " << highestInteger << endl;
  cout << "\nThe lowest value in the integer array is: " << lowestInteger << endl;


  float highestFloat, lowestFloat;
    highestFloat = floatArray[0]; 
    for (count = 1; count < SIZE; count++) {
      if (floatArray[count] > highestFloat)
        highestFloat = floatArray[count];
    }

    lowestFloat = floatArray[0];
    for (count = 1; count < SIZE; count++) {
      if (floatArray[count] < lowestFloat)
        lowestFloat = floatArray[count];
    }

  cout << "\nThe highest value in the float array is: " << highestFloat << endl;
  cout << "\nThe lowest value in the float array is: " << lowestFloat << endl;

  cout << "\n\n" << endl;
  
}

// Speciﬁcation B1 – Value Hunt 
//two bool functions to determine if the integer and float values are in array
//two functions that display the results of the bool functions depending on if they return true or false
bool integerValueHunt(int integerArray[], int SIZE) {
  
  cout << "Enter an Integer value to search for in the integer array:\n" << endl;
  int integerValue;
  cin >> integerValue;
  

  for (int count = 0; count < SIZE; count++) {
    if (integerArray[count] == integerValue) {
      return true;
    }
  }
  return false;
  
}

  void integerValueHuntResults(bool foundInteger, int integerArray[], int SIZE) {
    if (foundInteger == true) {
      cout << "The value you entered was found in the integer array." << endl; }

    if (foundInteger == false) {
      cout << "The value you entered was not found in the integer array." << endl;
    }
  cout << "\n\n" << endl;
  }

  bool floatValueHunt(int SIZE, float floatArray[]) {
  
  cout << "Enter a float value to search for in the float array:\n" << endl;
  float floatValue;
  cin >> floatValue;

  for (int count = 0; count < SIZE; count++) {
    if (floatArray[count] == floatValue) {
      return true;
    }
  }
return false;

} 

void floatValueHuntResults(bool foundFloat, float floatArray[], int SIZE) {
  if (foundFloat == true) {
    cout << "The value you entered was found in the float array." << endl;
  }

  if (foundFloat == false) {
    cout << "The value you entered was not found in the float array." << endl;
  }
    cout << "\n\n" << endl;
}

// Speciﬁcation B2 – A Ray Reversal 
//function to reverse integer array
void reverseIntegerArray(int integerArray[], int SIZE) {

  cout << "The integer array before reversal:\n" << endl;
  for (int i = 0; i < SIZE; i++) {
    cout << integerArray[i] << " ";
  }
  
  for (int i = 0; i < (SIZE - 1) / 2; i++) {
    swap(integerArray[i], integerArray[SIZE - 1 - i]);
  }

  cout << "\n\nThis is the integer array after reversal:" << endl;
  for (int i = 0; i < SIZE; i++) {
    cout << integerArray[i] << " ";
  }
  cout << "\n\n" << endl;
}

//function to reverse float array
void reverseFloatArray(float floatArray[], int SIZE) {
  cout << "The float array before reversal:\n" << endl;
  for (int i = 0; i < SIZE; i++) {
    cout << floatArray[i] << " ";
  }

  for (int i = 0; i < (SIZE - 1) / 2; i++) {
    swap(floatArray[i], floatArray[SIZE - 1 - i]);
  }

  cout << "\n\nThis is the float array after reversal:" << endl;
  for (int i = 0; i < SIZE; i++) {
    cout << floatArray[i] << " ";
  }

  cout << "\n\n" << endl;
}

// Speciﬁcation B3 - Element Shift
//Function to shift Integer Array right
void integerElementShift(int integerArray[], int SIZE) {
  cout << "\nThe integer array before element shift:\n" << endl;
  for (int i = 0; i < SIZE; i++) {
    cout << integerArray[i] << " ";
  }
  
  int last = integerArray[SIZE - 1];
  for (int i = (SIZE - 1); i > 0; i--) {
    integerArray[i] = integerArray[i - 1];
  }
  integerArray[0] = last;

  cout << "\n\nThe integer array after element shift:\n" << endl;
  for (int i = 0; i < SIZE; i++) {
    cout << integerArray[i] << " ";
  }
  cout << "\n\n" << endl;
}

//Funtion to shift Float Array right
void floatElementShift(float floatArray[], int SIZE) {
  cout << "\n\nThe float array before element shift:\n" << endl;
  
  for (int i = 0; i < SIZE; i++) {
    cout << floatArray[i] << " ";
  }

  float last = floatArray[0];
  for (int i = 0; i < (SIZE - 1); i++) {
    floatArray[i] = floatArray[i + 1];
  }
  floatArray[SIZE - 1] = last;

  cout << "\n\nThe float array after element shift:\n" << endl;
  for (int i = 0; i < SIZE; i++) {
    cout << floatArray[i] << " ";
  }
}


// Specification A3 - Random Number in Singleton Pattern
  int randomInt(int min, int max) {                //random function generator
    static bool isSeeded = false;
    if (!isSeeded) {
        srand(time(0));
    }
    return( min + rand() % (max - min + 1));
  }


void singletonPattern(){                //loop to fill the array 
  const int SIZE = 10;
  int arraysp[SIZE];
  for (int i = 0; i < SIZE; i++) {
    arraysp[i] = randomInt(1, 100);
  }
  cout << "The singleton pattern array is:" << endl;
  for (int i = 0; i < SIZE; i++) {
    cout << arraysp[i] << " ";
  }
}


/* Commented Sample Run:
Welcome to the program Ray!


The Integer Array is: 
1 2 3 4 5 6 7 8 9 10 



The Float Array is: 
1.1 2.2 3.3 4.4 5.5 6.6 7.7 8.8 9.9 10.1 



The sum of the integers in the integer array is: 55

The sum of the floats in the float array is: 59.6

The highest value in the integer array is: 10

The lowest value in the integer array is: 1

The highest value in the float array is: 10.1

The lowest value in the float array is: 1.1



Enter an Integer value to search for in the integer array:

5
The value you entered was found in the integer array.



Enter a float value to search for in the float array:

2.2
The value you entered was found in the float array.



The integer array before reversal:

1 2 3 4 5 6 7 8 9 10 

This is the integer array after reversal:
10 9 8 7 5 6 4 3 2 1 


The float array before reversal:

1.1 2.2 3.3 4.4 5.5 6.6 7.7 8.8 9.9 10.1 

This is the float array after reversal:
10.1 9.9 8.8 7.7 5.5 6.6 4.4 3.3 2.2 1.1 



The integer array before element shift:

10 9 8 7 5 6 4 3 2 1 

The integer array after element shift:

1 10 9 8 7 5 6 4 3 2 




The float array before element shift:

10.1 9.9 8.8 7.7 5.5 6.6 4.4 3.3 2.2 1.1 

The float array after element shift:

9.9 8.8 7.7 5.5 6.6 4.4 3.3 2.2 1.1 10.1 

Stack elements: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1

*/
