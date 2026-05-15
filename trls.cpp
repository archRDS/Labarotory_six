#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "trl.h"

using namespace std;

void TRLS(map<string, vector<string>>& trls) {
    if (trls.empty()) {
        cout << "Ошибка: Троллейбусы не найдены\n";
        return;
    }
    
    for (const pair<const string, vector<string>>& element : trls) {
        cout << "Троллейбус " << element.first << ": ";
        for (int i = 0; i < element.second.size(); i++) {
            cout << element.second[i] << " ";
        }
        cout << "\n";
    }
}