#include <iostream>
#include <string>
using namespace std;

// Задание 1
// Реализуйте класс "Товар".
// Необходимо хранить в переменных - членах класса:
// -название товара,
// -цена,
// -описание,
// -фирма изготовитель,
// -количество товара на складе.
// Реализуйте функции - члены класса для ввода данных, вывода данных, реализуйте аксессоры для доступа к отдельным переменным - членам.

class Product
{
private:
	string name;
	int price;
	string desc;
	string maker;
	int numOfProd;

public:
	// методы-аксессеры: геттеры и сеттеры
	void SetName(string newName) { name = newName; }
	bool SetPrice(int newPrice)
	{
		if (newPrice >= 100)
		{
			price = newPrice;
			return true;
		}
		else
		{
			cout << "Ошибка: цена не должна быть ниже 100 тг! ";
			return false;
		}
	}
	void SetDesc(string newDesc) { desc = newDesc; }
	void SetMaker(string newMaker) { maker = newMaker; }
	bool SetNum(int newNum)
	{
		if (newNum >= 0)
		{
			numOfProd = newNum;
			return true;
		}
		else
		{
			cout << "Ошибка: кол-во продуктов не может быть отрицательным числом! ";
			return false;
		}
	}

	void SetAll(string newName, int newPrice, string newDesc, string newMaker, int newNum)
	{
		SetName(newName);
		SetPrice(newPrice);
		SetDesc(newDesc);
		SetMaker(newMaker);
		SetNum(newNum);
	}

	string GetName() { return name; }
	int GetPrice() { return price; }
	string GetDesc() { return desc; }
	string GetMaker() { return maker; }
	int GetNum() { return numOfProd; }


	// метод для вывода данных на консоль
	void PrintInfo()
	{
		cout << "\nНазвание: " << name
			<< "\nЦена: " << price << " тг за штуку"
			<< "\nОписание: " << desc
			<< "\nФирма изготовитель: " << maker
			<< "\nКол-во тораров: " << numOfProd << endl;
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
};

int main()
{
	system("chcp 1251 > nul");
	Product prod1, prod2;
	prod1.InputInfo();
	prod1.PrintInfo();

	prod2.SetAll("Маркеры \"COPIC SKETCH\"", 1000, "разноцветные, быстросохнущие, прозрачные спиртовые чернила", "Copic Too Corporation", 100);
	prod2.PrintInfo();
}