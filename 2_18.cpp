#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	int m[4][4] = { {1,2,3,4}, {1,2,3,4}, {1,2,3,4}, {1,2,3,4} };
	int n[4][4] = { {2,4,6,8 }, { 3,6,9,12 }, { 1,1,1,1 }, { 2,1,2,1 }
};
	int** mult = new int*[4];
	int** multT = new int*[4];

	for (int i = 0; i < 4; i++)
	{
		mult[i] = new int[4];
		multT[i] = new int[4];

		for (int j = 0; j < 4; j++)
		{
			mult[i][j] = 0;
			multT[i][j] = 0;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				mult[i][j] += m[i][k] * n[k][j];
			}

			cout << mult[i][j] << "	";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			multT[i][j] = mult[j][i];
			cout << multT[i][j] << "	";
		}
		cout << endl;
	}
	return 0;
}