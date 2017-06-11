#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <iostream>

class BlockLoader
{
private:
	std::vector<std::string> read_files();
public:
	BlockLoader();
	~BlockLoader();
};

