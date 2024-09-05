.PHONY: build test clean configure all

all: build

configure:
	cmake -S . -B build  -DCMAKE_BUILD_TYPE=Debug

build: configure
	cmake --build build --config Debug --target all --parallel 8

test: build
	./build/unit-tests

clean:
	rm -rf build
