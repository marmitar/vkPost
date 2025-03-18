# <img style="width: 50px; height: 50px;" src="https://github.com/KowabungaOfficial/vkPost/blob/main/vkPost_Logo.svg"> vkPost
vkPost is a Vulkan post processing layer to enhance the visuals of games.

Currently, the build in effects are:
- Contrast Adaptive Sharpening
- Denoised Luma Sharpening
- Fast Approximate Anti-Aliasing
- Enhanced Subpixel Morphological Anti-Aliasing
- 3D color LookUp Table

## Disclaimer
This project was originally [DadSchoorse's](https://github.com/DadSchoorse/).

vkPost is a continuation of where vkBasalt left off.

## Building from Source

### Dependencies
Before building, you will need:
- GCC >= 9
- X11 development files
- glslang
- SPIR-V Headers
- Vulkan Headers

### Building

**These instructions use `--prefix=/usr`, which is generally not recommened since vkPost will be installed in directories that are meant for the package manager. The alternative is not setting the prefix, it will then be installed in `/usr/local`. But you need to make sure that `ld` finds the library since /usr/local is very likely not in the default path.** 

In general, prefer using distro provided packages.

```
git clone https://github.com/KowabungaOfficial/vkPost.git
cd vkPost
```

#### 64bit

```
meson setup --buildtype=release --prefix=/usr builddir
ninja -C builddir install
```
#### 32bit

Make sure that `PKG_CONFIG_PATH=/usr/lib32/pkgconfig` and `--libdir=lib32` are correct for your distro and change them if needed. On Debian based distros you need to replace `lib32` with `lib/i386-linux-gnu`, for example.
```
ASFLAGS=--32 CFLAGS=-m32 CXXFLAGS=-m32 PKG_CONFIG_PATH=/usr/lib32/pkgconfig meson setup --prefix=/usr --buildtype=release --libdir=lib32 -Dwith_json=false builddir.32
ninja -C builddir.32 install
```

## Packaging status

Coming Soon once adoption picks up

## Usage
Enable the layer with the environment variable.

### Standard
When using the terminal or an application (.desktop) file, execute:
```ini
ENABLE_VKPOST=1 yourgame
```

### Lutris
With Lutris, follow these steps below:
1. Right click on a game, and press `configure`.
2. Go to the `System options` tab and scroll down to `Environment variables`.
3. Press on `Add`, and add `ENABLE_VKPOST` under `Key`, and add `1` under `Value`.

### Steam
With Steam, edit your launch options and add:
```ini
ENABLE_VKPOST=1 %command% 
```

## Configure

Settings like the CAS sharpening strength can be changed in the config file.
The config file will be searched for in the following locations:
* a file set with the environment variable`VKPOST_CONFIG_FILE=/path/to/vkPost.conf`
* `vkPost.conf` in the working directory of the game
* `$XDG_CONFIG_HOME/vkPost/vkPost.conf` or `~/.config/vkPost/vkPost.conf` if `XDG_CONFIG_HOME` is not set
* `$XDG_DATA_HOME/vkPost/vkPost.conf` or `~/.local/share/vkPost/vkPost.conf` if `XDG_DATA_HOME` is not set
* `/etc/vkPost.conf`
* `/etc/vkPost/vkPost.conf`
* `/usr/share/vkPost/vkPost.conf`

If you want to make changes for one game only, you can create a file named `vkPost.conf` in the working directory of the game and change the values there.

#### Quick override
To override some of the default config options the `VKPOST_CONFIG` env var can be used, e.g. `VKPOST_CONFIG='effects=fxaa:cas;casSharpness=1.0'`.
The separator is `;`

#### Reshade Fx shaders

To run reshade fx shaders e.g. shaders from the [reshade repo](https://github.com/crosire/reshade-shaders), you have to set `reshadeTexturePath` and `reshadeIncludePath` to the matching dirctories from the repo. To then use a specific shader you need to set a custom effect name to the shader path and then add that effect name to `effects` like every other effect.

```ini
effects = colorfulness:denoise

colorfulness = /home/user/reshade-shaders/Shaders/Colourfulness.fx
denoise = /home/user/reshade-shaders/Shaders/Denoise.fx
reshadeTexturePath = /home/user/reshade-shaders/Textures
reshadeIncludePath = /home/user/reshade-shaders/Shaders
```

#### Ingame Input

The [HOME key](https://en.wikipedia.org/wiki/Home_key) can be used to disable and re-enable the applied effects, the key can also be changed in the config file. This is based on X11 so it won't work on pure wayland. It **should** however at least not crash without X11.


#### Debug Output

The amount of debug output can be set with the `VKPOST_LOG_LEVEL` env var, e.g. `VKPOST_LOG_LEVEL=debug`. Possible values are: `trace, debug, info, warn, error, none`.

By default the logger outputs to stderr, a file as output location can be set with the `VKPOST_LOG_FILE` env var, e.g. `VKPOST_LOG_FILE="vkPost.log"`.


## FAQ

#### Why is it called vkPost?
Based on vkBasalt, but takes Basalt out for Post which hints at Post-Processing
#### Does vkPost work with dxvk and vkd3d?
Yes.
#### Will there be a openGl version?
If someone comes in and adds it I will happily include it.
#### Will there be a GUI in the future?
Not for this project, but if anyone wants to make one they are free to.
#### Can you make reshade shaders work?
If someone wants to add it they are free to.
