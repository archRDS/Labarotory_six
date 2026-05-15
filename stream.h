#ifndef STREAM_H
#define STREAM_H
#pragma once

#include <string>
#include <vector>
#include <set>

enum class CommandType {
    NEW_STUDENTS,
    SUSPICIOUS,
    IMMORTAL,
    TOP_LIST,
    UNKNOWN
};


CommandType parseCommand(const std::string& command);

// Обработчики команд
void handleNewStudents(int n, int& totalStudents, std::set<int>& expulsionList);
void handleSuspicious(int id, int totalStudents, std::set<int>& expulsionList, const std::set<int>& immortalList);
void handleImmortal(int id, std::set<int>& expulsionList, std::set<int>& immortalList);
void handleTopList(const std::set<int>& expulsionList);

#endif