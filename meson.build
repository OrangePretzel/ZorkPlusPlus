project('Zork Plus Plus', 'cpp',
	version : '0.1',
	default_options : [
		'warning_level=3',
		'cpp_std=c++17'
	])

external_includes = include_directories('externals')

subdir('source/Zork.Core')

subdir('tests')

# Create the executable
# This is currently in the root meson.build to ensure the executable gets output in the correct location within the build folder
exe_name = 'zork'
executable(exe_name,
	sources: ['./source/Zork.ConsoleApp/main.cpp'],
	include_directories: [external_includes],
	dependencies: [core_lib_static_dependency],
	install : true
)
