#pragma once

const int evNothing = 0; 
const int evMessage = 100; 
const int cmMake = 1; //Создать группу(формат команды : m количество элементов группы).
const int cmAdd = 2; //Добавить элемент в группу(формат команды : +)
const int cmDel = 3; //Удалить элемент из группы(формат команды - )
const int cmShow = 4; //Вывести информацию об элементах группы(формат команды : s)
const int cmGetName = 5; //Вывести информацию об имени элемента с номером k(формат команды : z k, где k – целое число)
const int cmQuit = 101; //Конец работы(формат команды : q)

struct TEvent
{
	int what;
	union
	{
		int command;
		struct
		{
			int message;
			int a;
		};
	};
};