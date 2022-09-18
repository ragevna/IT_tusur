#include <iostream>
#include <windows.h>
#include <cmath>
#include <bitset>

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    
    // Задание 1, через cin и строку

    std::cout << "_____Задание 1______\n";
    std::string name = "Никита и Арина";

    std::cout << "Hello, " << name << "!\n";

    // Задание 1, через scanf и массив char
    char cName[100];
    scanf("%s", cName); // Читает только до пробела
    printf("%s", cName);
    
    // Задание 2, вариант 7
    //В7. Дано x. Вычислить a, если a=cos(tg(x)-1). Числа, водить с клавиатуры

    std::cout << "\n_____Задание 2______\n";
    float x, a;
    std::cout << "Введите x:";
    std::cin >> x;

    a = cos(tan(x) - 1);

    std::cout << "При Х =" << x << ", A = " << a << std::endl;
    
    // 42(10) - 2(восемь разрядов), 8, hex

    std::cout << "\n_____Задание 3______\n";
    int ten = 42;

    std::bitset<8> tenTwo (ten);
    std::cout << "42(10) = " << tenTwo << "(2)" << std::endl;
    std::cout << "42(10) = " << ten << "(10)" << std::endl;
    std::cout << "42(10) = " << std::oct << ten << "(8)" << std::endl;
    std::cout << "42(10) = " << std::hex << ten <<  "(hex)" << std::endl;
    std::cout << std::hex << ten <<  "(hex) = " << std::dec << ten <<  "(10)" << std::endl;
    return 0;
}
