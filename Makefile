PROG := nhf
SRCDIR := src
BUILDDIR := build
OBJDIR := $(BUILDDIR)/obj
TARGET := $(BUILDDIR)/bin
CXXFLAGS := -Wall -Werror -std=c++11
INCLUDE := -I include
LIB := -lSDL2_gfx -lSDL2_image -lSDL2_mixer -lSDL2_ttf
OBJECTS := $(patsubst $(SRCDIR)/%.cpp, %.o, $(wildcard $(SRCDIR)/*.cpp))

# Windows
ifdef OS
	RM := rmdir /S /Q
	INCLUDE += -I"$(SDL_INCLUDE)"
	LIB := -L"$(MINGW_LIB)" -lmingw32 -lSDL2main -lSDL2 $(LIB) -luser32 -lgdi32 -lwinmm -ldxguid
	MKDIR := if not exist "$(BUILDDIR)" mkdir $(BUILDDIR) & if not exist "$(OBJDIR)" mkdir "$(OBJDIR)" & if not exist "$(TARGET)" mkdir "$(TARGET)"
	COPYASSETS := xcopy assets\ build\bin\assets\ /Y
# Linux
else
	RM := rm -rf
	INCLUDE += `sdl2-config --cflags`
	LIB := -lm `sdl2-config --libs` $(LIB)
	MKDIR := mkdir -p $(BUILDDIR); mkdir -p $(OBJDIR); mkdir -p $(TARGET)
	COPYASSETS := cp assets/ build/bin/ -r -f
endif

default: CXXFLAGS += -O3
default: setupdirs $(PROG)

debug: CXXFLAGS += -g
debug: setupdirs $(PROG)

setupdirs:
	$(MKDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c -o $@ $<

$(PROG): $(addprefix $(OBJDIR)/, $(OBJECTS))
	$(CXX) $(CXXFLAGS) -o $(TARGET)/$@ $^ $(LIB)

clean:
	$(RM) $(BUILDDIR)

uml:
	hpp2plantuml -i "include/*" -o "docs/classdiagram.puml"