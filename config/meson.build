data_dir = get_option('datadir')
vulkan_layer_dir = join_paths(data_dir, 'vulkan', 'implicit_layer.d')

configure_file(
    input: 'vkPost.json.in',
    output: 'vkPost.json',
    configuration: {'ld_lib_dir_vkpost': ld_lib_dir_vkpost},
    install: true,
    install_dir: vulkan_layer_dir
)
