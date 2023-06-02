//1.21 Найдите наименьшее число, оканчивающееся на 5, такое, что, если перенести его последнюю цифру в начало, то число увеличится в пять раз.
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

int main() {
	int number = 7;
	while (true) {
		int a = number % 10;
		int b = number / 10;
		std::string s = std::to_string(a) + std::to_string(b);
		int i = std::atoi(s.c_str());
	
		if (i == number * 5) {
			cout << number << endl ;
			break;
		}
		//std::this_thread::sleep_for(std::chrono::nanoseconds(5000000000));
		number += 10;
		
	}
}	