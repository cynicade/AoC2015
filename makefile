day1_1:
	g++ -Wall -Wextra -pedantic -std=c++14 ./Day\ 1/1.cpp ./libraries/readfile.cpp -o day1_1.exe

day1_2:
	g++ -Wall -Wextra -pedantic -std=c++14 ./Day\ 1/2.cpp ./libraries/readfile.cpp -o day1_2.exe

day2_1:
	g++ -Wall -Wextra -pedantic -std=c++14 ./Day\ 2/1.cpp ./libraries/readfile.cpp ./libraries/split.cpp -o day2_1.exe

day2_2:
	g++ -Wall -Wextra -pedantic -std=c++14 ./Day\ 2/2.cpp ./libraries/readfile.cpp ./libraries/split.cpp -o day2_2.exe

day3_1:
	g++ -Wall -Wextra -pedantic -std=c++14 ./Day\ 3/1.cpp ./libraries/readfile.cpp -o day3_1.exe

day3_2:
	g++ -Wall -Wextra -pedantic -std=c++14 ./Day\ 3/1.cpp ./libraries/readfile.cpp ./libraries/contains.h -o day3_1.exe

clean:
	rm *.exe
