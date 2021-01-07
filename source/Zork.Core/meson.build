core_lib_name = 'zorkcorelib'
core_lib_version = '0.0.1'
core_lib_includes = include_directories('../../include')
source_files = [
	'App.cpp'
]

# Create the static library
core_lib_static = static_library(core_lib_name,
	sources: source_files,
	include_directories: [external_includes, core_lib_includes]
)
core_lib_static_dependency = declare_dependency(
	link_with: core_lib_static,
	include_directories: core_lib_includes
)

# Create the shared library
core_lib_shared = shared_library(core_lib_name,
	sources: source_files,
	include_directories: [external_includes, core_lib_includes],
	version: core_lib_version,
	install: true
)
core_lib_shared_dependency = declare_dependency(
	link_with: core_lib_shared,
	include_directories: core_lib_includes
)