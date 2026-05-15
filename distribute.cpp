#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include "queue.h"

using namespace std;

void DISTRIBUTE(int windows, vector<pair<string, int>> visitors) {
    //векторы для хранения распределения и времени занятости
    vector<vector<string>> distribution(windows);
    vector<int> busyTime(windows, 0);
    
    //распределение каждого посетителя
    for (int i = 0; i < visitors.size(); i++) {
        // Находим окно с минимальным временем занятости
        int windowIndex = 0;
        int minTime = busyTime[0];
        
        for (int j = 1; j < windows; j++) {
            if (busyTime[j] < minTime) {
                minTime = busyTime[j];
                windowIndex = j;
            }
        }
        
        // Добавляем посетителя в выбранное окно
        distribution[windowIndex].push_back(visitors[i].first);
        busyTime[windowIndex] += visitors[i].second;
    }
    
    // Выводим результаты
    for (int i = 0; i < windows; i++) {
        cout << "Окно " << (i + 1) << " (" << busyTime[i] << " минут): ";
        
        for (int j = 0; j < distribution[i].size(); j++) {
            cout << distribution[i][j];
            if (j != distribution[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "\n";
    }
}