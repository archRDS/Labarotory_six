#include <sstream>
#include <string>
#include <iomanip>
#include "queue.h"

using namespace std;

string generateTalon(int& counter) {
    stringstream ss;
    ss << "T" << setw(3) << setfill('0') << counter;
    counter++;
    return ss.str();
}