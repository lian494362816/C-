
OBJS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))
LIB_OBJS := $(filter-out main.o, ${OBJS})

LIB_NAME=libHuman.so
TARGET=main

LD_FLAGS += -lHuman

CPP_FLAGS += -fPIC

all: ${LIB_NAME} ${TARGET} 

${LIB_NAME}:${LIB_OBJS}
	g++ -shared ${CPP_FLAGS} -o $@ $^

${TARGET}:main.o ${LIB_NAME}
	g++ $^ -o $@

%.o:%.cpp
	g++ -c ${CPP_FLAGS} $< -o $@

clean:
	rm -f ${TARGET} ${OBJS} ${LIB_NAME}


