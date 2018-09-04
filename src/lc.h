#pragma once

#include <thread>
#include <chrono>

#include "lc\Graphics\buffers\buffer.h"
#include "lc\Graphics\buffers\indexBuffer.h"
#include "lc\Graphics\buffers\vertexArray.h"

#include "lc\Graphics\shaders\shaderManager.h"

#include "lc\Graphics\Render\renderer2D.h"
#include "lc\Graphics\Render\renderable2D.h"
#include "lc\Graphics\Render\simple2Drenderer.h"

#include "lc\Graphics\camera\camera.h"
#include "lc\Graphics\camera\FPSCamera.h"
#include "lc\Graphics\camera\TPSCamera.h"

#include "lc\Application\FPSCounter.h"
#include "lc\Application\Window.h"
#include "lc\Application\input.h"

#include "lc\maths\maths.h"

#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <glm\gtc\matrix_transform.hpp>
