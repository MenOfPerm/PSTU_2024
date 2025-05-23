//�����- ��������� ��������� � ���������� ���� int. 
// ����������� ��������: 
// [] � ������� �� �������; 
// == - �������� �� ���������; 
// > ����� � �������������� ����� ���������; 
// - n - ������� ����� � �������� � ������� n ( � ������� ������-���������).


#include <iostream>
using namespace std;


class Iterator {
	friend class MMany;//������������� ����� 
public: Iterator(){elem=0;}
	  //����������� ��� ���������� 
	  Iterator(const Iterator&it){elem=it.elem;}//����������� ����������� 
	  //������������� �������� ��������� 
	  bool operator==(const Iterator&it){return elem==it.elem;} 
	  bool operator!=(const Iterator&it){return elem!=it.elem;};  
	  void operator++(){ ++elem;}; //������������� �������� ���������
	  void operator--(){ --elem;} //������������� �������� ��������� 
int& operator *() const{ return*elem;} //������������� �������� ������������� 
private: int*elem;//��������� �� ������� ���� int 

};

class MMany {
public: 
	//����������� � �����������: 
	//�������� ������ ��� s ��������� � ��������� �� 
	//��������� k 
	MMany(int s, int k = 0) 
	{
		size = s;
		data = new int[size]; 
		for (int i = 0;i < size;i++)
			data[i] = k;
		beg.elem = &data[0]; 
		end.elem = &data[size];
	};
	//����������� ����������� 
	MMany(const MMany& a) 
	{
		size = a.size; 
		data = new int[size]; 
		for (int i = 0;i < size;i++) 
			data[i] = a.data[i];
		beg = a.beg;
		end = a.end;
	};

	Iterator first() { return beg; }//���������� ��������� �� ������ ������� 
	Iterator last(){return end;}//���������� ��������� �� ������� ��������� �� ���������

	//���������� 
	~MMany() { delete[]data; data = 0; };
	//�������� ������������ 
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
	//�������� ������� �� ������� 
	int& operator[](int index) 
	{
		if (index < size) return data[index]; 
		else cout << "\nError! Index>size";
	
	};
	//�������� ��� ���������� ��������� 
	MMany operator+(const int k) 
	{
		 MMany temp(size); 
		 for (int i=0;i<size;++i) 
			 temp.data[i]+=data[i]+k; 
		 return temp;
	
	};
	//��������, ������������ ����� ���������
	int operator()() 
	{
		return size;
	};
	//������������� �������� �����-������ 
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
	int size;//������ ������� 
	int*data;//�������� �� ������������ ������ �������� ������� 
	Iterator beg;//��������� �� ������ ������� ������� 
	Iterator end;//��������� �� ������� ��������� �� ���������

	};