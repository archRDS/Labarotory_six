#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "trl.h"

using namespace std;

void CREATE_TRL(map<string, vector<string>>& trls,
                map<string, vector<string>>& stops,
                const vector<string>& tokens) {
    if (tokens.size() < 4) {
        cout << "Ошибка: Неверная команда\n";
        return;
    }
    
    string trl = tokens[1];
    int count = stoi(tokens[2]);
    
    if (trls.find(trl) != trls.end()) {
        cout << "Ошибка: Троллейбус с именем " << trl << " уже создан\n";
        return;
    }
    
    if (count < 2) {
        cout << "Ошибка: Троллейбус не может быть создан менее чем с двумя остановками\n";
        return;
    }
    
    if (tokens.size() != 3 + count) {
        cout << "Ошибка: Неверное количество остановок\n";
        return;
    }
    
    vector<string> route;
    for (int i = 3; i < tokens.size(); i++) {
        if (find(route.begin(), route.end(), tokens[i]) != route.end()) {
            cout << "Ошибка: Троллейбус не может проходить через одну остановку дважды\n";
            return;
        }
        route.push_back(tokens[i]);
    }
    
    trls[trl] = route;
    
    for (int i = 0; i < route.size(); i++) {
        stops[route[i]].push_back(trl);
    }
    
    cout << "Троллейбус " << trl << " создан\n";
}