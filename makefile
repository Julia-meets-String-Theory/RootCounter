# Install the software
# Install the software

all: install

install: uninstall
	g++ -std=c++17 src/root_counter.cpp -lboost_thread -lboost_system -lpthread -o RootCounter
	g++ -std=c++17 src/tests.cpp -lboost_thread -lboost_system -lpthread --coverage -o src/tests


# Remove the software
# Remove the software

uninstall:
	(rm -f RootCounter && rm -f src/tests)



# Test the software
# Test the software

test:
	chmod +x src/tests
	src/./tests
