day1_1:
	g++ -Wall -Wextra -pedantic -std=c++14 ./Day\ 1/1.cpp ./libraries/readfile.cpp -o day1_1.exe

day1_2:
	g++ -Wall -Wextra -pedantic -std=c++14 ./Day\ 1/2.cpp ./libraries/readfile.cpp -o day1_2.exe

clean:
	rm *.exe
