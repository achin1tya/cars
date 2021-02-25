#include<iostream>
#include<math.h>
int main()
{
	int mat[5][5];
	int fI, fJ;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			std::cin >> mat[i][j];
		}
	}
	bool flag = false;

	for (int i = 0; i < 5; i++)
	{
		for(int j = 0;j<5;j++)
		{
			if (mat[i][j] == 1)
			{
				fI = i; fJ = j;
				flag = true;
				break;
			}

		}
		if (flag)
			break;

	}

	std::cout << abs(fI - 2) + abs(fJ - 2);

}