#include <iostream>
#include<limits>
#include <vector>
#include <coordinate.h>

using namespace std;

bool debug_mazeBuild = true;    // debug the process set up maze
bool debug_InrRangecheck = false;     // debug the maze while it's modified
bool debug_mazeSearhing = true;     // debug the searching a path to solution
char explored = '+';    // a char to marker where the solution or partial path in the maze can be
char unexplored = '.';

// function protypes
void PrintMaze(const vector<vector<char>>& maze);

vector<vector<char>> SetUpMaze();

bool InRange(const coordinate& where, const vector<vector<char>>& maze);

char WhatMazeHasAt(const coordinate& where, const vector<vector<char>>& maze);

void ChangeMazeAt(const coordinate& where, const char ch, vector<vector<char>>& maze);

bool DefineStartAndDestinationSpot(const coordinate& start, const coordinate& destination, vector<vector<char>>& maze);

bool SearchForPath(coordinate spot, vector<vector<char>>& maze);

coordinate askUserACoordinate(const string claim);

int main() {
    char keepGoing = 'y';
    cout << "Hello World!" << endl;
    while(keepGoing == 'y') {
        vector<vector<char>> maze = SetUpMaze();
        coordinate start = askUserACoordinate("where to start");    // coordinate(1, 1);
        coordinate goal = askUserACoordinate("where the goal is");  // coordinate(5, 1);
        while (!DefineStartAndDestinationSpot(start, goal, maze)) {
            goal = askUserACoordinate("where to start");
            start = askUserACoordinate("where the goal is");
        }
        // start from starting point, check a spot of a maze
        if (SearchForPath(start, maze)) {
            cout << "Here is a path" << endl;
            PrintMaze(maze);
        }
        // ask user if restart the game
        cout << "keepGoing? (y/n)";
        cin >> keepGoing;
    }
    return 0;
}


void PrintMaze(const vector<vector<char>>& maze){
    string output = "The maze is now ";
    output += (debug_mazeBuild? "\n" : " (the row is secondary vector in the first vector) \n");
    int numOfRow = maze.size()-1;
    int numOfCol_thisRow = 0;   // count the number of col in each row
    int numOfCol = 0;   // maxium number of col in the whole 2D vector
    for (auto row : maze) {     // print the all the info instead of col coordinates
        numOfCol_thisRow = 0;
        for (auto ele : row) {  // for each of element in this row
            if (numOfCol_thisRow == 0) {
                output += (to_string(numOfRow) + " ");// add a row coordinate to output
                numOfRow--;
            }
            output += ele;
            output += "  ";  // add theis element to uotput
            numOfCol_thisRow++;
        }
        output += "\n";     // go to next line
        numOfCol = numOfCol_thisRow > numOfCol? numOfCol_thisRow : numOfCol;
    }
    output += "  ";
    for (int i = 0; i < numOfCol; i++) { // add col coordintes to ouput
        output += (to_string(i) + "  ");
    }
    cout << output << endl;
}

vector<vector<char>> SetUpMaze() {
    vector<vector<char>> maze {{'.', '#' ,'#', '#', '#', '#'},
                               {'.', '.', '.', '#', '.', '#'},
                               {'#', '.', '#', '#', '.', '#'},
                               {'#', '.', '#', '#', '.', '#'},
                               {'.', '.', '#', '.', '.', '.'},
                               {'#', '.', '.', '.', '#', '#'}};
    PrintMaze(maze);
    return maze;
}

bool InRange(const coordinate& where, const vector<vector<char>>& maze) {
    if (where.GetX() < 0 || where.GetY() < 0) { // check x y lower bound
        if (debug_InrRangecheck) cout << "Check maze failure: coordinates negitive" << endl;
    } else {
        if (where.GetY() > int(maze.size()-1)) {   // check y upper bound
            if (debug_InrRangecheck) cout << "Check maze failure: y coordinates out of range" << endl;
        } else {
            if (where.GetX() > int(maze.at(int(maze.size()) - 1 - where.GetY()).size() - 1)) {   // check x upper bound
                if (debug_InrRangecheck) cout << "Check maze failure: x coordinates out of range" << endl;
            } else {
                return true;
            }
        }
    }
    return false;
}

char WhatMazeHasAt(const coordinate& where, const vector<vector<char>>& maze) {
    if (InRange(where, maze)) {     // if in bound
        return maze.at(maze.size() - 1 - where.GetY()).at(where.GetX());
    } else {
        return ' ';
    }
}

void ChangeMazeAt(const coordinate& where, const char ch, vector<vector<char>>& maze) {
    char what = WhatMazeHasAt(where, maze);
    if (what != ' ') {
        if (what == '#') {
            char going = 'n';
            cout << "This is a wall element, sure you wanna change it? (y/n)";
            cin >> going;
            if (going == 'y') maze.at(maze.size() - 1 - where.GetY()).at(where.GetX()) = ch;
        } else {
            maze.at(maze.size() - 1 - where.GetY()).at(where.GetX()) = ch;
        }
        if (debug_InrRangecheck) {
            cout << "Change maze at (" << to_string(where.GetX()) << ", " << to_string(where.GetY()) << ")" << endl;
            cout << "       from " << what;
            cout << " to " << WhatMazeHasAt(where, maze) << endl;
            PrintMaze(maze);
        }
    } else {
        out_of_range("Intend to change a element out of bound");
    }
}

bool DefineStartAndDestinationSpot(const coordinate& start, const coordinate& destination, vector<vector<char>>& maze) {
    if (InRange(start, maze) && InRange(destination, maze)) {
        char char_start = WhatMazeHasAt(start, maze);
        char char_destination = WhatMazeHasAt(destination, maze);
        if (char_start == '#' || char_destination == '#') { // check if the start or destination coordinates is wall
            cout << "Invalid position to start or end" << endl;
            return false;
        } else {
            ChangeMazeAt(start, 'S', maze); // change start spot
            ChangeMazeAt(destination, 'G', maze);   // change end spot
            return true;
        }
    } else {
        cout << "start or destination coordinates out of range:";
        cout << "start(" << start.GetX() << ", " << start.GetY() << ") " ;
        cout << "goal(" << destination.GetX() << ", " << destination.GetY() << ")" << endl;
        return false;
    }
}

bool SearchForPath(coordinate spot, vector<vector<char>>& maze) {
    char underFoot = WhatMazeHasAt(spot, maze);     // check where you are in this maze
    if (underFoot == 'G') {     // base case: find goal
        return true;
    } else {
        if (underFoot == unexplored || underFoot == 'S') {     // recursive case: find a start point or road and keep searching
            if (underFoot == unexplored) ChangeMazeAt(spot, explored, maze);          // mark this road as been explored
            // search north // search east  // search south // search west
            if (SearchForPath(spot.GoNorth(), maze) || SearchForPath(spot.GoEast(), maze) || SearchForPath(spot.GoSouth(), maze) || SearchForPath(spot.GoWest(), maze)) {
                return true;
            } else {    // not possible to find a path from this spot
                ChangeMazeAt(spot, unexplored, maze);
                return false;
            }
        } else {       // if what you stand at is not a road or goal, return false(unable to find a path from here)
            return false;
        }
    }
}

coordinate askUserACoordinate(const string claim) {
    int x, y;
    cout << "Please enter x and y coordinate of " << claim << " (seperate by space): ";
    while(!(cin >> x) || !(cin >> y)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input.  Try again: ";
    }
    coordinate spot(x, y);
    return spot;
}
