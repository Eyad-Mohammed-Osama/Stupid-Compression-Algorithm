#ifndef __COMPRESSION_TEST_HELPER_H__
#define __COMPRESSION_TEST_HELPER_H__

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

extern std::string CharacterToBinary(unsigned char);
extern unsigned char BinaryToCharacter(std::string);
extern void Compress(std::string);
extern void Decompress(std::string);

#endif