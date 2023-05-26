PROG := nhf
SRCDIR := src
BUILDDIR := build
OBJDIR := $(BUILDDIR)/obj
TARGET := $(BUILDDIR)/bin
CXXFLAGS := -Wall -Wextra -pedantic -Werror -std=c++17 -DMEMTRACE
INCLUDE := -I include
LIB := -lSDL2_gfx -lSDL2_image -lSDL2_mixer -lSDL2_ttf
OBJECTS := $(patsubst $(SRCDIR)/%.cpp, %.o, $(filter-out $(SRCDIR)/test.cpp $(SRCDIR)/main.cpp, $(wildcard $(SRCDIR)/*.cpp)))

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

test: CXXFLAGS += -g -DCPORTA
test: setupdirs $(PROG)_test

setupdirs:
	$(MKDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c -o $@ $<

$(PROG): $(OBJDIR)/main.o $(addprefix $(OBJDIR)/, $(OBJECTS))
	$(CXX) $(CXXFLAGS) -o $(TARGET)/$@ $^ $(LIB)

$(PROG)_test: $(OBJDIR)/test.o $(addprefix $(OBJDIR)/, $(OBJECTS))
	$(CXX) $(CXXFLAGS) -o $(TARGET)/$@ $^ $(LIB)
	$(TARGET)/$@

clean:
	$(RM) $(BUILDDIR)
	$(MAKE) -C docs/ clean

uml: setupdirs
	if not exist "build/docs" mkdir "build/docs"
	hpp2plantuml -i "include/*" -o "build/docs/classdiagram.puml" -t docs/diagrams/src/template.puml
	code "build/docs/classdiagram.puml"

pdf: docs/build/dokumentacio.pdf

docs/build/dokumentacio.pdf: 
	$(MAKE) -C docs/

jporta: setupdirs pdf
	if not exist "build/jporta" mkdir "build/jporta"
	$(shell robocopy src build/jporta * /XF main.cpp sdl* )
	$(shell robocopy include build/jporta * /XF sdl* )
	xcopy /Y docs\\build\\dokumentacio.pdf build\\jporta\\

static:
	cppcheck src/ --force --enable=all -i .\src\memtrace.cpp -i .\src\test.cpp -I include/
