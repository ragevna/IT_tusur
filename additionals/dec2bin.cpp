#include <iostream>

void reverseStr(std::string& str)
{
    int len = str.length();
    int n = len-1;
    int i = 0;
    while(i<=n){
        //Using the swap method to switch values at each index
        std::swap(str[i],str[n]);
        n = n-1;
        i = i+1;
    }

}

void dec2bin(int num, std::string &res) {
    if(num % 2 == 0) {
        res += "0";
    }
    else if (num % 2 == 1) {
        res += "1";
    }
    if ((num / 2) != 0) {
        dec2bin(num/2, res);
    }
    else {
        return;
    }
}

int main() {
    std::string res;
    int dec;

    std::cout << "Введите число в десятичной СС: ";
    std::cin >> dec;
    dec2bin(dec, res);
    reverseStr(res);
    std::cout << "Число " << dec << " в двоичной СС равняется " << res;


    return 0;
}
