﻿#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int n, sum;
	cin >> n;
	sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i % 3 != 0)
		{
			sum+=i;
		}
		else
		{ 
			sum-=i;
		}
	}
	cout << sum << endl;
	return 0;
}