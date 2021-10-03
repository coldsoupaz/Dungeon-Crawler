#ifndef LOGIC_H
#define LOGIC_H

#define INFO(X) cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " = " << X << endl;
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Player object container
struct Player {
	int row = 0;
	int col = 0;
	int treasure = 0;
};

// constants for tile status
const char TILE_OPEN      = '-';    // blank tile
const char TILE_PLAYER    = 'o';    // tile for player's current location
const char TILE_TREASURE  = '$';    // tile for unpassable pillar location
const char TILE_AMULET    = '@';    // tile for hazard that enlarges the dungeon
const char TILE_MONSTER   = 'M';    // tile for monster current location
const char TILE_PILLAR    = '+';    // tile for unpassable pillar location
const char TILE_DOOR      = '?';    // tile for door to the next room
const char TILE_EXIT      = '!';    // tile for exit door out of dungeon

// constants for movement status flags 
const int STATUS_STAY     = 0;      // flag indicating player has stayed still
const int STATUS_MOVE     = 1;      // flag indicating player has moved in a direction
const int STATUS_TREASURE = 2;      // flag indicating player has stepped onto the treasure
const int STATUS_AMULET   = 3;      // flag indicating player has stepped onto an amulet
const int STATUS_LEAVE    = 4;      // flag indicating player has left the current room
const int STATUS_ESCAPE   = 5;      // flag indicating player has gone through the dungeon exit

// constants for user's keyboard inputs
const char INPUT_QUIT     = 'q';    // quit command
const char INPUT_STAY     = 'e';    // no movement
const char MOVE_UP        = 'w';    // up movement
const char MOVE_LEFT      = 'a';    // left movement
const char MOVE_DOWN      = 's';    // down movement
const char MOVE_RIGHT     = 'd';    // right movement


// function signatures, do not change
char** loadLevel(const string fileName, int& maxRow, int& maxCol, Player& player);

void getDirection(char input, int& nextRow, int& nextCol);

char** createMap(int maxRow, int maxCol);

void deleteMap(char** board, int maxRow);

char** resizeMap(char** map, int& maxRow, int& maxCol);

int doPlayerMove(char** map, int maxRow, int maxCol, Player& player, int& nextRow, int& nextCol);

bool doMonsterAttack(char** map, int maxRow, int maxCol, Player& player);

#endif
