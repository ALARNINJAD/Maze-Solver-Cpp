#ifndef MAZE_HPP
#define MAZE_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>
using namespace std;

struct point { int x,y; };
struct side { int loc; char c; };

class Maze {

    point mouse,cheese;
    vector <vector<char>> map;

    void read_file ( string fileName );
    void find_locations ();
    void separate ();
    void go ();

public:

    Maze ( string fileName );
    ~Maze (){};

    void show_map ();
};

#endif