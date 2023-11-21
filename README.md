# ft_printf - Custom Printf Implementation

<p align="center">
  <img src="https://github.com/pmarkaide/meta/raw/master/ft_printf.png" alt="ft_printf Logo" width="600"/>
</p>

## Introduction

This project provides a custom implementation of the `printf` function, supporting the specifiers `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, and `%`. It is developed as part of the printf project at Hive [Helsinki Coding School](https://www.hive.fi/en/), with the primary goal of learning how to work with variadic arguments using `va_list`.

The `va_list` is a type in C used to handle variable argument lists in functions. It provides a mechanism for accessing arguments of variable length in a function, typically used with the `stdarg.h` header. In the context of the `printf` implementation, `va_list` is used to handle variable arguments passed to the function, allowing for flexibility in the number and types of arguments.

Specifiers printers are based on the `libft` project functions ([v1.0.0](https://github.com/pmarkaide/42_libft/releases/tag/v1.0.0)), modified to return an `int` instead of `void`. This make possible to catch `-1` errors when calling `write`. The code is designed to be extensible, allowing for future support of different file descriptors. For now, the file descriptor is set for printing to the screen.

## Contents

- **Source Files:**
  - `ft_printf.c`: Main `printf` implementation.
  - `ft_putformat.c`: Function to handle formatting based on specifiers.
  - `ft_putchar_fd.c`: Function to print a character.
  - `ft_putstr_fd.c`: Function to print a string.
  - `ft_putptr_fd.c`: Function to print a pointer.
  - `ft_putnbr_fd.c`: Function to print a number.
  - `ft_putnbr_fd_uns.c`: Function to print an unsigned number.
  - `ft_putnbr_fd_hex.c`: Function to print a hexadecimal number.

## Implementation

The `ft_printf` function serves as the main entry point. It mimics the standard `printf` by parsing the format string, identifying specifiers, and printing formatted output. The implementation follows a modular design:

- `ft_printf` iterates through the string, printing its characters, until the end or a specifier is found.
- If a specifier is found, the `ft_putformat` function handles formatting based on the specified specifier and calls the corresponding printer functions.
- Specific printer functions (`ft_putchar_fd`, `ft_putstr_fd`, etc.) handle the actual printing.
- All functions return an `int` and handle errors during writing.

At any step of the printing process, if any error arises from the `write` function, `ft_error_w` catches the error and returns a `-1` value that cascades until `ft_printf` and the functions exit.

## Getting Started

To use this `printf` implementation, you must clone the repo and run the makefile

```bash
git clone https://github.com/pmarkaide/42_printf.git ft_printf
cd ft_printf
make
```

Call `ft_printf` in your code as you would with the standard `printf` function.

## Usage Examples
```c
#include "ft_printf.h"

int main() {
    // Example 1: Print integers
    int num = 42;
    ft_printf("Integer: %d\n", num);

    // Example 2: Print strings
    const char *str = "Hello, World!";
    ft_printf("String: %s\n", str);

    // Example 3: Print characters
    char ch = 'A';
    ft_printf("Character: %c\n", ch);

    // Example 4: Print hexadecimal number
    unsigned int hex_num = 0xA5;
    ft_printf("Hexadecimal: %x\n", hex_num);

    // Example 5: Print pointer address
    void *ptr = &num;
    ft_printf("Pointer Address: %p\n", ptr);

    // Example 6: Print percentage sign
    ft_printf("This is a percentage sign: %%\n");

    return 0;
}
```

## Contribution Guidelines

Contributions to this `printf` implementation are welcome! If you find any bugs, feel free to open an issue.

## License

This project is licensed under the [MIT License](https://raw.githubusercontent.com/pmarkaide/42_printf/master/LICENSE).
