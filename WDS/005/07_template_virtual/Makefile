
OBJS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))
TARGET=main

all:${TARGET}

${TARGET}:${OBJS}
	g++ $^ -o $@

%.o:%.cpp
	g++ -c $< -o $@

clean:
	rm ${TARGET} ${OBJS}


