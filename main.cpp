#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3

struct point { int x,y; };
struct side { int loc; char c; };

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

    // separating the location of cheese/mouse from map
    void separate (){
        map[mouse.x][mouse.y] = ' ';
        map[cheese.x][cheese.y] = ' ';
    }

    void go (){

        vector <point> diff_ways;

        // moving mouse untill it finds the cheese
        while ( mouse.x!=cheese.x || mouse.y!=cheese.y ){

            side around[4]; // 4 different directions around the mouse
            around[0].c = map[mouse.x][mouse.y+1];
            around[0].loc = RIGHT;
            around[1].c = map[mouse.x+1][mouse.y];
            around[1].loc = DOWN;
            around[2].c = map[mouse.x][mouse.y-1];
            around[2].loc = LEFT;
            around[3].c = map[mouse.x-1][mouse.y];
            around[3].loc = UP;

            int ways = 0;
            for ( int i=0 ; i<4 ; i++ )            // counting the ways
                if ( around[i].c==' ' ) ways++;

            if ( ways>1 ){
                diff_ways.push_back(mouse);        // when new directions found
                map[mouse.x][mouse.y] = '*';
            } else if ( ways==0 ){
                map[mouse.x][mouse.y] = '.';       // when ther is now way
                mouse = diff_ways.back();
                diff_ways.pop_back();
                continue;
            }

            // bubble sorting directions:
            for ( bool condition=true ; condition ;){
                condition = false;
                for ( int i=0 ; i<3 ; i++ ){
                    if ( (int)around[i].c > (int)around[i+1].c ){
                        side temp;
                        temp = around[i];
                        around[i] = around[i+1];
                        around[i+1] = temp;
                        condition = true;
                    }
                }
            }

            // make a move
            if ( around[0].loc == RIGHT ){
                if ( ways==1 )  
                    map[mouse.x][mouse.y] = '.';
                mouse.y++;
            } else if ( around[0].loc == DOWN ){
                if ( ways==1 )
                    map[mouse.x][mouse.y] = '.';
                mouse.x++;
            } else if ( around[0].loc == LEFT ){
                if ( ways==1 )
                    map[mouse.x][mouse.y] = '.';
                mouse.y--;
            } else if ( around[0].loc == UP ){
                if ( ways==1 )
                    map[mouse.x][mouse.y] = '.';
                mouse.x--;
            }

            show_map();     // show frame
        }
    }

public:

    Map(string fileName) {
        read_file(fileName);
        find_locations();
        separate();
        go();
    }

    void show_map (){
        clear();                                  // clear frame
        for ( int i=0 ; i<map.size() ; i++ ){           // row
            for ( int j=0 ; j<map[i].size() ; j++ )     // column
                if ( mouse.x==i && mouse.y==j ) {       // mouse
                    cout << 'M';
                } else if ( cheese.x==i && cheese.y==j ){
                    cout << 'C';
                } else { cout << map[i][j]; }           // walls and ways
            cout << endl;
        }
        sleep();                                    // for better view
    }
};

void clear (){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void sleep (){
    #ifdef _WIN32
        _sleep(200);
    #else
        usleep(200000);
    #endif
}

int main (){
	Map maze("map.txt");
    return 0;
}