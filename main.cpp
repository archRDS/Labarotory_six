#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "stream.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    
    cout << "Доступные команды: NEW_STUDENTS, SUSPICIOUS, IMMORTAL, TOP-LIST\n";

    cout << "Введите количество запросов (N): ";
    int N;
    if (!(cin >> N) || N <= 0) return 1;
    cin.ignore();
    
    int totalStudents = 0;
    set<int> expulsionList;
    set<int> immortalList;
    
    for (int i = 0; i < N; ++i) {
        cout << ">>> ";
        string line;
        getline(cin, line);
        
        stringstream ss(line);
        vector<string> tokens;
        string token;
        while (ss >> token) tokens.push_back(token);
        
        if (tokens.empty()) continue;
        
        CommandType type = parseCommand(tokens[0]);
        
        switch (type) {
            case CommandType::NEW_STUDENTS: {
                if (tokens.size() < 2) {
                    cout << "Ошибка: Неверный формат команды\n";
                    continue;
                }
                int n = stoi(tokens[1]);
                handleNewStudents(n, totalStudents, expulsionList);
                break;
            }
            case CommandType::SUSPICIOUS: {
                if (tokens.size() < 2) {
                    cout << "Ошибка: Неверный формат команды\n";
                    continue;
                }
                int id = stoi(tokens[1]);
                handleSuspicious(id, totalStudents, expulsionList, immortalList);
                break;
            }
            case CommandType::IMMORTAL: {
                if (tokens.size() < 2) {
                    cout << "Ошибка: Неверный формат команды\n";
                    continue;
                }
                int id = stoi(tokens[1]);
                handleImmortal(id, expulsionList, immortalList);
                break;
            }
            case CommandType::TOP_LIST: {
                handleTopList(expulsionList);
                break;
            }
            default:
                cout << "Неизвестная команда\n";
        }
    }
    
    return 0;
}