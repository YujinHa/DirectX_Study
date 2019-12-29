#include<stdio.h>
#include<iostream>

using namespace std;

void makeArray(int **tempArr, int **m, int row, int col, int num)
{
	int k = 0, l = 0;

	for (int i = 0; i < num; i++)
	{
		tempArr[i] = new int[num];
		l = 0;
		for (int j = 0; j < num; j++)
		{
			if (k == row)
				k++;
			if (l == col)
				l++;

			tempArr[i][j] = m[k][l];
			l++;
		}
		k++;
	}
}

int det(int **m, int num)
{
	int sum = 0;

	if (num > 2)
	{
		for (int i = 0; i < num; i++)
		{
			int **tempArray = new int * [num - 1];
			makeArray(tempArray, m, 0, i, num - 1);

			if (i % 2 == 0)
			{
				sum += m[0][i] * det(tempArray, num - 1);
			}
			else
			{
				sum -= m[0][i] * det(tempArray, num - 1);
			}
		}
		//cout << "sum: " << sum << endl;
		return sum;
	}
	else
	{
		//cout << "sum: " << m[0][0] * m[1][1] - m[0][1] * m[1][0] << endl;
		return (m[0][0] * m[1][1] - m[0][1] * m[1][0]);
	}
}

int main()
{
	int **m = new int*[4];
	int **C = new int*[4];
	float **m_inverse = new float*[4];
	int finalDet;

	for (int i = 0; i < 4; i++)
	{
		m[i] = new int[4];
		C[i] = new int[4];
		m_inverse[i] = new float[4];
	}

	m[0][0] = 1;
	m[0][1] = 1;
	m[0][2] = 1;
	m[0][3] = -1;
	m[1][0] = 1;
	m[1][1] = 1;
	m[1][2] = -1;
	m[1][3] = 1;
	m[2][0] = 1;
	m[2][1] = -1;
	m[2][2] = 1;
	m[2][3] = 1;
	m[3][0] = -1;
	m[3][1] = 1;
	m[3][2] = 1;
	m[3][3] = 1;

	cout << "<<Matrix M>>" << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << m[i][j] << "	";
		}
		cout << endl;
	}
	cout << endl;

	finalDet = det(m, 4);

	cout << "Determinant: " << finalDet << endl;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int **tempArray = new int *[3];
			makeArray(tempArray, m, i, j, 3);

			if (((i + 1) + (j + 1)) % 2 == 0)
				C[i][j] = det(tempArray, 3);
			else
				C[i][j] = -det(tempArray, 3);
		}
	}

	cout << endl << "<<inverse>>" << endl;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m_inverse[i][j] = C[j][i] / (float)finalDet;
			cout << m_inverse[i][j] << "	";
		}
		cout << endl;
	}
	return 0;
}
