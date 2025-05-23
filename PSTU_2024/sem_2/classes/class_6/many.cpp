// ласс- контейнер ћЌќ∆≈—“¬ќ с элементами типа int. 
// –еализовать операции: 
// [] Ц доступа по индексу; 
// == - проверка на равенство; 
// > число Ц принадлежность числа множеству; 
// - n - переход влево к элементу с номером n ( с помощью класса-итератора).


#include <iostream>
using namespace std;


class Iterator {
	friend class MMany;//дружественный класс 
public: Iterator(){elem=0;}
	  //конструктор без параметров 
	  Iterator(const Iterator&it){elem=it.elem;}//конструктор копировани€ 
	  //перегруженные операции сравнени€ 
	  bool operator==(const Iterator&it){return elem==it.elem;} 
	  bool operator!=(const Iterator&it){return elem!=it.elem;};  
	  void operator++(){ ++elem;}; //перегруженна€ операци€ инкремент
	  void operator--(){ --elem;} //перегруженна€ операци€ декремент 
int& operator *() const{ return*elem;} //перегруженна€ операци€ разыменовани€ 
private: int*elem;//указатель на элемент типа int 

};

class MMany {
public: 
	//конструктор с параметрами: 
	//выдел€ет пам€ть под s элементов и заполн€ет их 
	//значением k 
	MMany(int s, int k = 0) 
	{
		size = s;
		data = new int[size]; 
		for (int i = 0;i < size;i++)
			data[i] = k;
		beg.elem = &data[0]; 
		end.elem = &data[size];
	};
	//конструктор копировани€ 
	MMany(const MMany& a) 
	{
		size = a.size; 
		data = new int[size]; 
		for (int i = 0;i < size;i++) 
			data[i] = a.data[i];
		beg = a.beg;
		end = a.end;
	};

	Iterator first() { return beg; }//возвращает указатель на первый элемент 
	Iterator last(){return end;}//возвращает указатель на элемент следующий за последним

	//деструктор 
	~MMany() { delete[]data; data = 0; };
	//оператор присваивани€ 
	MMany& operator=(const MMany& a) 
	{
		if (this == &a)return *this; 
		size = a.size; 
		if (data != 0) delete[]data; 
		data = new int[size]; 
		for (int i = 0;i < size;i++) 
			data[i] = a.data[i]; 
		beg = a.beg; 
		end = a.end; 
		return *this;

	};
	//операци€ доступа по индексу 
	int& operator[](int index) 
	{
		if (index < size) return data[index]; 
		else cout << "\nError! Index>size";
	
	};
	//операци€ дл€ добавление константы 
	MMany operator+(const int k) 
	{
		 MMany temp(size); 
		 for (int i=0;i<size;++i) 
			 temp.data[i]+=data[i]+k; 
		 return temp;
	
	};
	//операци€, возвращающа€ длину множества
	int operator()() 
	{
		return size;
	};
	//перегруженные операции ввода-вывода 
	friend ostream& operator<<(ostream& out, const MMany& a) 
	{
		for (int i = 0;i < a.size;++i) 
			out << a.data[i] << " "; 
		return out;
	};
	friend istream& operator>>(istream& in, MMany& a) 
	{
		for (int i = 0;i < a.size;++i) 
			in >> a.data[i];
		return in;
	};
private: 
	int size;//размер вектора 
	int*data;//укзатель на динамический массив значений вектора 
	Iterator beg;//указатель на первый элемент вектора 
	Iterator end;//указатель на элемент следующий за последним

	};