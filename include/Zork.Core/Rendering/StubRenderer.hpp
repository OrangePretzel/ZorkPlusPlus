#pragma once

#include <Zork.Core/Rendering/IRenderer.hpp>

namespace Zork
{
	class StubRenderer : IRenderer
	{
	public:
		inline void render() override
		{
			// Do nothing (it's a stub!)
		}
	};
} // namespace Zork
