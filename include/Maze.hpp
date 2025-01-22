#ifndef MAZE_HPP
#define MAZE_HPP

#include <fstream>
#include <vector>
#include <./struct.hpp>
#include <./function.hpp>
using namespace std;

class Maze {

    point mouse,cheese;
    vector <vector<char>> map;

    void read_file ( string fileName );
    void find_locations ();
    void separate ();
    void go ();

public:

    Maze ( string fileName );
    ~Maze ();

    void show_map ();
};

#endif