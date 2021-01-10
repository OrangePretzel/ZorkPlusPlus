exe_name = 'zork'
source_files = [
	'main.cpp',
]

executable(
	exe_name,
	sources: source_files,
	include_directories: [external_includes],
	dependencies: [
		core_lib_static_dependency,

		opengl_lib,
		glfw_lib,
		sdl2_lib,
		sdl2_mixer_lib,
	],
	install : true
)
