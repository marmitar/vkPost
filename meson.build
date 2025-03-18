project('vkPost', ['c', 'cpp'],
    default_options: ['c_std=c11', 'cpp_std=c++2a'],
    version: '0.4.4',
    license: 'Zlib'
)

cpp = meson.get_compiler('cpp')

vkPost_include_path = include_directories('src')

lib_dir = get_option('libdir')
ld_lib_dir_vkpost = join_paths(get_option('prefix'), lib_dir)

if get_option('append_libdir_vkpost')
    lib_dir = join_paths(lib_dir, 'vkpost')
    ld_lib_dir_vkpost = join_paths(ld_lib_dir_vkpost, 'vkpost')
endif

# Create configuration_data object
conf_data = configuration_data()
conf_data.set('ld_lib_dir_vkpost', ld_lib_dir_vkpost)

# This line MUST be AFTER the definition of ld_lib_dir_vkpost and conf_data
subdir('config')

if get_option('with_so')
    subdir('src')
else
    if get_option('with_json')
        warning('with_json is enabled but with_so is disabled; JSON will be installed without a library.')
    endif
endif
