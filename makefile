# Install the software
# Install the software

all: install

install: uninstall
	(g++ -std=gnu++14 -c -lboost_thread -lboost_system -lpthread root_counter.cpp && g++ -std=gnu++14 -o rootCounter root_counter.o -lboost_thread -lboost_system -lpthread)
	(g++ -std=c++17 root_counter_test.cpp -c -lboost_thread -lboost_system -lpthread -lcppunit -o rootCounterTest)

install-with-local-boost: uninstall \
	install-boost-from-source \
	(g++ -std=gnu++14 -c -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread root_counter.cpp && g++ -std=gnu++14 -o rootCounter root_counter.o -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread)

install-boost-from-source: uninstall-boost-from-source
	(cd boost && wget -O boost_1_77_0.tar.gz https://sourceforge.net/projects/boost/files/boost/1.77.0/boost_1_77_0.tar.gz/download; tar xzvf boost_1_77_0.tar.gz; rm boost_1_77_0.tar.gz)
	(cd boost && mkdir -p library)
	(cd boost/boost_1_77_0 && ./bootstrap.sh --prefix=$$(realpath ../library) && ./b2 --prefix=$$(realpath ../library) --threading=multi install)

DIR := ${CURDIR}
P1 := ${DIR}/boost/library/lib
P2 := ${DIR}/boost/library/include




# Test the software
# Test the software

test:
	chmod +x rootCounterTest
	./rootCounterTest




# Remove the software
# Remove the software

clean: uninstall

uninstall: uninstall-boost-from-source
	(rm -f root_counter.o && rm -f rootCounter)
	($(RM) rootCounterTest)

uninstall-boost-from-source:
	(cd boost && rm -r -f boost_1_77_0 && rm -r -f library)
