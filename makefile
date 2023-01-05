# Install the software
# Install the software

all: install

install: uninstall
	#(cd src/ && g++ -std=c++17 root_counter.cpp -lboost_thread -lboost_system -lpthread -o RootCounter)
	#(cd src/ && g++ -std=c++17 tests.cpp -fprofile-arcs -ftest-coverage -lboost_thread -lboost_system -lpthread -o tests)
	(g++ -std=c++17 src/tests.cpp -lboost_thread -lboost_system -lpthread --coverage -o src/tests)


# Remove the software
# Remove the software

uninstall:
	(rm -f src/RootCounter && rm -f src/tests)



# Test the software
# Test the software

test:
	chmod +x src/tests
	src/./tests
