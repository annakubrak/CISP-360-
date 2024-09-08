//drakeequationannakubrak.cpp
//Anna Kubrak, CISP 360
//02/04/24

#include <iostream>
#include <string>
using namespace std; 


int main() {

//program greeting
cout << "Drake Equation, Anna Kubrak, 02/04/24" << endl;
cout << "This program will calculate the number of potential civilizations using the Drake equation.\n";

// Speciﬁcation C1 - Variable Declaration 
// Speciﬁcation C2 - Variable Initialization 
// Speciﬁcation C3 - Constant Variables 
  const int star_rate = 7;           //rate of star creation
  const float stars_w_plnts = 0.4;   // % of stars with planets
  const float avg_num_plnts = 0.9;   //avg # of planets that can potentially support life per star with planets
  const float dvlp_life = 0.13;      //% of those that go on to develop life
  const float dvlp_iLife = 0.5;      //% of those that go on to intelligent develop life
  const float plnts_comm = 0.8;      //% of those willing and able to communicate
  const int life_civ = 10000;        //expected lifetime of civilizations
  float etCiv;                       //# of potential civilizations
  

  
 // Speciﬁcation B1 - Calculation 
  etCiv = star_rate * stars_w_plnts * avg_num_plnts * dvlp_life * dvlp_iLife * plnts_comm * life_civ;

  
// Speciﬁcation B2 - Drake Equation Heading
  cout << "\n\n";
  cout << "\nCHANCE OF INTELLIGENT LIFE\n";
  cout << "==========================\n";
  cout << "The estimated number of potential civilizations is: " << etCiv << endl;
  
 // Speciﬁcation B3 - Double and Half Output and Headings 
  cout << "\n\n";
  cout << "\nSENSITIVITY ANALYSIS\n";
  cout << "==================================\n";
  cout << "|Double Output result: |" << etCiv * 2 << "   |" << endl;
  cout << "|----------------------|---------|\n";
  cout << "|Half Output result:   |" << etCiv / 2 << "    |" << endl;
  cout << "==================================\n";


// Specification A1 - Variable Table
  cout << "\n\n";
  cout << "\nVARIABLE TABLE\n";
  cout << "================================\n";
  cout << "|Variable Name  |Variable Value|\n";
  cout << "|---------------|--------------|\n";
  cout << "|star_rate:     |" << star_rate << "             |" << endl;
  cout << "|---------------|--------------|\n";
  cout << "|stars_w_plnts: |" << stars_w_plnts << "           |" << endl;
  cout << "|---------------|--------------|\n";
  cout << "|avg_num_plnts: |" << avg_num_plnts << "           |" << endl;
  cout << "|---------------|--------------|\n";
  cout << "|dvlp_life:     |" << dvlp_life << "          |" << endl;
  cout << "|---------------|--------------|\n";
  cout << "|dvlp_iLife:    |" << dvlp_iLife << "           |" << endl;
  cout << "|---------------|--------------|\n";
  cout << "|plnts_comm:    |" << plnts_comm << "           |" << endl;
  cout << "|---------------|--------------|\n";
  cout << "|life_civ:      |" << life_civ << "         |" << endl;
  cout << "|---------------|--------------|\n";
  cout << "|etCiv:         |" << etCiv << "        |" << endl;
   cout << "================================";
  
// Specification A2 - Output Table
  cout << "\n\n";
  cout << "\nOUTPUT TABLE\n";
  cout << "===============================\n";
  cout << "|Drake Equation Value: |" << etCiv << "|" << endl;
  cout << "===============================\n";

// Specification A3 - Sensitivity Analysis Table
  cout << "\n\n";
  cout << "\nSENSITIVITY ANALYSIS TABLE \n";
  cout << "==========================\n";
  cout << "|Double results: |" << etCiv * 2 << " |" << endl;
  cout << "|----------------|-------|\n";
  cout << "|Half results:   |" << etCiv / 2 << "  |" << endl;
  cout << "==========================\n";

}

/*
Drake Equation, Anna Kubrak, 02/04/24
This program will calculate the number of potential civilizations using the Drake equation.



CHANCE OF INTELLIGENT LIFE
==========================
The estimated number of potential civilizations is: 1310.4



SENSITIVITY ANALYSIS
==================================
|Double Output result: |2620.8   |
|----------------------|---------|
|Half Output result:   |655.2    |
==================================



VARIABLE TABLE
================================
|Variable Name  |Variable Value|
|---------------|--------------|
|star_rate:     |7             |
|---------------|--------------|
|stars_w_plnts: |0.4           |
|---------------|--------------|
|avg_num_plnts: |0.9           |
|---------------|--------------|
|dvlp_life:     |0.13          |
|---------------|--------------|
|dvlp_iLife:    |0.5           |
|---------------|--------------|
|plnts_comm:    |0.8           |
|---------------|--------------|
|life_civ:      |10000         |
|---------------|--------------|
|etCiv:         |1310.4        |
================================


OUTPUT TABLE
===============================
|Drake Equation Value: |1310.4|
===============================



SENSITIVITY ANALYSIS TABLE 
==========================
|Double results: |2620.8 |
|----------------|-------|
|Half results:   |655.2  |
==========================

*/
