#ifndef SCLAD_H
#define SCLAD_H
#pragma once

#include <map>
#include <string>
#include <utility>

const char ZONE_CHAR = 'A';
const int RACKS_COUNT = 12;
const int SECTIONS_COUNT = 7;
const int SHELVES_COUNT = 4;
const int TOTAL_CAPACITY = 3360;
const int MAX_CELL_CAPACITY = 10;

// Объявления функций
void initialiazeSclad(std::map<std::string, std::pair<std::string, int>>& sclad);
void ADD(std::map<std::string, std::pair<std::string, int>>& sclad, 
         const std::string& nameOfProduct, const int& quantityProduct, const std::string& address);
void REMOVE(std::map<std::string, std::pair<std::string, int>>& sclad, 
            const std::string& nameOfProduct, const int& quantityProduct, const std::string& address);
void INFO(const std::map<std::string, std::pair<std::string, int>>& sclad);

#endif