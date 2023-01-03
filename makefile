# Install the software
# Install the software

all: install

install: uninstall
	(cd src/ && g++ -std=c++17 root_counter_test.cpp -lboost_thread -lboost_system -lcppunit -o rootCounterTest)
	(cd src/ && g++ -std=c++17 QSM_test.cpp -lboost_thread -lboost_system -lpthread -lcppunit -o QSMTest)
	(cd src/ && g++ -std=c++17 root_counter.cpp -lboost_thread -lboost_system -lpthread -o rootCounter)



# Test the software
# Test the software

alltest: test \
	QSMtest

test:
	chmod +x src/rootCounterTest
	src/./rootCounterTest

QSMtest:
	chmod +x src/QSMTest
	src/./QSMTest



# Remove the software
# Remove the software

clean: uninstall

uninstall:
	(rm -f src/root_counter.o && rm -f src/rootCounter && rm -f src/rootCounterTest && rm -f src/QSMTest)
