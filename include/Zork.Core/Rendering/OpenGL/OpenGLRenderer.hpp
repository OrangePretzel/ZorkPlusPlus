#pragma once

#include <Zork.Core/Rendering/IRenderer.hpp>

namespace Zork
{
	class OpenGLRenderer : public IRenderer
	{
	public:
		OpenGLRenderer()
		{
		}

	public:
		void render() override;
	};
} // namespace Zork
