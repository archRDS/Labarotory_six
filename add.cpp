#include "sclad.h"
#include <iostream>

void ADD(std::map<std::string, std::pair<std::string, int>>& sclad, 
         const std::string& nameOfProduct, const int& quantityProduct, const std::string& address) {
    if (sclad.find(address) == sclad.end()) {
        std::cout << "Ошибка: несуществующий адрес!\n";
        return;
    }
    if (!sclad[address].first.empty()) {
        std::cout << "Ошибка: Ячейка " << address << " занята товаром " << sclad[address].first << "\n";
        return;
    }
    if (quantityProduct <= 0 || quantityProduct > MAX_CELL_CAPACITY) {
        std::cout << "Ошибка: Превышена вместимость ячейки (максимум " << MAX_CELL_CAPACITY << ") или количество должно быть > 0.\n";
        return;
    }

    sclad[address] = {nameOfProduct, quantityProduct};
    std::cout << "Добавлено " << quantityProduct << " " << nameOfProduct << " в " << address << "\n";
}