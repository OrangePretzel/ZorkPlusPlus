exe_name = 'Zork.Core.Tests'
source_files = [
	'main.cpp',
	'AppTests.cpp',
]

executable(exe_name,
	sources: source_files,
	include_directories: [external_includes],
	dependencies: [core_lib_static_dependency],
	install : true
)
