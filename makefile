include list.txt

OutDir = _build
ObjDir = $(OutDir)/obj

Objs := $(CppFiles:.cpp=.o)
Objs := $(subst SourceCode, _build, $(Objs))

OutName = program

program: $(CppFiles)
	g++ $(CppFiles) -o test -D NOREGISTRY -fpermissive -g
#	echo star star: $**
#	echo.

_build/%.o: SourceCode/%.cpp
#	echo malpa: $@
#	echo strzalka: $<
	$(CC) -c  $< -o $@ -D NOREGISTRY -fpermissive
#	echo.
