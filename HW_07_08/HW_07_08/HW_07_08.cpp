#include <iostream>
#include <string>
#include <algorithm>
#include <time.h>
using namespace std;
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); } ~LC() { cout << "\nGood bye..\n"; cin.get(); cin.get(); } } _;
#define RAND(Min,Max) (rand()%((Max)-(Min)+1)+(Min))



string ListOfDesc[] =
{
  "Хлеб и Булочки",
  "Молочная продукция",
  "Шоколад",
  "Овощи",
  "Фрукты",
  "Колбасные изделия",
  "Вода"
};

int sizeListOfDesc = sizeof(ListOfDesc) / sizeof(ListOfDesc[0]);


// Задание 1a
// *Реализуйте класс "Товар" (или используйте ранее созданный класс).
// Необходимо хранить в переменных - членах класса :
// -название товара,
// -цена,
// -описание,
// -фирма изготовитель,
// -количество товара на складе.
// Используйте конструкторы, делегирование конструкторов.
// Реализуйте аксессоры для доступа к отдельным переменным - членам - get / set - методы.
// Реализуйте функции - члены класса для ввода данных с консоли, вывода данных на консоль.
class Product
{
private:
	string Name;
	int Price;
	string Desc;
	string Maker;
	int NumOfProd;

public:
	// конструкторы; делегирование конструкторов
	Product() : Name("Неизвестно"), Price(100), Desc("Пусто"), Maker("Неизвестно"), NumOfProd(0) { }
	Product(string name, int price, int num) : Name(name), Price(price), NumOfProd(num), Desc("Пусто"), Maker("Неизвестно") { }
	Product(string name, int price, string desc, string maker, int num) : Product(name, price, num)
	{
		SetDesc(desc);
		SetMaker(maker);
	}

	// методы-аксессеры: геттеры и сеттеры
	void SetName(string name) { Name = name; }
	bool SetPrice(int price)
	{
		if (price >= 100)
		{
			Price = price;
			return true;
		}
		else
		{
			cout << "Ошибка: цена не должна быть ниже 100 тг! ";
			return false;
		}
	}
	void SetDesc(string desc) { Desc = desc; }
	void SetMaker(string maker) { Maker = maker; }
	bool SetNum(int num)
	{
		if (num >= 0)
		{
			NumOfProd = num;
			return true;
		}
		else
		{
			cout << "Ошибка: кол-во продуктов не может быть отрицательным числом! ";
			return false;
		}
	}

	string GetName() { return Name; }
	int GetPrice() { return Price; }
	string GetDesc() { return Desc; }
	string GetMaker() { return Maker; }
	int GetNum() { return NumOfProd; }


	// метод для вывода данных на консоль
	void PrintInfo()
	{
		cout << "\nНазвание: " << GetName()
			<< "\nЦена: " << GetPrice() << " тг за штуку"
			<< "\nОписание (категория товара): " << GetDesc()
			<< "\nФирма изготовитель: " << GetMaker()
			<< "\nКол-во тораров: " << GetNum() << endl;
	}

	// пользователь вводит данные через консоль
	void InputInfo()
	{
		string temp;
		int temp2;

		cout << "Введите название: ";
		getline(cin, temp);
		SetName(temp);

		while (true)
		{
			cout << "Введите цену: ";
			(cin >> temp2).ignore();

			if (SetPrice(temp2) == true) { break; }
			cout << "Попробуйте еще раз!" << endl;
		}

		cout << "Введите описание: ";
		getline(cin, temp);
		SetDesc(temp);

		cout << "Введите фирму изготовителя: ";
		getline(cin, temp);
		SetMaker(temp);

		while (true)
		{
			cout << "Введите кол-во товаров: ";
			(cin >> temp2).ignore();

			if (SetNum(temp2) == true) { break; }
			cout << "Попробуйте еще раз!" << endl;
		}
	}

	void InitRand()
	{
		Name = StrRand(RAND(5, 15));
		Price = RAND(100, 5000);
		Desc = ListOfDesc[rand() % sizeListOfDesc];
		Maker = StrRand(RAND(10, 20));
		NumOfProd = RAND(1, 100);
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
};



// Задание 1b
// ***Создайте класс "Магазин", который будет содержать в себе массив объектов "Товар".
// В классе "Магазин" для работы с массивом объектов "Товар" необходимо реализовать следущие методы:
// - Ввод данных с консоли для товаров в "Магазине".
// - Случайное(рандомное) заполнение товаров в массиве.
// - Печать всех товаров в "Магазине".
// - Печать только тех товаров, цена которых лежит в указанном диапазоне. Диапазон цен вводит пользователь.
// - Поиск товара в "Магазине" по названию товара.
// - Поиск товара по названию фирмы изготовителя.
// - Сортировка массива товаров по названию товара.
// - Сортировка массива товаров по цене товара.
class Store
{
private:
	Product* Arr;
	int Size;
public:
	Store() : Arr(), Size() { }
	Store(int size) : Store()
	{
		SetSize(size);
	}
	Store(Product arr) : Store(&arr, 1) { }
	Store(Product* arr, int size) : Store()
	{
		SetArr(arr, size);
	}
	~Store() { delete[]Arr; }


	void SetSize(int newSize)
	{
		Product* Temp = new Product[newSize];
		int minSize = (Size > newSize) ? newSize : Size;

		for (int i = 0; i < minSize; i++)
		{
			Temp[i] = Arr[i];
		}

		delete[] Arr;
		Arr = Temp;
		Size = newSize;
	}

	void SetArr(Product* arr, int size)
	{
		delete[] Arr;
		Arr = new Product[size];
		for (int i = 0; i < size; i++)
		{
			Arr[i] = arr[i];
		}
		Size = size;
	}

	int GetSize()const { return Size; }
	Product* GetProducts() { return Arr; }

	// - Ввод данных с консоли для товаров в "Магазине".
	void InputProducts()
	{
		int tempSize, curSize;
		cout << "Введите кол-во товаров в магазине: ";
		(cin >> tempSize).ignore();

		curSize = GetSize();
		SetSize(curSize + tempSize);

		cout << "Введите информацию о товарах:" << endl;
		for (int i = curSize; i < GetSize(); i++)
		{
			Arr[i].InputInfo();
			cout << endl;
		}
		cout << "Товар(ы) успешно добавлен(ы)!\n\n";
	}

	// - Случайное(рандомное) заполнение товаров в массиве.
	void RandomProducts()
	{
		int tempSize, curSize;
		cout << "Введите кол-во товаров в магазине: ";
		(cin >> tempSize).ignore();

		curSize = GetSize();
		SetSize(curSize + tempSize);

		for (int i = curSize; i < GetSize(); i++)
		{
			Arr[i].InitRand();
		}
		cout << "\nТовар(ы) успешно добавлен(ы)!\n\n";
	}

	// - Печать всех товаров в "Магазине".
	void PrintProducts()
	{
		if (GetSize() == 0)
		{
			cout << "\nМагазин пуст. Сначала добавьте товары в магазин.\n\n";
		}
		else
		{
			for (int i = 0; i < GetSize(); i++)
			{
				cout << "Товар №" << i + 1;
				Arr[i].PrintInfo();
				cout << endl;
			}
		}
	}

	// - Печать только тех товаров, цена которых лежит в указанном диапазоне. Диапазон цен вводит пользователь.
	void PrintByPrice(int minPrice, int maxPrice)
	{
		if (GetSize() == 0)
		{
			cout << "\nМагазин пуст. Сначала добавьте товары в магазин.\n\n";
		}
		else
		{
			cout << "Введите минимальную цену: ";
			cin >> minPrice;
			cout << "Введите максимальную цену: ";
			cin >> maxPrice;

			int price;
			bool rightPrice = false;
			for (int i = 0; i < Size; i++)
			{
				price = Arr[i].GetPrice();
				if (price >= minPrice && price <= maxPrice)
				{
					cout << "Товар №" << i + 1;
					Arr[i].PrintInfo();
					cout << endl;
					rightPrice = true;
				}
			}

			if (rightPrice == false)
			{
				cout << "\nОшибка: Некорректный ввод цен!\n\n";
			}
		}
	}

	// - Поиск товара в "Магазине" по названию товара.
	void SearchByName(string name)
	{
		if (GetSize() == 0)
		{
			cout << "\nМагазин пуст. Сначала добавьте товары в магазин.\n\n";
		}
		else
		{
			cout << "Введите название: ";
			(cin >> name).ignore();

			bool found = false;
			for (int i = 0; i < GetSize(); i++)
			{
				if (Arr[i].GetName() == name)
				{
					cout << "Товар №" << i + 1;
					Arr[i].PrintInfo();
					cout << endl;
					found = true;
				}
			}

			if (found == false)
			{
				cout << "\nОшибка: товар не найден!\n\n";
			}
		}
	}

	// - Поиск товара по названию фирмы изготовителя.
	void SearchByMaker(string maker)
	{
		if (GetSize() == 0)
		{
			cout << "\nМагазин пуст. Сначала добавьте товары в магазин.\n\n";
		}
		else
		{
			cout << "Введите фирму изготовителя: ";
			(cin >> maker).ignore();

			bool found = false;
			for (int i = 0; i < GetSize(); i++)
			{
				if (Arr[i].GetMaker() == maker)
				{
					cout << "Товар №" << i + 1;
					Arr[i].PrintInfo();
					cout << endl;
					found = true;
				}
			}

			if (found == false)
			{
				cout << "\nОшибка: изготовитель не найден!\n\n";
			}
		}
	}

	// - Сортировка массива товаров по названию товара.
	void SortByName()
	{
		if (GetSize() == 0)
		{
			cout << "\nМагазин пуст. Сначала добавьте товары в магазин.\n\n";
		}
		else
		{
			auto cmpFunc = [](auto left, auto right)
			{
				return (left.GetName() < right.GetName());
			};
			sort(Arr, Arr + Size, cmpFunc);

			cout << "\nСортировка товаров по названию прошла успешно.\n\n";
		}
	}

	// - Сортировка массива товаров по цене товара.
	void SortByPrice()
	{
		if (GetSize() == 0)
		{
			cout << "\nМагазин пуст. Сначала добавьте товары в магазин.\n\n";
		}
		else
		{
			auto cmpFunc = [](auto left, auto right)
			{
				return (left.GetPrice() < right.GetPrice());
			};
			sort(Arr, Arr + Size, cmpFunc);

			cout << "\nСортировка товаров по цене прошла успешно.\n\n";
		}
	}
};



int main()
{
	Store firstStore;
	int c;
	int minP = 0, maxP = 0;
	string name, maker;

	do
	{
		cout << "МЕНЮ:" << endl;
		cout << "\tВвод / Добавить:" << endl;
		cout << "(1) Добавить новый товар в магазин." << endl;
		cout << "(2) Проинициализировать товар случайными значениями." << endl;
		cout << "\tВывод / Печать:" << endl;
		cout << "(3) Вывод всех товаров в магазине." << endl;
		cout << "(4) Вывод товаров, цена которых лежит в указанном диапазоне." << endl;
		cout << "\tПоиск:" << endl;
		cout << "(5) Поиск товара по названию товара." << endl;
		cout << "(6) Поиск товара по названию фирмы изготовителя." << endl;
		cout << "\tСортировка:" << endl;
		cout << "(7) Отсортировать товар по названию товара." << endl;
		cout << "(8) Отсортировать товар по цене товара." << endl;
		cout << "(0) Выйти" << endl;
		cout << "Введите вариант: ";
		cin >> c;

		switch (c)
		{
		case 1:
			firstStore.InputProducts();
			break;
		case 2:
			firstStore.RandomProducts();
			break;
		case 3:
			firstStore.PrintProducts();
			break;
		case 4:
			firstStore.PrintByPrice(minP, maxP);
			break;
		case 5:
			firstStore.SearchByName(name);
			break;
		case 6:
			firstStore.SearchByMaker(maker);
			break;
		case 7:
			firstStore.SortByName();
			break;
		case 8:
			firstStore.SortByPrice();
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