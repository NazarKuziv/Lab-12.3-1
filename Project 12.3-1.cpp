// Lab_12_3.cpp
// < Кузів Назар >
// Лабораторна робота № 12.3
// Опрацювання лінійного двонаправленого списку
// Варіант 6


#include <iostream>
#include <Windows.h>
#include <ctime>

using namespace std;

struct Elem
{
    Elem* next,
        * prev;
    int info;
};

void Create(Elem*& first, Elem*& last)
{
    Elem* tmp = new Elem; // ініціалізуємо вказівник tmp – налаштуємо його на новостворений елемент.
    tmp->info = 0 + rand() % 5; //  В новостворенbq елемент запишемо випадкові числа від 0 дло 3
    tmp->next = NULL;  // Першому полю зв’язку новоствореного елемента присвоїмо значення нульового вказівника.
    if (last != NULL)
        last->next = tmp; // перше поле зв’язку останнього елементу черги налаштуємо на новостворений елемент

    tmp->prev = last; // Другому полю зв’язку новоствореного елемента присвоїмо значення адреси останнього елемента черги
    last = tmp; // Вказівник last налаштуємо на новостворений елемент

    if (first == NULL) // якщо вказівник first мав значення NULL, налаштуємо його на новостворений елемент
        first = tmp;
}

void Print(Elem* first)
{
    while (first != NULL)
    {
        cout << first->info << " ";
         first =first->next;
    }
   
}
void Add(Elem* first, int V1, int V2 )
{
    while (first != NULL)
    {
        if (first->info == V1)
        {
            Elem* tmp = new Elem;
            tmp->info = V2; 
            tmp->next = first->next; 
            first->next = tmp; // 4
            if (tmp->next == NULL)
            {

            }
            else
                tmp->next->prev = tmp; // 5

            tmp->prev = first; // 6

            first = tmp->next;
        }
        else
            first = first->next;
    }
   
    
}



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(NULL));

    int V1 = 1, // значенням інформаційного поля після якого потрібно втвавити новий елемент
        V2 = 2 ; // значення нового елемента


    Elem* first = NULL,
        * last = NULL;

    for (int i = 1; i <= 10; i++)
        Create(first, last);
    cout << "Список:" << endl;
    cout << endl;
    Print(first);
    cout << endl << endl;

    Add(first,V1,V2);

    cout<<"Новий список:"<<endl;

    cout << endl;
    Print(first);

    return 0;
}