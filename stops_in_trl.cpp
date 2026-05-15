#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "trl.h"

using namespace std;

void STOPS_IN_TRL(map<string, vector<string>>& trls,
                  map<string, vector<string>>& stops,
                  const string& trl) {
    if (trls.find(trl) == trls.end()) {
        cout << "Ошибка: Троллейбус " << trl << " не найден\n";
        return;
    }
    
    cout << "Остановки троллейбуса " << trl << ": ";
    for (int i = 0; i < trls[trl].size(); i++) {
        cout << trls[trl][i] << " ";
    }
    cout << "\n";
    
    for (int i = 0; i < trls[trl].size(); i++) {
        string stop = trls[trl][i];
        cout << "Остановка " << stop << ": ";
        
        bool found = false;
        for (int j = 0; j < stops[stop].size(); j++) {
            if (stops[stop][j] != trl) {
                cout << stops[stop][j] << " ";
                found = true;
            }
        }
        
        if (!found) {
            cout << "-";
        }
        cout << "\n";
    }
}