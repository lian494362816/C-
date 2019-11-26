
TARGET=test

OBJS=main.o person.o

all:${TARGET}

${TARGET}:${OBJS}
	g++ $^ -o $@

%.o:%.cpp
	g++ -c $< -o $@

clean:
	rm *.o ${TARGET}
