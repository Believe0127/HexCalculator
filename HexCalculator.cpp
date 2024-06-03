#include <iostream>
#include <limits>
#include <stdint.h>

typedef uint32_t u32;

u32 addcalc(u32 v1, u32 v2);
u32 minuscalc(u32 v1, u32 v2);
u32 multicalc(u32 v1, u32 v2);
u32 dividecalc(u32 v1, u32 v2);

void clearInput() {
    std::cin.clear(); // エラー状態クリア
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 入力バッファをクリア
}

int main() {
    int calcsettings;
    static bool check = true;
    u32 value1;
    u32 value2;
    u32 result;
    
    system("chcp 65001");
    system("cls");
    system("title Hex Calculator");

    do {
        std::cout << "数値1: ";
        std::cin >> std::hex >> value1;
        if(std::cin.fail()) {
            std::cout << "\033[31m!無効な値です \033[m" << "\n\n";
            clearInput();
            continue;
        }

        std::cout << "数値2: ";
        std::cin >> std::hex >> value2;
        if(std::cin.fail()) {
            std::cout << "\033[31m!無効な値です \033[m" << "\n\n";
            clearInput();
            continue;
        }

        std::cout << "計算方法(0: +, 1: -, 2: x, 3: ÷): ";
        std::cin >> calcsettings;
        if(std::cin.fail()) {
            std::cout << "\033[31m!無効な値です \033[m" << "\n\n";
            clearInput();
            continue;
        }

        if(calcsettings >= 0 && calcsettings <= 3) {
            if( value1 != 0 || value2 != 0 ) {
                switch (calcsettings) {
                case 0:
                    result = addcalc(value1, value2);
                    break;
                case 1:
                    result = minuscalc(value1, value2);
                    break;
                case 2:
                    result = multicalc(value1, value2);
                    break;
                case 3:
                    result = dividecalc(value1, value2);
                    break;
                default:
                    std::cout << "\033[31m!無効な値です \033[m" << "\n\n";
                    break;
                }
                std::cout << "計算結果: " << std::uppercase << std::hex << result << "\n\n";
            } else std::cout << "\033[31m!無効な値です \033[m" << "\n\n";
        }
    } while(check);
}

u32 addcalc( u32 v1, u32 v2 ) {
    return v1 + v2;
}

u32 minuscalc( u32 v1, u32 v2 ) {
    return v1 - v2;
}

u32 multicalc( u32 v1, u32 v2 ) {
    return v1 * v2;
}

u32 dividecalc( u32 v1, u32 v2 ) {
    return v1 / v2;
}