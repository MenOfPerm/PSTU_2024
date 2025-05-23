#include "file_work.h"

int make_file(const char* filename)
{
	fstream file(filename, ios::out | ios::trunc);
	if (!file) return -1;

	int c;
	cout << "Enter the number of records in the file: ";
	cin >> c;

	Money money;
	for (int i = 0; i < c; ++i)
	{
		cout << "Enter rubles and kopecks: ";
		cin >> money;
		file << money;
	}

	file.close();
	return c;
}

int print_file(const char* filename)
{
	fstream file(filename, ios::in);
	if (!file) return -1;

	int c = 0;
	Money money;
	while (file >> money)
	{
		cout << money << endl;
		++c;
	}

	file.close();
	return c;
}

int delete_by_value(const char* filename, const Money& value)
{
	ifstream in(filename);
	if (!in) return -1;

	vector<Money> v;
	Money money;
	int c = 0;

	while (in >> money)
	{
		if (money == value)
		{
			++c;
			continue;
		}
		v.push_back(money);
	}

	in.close();

	ofstream out(filename);
	if (!out) return -1;

	for (const auto& it : v)
	{
		out << it << '\n';
	}

	out.close();
	return c;
}

int increase_by_value(const char* filename, const Money& value)
{
	ifstream in(filename);
	if (!in) return -1;

	vector<Money> v;
	Money money;
	int c = 0;

	while (in >> money)
	{
		if (money == value)
		{
			++c;
			money.increase();
		}
		v.push_back(money);
	}

	in.close();

	ofstream out(filename);
	if (!out) return -1;

	for (const auto& it : v)
	{
		out << it << '\n';
	}

	out.close();
	return c;
}

int add_file(const char* filename, int k, int n)
{
	ifstream in(filename);
	if (!in) return -1;

	vector<Money> v;
	Money money;
	int it = 0;

	while (in >> money)
	{
		if (it == n)
		{
			v.push_back(money);

			for (int i = 0; i < k; ++i)
			{
				v.push_back(Money());
			}
		}
		else
		{
			v.push_back(money);
		}

		++it;
	}

	in.close();

	ofstream out(filename);
	if (!out) return -1;

	for (const auto& it : v)
	{
		out << it << '\n';
	}

	out.close();
	return k;
}