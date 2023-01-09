# Install the software
# Install the software

all: install

install: uninstall
	g++ -std=c++17 src/root_counter.cpp -lboost_thread -lboost_system -lpthread -o RootCounter


# Remove the software
# Remove the software

clean: uninstall
	(rm -f tst/basic_test.gcda && rm -f tst/basic_test.gcno)
	(rm -f tst/poly8.gcda && rm -f tst/poly8.gcno)
	(rm -f tst/poly4.gcda && rm -f tst/poly4.gcno)
	(rm -f tst/poly134.gcda && rm -f tst/poly134.gcno)
	(rm -f tst/poly128.gcda && rm -f tst/poly128.gcno)
	(rm -f tst/poly88.gcda && rm -f tst/poly88.gcno)

uninstall:
	(rm -f RootCounter)
	(rm -f tst/basic_test)
	(rm -f tst/poly8)
	(rm -f tst/poly4)
	(rm -f tst/poly134)
	(rm -f tst/poly128)
	(rm -f tst/poly88)


# Test the software
# Test the software

basic_test:
	g++ -std=c++17 tst/basic_test.cpp -lboost_thread -lboost_system -lpthread --coverage -o tst/basic_test
	chmod +x tst/basic_test
	tst/./basic_test

poly8_test:
	g++ -std=c++17 tst/poly8.cpp -lboost_thread -lboost_system -lpthread --coverage -o tst/poly8
	chmod +x tst/poly8
	tst/./poly8

poly4_test:
	g++ -std=c++17 tst/poly4.cpp -lboost_thread -lboost_system -lpthread --coverage -o tst/poly4
	chmod +x tst/poly4
	tst/./poly4

poly134_test:
	g++ -std=c++17 tst/poly134.cpp -lboost_thread -lboost_system -lpthread --coverage -o tst/poly134
	chmod +x tst/poly134
	tst/./poly134

poly128_test:
	g++ -std=c++17 tst/poly128.cpp -lboost_thread -lboost_system -lpthread --coverage -o tst/poly128
	chmod +x tst/poly128
	tst/./poly128

poly88_test:
	g++ -std=c++17 tst/poly88.cpp -lboost_thread -lboost_system -lpthread --coverage -o tst/poly88
	chmod +x tst/poly88
	tst/./poly88

