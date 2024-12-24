#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	int N, max, min, num;
	int	*ptr = &num;
	cout << "укажите длину последовательности:" << endl;
	cin >> N;
	cout << "вводите числа через enter" << endl;
	cin >> *ptr;
	max = *ptr;
	min = *ptr;

	for (int i = 2; i <= N; i++) {
		cin >> *ptr;
		if (*ptr > max) {
			max = *ptr;
		}
		else if (*ptr < min) {
			min = *ptr;
		}
	}
	cout << "Максимальный элемент:" << max << endl;
	cout << "Минимальный элемент:" << min << endl;
	return 0;
}
