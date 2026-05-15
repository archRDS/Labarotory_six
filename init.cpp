#include "sclad.h"
#include <string>

void initialiazeSclad(std::map<std::string, std::pair<std::string, int>>& sclad) {
    for (int rack = 1; rack <= RACKS_COUNT; ++rack) {
        for (int section = 1; section <= SECTIONS_COUNT; ++section) {
            for (int shelf = 1; shelf <= SHELVES_COUNT; ++shelf) {
                std::string address = std::string(1, ZONE_CHAR) + 
                                      std::to_string(rack) + 
                                      std::to_string(section) + 
                                      std::to_string(shelf);
                sclad[address] = {"", 0};
            }
        }
    }
}