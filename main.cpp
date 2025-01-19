#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct point { int x,y; };

class Map {

    point mouse,cheese; // the location of mouse and cheese
    vector <vector<char>> map;

    void read_file ( string fileName ){

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

    void find_locations (){

        // finding the location of mouse and cheese
        for ( int i=0 ; i<map.size() ; i++ )            // row
            for ( int j=0 ; j<map[i].size() ; j++ )     // column
                if ( map[i][j]=='M' ){
                    mouse.x=i; mouse.y=j;               // mouse
                } else if ( map[i][j]=='C' ){
                    cheese.x=i; cheese.y=j;             // cheese
                }
    }

    void separate (){

        // separating the location of cheese/mouse from map
        map[mouse.x][mouse.y] = '|';
        map[cheese.x][cheese.y] = '|';
    }

public:

    Map(string fileName) {
        read_file(fileName);
        find_locations();     
        separate();
    }

    void show_map (){
        system("cls"); 
        for ( int i=0 ; i<map.size() ; i++ ){
            for ( int j=0 ; j<map[i].size() ; j++ )
                cout << map[i][j];
            cout << endl;
        }
        _sleep(500);
    }
};

int main (){
    
	Map maze("map.txt");
    //maze.show_map();

    return 0;
}
