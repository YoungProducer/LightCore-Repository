#include "shader.h"

namespace lc { namespace graphics {

	Shader::Shader()
	{
		m_Source = new Source();
	}

	Shader::Shader(std::string vert, std::string frag)
	{

		m_Source = new Source;
		m_Source->m_VertexShaderSrc		= File::readFile(vert);
		m_Source->m_FragmentShaderSrc	= File::readFile(frag);

		m_ShaderID = ShaderFactory::CreateShader(m_Source->m_VertexShaderSrc, m_Source->m_FragmentShaderSrc);
	}

	void Shader::enable()
	{
		glUseProgram(m_ShaderID);
	}

	void Shader::disable()
	{
		glUseProgram(0);
	}

} }