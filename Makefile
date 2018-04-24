PROG = ppl
CC = g++
CPPFLAGS = -O0 -g -Wall -pedantic -lboost_system -I /usr/include/boost/algorithm
OBJS = main.o adicionarInstrucao.o verDepend.o imprimirPipeline.o calcularPipeline.o assembly.o

$(PROG) : $(OBJS)
	$(CC) $(OBJS) -o bin/$(PROG)

main.o :
	$(CC) $(CPPFALGS) -c src/main.cpp

adicionarInstrucao.o : include/adicionarInstrucao.hpp
	$(CC) $(CPPFLAGS) -c src/adicionarInstrucao.cpp 

imprimirPipeline.o : include/imprimirPipeline.hpp
	$(CC) $(CPPFLAGS) -c src/imprimirPipeline.cpp 

verDepend.o : include/verDepend.hpp
	$(CC) $(CPPFLAGS) -c src/verDepend.cpp 

calcularPipeline.o : include/calcularPipeline.hpp
	$(CC) $(CPPFLAGS) -c src/calcularPipeline.cpp

assembly.o : include/assembly.hpp
	$(CC) $(CPPFLAGS) -c src/assembly.cpp 

move:
	mv *.o build/
clean:
	rm -f build/*.o
