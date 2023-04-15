#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Задание 1
// *Создайте класс работника - Worker.
// В классе необходимо хранить данные:
// -ФИО;
// -Должность;
// -Год поступления на работу;
// -Зарплата.
// (1) Реализуйте аксессоры(get / set - методы) для доступа к отдельным переменным - членам.
// (2) Реализуйте функции - члены класса для консольного ввода - вывода данных.
// (3) Реализуйте сохранение в файл и загрузку данных из файла.
// (4) Реализуйте конструкторы для начальной инициализации объекта Worker
// Приведите демонстрацию работы с классом в main().

class Worker
{
private:
	string FIO;
	string pos;
	int yearOfAdm;
	int salary;

public:
	// (4) Реализуйте конструкторы для начальной инициализации объекта Worker
	Worker()
	{
		FIO = " ";
		pos = " ";
		yearOfAdm = 2023;
		salary = 50000;
	}

	Worker(string newFIO, string newPos, int newYearOfAdm, int newSalary)
	{
		SetFIO(newFIO);
		SetPos(newPos);
		SetYearOfAdm(newYearOfAdm);
		SetSalary(newSalary);
	}

	// (1) Реализуйте аксессоры(get / set - методы) для доступа к отдельным переменным - членам.
	void SetFIO(string newFIO) { FIO = newFIO; }
	void SetPos(string newPos) { pos = newPos; }

	bool SetYearOfAdm(int newYearOfAdm)
	{
		if (newYearOfAdm >= 1970 && newYearOfAdm <= 2023)
		{
			yearOfAdm = newYearOfAdm;
			return true;
		}
		else
		{
			cout << "Ошибка: Год поступления на работу не должно быть ниже 1970 и высше 2023! ";
			return false;
		}
	}

	bool SetSalary(int newSalary)
	{
		if (newSalary >= 50000)
		{
			salary = newSalary;
			return true;
		}
		else {
			cout << "Ошибка: Зарплата не должна быть ниже 50.000 тг! ";
			return false;
		}
	}

	string GetFIO() { return FIO; }
	string GetPos() { return pos; }
	int GetYearOfAdm() { return yearOfAdm; }
	int GetSalary() { return salary; }


	// (2) Реализуйте функции - члены класса для консольного ввода - вывода данных.
	void PrintInfo()
	{
		cout << "ФИО: " << FIO
			<< "\nДолжность: " << pos
			<< "\nГод поступления на работу: " << yearOfAdm
			<< "\nЗарплата: " << salary << " тг" << endl;
	}

	void InputInfo()
	{
		string temp;
		int temp2;

		cout << "Введите ФИО: ";
		getline(cin, temp);
		SetFIO(temp);

		cout << "Введите должность: ";
		getline(cin, temp);
		SetPos(temp);

		while (true)
		{
			cout << "Введите год поступления на работу: ";
			(cin >> temp2).ignore();

			if (SetYearOfAdm(temp2) == true) { break; }
			cout << "Повторите еще раз!" << endl;
		}

		while (true)
		{
			cout << "Введите зарплату: ";
			(cin >> temp2).ignore();

			if (SetSalary(temp2) == true) { break; }
			cout << "Повторите еще раз!" << endl;
		}
	}


	// (3) Реализуйте сохранение в файл и загрузку данных из файла.
	void SaveToFile(string FileName)
	{
		ofstream file;
		file.open(FileName);
		if (file.is_open() == true)
		{
			cout << "Файл для записи успешно открыт!" << endl;
			file << GetFIO() << endl;
			file << GetPos() << endl;
			file << GetYearOfAdm() << endl;
			file << GetSalary() << endl;
		}
		else
		{
			cout << "Ошибка: файл для записи не создан!\n";
		}
	}

	void LoadFromFile(string FileName)
	{
		ifstream file(FileName);
		if (file.is_open() == true)
		{
			cout << "Файл для чтения успешно открыт!" << endl;
			string temp1, temp2;
			int t1, t2;

			getline(file, temp1);
			SetFIO(temp1);

			getline(file, temp2);
			SetPos(temp2);

			file >> t1 >> t2;
			SetYearOfAdm(t1);
			SetSalary(t2);
		}
		else
		{
			cout << "Ошибка: файл для чтения не найден!\n";
		}
	}
};


// Задание 2
void PrintWorkers(Worker worker[], int size)
{
	cout << "Список всех работников:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Работник №" << i + 1 << endl;
		worker[i].PrintInfo();
		cout << endl;
	}
}

void InputWorkers(Worker worker[], int size)
{
	cout << "Введите информацию о работниках:" << endl;
	for (int i = 0; i < size; i++)
	{
		worker[i].InputInfo();
		cout << endl;
	}
}

void PrintByExpYear(Worker worker[], int size, int n)
{
	bool found = false;
	for (int i = 0; i < size; i++)
	{
		if (n <= (2023 - worker[i].GetYearOfAdm()))
		{
			cout << "Работник №" << i + 1 << endl;
			worker[i].PrintInfo();
			cout << endl;
			found = true;
		}
	}
	if (found == false)
	{
		cout << "Работники с таким стажем работы не существуют.\n\n";
	}
}

void PrintBySalary(Worker worker[], int size, int n)
{
	bool found = false;
	for (int i = 0; i < size; i++)
	{
		if (n <= worker[i].GetSalary())
		{
			cout << "Работник №" << i + 1 << endl;
			worker[i].PrintInfo();
			cout << endl;
			found = true;
		}
	}
	if (found == false)
	{
		cout << "Работников с зарплатой выше указанной не существует.\n\n";
	}
}

void PrintByPos(Worker worker[], int size, string pos)
{
	bool found = false;
	for (int i = 0; i < size; i++)
	{
		if (pos == worker[i].GetPos())
		{
			cout << "Работник №" << i + 1 << endl;
			worker[i].PrintInfo();
			cout << endl;
			found = true;
		}
	}
	if (found == false)
	{
		cout << "Работники с такой должностью не существуют.\n\n";
	}
}


int main()
{
	system("chcp 1251 > nul");
	cout << "Задание 1." << endl;
	Worker wrk1, wrk2;
	wrk1.InputInfo();
	wrk1.PrintInfo();
	cout << endl;

	wrk1.SaveToFile("Workers.txt");
	wrk2.LoadFromFile("Workers.txt");
	wrk2.PrintInfo();
	cout << endl;

	Worker wrk3("Иванов Иван", "менеджер", 2020, 350000);
	wrk3.PrintInfo();
	cout << endl;



	// Задание 2
	// ***Создать массив объектов Worker.
	// Для массива объектов Worker реализовать возможность вывести:
	// -список работников, стаж работы которых на данном предприятии превосходит заданное число лет;
	// -список работников, зарплата которых превосходит заданную;
	// -список работников, занимающих заданную должность.
	cout << "\nЗадание 2." << endl;
	const int numOfWorkers = 3;
	Worker workers[numOfWorkers];
	InputWorkers(workers, numOfWorkers);
	string pos;

	while (true)
	{
		cout << "МЕНЮ:" << endl;
		cout << "(1) Список всех работников;" << endl;
		cout << "(2) Cписок работников, стаж работы которых на данном предприятии превосходит заданное число лет;" << endl;
		cout << "(3) Cписок работников, зарплата которых превосходит заданную;" << endl;
		cout << "(4) Cписок работников, занимающих заданную должность;" << endl;
		int c;
		cout << "Введите вариант: ";
		cin >> c;

		switch (c)
		{
		case 1: PrintWorkers(workers, numOfWorkers);
			break;
		case 2:
			int expYears;
			cout << "Введите кол-во лет стажа работы: ";
			cin >> expYears;
			PrintByExpYear(workers, numOfWorkers, expYears);
			break;
		case 3:
			int salary;
			cout << "Введите зарплату: ";
			cin >> salary;
			PrintBySalary(workers, numOfWorkers, salary);
			break;
		case 4:
			cout << "Введите должность: ";
			cin >> pos;
			PrintByPos(workers, numOfWorkers, pos);
			break;
		default:
			cout << "Ошибка: такого варианта нет!\n\n";
			break;
		}
	}
}