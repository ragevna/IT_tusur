#include <iostream>
#include <fstream>
#include <string>

// 1) считывает файл в котором у тебя «123456789»
// 2) изменяет эту строку, на ту же строку в обратном порядке
// 3) записывает и сохраняет в новый файл

int readFile(std::string& str){
    std::ifstream oldFile;
    std::string fileName = "/Users/ragevna/CLionProjects/reverseStrFromFile/oldFile.txt";
    oldFile.open(fileName);

    if (oldFile.is_open()) {
        std::cout << "Файл " << fileName << " успешно открыт, приступаем к работе!\n";
        oldFile >> str;
        return 0;
    } else {
        std::cout << "Проблемы с открытием файла.";
        return -1;
    }
}

void reverseString(std::string& str) {

    std::cout << "Полученная из файла строка: " << str << std::endl;
    std::cout << "Обработка строки..." << std::endl;
    std::reverse(str.begin(), str.end());
    std::cout << "Измененная строка: " << str;
    std::cout << std::endl;

}

int writeFile(std::string& str) {
    std::ofstream newFile;
    std::string fileName = "/Users/ragevna/CLionProjects/reverseStrFromFile/newFile.txt";
    newFile.open("/Users/ragevna/CLionProjects/reverseStrFromFile/newFile.txt");

    if (newFile.is_open()){
        std::cout << "Создан и открыт файл " << fileName << ".\nЗапись строки..." << std::endl;
        newFile << str;
        std::cout << "Строка успешно записана!";
        return 0;
    } else {
        std::cout << "Проблемы с созданием/открытием файла.";
        return -1;
    }

    std::cout << "End of program" << std::endl;
}

int main() {

    std::string str;
    readFile(str);
    reverseString(str);
    writeFile(str);

}
