#include <iostream>
#include <stdint.h>

uint32_t addcalc( uint32_t v1, uint32_t v2);
uint32_t minuscalc( uint32_t v1, uint32_t v2);
uint32_t multicalc( uint32_t v1, uint32_t v2);
uint32_t dividecalc( uint32_t v1, uint32_t v2);

int main() {
    int calcsettings;
    bool ct = true;
    uint32_t value1;
    uint32_t value2;
    uint32_t result;
    
    system("chcp 65001");
    system("cls");

    while (ct) {
        std::cout << "数値1: ";
        std::cin >> std::hex >> value1;
        std::cout << "数値2: ";
        std::cin >> std::hex >> value2;
        std::cout << "計算方法(0: +, 1: -, 2: x, 3: ÷): ";
        std::cin >> calcsettings;

        if( value1 != 0 || value2 != 0 ) {
            if( calcsettings == 0 ) result = addcalc(value1, value2);
            else if( calcsettings == 1 ) result = minuscalc(value1, value2);
            else if( calcsettings == 2 ) result = multicalc(value1, value2);
            else if( calcsettings == 3 ) result = dividecalc(value1, value2);
            else ct = false;

            std::cout << "計算結果: " << std::uppercase << std::hex << result << "\n\n";
        } else {
            std::cout << "\033[31m!無効な値です \033[m" << "\n\n";
        }
        value1, value2 = 0;
    }
    ct = true;
}

uint32_t addcalc( uint32_t v1, uint32_t v2) {
    return v1 + v2;
}

uint32_t minuscalc( uint32_t v1, uint32_t v2) {
    return v1 - v2;
}

uint32_t multicalc( uint32_t v1, uint32_t v2) {
    return v1 * v2;
}

uint32_t dividecalc( uint32_t v1, uint32_t v2) {
    return v1 / v2;
}