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
		email = nullptr;
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
		/*if (name != nullptr)
		{
			cout << "Delete -> " << name << "... \n";
			delete[]name;
		}
		name = new char[strlen(buff) + 1];
		strcpy_s(name, strlen(buff) + 1, buff);*/
		setName(buff);
		
		cout << "Enter email: ";
		cin >> buff;
		/*if (email != nullptr)
		{
			cout << "Delete -> " << email << "... \n";
			delete[]email;
		}
		email = new char[strlen(buff) + 1];
		strcpy_s(email, strlen(buff) + 1, buff);*/
		setEmail(buff);


		cout << "Enter age: ";
		cin >> age;
	}
	void Print()
	{
		cout << "Name: " << name << "\tEmail: "<<email << "\tAge: " << age << endl;
	}
	~Student()
	{
		delete[] name; // явно освобождаем память при уничтожении объекта !!!!
		delete[] email;// явно освобождаем память при уничтожении объекта !!!!
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
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
		
	}

	void setEmail( char* e) {
		if (email != nullptr)
		{
			cout << "Delete -> " << email << "... \n";
			delete[]email;
		}
		email = new char[strlen(e) + 1];
		strcpy_s(email, strlen(e) + 1, e);
	}


	void setAge(int a) {
		age = a;
	}




	/*add:
* email field(char*)
* constructor with 3 parameters
* accessor methods
* in the name and mail setters, implement a check for non-zero values
* deleting allocated dynamic memory in the destructor.*/

	/* добавить:
	   * поле емайл(char*)
	   * конструктор  с 3я параметрами
	   * методы аксессоры
	   * в сеттерах имени и почты реализовать проверку на ненулевое значение 
	   * удаление выделенной динамической памяти в деструкторе.
	*/

};

int main()
{
	Student obj1("Oleg","oleg@oleg.com", 20);
	obj1.Print();
	obj1.Input();
	obj1.Print();

}