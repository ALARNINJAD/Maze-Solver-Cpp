#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Map {

    vector <vector<char>> map;

public:

    Map(string fileName) {

        ifstream file(fileName); // open file on reading mode
        if ( !file.is_open() ) { cerr << "File error" << endl; } // error handling

        // read text and write to 2d vector
        string str;                                        // str is for each line of text
        while ( getline(file, str) ){                      // reading each line of file and write it to str 
            vector <char> row;                             // a temporarly vector for breaking str to chars
            for ( int i=0 ; i<str.size() ; i++ )           // str to vector of chars
                row.push_back(str[i]);
            map.push_back(row);                            // push each row to the map
            row.clear();                                   // making row fresh for each line
        }

        // close the file
        file.close();
    }

    void show_map (){
        for ( int i=0 ; i<map.size() ; i++ ){           // column
            for ( int j=0 ; j<map[i].size() ; j++ )     // row
                cout << map[i][j];
            cout << endl;
        }
    }
};

int main (){
    
	Map maze("map.txt");

    maze.show_map();

    return 0;
}
