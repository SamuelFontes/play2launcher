#
# Makefile for PS2 Hello World Launcher
#

# Application name
EE_BIN = play2launcher.elf

# Source files
EE_OBJS = main.o

# PS2SDK libraries to link
EE_LIBS = -ldebug -lpad -lkernel

# Compiler flags without debug symbols
EE_CFLAGS = -D_EE -G0 -O2 -Wall

# Include PS2SDK makefiles
all: $(EE_BIN)
	mips64r5900el-ps2-elf-strip $(EE_BIN)

clean:
	rm -f $(EE_OBJS) $(EE_BIN)

# Include PS2SDK build rules
# These will be available when PS2SDK is properly installed
include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal
