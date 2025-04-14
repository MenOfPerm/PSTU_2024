//Поле first – дробное число х, координата точки , поле second – дробное число y, координата точки.
// Реализовать метод distance() – вычисление расстояния от точки с координатами (first, second)
// до начала координат.
// будем искать по старинке, через треугольник a^2+b^2 = c^2
// справка :
// exit позволяет завершит программу с определённым кодом


#include <iostream>
using namespace std;
class myclass
{
	float x = 0;
	float y = 0;
public:
	void init(float a,float b) 
	{
		x = a;
		y = b;
	};
	// init здесь не нужен но в методичке просили его сделать
	float calculate_distance();

	void read() 
	{
		cout << "задайте координаты точки" << endl;
		cout << "x: ";cin >> x;
		cout << "y";cin >> y;
		if ((x || y) == 0)
		{
			cout << "ты ввёл начало координат, нам нечего считать";
			exit;
		}
	};

};
float myclass::calculate_distance()
{
	float c = sqrt(x * x + y*y);
	if (x<0 or y<0)
	{
		return -(c);
	}
	else
	{
		return c;
	}

}

int main()
{
	setlocale(LC_ALL, "RU");
	myclass ee;
	ee.read();
	cout<<"расстояние до точки:"<<ee.calculate_distance();



}