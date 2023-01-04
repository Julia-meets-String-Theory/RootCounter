# Install the software
# Install the software

all: install

install: uninstall
	(cd src/ && g++ -std=c++17 root_counter.cpp -lboost_thread -lboost_system -lpthread -o RootCounter)
	(cd src/ && g++ -std=c++17 basic_test.cpp -lboost_thread -lboost_system -lcppunit -o BasicTest)
	(cd src/ && g++ -std=c++17 QSM6_test.cpp -lboost_thread -lboost_system -lpthread -lcppunit -o QSM6Test)
	(cd src/ && g++ -std=c++17 QSM10_test.cpp -lboost_thread -lboost_system -lpthread -lcppunit -o QSM10Test)



# Remove the software
# Remove the software

clean: uninstall

uninstall:
	(rm -f src/RootCounter && rm -f src/BasicTest && rm -f src/QSM6Test && rm -f src/QSM10Test)



# Test the software
# Test the software

test: basic_test \
	QSM6_test \
	QSM10_Test

basic_test:
	chmod +x src/BasicTest
	src/./BasicTest

QSM6_test:
	chmod +x src/QSM6Test
	src/./QSM6Test

QSM10_test:
	chmod +x src/QSM10Test
	src/./QSM10Test
