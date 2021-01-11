#pragma once

#include <Zork.Core/Rendering/IRenderer.hpp>

namespace Zork
{
	class OpenGLRenderer : public IRenderer
	{
	public:
		OpenGLRenderer(IApplicationContext* appContext) :
			IRenderer(appContext) {}

	public:
		void render() override;
	};
} // namespace Zork
