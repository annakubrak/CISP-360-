//cisp360AlGoresRevengeAnnaKubrak.cpp
//Anna Kubrak, CISP 360
//02/18/24

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

// Speciﬁcation C1 - const Conversions
const float MM2IN = 0.03937;
const float F2C = 5.0 / 9.0;

// Specification A3 - One Function
//function prototype
void programGreeting();
void autoHeader(string header);
int oceanRise(double  riseRate);
void tempRise();


//main function
int main() {
  programGreeting();
  oceanRise(3.1);
  tempRise();
}

//Program Greeting 
void programGreeting() {
  cout << "The Earth's climate has changed over the past century and this program is designed to project what future temperatures and the ocean levels might be like." << endl;
  cout << "\n\n" << endl;
}

// Speciﬁcation B3 - Auto Heading Function 
void autoHeader(string header) {
  for (int i = 0; i < header.length(); ++i)
    header[i] = toupper(header[i]);
  cout << header << endl;
  for (int i = 0; i < header.size(); ++i)
    cout << "=";
  cout << endl;
}

// Speciﬁcation C2 - 5 year ocean rise 
// Speciﬁcation B1 - Mixed length output 
// Specification A1 - Ocean Rise Table
int oceanRise(double riseRate) {
  autoHeader("Ocean Levels");
  cout << setw(10) << "Year" << setw(20) << "Ocean Level MM" << setw(20) << "Ocean Level In" << endl;
  double riseinMM = 0;
  for (int year = 1; year <= 5; ++year) {
    riseinMM += riseRate;
  double riseinIn = riseinMM * MM2IN;
cout << setw(10) << year << setw(20) << fixed << setprecision(3)   << riseinMM << setw(20) << riseinIn << endl;
  }
  cout << "\n\n";
  return 0;
}

// Speciﬁcation C3 - 5 year temp  
// Speciﬁcation B2 - Mixed temperature output 
// Specification A2 - July Temp Table
void tempRise() {
autoHeader("July Temperature Levels");
  cout << setw(15) << "YEAR" << setw(10) << "1" << setw(18) << "2" << setw(18) << "3" << setw(18) << "4" << setw(18) << "5" << endl;
  cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
  cout << setw(15) << "City" << setw(10) << "Temp °F" << setw(10) << "Temp °C" << setw(10) << "Temp °F" << setw(10) << "Temp °C" << setw(10) << "Temp °F" << setw(10) << "Temp °C" << setw(10) << "Temp °F" << setw(10) << "Temp °C" << setw(10) << "Temp °F" << setw(10) << "Temp °C" << endl;
  cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
  
 //NYC 
  cout << setw(15) << "NYC";
  double nycF = 85.0; 
  for (int year = 1; year <= 5; ++year) {
    double nycC = (nycF - 32.0) * F2C;
      cout << setw(9) << nycF << setw(9) << nycC;
    nycF += 0.13; 
  }
  cout << endl;
  
  cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
  
  // Denver
  cout << setw(15) << "Denver";
  double dvF = 88.0;
  for (int year = 1; year <= 5; ++year){
    double dvC = (dvF - 32.0) * F2C;
    cout << setw(9) << dvF << setw(9) << dvC;
    dvF += 0.13;
  }
  cout << endl;
  
  cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
  
  // Sacramento
  cout << setw(15) << "Sacramento";
  double sacF = 106.0;
  for (int year = 1; year <= 5; ++year) {
    double sacC = (sacF - 32.0) * F2C;
    cout << setw(9) << sacF << setw(9) << sacC;
    sacF += 0.13;
  }
  cout << endl;
  
  cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;

  // Phoenix
  cout << setw(15) << "Pheonix";
  double phxF = 98.0;
  for (int year = 1; year <= 5; ++year) {
    double phxC = (phxF - 32.0) * F2C;
    cout << setw(9) << phxF << setw(9) << phxC;
    phxF += 0.13;
  }
   cout << endl;
  
   cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
}



/* sample run:
The Earth's climate has changed over the past century and this program is designed to project what future temperatures and the ocean levels might be like.



OCEAN LEVELS
============
      Year      Ocean Level MM      Ocean Level In
         1               3.100               0.122
         2               6.200               0.244
         3               9.300               0.366
         4              12.400               0.488
         5              15.500               0.610


JULY TEMPERATURE LEVELS
=======================
           YEAR         1                 2                 3                 4                 5
--------------------------------------------------------------------------------------------------------------------------
           City  Temp °F  Temp °C  Temp °F  Temp °C  Temp °F  Temp °C  Temp °F  Temp °C  Temp °F  Temp °C
--------------------------------------------------------------------------------------------------------------------------
            NYC   85.000   29.444   85.130   29.517   85.260   29.589   85.390   29.661   85.520   29.733
--------------------------------------------------------------------------------------------------------------------------
         Denver   88.000   31.111   88.130   31.183   88.260   31.256   88.390   31.328   88.520   31.400
--------------------------------------------------------------------------------------------------------------------------
     Sacramento  106.000   41.111  106.130   41.183  106.260   41.256  106.390   41.328  106.520   41.400
--------------------------------------------------------------------------------------------------------------------------
        Pheonix   98.000   36.667   98.130   36.739   98.260   36.811   98.390   36.883   98.520   36.956
--------------------------------------------------------------------------------------------------------------------------

*/
