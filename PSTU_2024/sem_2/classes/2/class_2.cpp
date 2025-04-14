//ѕользовательский класс  ¬ј–“»–ј 
// јдрес Ц string 
//ѕлощадь Ц double
// оличество комнат Ц int

#include <iostream>
using namespace std;
class apartment
{
	string adress;
	double S;
	int numberOfRooms;

public:
	//конструкторы
	apartment() 
	{
		this->adress = "стандартное значение";
		this->S = 100;
		this->numberOfRooms = 999;
	};

	apartment(string adr, double pl, int rooms)
	{
		adress = adr;
		S = pl;
		numberOfRooms = rooms;

	};

	apartment(const apartment&a)
	{
		adress = a.adress;
		S = a.S;
		numberOfRooms = a.numberOfRooms;
	}
	void info()
	{

		cout << "это квартира по адресу: " << adress << endl;
		cout << "с площадью :" << S << endl;
		cout << "и количеством комнат: " << numberOfRooms << endl << endl;
	
	}
	void change_adress(string new_adress)
	{
		adress = new_adress;
	}
	//--------------------------------------
	// деструктор (можно не писать если в классе нет динамических структур данных , ну собственно у мен€ их и нет)
	//~apartment() {};

};

int main()
{
	setlocale(LC_ALL, "RU");
	apartment e ;// создаЄм через пустой
	string adr = "улица пулаз";
	double s = 123;
	int rooms = 5;
	apartment x(adr, s, rooms);
	apartment y(x); // или y = x
	// Person* pp1=new(Person);
	//указатель на пустой объект 
	//Person*pp2=new Person(ФPetrovФ,32);
	//указатель на объект
	y.info();
	x.info();
	e.info();

}