#ifndef QUEUE_H
#define QUEUE_H
#pragma once

#include <string>
#include <vector>
#include <utility>

// Генерация номера талона
std::string generateTalon(int& counter);

// Распределение посетителей по окнам
void DISTRIBUTE(int windows, std::vector<std::pair<std::string, int>> visitors);

#endif