#pragma once

#include "../include/glew.h"

#include <iostream>
#include <string>

namespace lc { namespace graphics {

	class ShaderFactory
	{
	private:

	public:
		static unsigned int CompileShader(std::string vert, std::string frag, unsigned int type);
		static unsigned int CreateShader(std::string vert, std::string frag);

	};

} }
