#CC-compiler:
CC=g++
CFLAGS = -Wall -lao -ldl -lm -lncurses



OBJ = main.cpp input.cpp util.cpp cmnd.cpp
all: termseq

termseq: ${OBJ}
	${CC} -o $@ ${CFLAGS} ${OBJ}

.cpp.p:
	${CC} -c $< ${CFlAGS}
