

// < Шикітки Миколи>

// Лабораторна робота № 9.2
// Впорядкування та бінарний пошук в масиві структур.
// Варіант 21

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Specialty { MATHEMATICS, PHYSICS, COMPUTER_SCIENCE, INFORMATICS };

string specialtyStr[] = { "математика", "фізика", "комп'ютерні науки", "інформатика" };

struct Student
{
	string surname;
	int course;
	Specialty specialty;
	float physics;
	float math;
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
		cout << " інформатика: "; cin >> s[i].informatics;
		cout << endl;
	}
}

void Print(Student* s, const int N)
{
	cout << "==================================================================================="
		<< endl;
	cout << "|  №  |  Прізвище  | Курс |   Спеціальність   | Фізика | Математика | Інформатика |"
		<< endl;
	cout << "-----------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(3) << right << i + 1 << " ";

		cout << "| " << setw(11) << left << s[i].surname
			<< "| " << setw(4) << right << s[i].course << " "
			<< "| " << setw(18) << left << specialtyStr[s[i].specialty]
			<< "| " << setw(7) << left << s[i].physics
			<< "| " << setw(11) << left << s[i].math
			<< "| " << setw(11) << left << s[i].informatics
			<< " |" << endl;

	}
	cout << "==================================================================================="
		<< endl;
	cout << endl;
}

void Sort(Student* p, const int N)
{
	Student tmp;
	for (int i0 = 0; i0 < N - 1; i0++)
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
		{
			float avg1 = (p[i1].math + p[i1].physics + p[i1].informatics) / 3;
			float avg2 = (p[i1 + 1].math + p[i1 + 1].physics + p[i1 + 1].informatics) / 3;

			if (avg1 > avg2 ||
				(avg1 == avg2 && p[i1].specialty > p[i1 + 1].specialty) ||
				(avg1 == avg2 && p[i1].specialty == p[i1 + 1].specialty &&
					p[i1].surname > p[i1 + 1].surname))
			{
				tmp = p[i1];
				p[i1] = p[i1 + 1];
				p[i1 + 1] = tmp;
			}
		}	
}

int* CreateIndexArray(Student* p, const int N)
{
	int* indexArr = new int[N];
	for (int i = 0; i < N; i++)
	{
		indexArr[i] = i;
	}

	for (int i0 = 0; i0 < N - 1; i0++)
	{
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
		{
			float avg1 = (p[indexArr[i1]].math + p[indexArr[i1]].physics + p[indexArr[i1]].informatics) / 3;
			float avg2 = (p[indexArr[i1 + 1]].math + p[indexArr[i1 + 1]].physics + p[indexArr[i1 + 1]].informatics) / 3;

			if (avg1 < avg2 ||
				(avg1 == avg2 && p[indexArr[i1]].specialty < p[indexArr[i1 + 1]].specialty) ||
				(avg1 == avg2 && p[indexArr[i1]].specialty == p[indexArr[i1 + 1]].specialty &&
					p[indexArr[i1]].surname < p[indexArr[i1 + 1]].surname))
			{
				int temp = indexArr[i1];
				indexArr[i1] = indexArr[i1 + 1];
				indexArr[i1 + 1] = temp;
			}
		}
	}

	return indexArr;
}

int BinSearch(Student* p, const int N, const string surname, const int specialty, const float avg)
{

	int L = 0, R = N - 1, m;
	do {
		m = (L + R) / 2;

		float currentAvg = (p[m].math + p[m].physics + p[m].informatics) / 3;

		if (p[m].surname == surname && p[m].specialty == specialty && currentAvg == avg)
			return m;
		if ((p[m].specialty < specialty)
			||
			(p[m].specialty == specialty &&
				p[m].surname < surname)
			||
			(p[m].specialty == specialty &&
				p[m].surname == surname &&
				currentAvg < avg))
		{
			L = m + 1;
		}
		else
		{
			R = m - 1;
		}
	} while (L <= R);
	return -1;
}

int main()
{	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "Введіть N: "; cin >> N;

	string searchSurname;
	int searchSpecialty;
	float avg;
	int found;

	Student *s = new Student[N];

	int menuItem;

	if (N <= 0)
		return 0;

	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - впорядкування масиву" << endl;
		cout << " [4] - створення індексного масиву" << endl;
		cout << " [5] - бінарний пошук" << endl << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl << endl << endl;

		switch (menuItem)
		{
		case 1:
			Create(s, N);
			break;
		case 2:
			Print(s, N);
			break;
		case 3:
			Sort(s, N);
			cout << "Масив впорядковано" << endl;
			break;
		case 4:
			cout << CreateIndexArray(s, N) << endl;
			break;
		case 5:
			cin.get();
			cin.sync();

			cout << "прізвище: "; getline(cin, searchSurname);
			cout << "спеціальність (0 - математика, 1 - фізика, 2 - комп'ютерні науки, 3 - інформатика): "; cin >> searchSpecialty;
			cout << "середній бал: "; cin >> avg;
			cout << endl;

			found = BinSearch(s, N, searchSurname, searchSpecialty, avg);

			if (found >= 0) {
				cout << "Учня знайдено";
			}
			else {
				cout << "Учня не знайдено";
			}

			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);

	return 0;
}



