#include "stream.h"

CommandType parseCommand(const std::string& command) {
    if (command == "NEW_STUDENTS") return CommandType::NEW_STUDENTS;
    if (command == "SUSPICIOUS")   return CommandType::SUSPICIOUS;
    if (command == "IMMORTAL")     return CommandType::IMMORTAL;
    if (command == "TOP-LIST")     return CommandType::TOP_LIST;
    return CommandType::UNKNOWN;
}