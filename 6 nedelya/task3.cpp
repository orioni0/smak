#include <iostream>

// Основной шаблон
template <int Base, int Exponent>
struct Power {
    static constexpr int value = Base * Power<Base, Exponent - 1>::value;
};

// Частичная специализация для Exponent = 0
template <int Base>
struct Power<Base, 0> {
    static constexpr int value = 1;
};

int main() {
    std::cout << "3^4 = " << Power<3, 4>::value << std::endl;
    std::cout << "2^0 = " << Power<2, 0>::value << std::endl;
    std::cout << "5^3 = " << Power<5, 3>::value << std::endl;

    return 0;
}