# Install the software
# Install the software

all: install

install: uninstall
	(cd src/ && g++ -std=gnu++14 -c -lboost_thread -lboost_system -lpthread root_counter.cpp && g++ -std=gnu++14 -o rootCounter root_counter.o -lboost_thread -lboost_system -lpthread)
	(cd src/ && g++ -std=c++17 root_counter_test.cpp -lboost_thread -lboost_system -lpthread -lcppunit -o rootCounterTest)

install-with-local-boost: uninstall \
	install-boost-from-source \
	(cd src/ && g++ -std=gnu++14 -c -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread root_counter.cpp && g++ -std=gnu++14 -o rootCounter root_counter.o -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread)

install-boost-from-source: uninstall-boost-from-source
	(cd src/boost && wget -O boost_1_77_0.tar.gz https://sourceforge.net/projects/boost/files/boost/1.77.0/boost_1_77_0.tar.gz/download; tar xzvf boost_1_77_0.tar.gz; rm boost_1_77_0.tar.gz)
	(cd src/boost && mkdir -p library)
	(cd src/boost/boost_1_77_0 && ./bootstrap.sh --prefix=$$(realpath ../library) && ./b2 --prefix=$$(realpath ../library) --threading=multi install)

DIR := ${CURDIR}
P1 := ${DIR}/src/boost/library/lib
P2 := ${DIR}/src/boost/library/include




# Test the software
# Test the software

test:
	chmod +x src/rootCounterTest
	src/./rootCounterTest




# Remove the software
# Remove the software

clean: uninstall

uninstall:
	(rm -r -f src/boost/boost_1_77_0 && rm -r -f src/boost/library)
	(rm -f src/root_counter.o && rm -f src/rootCounter && rm -f src/rootCounterTest)
