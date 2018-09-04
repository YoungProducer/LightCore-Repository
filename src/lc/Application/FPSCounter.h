#pragma once

#include "../include/glfw3.h"

namespace lc
{

	class FPSCounter
	{
	private:

		double m_CurrentTime;
		double m_PreviousTime;
		double m_DeltaTime;

		double m_AverageFPS;
		double m_InstantaneousFPS;

	public:

		FPSCounter();

		void update();

		void calcAverageFPS();
		void calcInstantaneousFPS();

	public:

		inline const double& getDeltaTime() const { return m_DeltaTime; };
		inline const double& getAverageFPS() const { if (m_DeltaTime >= 1.0f) return m_AverageFPS; return 0; };
		inline const double& getInstantaneousFPS() { return m_InstantaneousFPS; };
	};

}
