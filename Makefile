#CC-compiler:
CC=g++
CFLAGS = -Wall -lao -ldl -lm -lncurses



OBJ = main.cpp seq.cpp env.cpp #input.cpp util.cpp cmnd.cpp env.cpp curs.cpp
all: termseq

termseq: ${OBJ}
	${CC} -o $@ ${CFLAGS} ${OBJ}

.cpp.p:
	${CC} -c $< ${CFlAGS}
