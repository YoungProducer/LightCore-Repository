#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

namespace lc 
{
	class File
	{
	public:
		static std::string readFile(std::string filePath);
	};
}

