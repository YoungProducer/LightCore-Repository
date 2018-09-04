#include "shaderFactory.h"

namespace lc { namespace graphics {

	unsigned int ShaderFactory::CompileShader(std::string vert, std::string frag, unsigned int type)
	{
		unsigned int id = glCreateShader(type);
		const char* src;

		if (type == GL_VERTEX_SHADER)
			src = vert.c_str();
		else if (type == GL_FRAGMENT_SHADER)
			src = frag.c_str();

		glShaderSource(id, 1, &src, nullptr);
		glCompileShader(id);

		int result;
		glGetShaderiv(id, GL_COMPILE_STATUS, &result);

		if (result == GL_FALSE)
		{
			int lenght;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &lenght);
			char* message = (char*)alloca(lenght * sizeof(char));
			glGetShaderInfoLog(id, lenght, &lenght, message);
			std::cout << "Failed to compile " <<
				(type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << std::endl;
			std::cout << message << std::endl;
			glDeleteShader(id);
			return 0;
		}

		return id;
	}

	unsigned int ShaderFactory::CreateShader(std::string vert, std::string frag)
	{
		unsigned int program = glCreateProgram();
		unsigned int vs = CompileShader(vert, frag, GL_VERTEX_SHADER);
		unsigned int fs = CompileShader(vert, frag, GL_FRAGMENT_SHADER);

		glAttachShader(program, vs);
		glAttachShader(program, fs);
		glLinkProgram(program);
		glValidateProgram(program);

		glDeleteShader(vs);
		glDeleteShader(fs);

		return program;
	}

} }