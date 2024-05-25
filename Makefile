# Compiler and flags
CC = g++
CXXFLAGS = -std=c++11 -Wall

# Detect the OS
ifeq ($(OS),Windows_NT)
    CXXFLAGS += -I./sdl/include
    LIBRARIES = -L./sdl/lib -lSDL2 -lSDL2_image
    TARGET = game.exe
    RM = del
    COPYDLL = copy
    DLLS = sdl/lib/SDL2.dll sdl/lib/SDL2_image.dll
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Darwin)
        CXXFLAGS += $(shell sdl2-config --cflags)
        LIBRARIES = $(shell sdl2-config --libs) -lSDL2_image
        TARGET = game
        RM = rm -f
        COPYDLL = cp
        DLLS = # No DLLs needed for macOS
    else
        $(error Unsupported OS: $(UNAME_S))
    endif
endif

# Source files
SRCS = $(wildcard src/*.cpp)
OBJS = $(SRCS:.cpp=.o)

# Default rule to build the target
all: $(TARGET)
	@echo "All done."

# Rule to link the object files into the target executable
$(TARGET): $(OBJS)
	@echo "Linking..."
	$(CC) $(OBJS) $(LIBRARIES) -o $@
	@echo "Copying DLLs..."
	$(COPYDLL) $(DLLS) .

# Rule to compile the source files into object files
%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

# Rule to clean up the build artifacts
clean:
	$(RM) $(TARGET) $(OBJS)

# Rule to run the program
run: $(TARGET)
	./$(TARGET)
