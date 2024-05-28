# Compiler and flags
CC = g++
CXXFLAGS = -std=c++11 -Wall

# Detect the OS
ifeq ($(OS),Windows_NT)
    CXXFLAGS += -I./sdl/include -I./headers
    LIBRARIES = -L./sdl/lib -lSDL2 -lSDL2_image
    TARGET = build/game.exe
    RM = del
    COPYDLL = copy
    DLLS = sdl/lib/SDL2.dll sdl/lib/SDL2_image.dll
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Darwin)
        CXXFLAGS += $(shell sdl2-config --cflags) -I./headers
        LIBRARIES = $(shell sdl2-config --libs) -lSDL2_image
        TARGET = build/game
        RM = rm -f
        COPYDLL = cp
        DLLS = # No DLLs needed for macOS
    else
        $(error Unsupported OS: $(UNAME_S))
    endif
endif

# Source and build directories
SRCDIR = src
BUILDDIR = build

# Source files
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRCS))

# Default rule to build the target
all: $(TARGET)
	@echo "All done."

# Rule to link the object files into the target executable
$(TARGET): $(OBJS)
	@echo "Linking..."
	$(CC) $(OBJS) $(LIBRARIES) -o $@
ifeq ($(OS),Windows_NT)
	@echo "Copying DLLs..."
	$(COPYDLL) $(DLLS) $(BUILDDIR)
endif

# Rule to compile the source files into object files
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp | $(BUILDDIR)
	@echo "Compiling $<..."
	$(CC) $(CXXFLAGS) -c $< -o $@ -I./headers

# Create the build directory if it doesn't exist
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Rule to clean up the build artifacts
clean:
	@echo "Cleaning up..."
	$(RM) $(TARGET) $(OBJS)

# Rule to run the program
run: $(TARGET)
	@echo "Running $(TARGET)..."
	./$(TARGET)
