<h1 align="center">42_MINITALK_1337</h1>
<p align="center">
  <a href="https://github.com/haytham-hammioui/42_Minitalk_1337">
    <img src="https://raw.githubusercontent.com/ayogun/42-project-badges/refs/heads/main/badges/minitalkm.png" alt="42 Badge">
  </a>
</p>

# minitalk

The `minitalk` project is part of the 42 network curriculum. It is a simple client-server communication program that uses UNIX signals (SIGUSR1 and SIGUSR2) to transmit messages between processes.

## Features

 - Implements inter-process communication (IPC) using signals.
 - Sends and receives ASCII characters bit by bit.
 - Handles multiple clients efficiently.
 - Ensures error handling for invalid PIDs and unexpected signals.
 - Compatible with both Linux and macOS.

## Getting Started

### Installation

1. **Clone the Repository**
   ```sh
   https://github.com/haytham-hammioui/42_Minitalk_1337.git minitalk
   ```

2. **Compile the Program**
   Navigate to the `ft_printf` directory and run `make`. This will generate the `server` and `client` executables.
   ```sh
   cd minitalk
   make
   ```

### Usage

To use `ft_printf` in your C projects:

1. Include the `ft_printf` header file in your C source files.
   ```c
   #include "ft_printf.h"
   ```

2. Compile your project along with `libftprintf.a`. For example:
   ```sh
   gcc -o your_program your_source_files libftprintf.a
   ```

## Contributing

Contributions to `ft_printf` are welcome! Whether you've found a bug, have a feature request, or want to contribute code:

1. Fork the repository.
2. Create a new branch for your changes.
3. Add your contributions.
4. Push your branch and open a pull request against the `ft_printf` repository.
