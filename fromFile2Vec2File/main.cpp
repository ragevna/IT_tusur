#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string oldFileName = "/Users/ragevna/CLionProjects/fromFile2Vector2File/PSS_128_RE.txt";
    string newFileName = "/Users/ragevna/CLionProjects/fromFile2Vector2File/newFile.txt";

    int counter = 0;

    vector <float> vec;

    std::ifstream oldFile;
    oldFile.open(oldFileName);

    if (oldFile.is_open()) {
        std::cout << "File " << oldFileName << " successfully opened!\n";
    } else {
        std::cout << "Error on file.open().";
        return -1;
    }

    float fValue;

    while(counter < 411){
        oldFile >> fValue;
        vec.push_back(fValue);
        counter++;
    }

    oldFile.close();

    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec.at(i) << "\n";
    }

    std::ofstream newFile;
    newFile.open(newFileName);

    for (int i = 0; i < vec.size(); i++) {
        newFile << vec[i] << " ";
        if (i == 136 || i == 273)
            newFile << "\n";
    }

    return 0;
}
