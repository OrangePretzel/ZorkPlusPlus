#pragma once

namespace Zork
{
	/* pure virtual */ class IApplicationContext
	{
	public:
		virtual ~IApplicationContext() {}

	public:
		virtual bool hasAppRequestedClose() = 0;
		virtual void getContextSize(int& width, int& height) = 0;
		virtual void update() = 0;

		virtual void swapBuffers() = 0;
	};

	/* pure virtual */ class IRenderer
	{
	public:
		IRenderer(IApplicationContext* appContext) :
			_appContext(appContext) {}
		virtual ~IRenderer() {}

	public:
		virtual void render() = 0;

	protected:
		inline IApplicationContext* getAppContext() { return _appContext; }

	private:
		IApplicationContext* _appContext;
	};
} // namespace Zork
