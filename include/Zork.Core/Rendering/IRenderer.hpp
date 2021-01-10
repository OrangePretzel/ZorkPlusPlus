#pragma once

namespace Zork
{
	/* pure virtual */ class IRenderer
	{
	public:
		virtual ~IRenderer() {}

	public:
		virtual void render() = 0;
	};

	/* pure virtual */ class IApplicationContext
	{
	public:
		virtual ~IApplicationContext() {}

	public:
		virtual bool hasAppRequestedClose() = 0;
		virtual void update() = 0;
	};
} // namespace Zork
