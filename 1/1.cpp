#include <iostream>
using namespace std;
const int N = 3, M = 4; 
int main()
{
	setlocale(LC_ALL, "Russian");
	int i, j, k, ind;
	float A[N][M] = { 3,-1,2,7,1,-3,-1,-1,4,-1,2,8 }, f, max, obm;
	int X[N];
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
			cout << " " << A[i][j] << "\t";
		cout << endl;
	}
	cout << endl;
	for (i = 0; i < M - 2; i++)
	{
		ind = i;
		for (j = i + 1; j < N; j++)
		{
			max = abs(A[i][i]);
			if (max < abs(A[j][i]))
			{
				max = abs(A[j][i]);
				ind = j;
			}
		}
		if (ind != i)
		{
			for (j = 0; j < M; j++)
			{
				obm = A[i][j];
				A[i][j] = A[ind][j];
				A[ind][j] = obm;
			}
		}
		for (j = 0; j < N; j++)
		{
			for (k = 0; k < M; k++)
				cout << " " << A[j][k] << "\t";
			cout << endl;
		}
		cout << endl;
		


		for (j = i + 1; j < N; j++)
		{
			f = A[j][i] / A[i][i];
			for (k = 0; k < M; k++)
				A[j][k] = -(f * A[i][k]) + A[j][k];
		}
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
			cout << " " << A[i][j] << "\t";
		cout << endl;
	}

	for (i = N - 1; i >= 0; i--)
	{
		f = A[i][M - 1];
		for (j = i + 1; j < N; j++)
			f -= A[i][j] * X[j];
		X[i] = f / A[i][i];
	}

	for (i = 0; i < N; i++)
	{
		cout << endl << " X[" << i + 1 << "] = " << X[i];
	}
	return 0;
}