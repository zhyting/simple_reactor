PROGS = heap_cc

CLEANFILES = *.o

all : ${PROGS}
CXXFLAGS += -g 

heap_cc: heap.o
	${CXX} ${CXXFLAGS} -o $@ $^ 

clean: 
	rm -rf ${PROGS} ${CLEANFILES}