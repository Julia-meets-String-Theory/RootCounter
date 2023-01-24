# Set variables for linking against local boost
# Set variables for linking against local boost

DIR := ${CURDIR}
P1 := ${DIR}/boost/library/lib
P2 := ${DIR}/boost/library/include


# Install the software
# Install the software

all: install

install: uninstall
	g++ -std=c++17 src/root_counter.cpp -lboost_thread -lboost_system -lpthread -o RootCounter

install-boost: uninstall-boost
	(cd boost && wget -O boost_1_81_0.tar.gz https://sourceforge.net/projects/boost/files/boost/1.81.0/boost_1_81_0.tar.gz/download; tar xzvf boost_1_81_0.tar.gz; rm boost_1_81_0.tar.gz)
	(cd boost && mkdir -p library)
	(cd boost/boost_1_81_0 && ./bootstrap.sh --prefix=$$(realpath ../library) && ./b2 --prefix=$$(realpath ../library) --threading=multi install)

install_lb: uninstall
	g++ -std=c++17 src/root_counter.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread -o RootCounter


# Remove the software
# Remove the software

clean: uninstall
	(rm -f tst/basic_test.gcda && rm -f tst/basic_test.gcno)
	(rm -f tst/poly8.gcda && rm -f tst/poly8.gcno)
	(rm -f tst/poly4.gcda && rm -f tst/poly4.gcno)
	(rm -f tst/poly134.gcda && rm -f tst/poly134.gcno)
	(rm -f tst/poly128.gcda && rm -f tst/poly128.gcno)
	(rm -f tst/poly88.gcda && rm -f tst/poly88.gcno)
	(rm -f tst/poly110.gcda && rm -f tst/poly110.gcno)
	(rm -f tst/poly272.gcda && rm -f tst/poly272.gcno)
	(rm -f tst/poly387.gcda && rm -f tst/poly387.gcno)
	(rm -f tst/poly798.gcda && rm -f tst/poly798.gcno)
	(rm -f tst/poly254.gcda && rm -f tst/poly254.gcno)
	(rm -f tst/result.txt && rm -f tst/unsorted_setups.txt)

uninstall:
	rm -f RootCounter
	rm -f tst/basic_test
	rm -f tst/poly8
	rm -f tst/poly4
	rm -f tst/poly134
	rm -f tst/poly128
	rm -f tst/poly88
	rm -f tst/poly110
	rm -f tst/poly272
	rm -f tst/poly387
	rm -f tst/poly798
	rm -f tst/poly254

uninstall-boost:
	rm -r -f boost/boost_1_81_0
	rm -r -f boost/library


# Test the software against system boost
# Test the software against system boost

basic_test:
	g++ -std=c++17 tst/basic_test.cpp -lboost_thread -lboost_system -lpthread --coverage -o tst/basic_test
	chmod +x tst/basic_test
	tst/./basic_test

simple_root_counting:
	g++ -std=c++17 tst/simple_root_counting.cpp -lboost_thread -lboost_system -lpthread --coverage -o tst/simple_root_counting
	chmod +x tst/simple_root_counting
	tst/./simple_root_counting

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

poly110_test:
	g++ -std=c++17 tst/poly110.cpp -lboost_thread -lboost_system -lpthread --coverage -o tst/poly110
	chmod +x tst/poly110
	tst/./poly110

poly272_test:
	g++ -std=c++17 tst/poly272.cpp -lboost_thread -lboost_system -lpthread --coverage -o tst/poly272
	chmod +x tst/poly272
	tst/./poly272

poly387_test:
	g++ -std=c++17 tst/poly387.cpp -lboost_thread -lboost_system -lpthread --coverage -o tst/poly387
	chmod +x tst/poly387
	tst/./poly387

poly798_test:
	g++ -std=c++17 tst/poly798.cpp -lboost_thread -lboost_system -lpthread --coverage -o tst/poly798
	chmod +x tst/poly798
	tst/./poly798

poly254_test:
	g++ -std=c++17 tst/poly254.cpp -lboost_thread -lboost_system -lpthread --coverage -o tst/poly254
	chmod +x tst/poly254
	tst/./poly254


# Test the software against local boost
# Test the software against local boost

basic_test_lb:
	g++ -std=c++17 tst/basic_test.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread --coverage -o tst/basic_test
	chmod +x tst/basic_test
	tst/./basic_test

simple_root_counting_lb:
	g++ -std=c++17 tst/simple_root_counting.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread --coverage -o tst/simple_root_counting
	chmod +x tst/simple_root_counting
	tst/./simple_root_counting

poly8_test_lb:
	g++ -std=c++17 tst/poly8.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread --coverage -o tst/poly8
	chmod +x tst/poly8
	tst/./poly8

poly4_test_lb:
	g++ -std=c++17 tst/poly4.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread --coverage -o tst/poly4
	chmod +x tst/poly4
	tst/./poly4

poly134_test_lb:
	g++ -std=c++17 tst/poly134.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread --coverage -o tst/poly134
	chmod +x tst/poly134
	tst/./poly134

poly128_test_lb:
	g++ -std=c++17 tst/poly128.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread --coverage -o tst/poly128
	chmod +x tst/poly128
	tst/./poly128

poly88_test_lb:
	g++ -std=c++17 tst/poly88.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread --coverage -o tst/poly88
	chmod +x tst/poly88
	tst/./poly88

poly110_test_lb:
	g++ -std=c++17 tst/poly110.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread --coverage -o tst/poly110
	chmod +x tst/poly110
	tst/./poly110

poly272_test_lb:
	g++ -std=c++17 tst/poly272.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread --coverage -o tst/poly272
	chmod +x tst/poly272
	tst/./poly272

poly387_test_lb:
	g++ -std=c++17 tst/poly387.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread --coverage -o tst/poly387
	chmod +x tst/poly387
	tst/./poly387

poly798_test_lb:
	g++ -std=c++17 tst/poly798.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread --coverage -o tst/poly798
	chmod +x tst/poly798
	tst/./poly798

poly254_test_lb:
	g++ -std=c++17 tst/poly254.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread --coverage -o tst/poly254
	chmod +x tst/poly254
	tst/./poly254
