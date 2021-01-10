external_lib_dir = join_paths(meson.current_source_dir(), 'libs')
external_includes = include_directories('include')

os = build_machine.system()
architecture = build_machine.cpu_family()
os_arch = os + '-' + architecture

cpp = meson.get_compiler('cpp')

opengl_lib = dependency('gl')

if os == 'windows'
	# On Windows we will use the precompiled binaries included in this repository
	glfw_lib = cpp.find_library('glfw3', dirs: [
		join_paths(external_lib_dir, os_arch, 'glfw')
	])
	sdl2_lib = cpp.find_library('SDL2', dirs: [
		join_paths(external_lib_dir, os_arch, 'SDL2')
	])
	sdl2_mixer_lib = cpp.find_library('SDL2_mixer', dirs: [
		join_paths(external_lib_dir, os_arch, 'SDL2_mixer')
	])
elif os == 'linux' or os == 'darwin'
	# On Linux/Darwin operating systems we will search for the external dependencies
	# TODO: We could add a fallback to precompiled binaries contained within the repository
	glfw_lib = dependency('glfw3')
	sdl2_lib = dependency('SDL2')
	sdl2_mixer_lib = dependency('SDL2_mixer')
else
	error('Unknown build machine os/architecture: [' + os + '/' + architecture + ']')
endif

# glfw_lib = cpp.find_library('SDL2', dirs: [join_paths(meson.current_source_dir(), 'externals/sdl/lib/')])