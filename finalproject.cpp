//Cisp360FinalProjectAnnakubrak.cpp
//Cisp 360, Anna Kubrak
//05/16/2024

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;


struct Room{
  string room_name;
  string room_description;
  int room_id; //for array
  bool occupied;
  bool visited;
  char exits[4]; 
};

//inventory
struct Item {
    string item_name;
    string description;
};

struct Inventory {
    static const int MAX_ITEMS = 5;
    Item items[MAX_ITEMS];
    int item_count;

    Inventory() : item_count(0) {}

    void addItem(const Item& item) {
        if (item_count < MAX_ITEMS) {
            items[item_count++] = item;
            cout << "You have picked up: " << item.item_name << endl;
        } else {
            cout << "Your inventory is full. You cannot carry more items." << endl;
        }
    }

    void clearInventory() {
        item_count = 0;
        cout << "Your inventory has been cleared." << endl;
    }

};

// Speciﬁcation C2 - Three Functions 
//Function Prototypes
void programGreeting();
void gameExplanation();
void printRoomDesc(Room currentRoom);
void look(Room dungeon[], Room& currentRoom);
void move(Room dungeon[], Room& currentRoom, char command);
void pickUpTreasures(Inventory& inventory, Room& currentRoom, Room dungeon[]);
void monsters(Room& currentRoom, Room dungeon[], Inventory& inventory);

int main() {
  
  // Speciﬁcation C3 - Function Activity to Disk
  ofstream outputFile;
  outputFile.open("log.txt");
  
  time_t currentTime = time(nullptr);
  tm* localTime = localtime(&currentTime);
  char buffer[80];
  strftime(buffer, 80, "%m/%d/%Y %I:%M:%S %p", localTime);

  outputFile << "Function programGreeting called" << buffer << endl;
  programGreeting();
  outputFile << "Function gameExplanation called" << buffer << endl;
  gameExplanation();

  Inventory inventory;
  // Speciﬁcation C1 - Main Data Structure
  //using array to store the rooms
  Room dungeon[11] = {
  
  //ROOM ONE
   {"Prison Cell", "You are locked in a prison cell.# The cell is empty and there is the locked door in front of you.", 0, false, false, {'n', ' ', ' ', ' '} },
  
  //ROOM TWO
  {"Middle of Main Corridor", "You are in a dimly lit corridor.# Find your way to the the other rooms.", 1, false, false, {'n', 's', 'e', 'w'} }, //middle of corridor, prisoner goes here when he exists prison cell
  {"West of Main Corrider", "You are in a dimly lit corridor.# Find your way to the other rooms.", 2, false, false, {' ', 's', 'e', ' '} }, //west of middle main corridor
  {"East of Main Corridor", "You are in a dimly lit corridor.# Find your way to the other roons.", 3, false, false, {' ', 's', ' ', 'w'} }, //east of middle main corridor

  //ROOM THREE
  // Specification A1 - Add Feature (Treasure)
  {"Treasure Room", "You are in a room that holds treasure.# Walk around the room and find the treasure", 4, false, false, {'n', ' ', ' ', ' '}}, //prisoner enters here when he goes to the west side of the main corridor and then goes south

  //ROOM FOUR 
  {"Kitchen", "You are in the kitchen.# find the knife to use to try to break the lock when you find the exit,", 5, false, false, {'n', ' ', ' ', ' '}}, //prisoner enters kitchen when he goes to the east side of the main corridor and then goes south

  
  //ROOM FIVE
  {"Beggning of North Wing Corridor", "You are in the dimly lit north wing corridor.# Find your way out of the dungeon.", 6, false, false, {'n', 's', ' ', 'w'}}, //prisoner enters here when character goes north from the corrider
  {"Middle of North Wing Corridor", "You are in the dimly lit north wing corridor.# Find your way out of the dungeon.", 7, false, false, {'n', 's', ' ', ' '}}, //north of beggining of north wing corridor
  {"End of North Wing Corridor", "You are in the dimly lit north wing corridor.# Find your way out of the dungeon.", 8, false, false, {' ', 's', ' ', 'w'}}, 
 

  //Room 6
  // Specification A2 - Add Feature (Extra room)
  // Specification A3 - Add Feature (Add Trap encounter)
  //this is the faux treasure room
  {"Treasure Room", "You are in a room that holds treasure.# Walk around the room and find the treasure", 9, false, false, {' ', ' ', 'e', ' '}}, //prison enters here when he goes to the beginning of the north wing corridor and then goes west

  
  //THE EXIT
  {"Exit", "Congrats! You found the exit.", 10, false, false, {' ', ' ', ' ', ' '} }, //prisoner enters here when he goes to the end of the north wing corridor and then goes west
  };


  //Game Loop
  
   Room currentRoom = dungeon[0]; //start in the prison cell
    do {
      cout << "\nYou are in the " << currentRoom.room_name << "." << endl;
      if (currentRoom.visited) {
          outputFile << "Function printRoomDesc called" << buffer << endl;
          printRoomDesc(currentRoom);
      } else {cout << currentRoom.room_description << endl; 
             currentRoom.visited = true; //marks room as visited
        }
      cout << "Available exits: ";
        for (int i = 0; i < 4; i++) {
          if (currentRoom.exits[i] != ' ') {
            cout << currentRoom.exits[i] << " ";
          }
        }
      cout << endl;
      
      char command;
      cout << "Enter command: ";
      cin >> command;
      
      // Specification B3 - Input Validation 
        switch (command) {
          case 'n':
          case 's':
          case 'e':
          case 'w':
              outputFile << "Function move called" << buffer << endl;
              move(dungeon, currentRoom, command);
              outputFile << "Function pickUpTreasures called" << buffer << endl;
              pickUpTreasures(inventory, currentRoom, dungeon);
              outputFile << "Function monsters called" << buffer << endl;
              monsters(currentRoom, dungeon, inventory);
              break;
          case 'l':
              outputFile << "Function look called" << buffer << endl;
              look(dungeon, currentRoom);
              break;
          case 'i':
              cout << "Inventory:" << endl;
              for (int i = 0; i < inventory.item_count; i++) {
                cout << inventory.item_count << endl;
              }          
          default:
              cout << "Invalid command. Enter valid command." << endl;
        }
      
      
    } while (currentRoom.room_id != 10); //exit room id is 10, and game ends when you reach this room

  cout << currentRoom.room_description << endl;
  cout << "Game over!" << endl;

  outputFile << "Game ended at: " << buffer << endl;
  outputFile.close(); 
  
  return 0;
}

void programGreeting(){
  cout << "Welcome to your Adventure!\n" << endl;
}

void gameExplanation(){
  cout << "Oops. Looks like you upset the queen and got locked in her castle's dungeon. Find a way to escape before the guards catch you and take you to your beheading.\n" << endl;
  cout << "Use keys N, S, E, W to move around the dungeon.\n" << endl;
  cout << "Use key L to 'look' around the room.\n" << endl;
  cout << "use key i to see your inventory.\n" << endl;
  cout << "Warning: there are 4 monsters that live in the dungeon. If you run into them there may be problems.\n" << endl;
}

// Specification B1 - Abbreviated Room Description
void printRoomDesc(Room currentRoom) {
    cout << currentRoom.room_name;
    for(int i = 0; i < currentRoom.room_description.length(); i++){
      if(currentRoom.visited == true || currentRoom.room_description[i] == '#')
        return;
      cout << currentRoom.room_description[i];
    
  }
}

// Speciﬁcation B2 - Detailed Look 
  void look(Room dungeon[], Room& currentRoom){
  cout << "You are in the " << currentRoom.room_name << endl;
  cout << currentRoom.room_description << endl;
}

void move(Room dungeon[], Room& currentRoom, char command) {
  int newroomId = currentRoom.room_id;
  switch(currentRoom.room_id) {
    case 0: //prison cell
      if(command == 'n') newroomId = 1; //main corridor
      break;

    case 1: //main corridor
      if(command == 'n') newroomId = 6; 
      else if(command == 's') newroomId = 0; 
      else if(command == 'e') newroomId = 3; 
      else if(command == 'w') newroomId = 2; 
      break;
      

    case 2: //west side of main corridor
      if(command == 's') newroomId = 4;
      else if(command == 'e') newroomId = 1; 
      break;

    case 3: //east side of main corridor
      if(command == 's') newroomId = 5; 
      else if(command == 'w') newroomId = 1; 
      break;
      
    case 4: //treasure room
      if(command == 'n') newroomId = 2; 
      break;

    case 5: //Kitchen
      if(command == 'n') newroomId = 3; 
      break;

    case 6: //Beggining of North Wing Corridor
      if(command == 'n') newroomId = 7; 
      else if(command == 's') newroomId = 1;
      else if(command == 'w') newroomId = 9;
      break;

    case 7: //Middle of North Wing Corridor
      if(command == 'n') newroomId = 8; 
      else if(command == 's') newroomId = 6; 
      break;


    case 8: //End of North Wing Corridor
      if(command == 's') newroomId = 7;
      else if(command == 'w') newroomId = 10; 
      break;


    case 9: //Treasure Room
      if(command == 'e') newroomId = 6; 
      break;
  }
  currentRoom.occupied = false; //mark room as not occupied when leaving
  currentRoom = dungeon[newroomId]; //change rooms
  currentRoom.occupied = true; //mark current room occupied
}

void pickUpTreasures(Inventory& inventory, Room& currentRoom, Room dungeon[]){
  switch(currentRoom.room_id){
    case 4: //treasure room
      if(currentRoom.room_id == dungeon[4].room_id) {
      inventory.addItem({"Treasure", "These treasures are worth millions."});
      cout << "You have picked up treasure." << endl; 
      }
      break;

    case 5: //kitchen
      if(currentRoom.room_id == dungeon[5].room_id) {
      inventory.addItem({"Knife", "A sharp knife that can be used to break the lock."});
      cout << "You have picked up the knife." << endl;
      }
      break;
    
    case 9: //faux treasure rolom
      if(currentRoom.room_id == dungeon[9].room_id) {
      cout << "Oops. This is actually not a treasure room, but the guards headquartets. You have been caught and taken to your beheading." << endl;
      }
      exit(0);
  }
}

//spawn one of 4 monsters 
void monsters(Room& currentRoom, Room dungeon[], Inventory& inventory) {

  if (currentRoom.occupied) {
    if (currentRoom.room_id != 1 && currentRoom.room_id != 2 && currentRoom.room_id != 3 && currentRoom.room_id != 6 && currentRoom.room_id != 7 && currentRoom.room_id != 8 && currentRoom.room_id != 10) {
    srand(time(0));
    int spawnChance = rand() % 2;

      if(spawnChance == 0) {
        int monster = rand() % 4;
         switch(monster) {
      
          case 0:  //monster 1
            cout << "The guard monster has caught you sneaking around the dungeon. He put you back in your cell. Try escaping again.\n" << endl;
          currentRoom = dungeon[0];
          break;
    
          case 1:  //monster 2
            cout << "Oops a big spider monster has moved into this room. It's okay though, he won't bother you. He is just trying to sleep\n" << endl;
          break;
    
          case 2: //monster 3
            cout << "A goblin is in the room. RUN!" << endl;
    
          case 3: //monster 4
            cout << "A robber has stolen everything in your inventory." << endl;
            //clear inventory here 
           inventory.clearInventory();
           break;
        }
      }
    }
  }
}


/*
Welcome to your Adventure!

Oops. Looks like you upset the queen and got locked in her castle's dungeon. Find a way to escape before the guards catch you and take you to your beheading.

Use keys N, S, E, W to move around the dungeon.

Use key L to 'look' around the room.

use key i to see your inventory.

Warning: there are 4 monsters that live in the dungeon. If you run into them there may be problems.


You are in the Prison Cell.
You are locked in a prison cell.# The cell is empty and there is the locked door in front of you.
Available exits: n 
Enter command: n

You are in the Middle of Main Corridor.
You are in a dimly lit corridor.# Find your way to the the other rooms.
Available exits: n s e w 
Enter command: w

You are in the West of Main Corrider.
You are in a dimly lit corridor.# Find your way to the other rooms.
Available exits: s e 
Enter command: s
You have picked up: Treasure
You have picked up treasure.
Oops a big spider monster has moved into this room. It's okay though, he won't bother you. He is just trying to sleep


You are in the Treasure Room.
You are in a room that holds treasure.# Walk around the room and find the treasure
Available exits: n 
Enter command: n

You are in the West of Main Corrider.
You are in a dimly lit corridor.# Find your way to the other rooms.
Available exits: s e 
Enter command: e

You are in the Middle of Main Corridor.
You are in a dimly lit corridor.# Find your way to the the other rooms.
Available exits: n s e w 
Enter command: n

You are in the Beggning of North Wing Corridor.
You are in the dimly lit north wing corridor.# Find your way out of the dungeon.
Available exits: n s w 
Enter command: n

You are in the Middle of North Wing Corridor.
You are in the dimly lit north wing corridor.# Find your way out of the dungeon.
Available exits: n s 
Enter command: n

You are in the End of North Wing Corridor.
You are in the dimly lit north wing corridor.# Find your way out of the dungeon.
Available exits: s w 
Enter command: w
Congrats! You found the exit.
Game over!
*/
