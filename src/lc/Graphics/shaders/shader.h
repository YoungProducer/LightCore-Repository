#pragma once

#include "../../Utils/File.h"
#include "shaderFactory.h"

namespace lc { namespace graphics {

	class Shader
	{
	private:
		struct Source
		{
			std::string m_VertexShaderSrc;
			std::string m_FragmentShaderSrc;
		};

		Source* m_Source;
		
		unsigned int m_ShaderID;
	public:
		Shader();
		Shader(std::string vert, std::string frag);
		~Shader() { glDeleteProgram(m_ShaderID); };

		void enable();
		void disable();

	public:
		inline void setVertexShaderSrc(std::string& src) { m_Source->m_VertexShaderSrc = src; };
		inline const std::string& getVertexShaderSrc() const { return m_Source->m_VertexShaderSrc; };
		
		inline void setFragmentShaderSrc(std::string& src) { m_Source->m_FragmentShaderSrc = src; };
		inline const std::string& getFragmnetShaderSrc() const { return m_Source->m_FragmentShaderSrc; };

		inline void setProgram(unsigned int& shader) { m_ShaderID = shader; };
		inline const unsigned int& getProgram() const { return m_ShaderID; };
	};

} }
