

all:
	make cmake
	make build

cmake:
	mkdir -p build.make
	cd build.make && cmake -DBOOST_ROOT="~/work/boost" ..

build:
	cd build.make && make
