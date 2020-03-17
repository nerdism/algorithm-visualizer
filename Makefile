
CXX=g++

HEADER_FILES=$(wildcard include/*.h include/sorts/*.h)

SRC_FILES=$(wildcard src/*.cc src/sorts/*.cc)

OBJ_FILES=${SRC_FILES:.cc=.o}

all: bin/main

run: bin/main
	./bin/main

bin/main: $(OBJ_FILES) 
	$(CXX) -Wall -Iinclude $^ -o $@
	@echo "[+] executable has been created" 

main_tut: main.cc
	$(CXX) $^ -DUSE_TUT_MODE -o $@

%.o: %.cc $(HEADER_FILES)
	$(CXX) -Wall -Iinclude -c $< -o $@

clean:
	rm src/*.o src/sorts/*.o bin/main
