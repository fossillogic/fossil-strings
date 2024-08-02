dir = include_directories('.')

fossil_strings_lib = library('fossil-strings',
    files('bstring.c', 'cstring.c', 'wstring.c',
          'bletter.c', 'cletter.c', 'wletter.c'),
    install: true,
    include_directories: dir)

fossil_strings_dep = declare_dependency(
    link_with: [fossil_strings_lib],
    include_directories: dir)
