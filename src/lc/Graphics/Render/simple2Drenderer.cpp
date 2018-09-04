#include "simple2Drenderer.h"

namespace lc { namespace graphics {

	void Simple2Drenderer::submit(const Renderable2D* renderable2D)
	{
		m_RendererQueue.push_back(renderable2D);
	}

	void Simple2Drenderer::flush()
	{
		while (!m_RendererQueue.empty())
		{
			const Renderable2D* renderable = m_RendererQueue.front();
			renderable->getVertexArray()->bind();
			renderable->getIndexBuffer()->bind();

			ShaderManager::setUniformMatrix4f(&renderable->getShader(), "ml_matrix", glm::translate(glm::mat4(1.0f), renderable->getPosition()));
			glDrawElements(GL_TRIANGLES, renderable->getIndexBuffer()->getCount(), GL_UNSIGNED_SHORT, nullptr);

			renderable->getIndexBuffer()->unbind();
			renderable->getVertexArray()->unbind();

			m_RendererQueue.pop_front();

		}
	}

} }