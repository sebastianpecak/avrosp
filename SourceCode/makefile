# -------------------------------------------
# List of source files to compile.
# -------------------------------------------
Sources = 				\
	AVRBootloader.cpp	\
	AVRDevice.cpp		\
	AVRInSystemProg.cpp	\
	AVRProgrammer.cpp	\
	CommChannel.cpp		\
	ErrorMsg.cpp		\
	HEXParser.cpp		\
	JobInfo.cpp			\
	main.cpp			\
	SerialPort.cpp		\
	Utility.cpp			\
	XMLParser.cpp

Objects = $(Sources:.cpp=.o)
OutName = avrosp-linux
Defines = -DNOREGISTRY -DLINUX
COptions = -c -fpermissive --std=c++0x -g

# -------------------------------------------
# Link.
# -------------------------------------------
build: $(Objects)
	g++ $(Objects) -o $(OutName)

# -------------------------------------------
# Compile.
# -------------------------------------------
%.o:%.cpp
	g++ $(COptions) $(Defines) -o $@ $<

# -------------------------------------------
# Clean.
# -------------------------------------------
clean:
	rm *.o -f
	rm $(OutName) -f
