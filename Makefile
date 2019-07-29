all:
	g++ -g -std=c++11 -o main sort.cpp

.PTHOY: clean
clean:
	rm -f main
