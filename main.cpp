#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "queue.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    
    cout << "Введите количество окон:\n";
    cout << ">>> ";
    int windows;
    cin >> windows;
    cin.ignore();
    
    if (windows < 1) {
        cout << "Количество окон должно быть больше 0.\n";
        return 1;
    }
    
    vector<pair<string, int>> visitors;
    int talonCounter = 1;
    
    cout << "Доступные команды: ENQUEUE <время>, DISTRIBUTE, EXIT\n";
    
    while (true) {
        cout << ">>> ";
        string inputFromUser;
        getline(cin, inputFromUser);
        
        stringstream ss(inputFromUser);
        vector<string> tokens;
        string token;
        
        while (ss >> token) {
            tokens.push_back(token);
        }
        
        if (tokens.empty()) continue;
        
        string command = tokens[0];
        
        if (command == "EXIT") {
            break;
        }
        else if (command == "ENQUEUE") {
            if (tokens.size() < 2 && stoi(tokens[1]) > 0) {
                cout << "Ошибка ввода!\n";
                continue;
            }
            
            int duration = stoi(tokens[1]);
            string talon = generateTalon(talonCounter);
            visitors.push_back(make_pair(talon, duration));
            cout << talon << "\n";
        }
        else if (command == "DISTRIBUTE") {
            DISTRIBUTE(windows, visitors);
            break;
        }
        else {
            cout << "Неизвестная команда!\n";
        }
    }
    
    return 0;
}