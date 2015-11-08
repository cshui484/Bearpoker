CXX        := g++-4.8
#CXX        := gcc
CXXFLAGS   := -pedantic -std=c++11 -Wall
LDFLAGS    := -lgtest -lgtest_main -pthread
GCOV       := gcov-4.8
GCOVFLAGS  := -fprofile-arcs -ftest-coverage
GPROF      := gprof
GPROFFLAGS := -pg
VALGRIND   := valgrind

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f RunBearpoker
	rm -f RunBearpoker.tmp
	rm -f TestBearpoker
	rm -f TestBearpoker.tmp
	rm -f solution
	rm -f *~

config:
	git config -l

scrub:
	make  clean
	rm -f  Bearpoker.log
	rm -rf bearpoker-tests
	rm -rf html
	rm -rf latex

status:
	make clean
	@echo
	git branch
	git remote -v
	git status

test: RunBearpoker.tmp TestBearpoker.tmp

solution: solution.cpp
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) solution.cpp -o solution

shi: shi.cpp
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) shi.cpp -o shi

#RunBearpoker: Bearpoker.h Bearpoker.c++ RunBearpoker.c++
#	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) Bearpoker.c++ RunBearpoker.c++ -o RunBearpoker
RunBearpoker: Bearpoker.c++
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) Bearpoker.c++ -o RunBearpoker

RunBearpoker.tmp: RunBearpoker
	./RunBearpoker < RunBearpoker.in > RunBearpoker.tmp
	diff -w RunBearpoker.tmp RunBearpoker.out

#TestBearpoker: Bearpoker.h Bearpoker.c++ TestBearpoker.c++
TestBearpoker: TestBearpoker.c++
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) TestBearpoker.c++ -o TestBearpoker $(LDFLAGS)

TestBearpoker.tmp: TestBearpoker
	$(VALGRIND) ./TestBearpoker                                       >  TestBearpoker.tmp 2>&1
	$(GCOV) -b Bearpoker.c++     | grep -A 5 "File 'Bearpoker.c++'"     >> TestBearpoker.tmp
	$(GCOV) -b TestBearpoker.c++ | grep -A 5 "File 'TestBearpoker.c++'" >> TestBearpoker.tmp
	cat TestBearpoker.tmp
