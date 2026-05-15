#include <string>
#include "trl.h"

using namespace std;

Type parseCommand(const string& command) {
    if (command == "CREATE_TRL") return Type::CREATE_TRL;
    if (command == "TRLS_IN_STOP") return Type::TRLS_IN_STOP;
    if (command == "STOPS_IN_TRL") return Type::STOPS_IN_TRL;
    if (command == "TRLS") return Type::TRLS;
    return Type::UNKNOWN;
}