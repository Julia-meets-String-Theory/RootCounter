all: install

clean: uninstall

uninstall: unistall-boost-from-source
	(rm -f partial_blowup.o && rm -f partialBlowups)

uninstall-boost-from-source:
	(cd boost && rm -r -f boost_1_77_0 && rm -r -f library)

install-with-local-boost: install-boost-from-source \
	install-with-links-to-local-boost

install-boost-from-source: uninstall-boost-from-source
	(cd boost && wget -O boost_1_77_0.tar.gz https://sourceforge.net/projects/boost/files/boost/1.77.0/boost_1_77_0.tar.gz/download; tar xzvf boost_1_77_0.tar.gz; rm boost_1_77_0.tar.gz)
	(cd boost && mkdir -p library)
	(cd boost/boost_1_77_0 && ./bootstrap.sh --prefix=$$(realpath ../library) && ./b2 --prefix=$$(realpath ../library) --threading=multi install)

DIR := ${CURDIR}
P1 := ${DIR}/boost/library/lib
P2 := ${DIR}/boost/library/include

install-with-links-to-local-boost: uninstall
	(g++ -std=gnu++14 -c -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread partial_blowup.cpp && g++ -std=gnu++14 -o partialBlowups partial_blowup.o -Wl,-rpath=${P1} -I${P2} -L${P1} -lboost_thread -lboost_system -lpthread)

install: uninstall
	(g++ -std=gnu++14 -c -lboost_thread -lboost_system -lpthread partial_blowup.cpp && g++ -std=gnu++14 -o partialBlowups partial_blowup.o -lboost_thread -lboost_system -lpthread)
