dyn: main.cpp input_array.cpp matrix.cpp
	g++ -o $@ $^ -Wall -Wextra -std=c++11
