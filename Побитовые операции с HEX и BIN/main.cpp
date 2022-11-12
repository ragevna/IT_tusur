#include <iostream>
#include <bitset>
#include <fstream>
#include <typeinfo>

using namespace std;

int main(){

    int numOfLines = 0; // ������� ��� �����, ����� ����� ������ ������ 10 �����.
    std::string digits; // ������, � ������� ����� �������� ����� �� �����.
    uint32_t a = 0x00000000; // ����������, � ������� ����� ������������ ����� �� ����.


    // �������� �����.
    std::ifstream file;
    std::string fileName = "P:\\162\\SSS_B2_1024.txt";
    file.open(fileName);

    // �������� �� �������� �������� �����.
    if (file.is_open()) {
        std::cout << "File " << fileName << " successfully opened!\n\n";

    } else {
        std::cout << "Error on file.open().";
        return -1;
    }

    // ����� ��������� ����������, ����������� ������, � HEX � BIN.
    std::cout << "Zeroed hex:\n " << std::hex << a << "(hex)\n" << std::bitset<8>(a) << "(dec)\n\n";

    // ����, ������� ��������� ���������� ����, ���� �� ��������� 10 �����.
    while(getline(file, digits) && numOfLines < 10){

        // ��������� ����������, ��� ����� ������ �����
        a = 0x00000000;

        // ����� ���������� �� ����� ������.
        std::cout << "string from file: " << digits << "\n";

        // ���������� 4-� ���������� ����� � 8-������������. ������ ������-���.
        digits = digits + "0000";

        // ����������� ������� ������. ���� ������ ������ ����� �������, �� ��������� �������� ������� � HEX �� digits.length()-(i+1) ������� �����
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

