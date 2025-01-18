#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Map {
public:
    vector<string> map;

    Map(string fileName) {
        ifstream file(fileName);
        string str;
        while (getline(file, str)) {
            map.push_back(str);
        }
        file.close();
    }
};

int main() {
    
	Map x("map.txt");

    return 0;
}
