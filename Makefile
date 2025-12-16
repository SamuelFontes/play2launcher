#
# Makefile for PS2 Hello World Launcher
#

# Application name
EE_BIN = play2launcher.elf

# Source files
EE_OBJS = main.o

# PS2SDK libraries to link
EE_LIBS = -ldebug -lkernel

# Include PS2SDK makefiles
all: $(EE_BIN)

clean:
	rm -f $(EE_OBJS) $(EE_BIN)

# Include PS2SDK build rules
# These will be available when PS2SDK is properly installed
include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal
