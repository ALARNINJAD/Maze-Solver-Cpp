#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Map {

    pair <int,int> mouse;
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

    void go_mouse (){

        // find the location of mouse
        for ( int i=0 ; i<map.size() ; i++ )            // row
            for ( int j=0 ; j<map[i].size() ; j++ )     // column
                if ( map[i][j]=='M' ) { mouse.first=i; mouse.second=j; }
    }

    void show_map (){
        system("cls");                             
        for ( int i=0 ; i<map.size() ; i++ ){      
            for ( int j=0 ; j<map[i].size() ; j++ )
                cout << map[i][j];
            cout << endl;
        }
    }
};

int main (){
    
	Map maze("map.txt");
    //maze.show_map();
    maze.go_mouse();


    return 0;
}
