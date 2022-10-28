build:
	rm -f tests
	g++ -std=c++11 tests.cpp -o tests -lgtest -lgtest_main -lpthread

run:
	./tests

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./tests
