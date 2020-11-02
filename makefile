all: sudoku

sudoku: sudoku.o sudokuboard.o stack.o
	g++ -o sudoku sudoku.o sudokuboard.o stack.o

stack.o: stack.cc stack.h
	g++ -c stack.cc

sudoku.o: sudoku.cc sudokuboard.h stack.h
	g++ -c sudoku.cc

sudokuboard.o: sudokuboard.cc sudokuboard.h
	g++ -c sudokuboard.cc

clean:
	rm -f *.o sudoku *~
