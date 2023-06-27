test:fileread.o filewrite.o main.o
	g++ -o test fileread.o filewrite.o main.o
fileread.o:
	g++ -c fileread.cpp
filewrite.o:
	g++ -c filewrite.cpp
main.o:
	g++ -c main.cpp
clean:
	rm *.o test