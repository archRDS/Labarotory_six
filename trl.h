#ifndef TRL_H
#define TRL_H
#pragma once

#include <map>
#include <string>
#include <vector>

enum class Type {
    CREATE_TRL,
    TRLS_IN_STOP,
    STOPS_IN_TRL,
    TRLS,
    UNKNOWN
};

Type parseCommand(const std::string& command);

void CREATE_TRL(std::map<std::string, std::vector<std::string>>& trls,
                std::map<std::string, std::vector<std::string>>& stops,
                const std::vector<std::string>& tokens);

void TRLS_IN_STOP(std::map<std::string, std::vector<std::string>>& stops,
                  const std::string& stop);

void TRLS(std::map<std::string, std::vector<std::string>>& trls);

void STOPS_IN_TRL(std::map<std::string, std::vector<std::string>>& trls,
                  std::map<std::string, std::vector<std::string>>& stops,
                  const std::string& trl);

#endif