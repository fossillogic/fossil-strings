# Fossil String Library by Fossil Logic

The Fossil String Library is a versatile, platform-independent library designed to provide robust string manipulation capabilities. It supports classic C strings, wide strings, and byte strings, offering a comprehensive solution for handling various string types in both C and C++ projects. The library is built using the Meson build system, ensuring efficient and seamless integration into your development workflow.

## Key Features

- **Cross-Platform Compatibility**: Consistent functionality across Windows, macOS, Linux, and other platforms, making it ideal for a wide range of applications.
- **Rich String Support**: Includes support for classic C strings (`char *`), wide strings (`wchar_t *`), and byte strings, catering to diverse encoding and memory management needs.
- **Modular Design**: Allows easy customization and integration of different string types into your projects, enabling tailored solutions for specific use cases.
- **Efficient Build System**: Utilizes the Meson build system for fast build times and user-friendly configuration, enhancing the development experience.
- **Comprehensive Documentation and Examples**: Provides detailed documentation and examples to help developers get started quickly and effectively.

## Prerequisites

Before using the Fossil String Library, ensure you have the following installed:

- **Meson Build System**: The library relies on Meson. Visit the [official Meson website](https://mesonbuild.com/) for installation instructions if you don't already have it.

## Adding Dependency

### Install Meson Build System

Ensure you have Meson 1.3 or newer installed on your system:

```bash
python -m pip install meson           # to install Meson
python -m pip install --upgrade meson # to upgrade Meson
```

### Adding Wrap File

To include the Fossil String Library in your project, navigate to the `subprojects` directory and create a `fossil-strings.wrap` file with the following content:

```ini
# ======================
# Git Wrap package definition
# ======================
[wrap-git]
url = https://github.com/fossillogic/fossil-strings.git
revision = v0.1.0

[provide]
fossil-string = fossil_strings_dep
```

### Integrate the New Dependency

Add the following line to your `meson.build` file to integrate the Fossil String Library into your project:

```meson
dep = dependency('fossil-strings') // Includes the string library
```

This line retrieves the `fossil-strings` dependency, making it available for use in your project.

## Configure Options

You can configure the build with various options to suit your needs:

- **Running Tests**: To enable tests, use `-Dwith_test=enabled` during configuration.

Example:

```bash
meson setup builddir -Dwith_test=enabled
```

## Contributing and Support

If you wish to contribute, encounter issues, have questions, or want to provide feedback, please open an issue or visit the Fossil Logic Docs for more information.