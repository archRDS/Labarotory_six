#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "sclad.h"

int main() {
    std::map<std::string, std::pair<std::string, int>> sclad;
    initialiazeSclad(sclad);

    std::cout << "Доступные команды: ADD, REMOVE, INFO, EXIT\n";
    std::cout << "Формат: ADD <наименование> <количество> <адрес>\n";
    std::cout << "Формат: REMOVE <наименование> <количество> <адрес>\n\n";

    std::string line;
    while (std::cout << ">>> " && std::getline(std::cin, line)) {
        std::istringstream iss(line);
        std::string command;
        iss >> command;

        if (command == "EXIT") break;
        if (command.empty()) continue;

        if (command == "ADD" || command == "REMOVE") {
            std::vector<std::string> tokens;
            std::string token;
            while (iss >> token) tokens.push_back(token);

            if (tokens.size() < 3) {
                std::cout << "Ошибка: неверный формат команды! Требуется: <название> <кол-во> <адрес>\n";
                continue;
            }

            std::string address = tokens.back();
            int quantity = 0;
            try {
                quantity = std::stoi(tokens[tokens.size() - 2]);
            } catch (...) {
                std::cout << "Ошибка: количество должно быть целым числом!\n";
                continue;
            }

            std::string name;
            for (size_t i = 0; i < tokens.size() - 2; ++i) {
                if (i > 0) name += " ";
                name += tokens[i];
            }

            if (command == "ADD") {
                ADD(sclad, name, quantity, address);
            } else {
                REMOVE(sclad, name, quantity, address);
            }
        } else if (command == "INFO") {
            INFO(sclad);
        } else {
            std::cout << "Неизвестная команда!\n";
        }
    }
    return 0;
}