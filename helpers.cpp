#include "./prototype.h"

std::string CharacterToBinary(unsigned char character) {
    std::string bin = "";
    int ascii = (int)character;
    for (int i = ascii; i > 0; i /= 2) {
        if (i % 2 == 0) {
            bin += "0";
        }
        else if (i % 2 == 1) {
            bin += "1";
        }
    }
    std::reverse(bin.begin(), bin.end());
    if (bin.length() != 8) {
        std::string temp = "";
        int count = bin.length();
        while (count != 8) {
            temp += "0";
            count++;
        }
        bin = temp + bin;
    }
    return bin;
}

unsigned char BinaryToCharacter(std::string bin) {
    int ascii = 0;
    int multiplier = 1;
    for (int i = 0; i < bin.length(); i++) {
        ascii += (bin[i] - 48) * multiplier;
        multiplier *= 2;
    }
    return (char)ascii;
}

void Compress(std::string filename) {
    std::string content = "";
    std::string line;
    std::fstream file;
    file.open(filename, std::ios::in);
    while (getline(file, line)) {
        content += line;
    }
    file.close();
    line = "";
    for (int i = 0; i < content.length(); i++) {
        line += CharacterToBinary(content[i]);
    }

    int temp[2] = {0, 0};
    std::string compressed = "";
    char current = line[0];
    int i = 0;
    while (i <= line.length()) {
        if (line[i] == current) {
            temp[current - 48]++;
            i++;
        }
        else {
            compressed += "[";
            compressed += std::to_string(temp[current - 48]);
            compressed += "]";
            compressed += current;
            temp[0] = temp[1] = 1;
            current = line[i];
            i++;
        }
    }

    std::fstream output_file;
    output_file.open(filename + ".cmp", std::ios::out);
    output_file.write(compressed.c_str(), compressed.length());
    output_file.close();
}

//  The following function is useless ...

void Decompress(std::string filename) {
    std::string content = "";
    std::string line;
    std::fstream file;
    file.open(filename, std::ios::in);
    while (getline(file, line)) {
        content += line;
    }
    std::string decompressed = "";
    std::string length;
    char current;
    for (int i = 0; i < content.length(); i++) {
        if (content[i] == '[') {
            int j = i + 1;
            while (content[j] != ']') {
                length += content[j];
                j++;
            }
            i = j;
        }
    }

    file.close();
}