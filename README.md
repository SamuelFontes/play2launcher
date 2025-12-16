# play2launcher

A custom .elf launcher for PlayStation 2 built in C using ps2dev toolchain.

## Description

This is a simple "Hello World" launcher application for the PlayStation 2 that demonstrates how to create custom .elf executables using the ps2dev SDK. The launcher initializes the PS2's debug screen and displays a welcome message.

## Prerequisites

Before building this project, you need to have the PS2 development environment installed:

### Installing ps2dev

1. **Clone ps2dev repository:**
   ```bash
   git clone https://github.com/ps2dev/ps2dev.git
   cd ps2dev
   ```

2. **Build and install ps2dev:**
   ```bash
   export PS2DEV=/usr/local/ps2dev
   export PS2SDK=$PS2DEV/ps2sdk
   export PATH=$PATH:$PS2DEV/bin:$PS2DEV/ee/bin:$PS2DEV/iop/bin:$PS2DEV/dvp/bin:$PS2SDK/bin
   
   ./build-all.sh
   ```

3. **Add environment variables to your shell profile:**
   ```bash
   echo "export PS2DEV=/usr/local/ps2dev" >> ~/.bashrc
   echo "export PS2SDK=\$PS2DEV/ps2sdk" >> ~/.bashrc
   echo "export PATH=\$PATH:\$PS2DEV/bin:\$PS2DEV/ee/bin:\$PS2DEV/iop/bin:\$PS2DEV/dvp/bin:\$PS2SDK/bin" >> ~/.bashrc
   source ~/.bashrc
   ```

## Building

Once ps2dev is installed and the environment variables are set:

```bash
make
```

This will generate `play2launcher.elf` which can be run on a PlayStation 2 console or emulator.

## Cleaning

To remove build artifacts:

```bash
make clean
```

## Running

### On Real Hardware
1. Transfer the `play2launcher.elf` file to your PS2 via USB or network
2. Use a loader like uLaunchELF or wLaunchELF to run the .elf file

### On Emulator (PCSX2)
1. Launch PCSX2
2. Go to File → Run ELF
3. Select `play2launcher.elf`

## Project Structure

- `main.c` - Main source file containing the hello world application
- `Makefile` - Build configuration for ps2dev toolchain
- `.gitignore` - Excludes build artifacts from version control

## License

This project is open source and available for educational purposes.