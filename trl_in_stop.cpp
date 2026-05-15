#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "trl.h"

using namespace std;

void TRLS_IN_STOP(map<string, vector<string>>& stops, const string& stop) {
    if (stops.find(stop) == stops.end()) {
        cout << "Ошибка: Остановка " << stop << " не найдена\n";
        return;
    }
    
    cout << "Троллейбусы на остановке " << stop << ": ";
    for (int i = 0; i < stops[stop].size(); i++) {
        cout << stops[stop][i];
        if (i != stops[stop].size() - 1) {
            cout << ", ";
        }
    }
    cout << "\n";
}