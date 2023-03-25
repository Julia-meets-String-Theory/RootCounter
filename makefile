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
	mkdir boost
	(cd boost && wget -O boost_1_81_0.tar.gz https://sourceforge.net/projects/boost/files/boost/1.81.0/boost_1_81_0.tar.gz/download; tar xzvf boost_1_81_0.tar.gz; rm boost_1_81_0.tar.gz)
	(cd boost && mkdir -p library)
	(cd boost/boost_1_81_0 && ./bootstrap.sh --prefix=$$(realpath ../library) && ./b2 --prefix=$$(realpath ../library) --threading=multi install)

install_lb: uninstall
	g++ -std=c++17 src/root_counter.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread -o RootCounter


# Remove the software
# Remove the software

clean: uninstall
	(rm -f tst/basic_test.gcda && rm -f tst/basic_test.gcno)
	(rm -f tst/h0_test.gcda && rm -f tst/h0_test.gcno)
	(rm -f tst/simple_root_counting_test.gcda && rm -f tst/simple_root_counting_test.gcno)
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
	(rm -f tst/poly52.gcda && rm -f tst/poly52.gcno)
	(rm -f tst/poly302.gcda && rm -f tst/poly302.gcno)
	(rm -f tst/poly786.gcda && rm -f tst/poly786.gcno)
	(rm -f tst/poly762.gcda && rm -f tst/poly762.gcno)
	(rm -f tst/poly417.gcda && rm -f tst/poly417.gcno)
	(rm -f tst/poly838.gcda && rm -f tst/poly838.gcno)
	(rm -f tst/poly782.gcda && rm -f tst/poly782.gcno)
	(rm -f tst/poly377.gcda && rm -f tst/poly377.gcno)
	(rm -f tst/poly1348.gcda && rm -f tst/poly1348.gcno)
	(rm -f tst/poly882.gcda && rm -f tst/poly882.gcno)
	(rm -f tst/poly1340.gcda && rm -f tst/poly1340.gcno)
	(rm -f tst/poly1879.gcda && rm -f tst/poly1879.gcno)
	(rm -f tst/poly1384.gcda && rm -f tst/poly1384.gcno)
	(rm -f tst/result.txt && rm -f tst/unsorted_setups.txt)

uninstall:
	rm -f RootCounter
	rm -f tst/basic_test
	rm -f tst/h0_test
	rm -f tst/simple_root_counting_test
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
	rm -f tst/poly52
	rm -f tst/poly302
	rm -f tst/poly786
	rm -f tst/poly762
	rm -f tst/poly417
	rm -f tst/poly838
	rm -f tst/poly782
	rm -f tst/poly377
	rm -f tst/poly1348
	rm -f tst/poly882
	rm -f tst/poly1340
	rm -f tst/poly1879
	rm -f tst/poly1384

uninstall-boost:
	rm -r -f boost/boost_1_81_0
	rm -r -f boost/library


# Test the software against system boost
# Test the software against system boost

basic_test:
	g++ -std=c++17 tst/basic_test.cpp -lboost_thread -lboost_system -lpthread --coverage -o tst/basic_test
	chmod +x tst/basic_test
	tst/./basic_test

h0_test:
	g++ -std=c++17 tst/h0_test.cpp -lboost_thread -lboost_system -lpthread --coverage -o tst/h0_test
	chmod +x tst/h0_test
	tst/./h0_test

simple_root_counting_test:
	g++ -std=c++17 tst/simple_root_counting_test.cpp -lboost_thread -lboost_system -lpthread --coverage -o tst/simple_root_counting_test
	chmod +x tst/simple_root_counting_test
	tst/./simple_root_counting_test

poly8_test:
	g++ -std=c++17 tst/poly8.cpp -lboost_thread -lboost_system -lpthread -o tst/poly8
	chmod +x tst/poly8
	tst/./poly8

poly4_test:
	g++ -std=c++17 tst/poly4.cpp -lboost_thread -lboost_system -lpthread -o tst/poly4
	chmod +x tst/poly4
	tst/./poly4

poly134_test:
	g++ -std=c++17 tst/poly134.cpp -lboost_thread -lboost_system -lpthread -o tst/poly134
	chmod +x tst/poly134
	tst/./poly134

poly128_test:
	g++ -std=c++17 tst/poly128.cpp -lboost_thread -lboost_system -lpthread -o tst/poly128
	chmod +x tst/poly128
	tst/./poly128

poly88_test:
	g++ -std=c++17 tst/poly88.cpp -lboost_thread -lboost_system -lpthread -o tst/poly88
	chmod +x tst/poly88
	tst/./poly88

poly110_test:
	g++ -std=c++17 tst/poly110.cpp -lboost_thread -lboost_system -lpthread -o tst/poly110
	chmod +x tst/poly110
	tst/./poly110

poly272_test:
	g++ -std=c++17 tst/poly272.cpp -lboost_thread -lboost_system -lpthread -o tst/poly272
	chmod +x tst/poly272
	tst/./poly272

poly387_test:
	g++ -std=c++17 tst/poly387.cpp -lboost_thread -lboost_system -lpthread -o tst/poly387
	chmod +x tst/poly387
	tst/./poly387

poly798_test:
	g++ -std=c++17 tst/poly798.cpp -lboost_thread -lboost_system -lpthread -o tst/poly798
	chmod +x tst/poly798
	tst/./poly798

poly254_test:
	g++ -std=c++17 tst/poly254.cpp -lboost_thread -lboost_system -lpthread -o tst/poly254
	chmod +x tst/poly254
	tst/./poly254

poly52_test:
	g++ -std=c++17 tst/poly52.cpp -lboost_thread -lboost_system -lpthread -o tst/poly52
	chmod +x tst/poly52
	tst/./poly52

poly302_test:
	g++ -std=c++17 tst/poly302.cpp -lboost_thread -lboost_system -lpthread -o tst/poly302
	chmod +x tst/poly302
	tst/./poly302

poly786_test:
	g++ -std=c++17 tst/poly786.cpp -lboost_thread -lboost_system -lpthread -o tst/poly786
	chmod +x tst/poly786
	tst/./poly786

poly762_test:
	g++ -std=c++17 tst/poly762.cpp -lboost_thread -lboost_system -lpthread -o tst/poly762
	chmod +x tst/poly762
	tst/./poly762

poly417_test:
	g++ -std=c++17 tst/poly417.cpp -lboost_thread -lboost_system -lpthread -o tst/poly417
	chmod +x tst/poly417
	tst/./poly417

poly838_test:
	g++ -std=c++17 tst/poly838.cpp -lboost_thread -lboost_system -lpthread -o tst/poly838
	chmod +x tst/poly838
	tst/./poly838

poly782_test:
	g++ -std=c++17 tst/poly782.cpp -lboost_thread -lboost_system -lpthread -o tst/poly782
	chmod +x tst/poly782
	tst/./poly782

poly377_test:
	g++ -std=c++17 tst/poly377.cpp -lboost_thread -lboost_system -lpthread -o tst/poly377
	chmod +x tst/poly377
	tst/./poly377

poly1348_test:
	g++ -std=c++17 tst/poly1348.cpp -lboost_thread -lboost_system -lpthread -o tst/poly1348
	chmod +x tst/poly1348
	tst/./poly1348

poly882_test:
	g++ -std=c++17 tst/poly882.cpp -lboost_thread -lboost_system -lpthread -o tst/poly882
	chmod +x tst/poly882
	tst/./poly882

poly1340_test:
	g++ -std=c++17 tst/poly1340.cpp -lboost_thread -lboost_system -lpthread -o tst/poly1340
	chmod +x tst/poly1340
	tst/./poly1340

poly1879_test:
	g++ -std=c++17 tst/poly1879.cpp -lboost_thread -lboost_system -lpthread -o tst/poly1879
	chmod +x tst/poly1879
	tst/./poly1879

poly1384_test:
	g++ -std=c++17 tst/poly1384.cpp -lboost_thread -lboost_system -lpthread -o tst/poly1384
	chmod +x tst/poly1384
	tst/./poly1384


# Test the software against local boost
# Test the software against local boost

basic_test_lb:
	g++ -std=c++17 tst/basic_test.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread --coverage -o tst/basic_test
	chmod +x tst/basic_test
	tst/./basic_test

h0_test_lb:
	g++ -std=c++17 tst/h0_test.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread --coverage -o tst/h0_test
	chmod +x tst/h0_test
	tst/./h0_test

simple_root_counting_test_lb:
	g++ -std=c++17 tst/simple_root_counting_test.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread --coverage -o tst/simple_root_counting_test
	chmod +x tst/simple_root_counting_test
	tst/./simple_root_counting_test

poly8_test_lb:
	g++ -std=c++17 tst/poly8.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread -o tst/poly8
	chmod +x tst/poly8
	tst/./poly8

poly4_test_lb:
	g++ -std=c++17 tst/poly4.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread -o tst/poly4
	chmod +x tst/poly4
	tst/./poly4

poly134_test_lb:
	g++ -std=c++17 tst/poly134.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread -o tst/poly134
	chmod +x tst/poly134
	tst/./poly134

poly128_test_lb:
	g++ -std=c++17 tst/poly128.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread -o tst/poly128
	chmod +x tst/poly128
	tst/./poly128

poly88_test_lb:
	g++ -std=c++17 tst/poly88.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread -o tst/poly88
	chmod +x tst/poly88
	tst/./poly88

poly110_test_lb:
	g++ -std=c++17 tst/poly110.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread -o tst/poly110
	chmod +x tst/poly110
	tst/./poly110

poly272_test_lb:
	g++ -std=c++17 tst/poly272.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread -o tst/poly272
	chmod +x tst/poly272
	tst/./poly272

poly387_test_lb:
	g++ -std=c++17 tst/poly387.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread -o tst/poly387
	chmod +x tst/poly387
	tst/./poly387

poly798_test_lb:
	g++ -std=c++17 tst/poly798.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread -o tst/poly798
	chmod +x tst/poly798
	tst/./poly798

poly254_test_lb:
	g++ -std=c++17 tst/poly254.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread -o tst/poly254
	chmod +x tst/poly254
	tst/./poly254

poly52_test_lb:
	g++ -std=c++17 tst/poly52.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread -o tst/poly52
	chmod +x tst/poly52
	tst/./poly52

poly302_test_lb:
	g++ -std=c++17 tst/poly302.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread -o tst/poly302
	chmod +x tst/poly302
	tst/./poly302

poly786_test_lb:
	g++ -std=c++17 tst/poly786.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread -o tst/poly786
	chmod +x tst/poly786
	tst/./poly786

poly762_test_lb:
	g++ -std=c++17 tst/poly762.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread -o tst/poly762
	chmod +x tst/poly762
	tst/./poly762

poly417_test_lb:
	g++ -std=c++17 tst/poly417.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread -o tst/poly417
	chmod +x tst/poly417
	tst/./poly417

poly838_test_lb:
	g++ -std=c++17 tst/poly838.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread -o tst/poly838
	chmod +x tst/poly838
	tst/./poly838

poly782_test_lb:
	g++ -std=c++17 tst/poly782.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread -o tst/poly782
	chmod +x tst/poly782
	tst/./poly782

poly377_test_lb:
	g++ -std=c++17 tst/poly377.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread -o tst/poly377
	chmod +x tst/poly377
	tst/./poly377

poly1348_test_lb:
	g++ -std=c++17 tst/poly1348.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread -o tst/poly1348
	chmod +x tst/poly1348
	tst/./poly1348

poly882_test_lb:
	g++ -std=c++17 tst/poly882.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread -o tst/poly882
	chmod +x tst/poly882
	tst/./poly882

poly1340_test_lb:
	g++ -std=c++17 tst/poly1340.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread -o tst/poly1340
	chmod +x tst/poly1340
	tst/./poly1340

poly1879_test_lb:
	g++ -std=c++17 tst/poly1879.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread -o tst/poly1879
	chmod +x tst/poly1879
	tst/./poly1879

poly1384_test_lb:
	g++ -std=c++17 tst/poly1384.cpp -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread -o tst/poly1384
	chmod +x tst/poly1384
	tst/./poly1384
