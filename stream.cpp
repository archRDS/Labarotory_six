#include "stream.h"
#include <iostream>
#include <algorithm>

void handleNewStudents(int n, int& totalStudents, std::set<int>& expulsionList) {
    if (n > 0) {
        totalStudents += n;
        std::cout << "Добавлено " << n << " студентов\n";
    } else if (n < 0) {
        int toRemove = std::abs(n);
        if (expulsionList.empty()) {
            std::cout << "Ошибка: Нет кандидатов на отчисление\n";
            return;
        }
        if (toRemove > static_cast<int>(expulsionList.size())) {
            std::cout << "Ошибка: невозможно отчислить больше студентов, чем есть их в списках на отчисление\n";
            return;
        }
        
        // Удаляем toRemove студентов из списка (берём первые по порядку номеров)
        auto it = expulsionList.begin();
        for (int i = 0; i < toRemove; ++i) {
            it = expulsionList.erase(it);
        }
        std::cout << "Удалено " << toRemove << " студентов\n";
    }
}

void handleSuspicious(int id, int totalStudents, std::set<int>& expulsionList, const std::set<int>& immortalList) {
    if (id < 1 || id > totalStudents) {
        std::cout << "Ошибка: Студент с номером " << id << " не существует\n";
        return;
    }
    if (expulsionList.count(id)) {
        std::cout << "Ошибка: Студент " << id << " уже является кандидатом на отчисление\n";
        return;
    }
    if (immortalList.count(id)) {
        std::cout << "Ошибка: Студент " << id << " неприкасаемый\n";
        return;
    }
    
    expulsionList.insert(id);
    std::cout << "Студент " << id << " стал кандидатом на отчисление\n";
}

void handleImmortal(int id, std::set<int>& expulsionList, std::set<int>& immortalList) {
    if (!expulsionList.count(id)) {
        std::cout << "Ошибка: Студент " << id << " не может стать неприкасаемым, поскольку он не находится в списках на отчисление\n";
        return;
    }
    
    expulsionList.erase(id);
    immortalList.insert(id);
    std::cout << "Студент " << id << " стал неприкасаемым\n";
}

void handleTopList(const std::set<int>& expulsionList) {
    if (expulsionList.empty()) {
        std::cout << "Список студентов на отчисление пуст\n";
        return;
    }
    
    std::cout << "Список студентов на отчисление: ";
    bool first = true;
    
    for (int id : expulsionList) {
        if (!first) std::cout << ", ";
        std::cout << "Студент " << id;
        first = false;
    }
    std::cout << "\n";
}