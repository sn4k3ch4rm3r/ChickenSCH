RM := rmdir /S /Q
PROG := nhf
SRCDIR := src
BUILDDIR := build
OBJDIR := $(BUILDDIR)/obj
TARGET := $(BUILDDIR)/bin
CXXFLAGS := -Wall -std=c++17 -DMEMTRACE
INCLUDE := -I include
LIB := -L"$(MINGW_LIB)" -lmingw32 -lSDL2main -lSDL2 -lSDL2_gfx -lSDL2_image -lSDL2_mixer -lSDL2_ttf -luser32 -lgdi32 -lwinmm -ldxguid
OBJECTS := $(patsubst $(SRCDIR)/%.cpp, %.o, $(wildcard $(SRCDIR)/*.cpp))


default: CXXFLAGS += -O3
default: INCLUDE += -I"$(SDL_INCLUDE)" $(LIB)
default: setupdirs $(PROG)

debug: CXXFLAGS += -g
debug: INCLUDE += -I"$(SDL_INCLUDE)" $(LIB)
debug: setupdirs $(PROG)

test: CXXFLAGS := -std=c++17 -Wall -Werror -g -DCPORTA -DMEMTRACE -D_JPORTA_STAT -fprofile-arcs -ftest-coverage -O0
test: setupdirs $(PROG)

setupdirs:
	if not exist "$(BUILDDIR)" mkdir $(BUILDDIR)
	if not exist "$(OBJDIR)" mkdir "$(OBJDIR)"
	if not exist "$(TARGET)" mkdir "$(TARGET)"
	xcopy assets\ build\bin\ /Y

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c -o $@ $<

$(PROG): $(addprefix $(OBJDIR)/, $(OBJECTS))
	$(CXX) $(CXXFLAGS) -o $(TARGET)/$@ $^ 

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
	$(shell robocopy src build/jporta * /XF memtrace.cpp )
	$(shell robocopy include build/jporta * /XF memtrace.h gtest_lite.h )
	$(shell cd build/jporta && zip ../jporta.zip ./*)

static:
	cppcheck src/ --force --enable=all -i .\src\memtrace.cpp -i .\src\test.cpp -I include/
