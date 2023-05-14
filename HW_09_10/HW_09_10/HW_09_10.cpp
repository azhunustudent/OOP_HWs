#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <time.h>
using namespace std;
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); } ~LC() { cout << "\nGood bye..\n"; cin.get(); cin.get(); } } _;
#define RAND(Min,Max) (rand()%((Max)-(Min)+1)+(Min))


// Создайте приложение "Телефонная книга".
// Для этого необходимо хранить данные об абоненте :
// -ФИО;
// -домашний телефон;
// -рабочий телефон;
// -мобильный телефон;
// -дополнительная информация о контакте;
// внутри соответствующего класса, например Abonent.
// Наполните класс переменными - членами, функциями - членами, конструкторами. 
class Abonent
{
private:
	string FIO;
	int HomePhone;
	int WorkPhone;
	int MobilePhone;
	string Info;
public:
	Abonent() : FIO("Неизвестно"), HomePhone(0), WorkPhone(0), MobilePhone(0), Info("Пусто") { }
	Abonent(string fio, int mobilePhone, string info) : FIO(fio), MobilePhone(mobilePhone), Info(info), HomePhone(0), WorkPhone(0) { }
	Abonent(string fio, int homePhone, int workPhone, int mobilePhone, string info) : Abonent(fio, mobilePhone, info)
	{
		SetHomePhone(homePhone);
		SetWorkPhone(workPhone);
	}

	void SetFIO(string fio) { FIO = fio; }

	bool SetHomePhone(int homePhone)
	{
		if (CheckPhoneNumber(homePhone))
		{
			HomePhone = homePhone;
			return true;
		}
		else
		{
			cout << "Ошибка: номер домашнего телефона не может быть больше 5! ";
			return false;
		}
	};

	bool SetWorkPhone(int workPhone)
	{
		if (CheckPhoneNumber(workPhone))
		{
			WorkPhone = workPhone;
			return true;
		}
		else
		{
			cout << "Ошибка: номер рабочего телефона не может быть больше 5! ";
			return false;
		}
	};

	bool SetMobilePhone(int mobilePhone)
	{
		if (CheckPhoneNumber(mobilePhone))
		{
			MobilePhone = mobilePhone;
			return true;
		}
		else
		{
			cout << "Ошибка: номер мобильного телефона не может быть больше 5! ";
			return false;
		}
	};

	void SetInfo(string info) { Info = info; }

	string GetFIO() { return FIO; }
	int GetHomePhone() { return HomePhone; }
	int GetWorkPhone() { return WorkPhone; }
	int GetMobilePhone() { return MobilePhone; }
	string GetInfo() { return Info; }


	void Print()
	{
		cout << "\nФИО: " << GetFIO()
			<< "\nДомашний телефон: " << GetHomePhone()
			<< "\nРабочий телефон: " << GetWorkPhone()
			<< "\nМобильный телефон: " << GetMobilePhone()
			<< "\nДополнительная информация о контактах: " << GetInfo() << endl;
	}

	void Input()
	{
		string temp;
		int temp2;

		cout << "Введите ФИО: ";
		getline(cin, temp);
		SetFIO(temp);

		while (true)
		{
			cout << "Введите номер домашнего телефона (5 чисел): ";
			(cin >> temp2).ignore();

			if (SetHomePhone(temp2) == true) { break; }
			cout << "Попробуйте еще раз!" << endl;
		}

		while (true)
		{
			cout << "Введите номер рабочего телефона (5 чисел): ";
			(cin >> temp2).ignore();

			if (SetWorkPhone(temp2) == true) { break; }
			cout << "Попробуйте еще раз!" << endl;
		}

		while (true)
		{
			cout << "Введите номер мобильного телефона (5 чисел): ";
			(cin >> temp2).ignore();

			if (SetMobilePhone(temp2) == true) { break; }
			cout << "Попробуйте еще раз!" << endl;
		}

		cout << "Введите дополнительную информацию о контактах: ";
		getline(cin, temp);
		SetInfo(temp);
	}


	void InitRand()
	{
		FIO = StrRand(RAND(5, 20));
		HomePhone = RAND(10000, 99999);
		WorkPhone = RAND(10000, 99999);
		MobilePhone = RAND(10000, 99999);
		Info = StrRand(RAND(5, 30));
	}

private:
	string StrRand(int len)
	{
		string Result = "";
		Result[0] = RAND('A', 'Z');
		for (int i = 1; i < len; i++) {
			Result += RAND('a', 'z');
		}
		return Result;
	}

	bool CheckPhoneNumber(int phoneNumber)
	{
		int count = 0;
		while (phoneNumber > 0)
		{
			phoneNumber /= 6;
			count++;
		}

		return count == 6;
	}
};



// Потом создайте класс "Телефонная книга" (PhoneBook), который будет хранить массив абонентов.
// Наполните необходимыми переменными, конструкторами, методами.
// В программе предоставьте пользователю возможность
// - показывать всех абонентов,
// - добавлять новых абонентов,
// - удалять абонентов,
// - искать абонентов по ФИО или телефону,
// - сортировать абонентов по ФИО или телефону,
// - сохранять информацию в файл,
// - загружать из файла.
class PhoneBook
{
private:
	Abonent* Arr;
	int Size;
public:
	PhoneBook() : Arr(), Size() { }
	PhoneBook(int size) : PhoneBook()
	{
		SetSize(size);
	}
	PhoneBook(Abonent arr) : PhoneBook(&arr, 1) { }
	PhoneBook(Abonent* arr, int size) : PhoneBook()
	{
		SetArr(arr, size);
	}
	~PhoneBook() { delete[]Arr; }


	void SetSize(int newSize)
	{
		Abonent* Temp = new Abonent[newSize];
		int minSize = (Size > newSize) ? newSize : Size;

		for (int i = 0; i < minSize; i++)
		{
			Temp[i] = Arr[i];
		}

		delete[] Arr;
		Arr = Temp;
		Size = newSize;
	}

	void SetArr(Abonent* arr, int size)
	{
		delete[] Arr;
		Arr = new Abonent[size];
		for (int i = 0; i < size; i++)
		{
			Arr[i] = arr[i];
		}
		Size = size;
	}

	int GetSize()const { return Size; }
	Abonent* GetAbonents() { return Arr; }


	// - добавлять новых абонентов
	void InputAbonents()
	{
		int tempSize, curSize;
		cout << "Введите кол-во абонентов, которых хотите добавить в телефонную книгу: ";
		(cin >> tempSize).ignore();

		curSize = GetSize();
		SetSize(curSize + tempSize);

		cout << "Введите информацию об абонентах:" << endl;
		for (int i = curSize; i < GetSize(); i++)
		{
			Arr[i].Input();
			cout << endl;
		}
		cout << "Абонент(ы) успешно добавлен(ы)!\n\n";
	}

	// - рандомная инициализация абонентов (дополнительно, если нет времени заполнять)
	void RandomAbonents()
	{
		int tempSize, curSize;
		cout << "Введите кол-во абонентов, которых хотите добавить в телефонную книгу: ";
		(cin >> tempSize).ignore();

		curSize = GetSize();
		SetSize(curSize + tempSize);

		for (int i = curSize; i < GetSize(); i++)
		{
			Arr[i].InitRand();
		}
		cout << "\nАбонент(ы) успешно добавлен(ы)!\n\n";
	}

	// - показывать всех абонентов
	void PrintAbonents()
	{
		if (GetSize() == 0)
		{
			cout << "\nТелефонная книга пустая. Сначала добавьте абонента.\n\n";
		}
		else
		{
			for (int i = 0; i < GetSize(); i++)
			{
				cout << "Абонент №" << i + 1;
				Arr[i].Print();
				cout << endl;
			}
		}
	}

	// - удалять абонентов
	void DeleteAbonents()
	{
		if (GetSize() == 0)
		{
			cout << "\nТелефонная книга пустая. Сначала добавьте абонента.\n\n";
		}
		else
		{
			int index;
			cout << "Выберете номер абонента, которого желаете удалить: ";
			(cin >> index).ignore();

			if (index < 0 || index >= GetSize())
			{
				cout << "\nОшибка: такого номера нет в книге!\n\n";
			}
			else
			{
				for (int i = index - 1; i < GetSize() - 1; i++)
				{
					Arr[i] = Arr[i + 1];
				}

				SetSize(GetSize() - 1);
				cout << "\nАбонент успешно удален.\n\n";
			}

		}
	}

	// - искать абонентов по ФИО
	void SearchByFIO(string fio)
	{
		if (GetSize() == 0)
		{
			cout << "\nТелефонная книга пустая. Сначала добавьте абонента.\n\n";
		}
		else
		{
			cout << "Введите ФИО: ";
			(cin >> fio).ignore();
			cout << endl;

			bool found = false;
			for (int i = 0; i < GetSize(); i++)
			{
				if (Arr[i].GetFIO() == fio)
				{
					cout << "Абонент №" << i + 1;
					Arr[i].Print();
					cout << endl;
					found = true;
				}
			}

			if (found == false)
			{
				cout << "\nОшибка: ФИО не найдено!\n\n";
			}
		}
	}

	// - искать абонентов по телефону
	void SearchByMobilePhone(int mobilePhone)
	{
		if (GetSize() == 0)
		{
			cout << "\nТелефонная книга пустая. Сначала добавьте абонента.\n\n";
		}
		else
		{
			cout << "Введите мобильный номер телефона: ";
			(cin >> mobilePhone).ignore();
			cout << endl;

			bool found = false;
			for (int i = 0; i < GetSize(); i++)
			{
				if (Arr[i].GetMobilePhone() == mobilePhone)
				{
					cout << "Абонент №" << i + 1;
					Arr[i].Print();
					cout << endl;
					found = true;
				}
			}

			if (found == false)
			{
				cout << "\nОшибка: номер мобильного телефона не найдено!\n\n";
			}
		}
	}

	// - сортировать абонентов по ФИО 
	void SortByFIO()
	{
		if (GetSize() == 0)
		{
			cout << "\nТелефонная книга пустая. Сначала добавьте абонента.\n\n";
		}
		else
		{
			auto cmpFunc = [](auto left, auto right)
			{
				return (left.GetFIO() < right.GetFIO());
			};
			sort(Arr, Arr + Size, cmpFunc);

			cout << "\nСортировка абонентов по ФИО прошла успешно.\n\n";
		}
	}

	// - сортировать абонентов по телефону
	void SortByMobilePhone()
	{
		if (GetSize() == 0)
		{
			cout << "\nТелефонная книга пустая. Сначала добавьте абонента.\n\n";
		}
		else
		{
			auto cmpFunc = [](auto left, auto right)
			{
				return (left.GetMobilePhone() < right.GetMobilePhone());
			};
			sort(Arr, Arr + Size, cmpFunc);

			cout << "\nСортировка абонентов по мобильному номеру телефона прошла успешно.\n\n";
		}
	}

	// - сохранять информацию в файл
	void SaveToFile(string FileName)
	{
		if (GetSize() == 0)
		{
			cout << "\nТелефонная книга пустая. Сначала добавьте абонента.\n\n";
		}
		else
		{
			ofstream file;
			file.open(FileName);
			if (file.is_open())
			{
				cout << "\nФайл для записи успешно открыт!\n\n";

				file << GetSize() << endl;

				for (int i = 0; i < GetSize(); i++)
				{
					file << Arr[i].GetFIO() << endl;
					file << Arr[i].GetHomePhone() << endl;
					file << Arr[i].GetWorkPhone() << endl;
					file << Arr[i].GetMobilePhone() << endl;
					file << Arr[i].GetInfo() << endl;
				}
				file.close();
			}
			else
			{
				cout << "\nОшибка: файл для записи не создан!\n\n";
			}
		}
	}

	// - загружать из файла
	void LoadFromFile(string FileName)
	{
		ifstream file(FileName);
		if (file.is_open())
		{
			cout << "\nФайл для чтения успешно открыт!\n\n";

			int fileSize;
			(file >> fileSize).ignore();

			int curSize = GetSize();
			SetSize(curSize + fileSize);

			for (int i = curSize; i < GetSize(); i++)
			{
				string temp1, temp2;
				int t1, t2, t3;

				getline(file, temp1);
				Arr[i].SetFIO(temp1);

				(file >> t1).ignore();
				Arr[i].SetHomePhone(t1);

				(file >> t2).ignore();
				Arr[i].SetWorkPhone(t2);

				(file >> t3).ignore();
				Arr[i].SetMobilePhone(t3);

				getline(file, temp2);
				Arr[i].SetInfo(temp2);
			}
			file.close();
		}
		else
		{
			cout << "\nОшибка: файл для чтения не найден!\n\n";
		}
	}
};


int main()
{
	system("chcp 1251 > nul");

	PhoneBook phoneBook;
	int c;
	string fio;
	int mobilePhone = 0;

	do
	{
		cout << "МЕНЮ:" << endl;
		cout << "\tВвод / Добавить:" << endl;
		cout << "(1) Добавить нового абонента в телефонную книгу." << endl;
		cout << "(2) Проинициализировать абонета случайными значениями." << endl;
		cout << "\tВывод / Печать:" << endl;
		cout << "(3) Вывод всех абонентов." << endl;
		cout << "\tУдалить:" << endl;
		cout << "(4) Удалить всех абонентов." << endl;
		cout << "\tПоиск:" << endl;
		cout << "(5) Поиск абонентов по ФИО." << endl;
		cout << "(6) Поиск абонентов по мобильному телефону." << endl;
		cout << "\tСортировка:" << endl;
		cout << "(7) Отсортировать абонентов по ФИО." << endl;
		cout << "(8) Отсортировать абонентов по мобильному телефону." << endl;
		cout << "\tРабота с файлами:" << endl;
		cout << "(9) Сохранение информации в файл." << endl;
		cout << "(10) Загрузить информацию из файла." << endl;
		cout << "(0) Выйти" << endl;
		cout << "Введите вариант: ";
		cin >> c;

		switch (c)
		{
		case 1:
			phoneBook.InputAbonents();
			break;
		case 2:
			phoneBook.RandomAbonents();
			break;
		case 3:
			phoneBook.PrintAbonents();
			break;
		case 4:
			phoneBook.DeleteAbonents();
			break;
		case 5:
			phoneBook.SearchByFIO(fio);
			break;
		case 6:
			phoneBook.SearchByMobilePhone(mobilePhone);
			break;
		case 7:
			phoneBook.SortByFIO();
			break;
		case 8:
			phoneBook.SortByMobilePhone();
			break;
		case 9:
			phoneBook.SaveToFile("PhoneBook.txt");
			break;
		case 10:
			phoneBook.LoadFromFile("PhoneBook.txt");
			break;
		case 0:
			cout << "Выход." << endl;
			break;
		default:
			cout << "Ошибка: такого варианта нет!\n\n";
			break;
		}
	} while (c != 0);
}
