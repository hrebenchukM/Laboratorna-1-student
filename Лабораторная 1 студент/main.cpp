#include<iostream>
using namespace std;

class Student
{
	char* name;
	char* email;
	int age;
public:
	Student()
	{
		cout << "Constructor by def.\n";
		name = nullptr;
		age = 0;
	}
	Student(const char* n, int a)// Oleg 20
	{
		name = new char[strlen(n) + 1]; // выделяем память при создани  объекта !!
		strcpy_s(name, strlen(n) + 1, n);
		age = a;
		cout << "Constructor 2 params\n";
	}
	Student(const char* n, const char* e, int a)// Oleg 20
	{
		name = new char[strlen(n) + 1]; // выделяем память при создани  объекта !!
		strcpy_s(name, strlen(n) + 1, n);
		email = new char[strlen(e) + 1]; // выделяем память при создани  объекта !!
		strcpy_s(email, strlen(e) + 1, e);
		age = a;
		cout << "Constructor 3 params\n";
	}
	void Input()
	{
		char buff[20];
		cout << "Enter name: ";
		cin >> buff;
		if (name != nullptr)
		{
			cout << "Delete -> " << name << "... \n";
			delete[]name;
		}
		name = new char[strlen(buff) + 1];
		strcpy_s(name, strlen(buff) + 1, buff);

		char buff2[20];
		cout << "Enter email: ";
		cin >> buff2;
		if (email != nullptr)
		{
			cout << "Delete -> " << email << "... \n";
			delete[]email;
		}
		email = new char[strlen(buff2) + 1];
		strcpy_s(email, strlen(buff2) + 1, buff2);

		cout << "Enter age: ";
		cin >> age;
	}
	void Print()
	{
		cout << "Name: " << name << "\tAge: " << age << endl;
	}
	~Student()
	{
		delete[] name; // явно освобождаем память при уничтожении объекта !!!!
		delete[] email;
		cout << "Destructor\n";
	}

	char* getName() {
		return name;
	}

	char* getEmail() {
		return email;
	}

	int getAge() {
		return age;
	}

	void setName(char* n) {
		if (name != nullptr)
		{
			cout << "Delete -> " << name << "... \n";
			delete[]name;
		}
		name = n;
	}

	void setEmail(char* e) {
		if (email != nullptr)
		{
			cout << "Delete -> " << email << "... \n";
			delete[]email;
		}
		email = e;
	}

	void setAge(char* a) {
		age = a;
	}





	/* добавить:
	   * поле емайл(char*)
	   * конструктор  с 3я параметрами
	   * методы аксессоры
	   * удаление выделенной динамической памяти в деструкторе.
	*/

};

int main()
{
	Student obj1("Oleg", 20);
	obj1.Print();
	obj1.Input();
	obj1.Print();

}