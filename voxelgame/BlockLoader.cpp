#include "BlockLoader.h"


BlockLoader::BlockLoader()
{
}

std::vector<std::string> BlockLoader::read_files()
{

	const std::string directory = "blocks";
	HANDLE dir;
	WIN32_FIND_DATA file_data;

	if ((dir = FindFirstFile((directory + "/*").c_str(), &file_data)) == INVALID_HANDLE_VALUE)
		std::cout << "ERROR!!!!! AHHHHH!!!!! NOOOOO!!!!!!! PLZ WORK!!! NO!!!!!!!" << std::endl;
	do {
		const std::string file_name = file_data.cFileName;
		const std::string full_file_name = directory + "/" + file_name;
		const bool is_directory = (file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;

		if (file_name[0] == '.')
			continue;

		if (is_directory)
			continue;

		//out.push_back(full_file_name);
	} while (FindNextFile(dir, &file_data));

	FindClose(dir);
	return {"hi","hi"};
}


BlockLoader::~BlockLoader()
{
}
