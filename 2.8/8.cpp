﻿#include <iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	for (int i=0; i <= N ; i++)
	{
		for (int j = i; j--; j < 0) 
		{
			cout << "*";
		}
		cout << endl;
	}
	return 1;
}