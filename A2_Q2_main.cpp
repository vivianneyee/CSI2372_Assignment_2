/**
* Vivianne Yee
* 300118867
**/

#include <iostream>
#include <cstddef>

using namespace std;

/**
 * Player struct
**/
struct Player {
    string name;
    int score;
};

/**
* add a new player and score
**/
Player* addplayer(Player * p, Player * players, int * n) {
  // check if array is already at capacity
  int size = *n;
  if (size >= 10) {
      cout << "List is full, player cannot be added." << endl;
      return players; 
  }
  // create a new array with size + 1
  Player * newPlayers;
  newPlayers = new Player[size + 1];
  // copy all players + new player
  for (int i = 0; i < *n; i++) {
      newPlayers[i] = players[i];
  }

  newPlayers[size] = *p;
  *n = size + 1;
  cout << "Player added." << endl;
  return newPlayers;
}

/**
* print all players abd their score to the screen
**/
void printplayers(Player * players, int * n) {
  // iterate through array by array size
  int size = *n;
  for (int i = 0; i < size; i++) {
      cout << i+1 << ". name: " << players[i].name << " score: " << players[i].score << endl;
  }
}

/**
* allow the user to enter a player name and output the player's
* score or a message if the player's name has not been entered
**/
void showscore(string name, Player * players, int * n) {
  // iterate through array
  int size = *n;
  for (int i = 0; i < size; i++) {
    // compare name with players[i].name 
    if (players[i].name.compare(name) == 0) {
        cout << players[i].name << "'s score is " << players[i].score << endl;
        break;
    } else if (i == size - 1) {
        cout << "There is no player with that name." << endl;
    }
  }
}

/**
* allow the user to enter a player name and remove the player from
* the list
**/
Player* removeplayer(string name, Player * players, int * n) {
    // check size (if <= 0)
    int size = *n;
    if (size <= 0) {
        cout << "List is already empty";
        return players;
    }
    // new array size - 1
    Player * newPlayers;
    newPlayers = new Player[size - 1];
    int counter = 0;
    bool found = false;
    // iterate through players
    // compare name with players[i].name
    // if not match, add to array
    for (int i = 0; i < size; i++) {
        if (players[i].name.compare(name) == 0) {
            found = true;
            cout << "Player removed successfully"<< endl;
        } else {
            newPlayers[counter] = players[i];
            counter++;
        }
    }
    if (!found) {
        cout << "Player not found." << endl;
        return players;
    }
    // size - 1
    *n = size - 1;
    //return smaller array
    return newPlayers;
}

int main() {
  // initialize empty dynamic array of size 0
  Player* players;
  players = new Player[0];
  // ask user what they want to do
  char choice;
  string name;
  int score;
  Player p;
  int size = 0;
  while (true) {
    cout << "\nEnter 'a' to add a new player\nEnter 'b' to print all players and their scores\nEnter 'c' to see a certain player's score\nEnter 'd' to remove a player\nEnter 'q' to quit\n";
    cin >> choice;
    switch(choice) {
      case 'a':
        cout << "enter player name: ";
        cin >> name;
        cout << "enter their score: ";
        cin >> score;
        p.name = name;
        p.score = score;
        players = addplayer(&p, players, &size);
        break;
      case 'b':
        printplayers(players, &size);
        break;
      case 'c':
        cout << "enter player name: ";
        cin >> name;
        showscore(name, players, &size);
        break;
      case 'd':
        cout << "enter player name: ";
        cin >> name;
        players = removeplayer(name, players, &size);
        break;
      case 'q':
        return 0;
        break;
      default:
        cout << "invalid selection\n";
        break;
    }
  }
}
