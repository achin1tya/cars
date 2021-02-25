#include<iostream>
#include <vector>

struct point
{
	int x; int y; int z;
	point(int a, int b, int c)
	{
		x = a; y = b; z = c;
	}
};

int main()
{
	std::string name;
	std::cin >> name;
	std::cout << name;
	/*int num;
	std::vector<point> points;

	std::cin >> num;
	
	for (int i = 0; i < num; i++)
	{
		int tx, ty, tz;
		std::cin >> tx >> ty >> tz;
		point tP(tx, ty, tz);
		points.push_back(tP);
	}

	int tX = 0, tY = 0, tZ = 0;

	for (auto i : points)
	{
		tX += i.x;
		tY += i.y;
		tX += i.z;
	}

	if (tX == 0 && tY == 0 && tZ == 0)
	{
		std::cout << "YES";
	}
	else
	{
		std::cout << "NO";
	}*/

	return 0;
}