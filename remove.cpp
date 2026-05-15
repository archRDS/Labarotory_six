#include "sclad.h"
#include <iostream>

void REMOVE(std::map<std::string, std::pair<std::string, int>>& sclad, 
            const std::string& nameOfProduct, const int& quantityProduct, const std::string& address) {
    if (sclad.find(address) == sclad.end()) {
        std::cout << "Ошибка: несуществующий адрес!\n";
        return;
    }
    if (sclad[address].first.empty()) {
        std::cout << "Ошибка: Товар " << nameOfProduct << " не найден в ячейке " << address << "\n";
        return;
    }
    if (sclad[address].first != nameOfProduct) {
        std::cout << "Ошибка: в ячейке " << address << " находится другой товар (" << sclad[address].first << ")!\n";
        return;
    }
    if (quantityProduct > sclad[address].second) {
        std::cout << "Ошибка: недостаточно товаров для удаления (осталось " << sclad[address].second << ")\n";
        return;
    }

    sclad[address].second -= quantityProduct;
    std::cout << "Удалено " << quantityProduct << " " << nameOfProduct << " (остаток: " << sclad[address].second << ")\n";

    if (sclad[address].second == 0) {
        sclad[address].first = "";
    }
}