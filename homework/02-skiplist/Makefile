TEST_FILES = ../thirdparty/gtest/gtest-all.cc ../thirdparty/gtest/gtest_main.cc
HDR = include/skiplist/node.h include/skiplist/iterator.h include/skiplist/skiplist.h
SRC = src/skiplist_impl.cpp src/skiplist_test.cpp


all: tests.done

skiplist_test: $(SRC) $(HDR)
	g++ -O1 -g -std=c++11 -o skiplist_test $(SRC) -I include -I../thirdparty $(TEST_FILES) -lpthread

tests.done: skiplist_test
	./skiplist_test
	touch tests.done
