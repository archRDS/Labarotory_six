#include "sclad.h"
#include <iostream>
#include <iomanip>

void INFO(const std::map<std::string, std::pair<std::string, int>>& sclad) {
    int totalItems = 0;
    int occupiedCount = 0;
    int emptyCount = 0;

    std::cout << std::fixed << std::setprecision(2);

    for (const auto& cell : sclad) {
        int qty = cell.second.second;
        totalItems += qty;
        if (qty > 0) occupiedCount++;
        else emptyCount++;
    }

    double warehousePercent = (static_cast<double>(totalItems) / TOTAL_CAPACITY) * 100.0;
    double zonePercent = (static_cast<double>(totalItems) / TOTAL_CAPACITY) * 100.0; // 1 зона = вся емкость

    std::cout << "Загруженность склада: " << warehousePercent << "%\n";
    std::cout << "Загруженность зоны " << ZONE_CHAR << ": " << zonePercent << "%\n";

    std::cout << "\nЗаполненные ячейки:\n";
    for (const auto& cell : sclad) {
        if (cell.second.second > 0) {
            std::cout << cell.first << ": " << cell.second.first << " (" << cell.second.second << ")\n";
        }
    }

    std::cout << "\nПустые ячейки:\n";
    bool first = true;
    for (const auto& cell : sclad) {
        if (cell.second.second == 0) {
            if (!first) std::cout << ", ";
            std::cout << cell.first;
            first = false;
        }
    }
    std::cout << "\n";
}