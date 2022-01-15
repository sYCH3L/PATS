#ifndef UTILITY_H
#define UTILITY_H
/*
    Utility file
    Holds utility structures and functions
*/
#include <iostream>
#include <functional>
#include <fstream>

typedef enum
{
    IPV4 = 0x0,
    IPV6 = 0x1
} Addr_Config;

static void WriteGenericLog(std::string module, std::string msg)
{
    std::cout << "[" << module << "]"
              << " " << msg << std::endl;
}

template <class T>
static std::function<T> GetStdFunction(void* ptr)
{
    return reinterpret_cast<T*>(ptr);
}

static std::vector<std::string> split(std::string str, std::string token)
{

	std::vector<std::string> result;
	while (str.size())
	{
		int index = str.find(token);
		if (index != std::string::npos)
		{
			result.push_back(str.substr(0, index));
			str = str.substr(index + token.size());
			if (str.size() == 0)
				result.push_back(str);
		}
		else
		{
			result.push_back(str);
			str = "";
		}
	}
	return result;
}

static std::string GetDataFromFile(std::string path)
{
	std::ifstream file(path);
	if (file.is_open())
	{
		std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
		file.close();
		return content;
	}
	return "";
}


#endif