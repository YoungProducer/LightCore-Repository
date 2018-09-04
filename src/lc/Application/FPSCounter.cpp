#include "FPSCounter.h"

namespace lc
{

	FPSCounter::FPSCounter()
	{
		m_PreviousTime = glfwGetTime();
		m_DeltaTime = glfwGetTime() - m_PreviousTime;
	}

	void FPSCounter::update()
	{
		m_DeltaTime = m_CurrentTime - m_PreviousTime;
		m_PreviousTime = m_CurrentTime;
	}

	void FPSCounter::calcAverageFPS()
	{
		m_CurrentTime = glfwGetTime();
		m_AverageFPS++;
		if (m_DeltaTime >= 1.0f)
		{
			m_AverageFPS = 0;
		}
	}

	void FPSCounter::calcInstantaneousFPS()
	{
		m_CurrentTime = glfwGetTime();
		m_InstantaneousFPS = 1.0 / (m_DeltaTime);
	}

}