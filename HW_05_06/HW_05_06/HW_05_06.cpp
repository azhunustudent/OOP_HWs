#include <iostream>
#include <string>
using namespace std;

// Задание 1
// Цифровой счетчик, это переменная с ограниченным диапазоном.
// Значение которой сбрасывается, когда ее целочисленное значение
// достигает определенного максимума (например, k принимает значения
// в диапазоне от 0 до 100).
// В качестве примера такого счетчика можно привести цифровые часы,
// счетчик километража. Опишите класс такого счетчика.
// Обеспечьте возможность установления максимального и минимального
// значений, увеличения счетчика на 1, возвращения текущего значения.
class Counter
{
private:
    int max, min, cur;
public:
    Counter()
    {
        min = 0;
        max = 100;
        cur = min;
    }

    void SetMin(int newMin) { min = newMin; }
    bool SetMax(int newMax)
    {
        if (newMax > min)
        {
            max = newMax;
            return true;
        }
        else
        {
            cout << "Ошибка: max должен быть больше min! ";
            return false;
        }
    }

    int GetCur() { return cur; }

    void Inc()
    {
        cur < max ? cur++ : cur = min;
    }

    void Print()
    {
        cout << "Текущее значение: " << GetCur() << endl;
    }

    void Input()
    {
        int temp;

        cout << "Введите мининмальное значение: ";
        (cin >> temp).ignore();
        SetMin(temp);
        cur = temp;

        while (true)
        {
            cout << "Введите максимальное значение: ";
            (cin >> temp).ignore();
            if (SetMax(temp) == true) { break; };
            cout << "Повторите еще раз!" << endl;
        }

    }
};

int main()
{
    system("chcp 1251 > nul");
    Counter counter1;
    counter1.Input();

    int step;
    cout << "Введите кол-во шагов: " << endl;
    cin >> step;

    for (int i = 0; i < step; i++)
    {
        counter1.Inc();
        counter1.Print();
    }
}