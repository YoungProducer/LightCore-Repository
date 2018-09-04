#include "File.h"

namespace lc 
{
	std::string File::readFile(std::string filePath)
	{
		filePath;

		std::ifstream stream(filePath);
		std::string line;
		std::stringstream ss;

		while (!stream.eof())
		{
			std::getline(stream, line);
			ss << line << "\n";
		}

		return ss.str();
	}
}