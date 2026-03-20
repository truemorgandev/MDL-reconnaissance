#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

void loadEnv(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Could not open the file: " << filename << std::endl;
        return;
    }

    while (std::getline(file, line)) {
        
        if (line.empty() || line[0] == '#') continue;

        size_t pos = line.find('=');
        if (pos == std::string::npos) continue; 

        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1);

        // Trim spaces
        key.erase(key.find_last_not_of(" \n\r\t") + 1);
        value.erase(0, value.find_first_not_of(" \n\r\t"));

        
        setenv(key.c_str(), value.c_str(), 1);
    }

    file.close();
}