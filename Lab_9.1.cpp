

// PR-9.1.cpp

// < Шикітки Миколи>
// Лабораторна робота № 9.1// Послідовний пошук в масиві структур.
// Варіант 9

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

enum Specialty { MATHEMATICS, PHYSICS, COMPUTER_SCIENCE, INFORMATICS }; //перелік

string specialtyStr[] = { "математика", "фізика", "комп'ютерні науки", "інформатика" };

struct Student
{
	string surname;
	int course;
	Specialty specialty;
	float physics;
	float math;
	float computer_science;
	float informatics;
};

void Create(Student* s, const int N)
{
	int specialty;
	for (int i = 0; i < N; i++)
	{
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();

		cout << " прізвище: "; getline(cin, s[i].surname);
		cout << " курс: "; cin >> s[i].course;
		cout << " спеціальність (0 - математика, 1 - фізика, 2 - комп'ютерні науки, 3 - інформатика): ";
		cin >> specialty;
		s[i].specialty = (Specialty)specialty;
		cout << " фізика: "; cin >> s[i].math;
		cout << " математика: "; cin >> s[i].physics;
		cout << " комп'ютерні науки: "; cin >> s[i].computer_science;
		cout << " інформатика: "; cin >> s[i].informatics;
		cout << endl;
	}
}

void Print(Student* s, const int N)
{
	cout << "======================================================================================================="
		<< endl;
	cout << "|  №  |  Прізвище  | Курс |   Спеціальність   | Фізика | Математика | Комп'ютерні науки | Інформатика |"
		<< endl;
	cout << "-------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(3) << right << i + 1 << " ";

		cout << "| " << setw(11) << left << s[i].surname
			<< "| " << setw(4) << right << s[i].course << " "
			<< "| " << setw(18) << left << specialtyStr[s[i].specialty]
			<< "| " << setw(7) << left << s[i].physics
			<< "| " << setw(11) << left << s[i].math
			<< "| " << setw(18) << left << s[i].computer_science
			<< "| " << setw(11) << left << s[i].informatics
			<< " |" << endl;

	}
	cout << "=======================================================================================================" 
		<< endl;
	cout << endl;
}

void MarkCount(Student* s, const int N)
{
	int p = 0, m = 0, c = 0, i = 0;

	for (int k = 0; k < N; k++)
	{
		if (s[k].physics == 5)
		{
			p++;
		}

		if (s[k].math == 5)
		{
			m++;
		}

		if (s[k].computer_science == 5)
		{
			c++;
		}

		if (s[k].informatics == 5)
		{
			i++;
		}
	}
	cout << "Кількість п'ятірок з фізики: " << p << endl;
	cout << "Кількість п'ятірок з математики: " << m << endl;
	cout << "Кількість п'ятірок з комп'ютерних наук: " << c << endl;
	cout << "Кількість п'ятірок з інформатики: " << i << endl;
	cout << endl;
}

void StudentsCount(Student* s, const int N)
{
	int count = 0;

	for (int k = 0; k < N; k++)
	{
		if (s[k].physics == 5 && s[k].math == 5) {
			count++;
		}
	}

	cout << "Кількість студентів, в яких середній бал «4,5» : " << count << endl;
}

int main()
{
	int N;
	cout << "Введіть N: "; cin >> N;

	Student* s = new Student[N];

	Create(s, N);
	Print(s, N);

	MarkCount(s, N);
	StudentsCount(s, N);

	return 0;
}

