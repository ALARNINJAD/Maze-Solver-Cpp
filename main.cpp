#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Map {

    vector <string> map;

public:

    Map(string fileName) {
        ifstream file(fileName);
        if ( !file.is_open() ) { cerr << "File error" << endl; }
        string str;
        while (getline(file, str)) { map.push_back(str); }
        file.close();
    }
};

int main() {
    
	Map maze("map.txt");

    return 0;
}
