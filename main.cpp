#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include "trl.h"



using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    
    map<string, vector<string>> trls;
    map<string, vector<string>> stops;
    
    cout << "Доступные команды: TRLS," << endl;
    cout << "CREATE_TRL <номер> <кол-во остановок> <остановки>," << endl;
    cout << "TRLS_IN_STOP <название остановки>," << endl;
    cout << "STOPS_IN_TRL <номер троллейбуса>. \n";


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
        
        Type type = parseCommand(tokens[0]);
        
        if (type == Type::CREATE_TRL) {
            CREATE_TRL(trls, stops, tokens);
        }
        else if (type == Type::TRLS_IN_STOP) {
            if (tokens.size() < 2) {
                cout << "Ошибка: Неверная команда\n";
                continue;
            }
            TRLS_IN_STOP(stops, tokens[1]);
        }
        else if (type == Type::STOPS_IN_TRL) {
            if (tokens.size() < 2) {
                cout << "Ошибка: Неверная команда\n";
                continue;
            }
            STOPS_IN_TRL(trls, stops, tokens[1]);
        }
        else if (type == Type::TRLS) {
            TRLS(trls);
        }
        else {
            cout << "Неизвестная команда\n";
        }
    }
    
    return 0;
}