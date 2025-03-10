// будет работать до 6 параметров

#include <iostream>
#include <cstdarg>
using namespace std;

int nok	( int n, ...)
{
    int mass[6];
    int result = 0;
    int min;
    int temp;
    int delimoe = 1;// верхн€€ часть формулы (а*б*с...)
    va_list args;
    va_start(args, n);

    for (int i = 0; i < n; ++i) 
    {
        temp = va_arg(args, int);
        delimoe *= temp;
        mass[i] = temp;
    }
    va_end(args);
    // ищем нод
    min = abs(mass[0]);

    for (int e = 1; e < n; e++)// находим минимальный элемент (игнориру€ (-,+))
    {   
        int elem = abs(mass[e]);
        if (min > elem)
        {
            min = elem;
        }
    }

    int temp_of_elem=0;
    for (int i = 0; i < n; i++)//5
    {
        if (min <= 1) { return 0; }// если нод не найден (мы дошли до 0)
        if ((temp_of_elem == n) && (i == n))break;//если найден делитель дл€ всех элементов
        if (mass[i] % min == 0) { temp_of_elem++; }// если элемент массива делитс€ на предпологаемый нод , записываем это
        else{temp_of_elem = 0; min--;i = -1;}// если не делитьс€ уменьшаем делитель и начинаем цикл с начала
    }
    return (delimoe / min);

}

int  main()
{
    setlocale(LC_ALL, "RU");
    cout << "программа вычисл€ет нок по формуле (a*b*c...)/Ќќƒ" << endl << endl;;
    cout << "при отсутствии нок, программа выведет: 0" << endl << endl;;
    cout <<"найдЄм нок дл€ 3 числел (10,50,100): " << nok(3, 10, 50, 100) << endl;
    cout <<"найдЄм нок дл€ 5 числел (10, 6, 30, 8, 80): " <<nok( 5, 10, 6, 30, 8, 80) << endl;
    cout <<"найдЄм нок дл€ 6 числел (9, 24, 17, 15, 19, 136): " << nok( 3, 9, 24, 17, 15, 19, 136) << endl;

}