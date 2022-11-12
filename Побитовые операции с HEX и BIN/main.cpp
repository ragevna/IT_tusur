#include <iostream>
#include <bitset>
#include <fstream>
#include <typeinfo>

using namespace std;

int main(){

    int numOfLines = 0; // Счетчик для цикла, чтобы взять только первые 10 строк.
    std::string digits; // Строка, в которую будет записано число из файла.
    uint32_t a = 0x00000000; // Переменная, в которую будет записываться число из файа.


    // Открытие файла.
    std::ifstream file;
    std::string fileName = "P:\\162\\SSS_B2_1024.txt";
    file.open(fileName);

    // Проверка на успешное открытие файла.
    if (file.is_open()) {
        std::cout << "File " << fileName << " successfully opened!\n\n";

    } else {
        std::cout << "Error on file.open().";
        return -1;
    }

    // Вывод начальной переменной, заполненной нулями, в HEX и BIN.
    std::cout << "Zeroed hex:\n " << std::hex << a << "(hex)\n" << std::bitset<8>(a) << "(dec)\n\n";

    // Цикл, которой построчно перебирает файл, пока не переберет 10 строк.
    while(getline(file, digits) && numOfLines < 10){

        // Обнуление переменной, для ввода нового числа
        a = 0x00000000;

        // Вывод полученной из файла строки.
        std::cout << "string from file: " << digits << "\n";

        // Приведение 4-х разрядного числа к 8-миразрядному. Просто потому-что.
        digits = digits + "0000";

        // Циклический перебор строки. Если символ строки равен единице, то побитовая операция толкает в HEX на digits.length()-(i+1) позиций влево
        for(int i = 0; i <= digits.length(); i++) {
            if (digits[i] == '1') {
                a = a  | 1 << (digits.length()-(i+1));
            }else {
                continue;
            }
        }

        std::cout << "New hex:\n " << std::hex << a << "(hex)\n" << std::bitset<8>(a) << "(dec)\n\n";
        numOfLines++;
    }
}

