project('vkPost', ['c', 'cpp'], default_options: ['c_std=c11', 'cpp_std=c++2a'])

cpp = meson.get_compiler('cpp')

vkPost_include_path = ''

lib_dir = get_option('libdir')
ld_lib_dir_vkpost = ''

if get_option('append_libdir_vkpost')
    lib_dir = join_paths(lib_dir, 'vkpost')
    ld_lib_dir_vkpost = get_option('prefix') + '/$LIB/vkpost/'
endif

if get_option('with_so')
    subdir('src')
endif

if get_option('with_json')
    subdir('config')
endif
