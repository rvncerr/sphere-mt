TEST_FILES = ../thirdparty/gtest/gtest-all.cc ../thirdparty/gtest/gtest_main.cc ../thirdparty/backward-cpp-1.3/backward.cpp
HDR = include/skiplist/node.h include/skiplist/iterator.h include/skiplist/skiplist.h
TEST_SRC = test/skiplist_test.cpp


all: tests.done

skiplist_test: $(TEST_SRC) $(HDR)
	g++ -O1 -g -std=c++11 -o skiplist_test -I include -I../thirdparty $(TEST_SRC) $(TEST_FILES) -lpthread -lbfd

tests.done: skiplist_test
	./skiplist_test
	touch tests.done
