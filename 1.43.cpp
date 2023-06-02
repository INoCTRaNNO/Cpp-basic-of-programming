//1.43 Даны числа h и m, где h – количество часов, m – количество минут некоторого момента времени. Найдите угол между часовой и минутной стрелками в этот момент времени.
#include <iostream>
#include <math.h>

int main() {
	int h = 6;
	int m = 0;
	int hg = 30 * h;
	int mg = 6 * m;
	std::cout << abs(hg-mg) << std::endl; 
}

