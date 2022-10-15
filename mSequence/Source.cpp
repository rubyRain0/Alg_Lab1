#include <iostream>

//12->	Написать программу генерации m - последовательностей 0 и 1, удовлетворяющих обоим требованиям :
//1)	хотя бы 3  единицы стоят рядом;
//2)	число единиц кратно 3..

void mSequenceConstruction(int* mass, int length, int m)
{
	int* result = new int[m];
	for (int i = 0; i < m; i++)
		result[i] = 0;

	for (int i = 0; i < length; i++)
	{
		result[mass[i]] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		std::cout << result[i] << ' ';
	}
	std::cout << '\n';
}

void noRepeatCombinations(int k, int n, int* A, bool* dop, int m)
{
	if (k == n)
	{
		int sum = 0;
		for (size_t i = 0; i < n; i++)
		{
			sum += A[i];
		}
		for (size_t i = 0; i < n; i++)
		{
			std::cout << A[i] << ' ';
		}
		std::cout << '\n';
		if (sum % 3 == 0 && (A[n - 1] - A[0]) == n - 1)
		{
			mSequenceConstruction(A, n, m);
		}
	}
	else
	{
		int r = 0;
		if (k <= 0)
			r = 0;
		else
			r = A[k - 1] + 1;
		for (int y = r; y < m; ++y)
		{
			if (dop[y])
			{
				A[k] = y;
				dop[y] = false;
				noRepeatCombinations(k + 1, n, A, dop, m);
				dop[y] = true;
			}
		}
	}
}

void mSequenceGeneration(int m)
{
	for (int n = 3; n <= m; n += 3)
	{
		int* onePlacements = new int[m];
		bool* isAvailable = new bool[m];
		for (int i = 0; i <= n; ++i)
			isAvailable[i] = true;

		noRepeatCombinations(0, n, onePlacements, isAvailable, m);
	}
}

int main()
{	
	std::cout << "Enter M length of the 1/0 sequence: \n";
	int mLength; std::cin >> mLength;
	std::cout << "Generated sequences: \n";
	mSequenceGeneration(mLength);

	std::cin.get();
}