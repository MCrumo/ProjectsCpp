OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: main.o
	g++ -o program.exe main.o
	
main.o: main.cc
	g++ -c main.cc $(OPCIONS)
	
clear:
	rm *.exe
	rm *.o
