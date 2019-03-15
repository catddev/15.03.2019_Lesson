#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>
#include<cstring>
#include<fstream>

using namespace std;

void fill_matrix(int **pp, int n, int m) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			pp[i][j] = rand() % 21;
}
void print_matrix(int**pp, int n, int m) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(3) << left << pp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void delete_matrix(int**pp, int n, int m) {
	for (int i = 0; i < n; i++)
		delete[] pp[i];
	delete[] pp;
}
void createArray(int *&a, int n) {
	a = new int[n];
}
void fillArray(int *a, int n) {
	for (int i = 0; i < n; i++)
		a[i] = rand() % 10;
}
void printArray(const int *a, int n) {
	for (int i = 0; i < n; i++)
		cout << setw(3) << a[i] << " ";
	cout << endl;
}
void deleteArray(int *&a) {
	delete[] a;
}

//Написать функцию, добавляющую строку двухмерному массиву в конец
void add_line(int **&p, int &n, int m) {
	int **tmp = new int*[n + 1];

	for (int i = 0; i < n; i++)
		tmp[i] = p[i];

	tmp[n] = new int[m];
	
	for (int i = 0; i < m; i++)
		tmp[n][i] = 0;

	delete[] p;
	p = tmp;
	n++;
}

//	Написать функцию, добавляющую строку двухмерному массиву в начало.
void add_first_line(int **&p, int &n, int m) {
	int **tmp = new int*[n + 1];

	for (int i = 0; i < n; i++)
		tmp[i+1] = p[i];

	tmp[0] = new int[m];

	for (int i = 0; i < m; i++)
		tmp[0][i] = 1;

	delete[] p;
	p = tmp;
	n++;
}
// Написать функцию, добавляющую строку двухмерному массиву в указанную позицию.
void add_any_line(int **&p, int &n, int m, int pos) {
	int **tmp = new int*[n + 1];

	for (int i = 0; i < pos; i++)
		tmp[i] = p[i];

	tmp[pos] = new int[m];
	for (int i = 0; i < m; i++)
		tmp[pos][i] = 88;

	for (int i = pos; i < n+1; i++)
		tmp[i+1] = p[i];

	delete[] p;
	p = tmp;
	n++;
}
// Написать функцию, удаляющую строку двухмерного массива по указанному номеру.
void erase_line(int **&pp, int &n, int m, int pos) {
	int **tmp = new int*[n - 1];

	for (int i = 0; i < pos; i++)
		tmp[i] = pp[i];

	for (int i = pos+1; i < n + 1; i++)
		tmp[i - 1] = pp[i];

	delete[] pp;
	pp = tmp;
	n--;
}
// Написать функцию, добавляющую столбец двухмерному массиву в указанную позицию.
void add_any_col(int **&p, int n, int &m, int pos) {
	int **tmp = new int*[n];

	for (int i = 0; i < n; i++)
		tmp[i] = new int[m + 1]; // необходимо перевыделить память, т.к. невозможно переназначить указатель, нет указателя на адрес столбца

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < pos; j++)
			tmp[i][j] = p[i][j];
		
		tmp[i][pos] = 77;

		for (int j = pos; j < m + 1; j++)
			tmp[i][j+1] = p[i][j];
	}

	delete[] p;
	p = tmp;
	m++;
}

// Написать функцию, удаляющую столбец двухмерного массива по указанному номеру
void erase_any_col(int **&p, int n, int &m, int pos) {
	int **tmp = new int*[n];

	for (int i = 0; i < n; i++)
		tmp[i] = new int[m - 1];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < pos; j++)
			tmp[i][j] = p[i][j];

		for (int j = pos; j < m - 1; j++)
			tmp[i][j] = p[i][j+1];
	}

	delete[] p;
	p = tmp;
	m--;
}

// Напишите функцию для обращения одномерного массива в N - мерный.Должны выполняться соответствующие проверки.
void reform_array(int *a, int n, int**&pp, int &nn, int &m) {
	
	int c = 0;
	if (n%nn == 0)
	{
		m = n / nn;
		pp = new int*[nn];
		for (int i = 0; i < nn; i++)
			pp[i] = new int[m];

		int k = 0;
		for (int i = 0; i < nn; i++)
			for (int j = 0; j < m; j++)
				pp[i][j] = a[k++];
	}
	else
	{
		c = n % nn;
		n = n - c;
		m = n / nn;
		pp = new int*[nn+1];
		for (int i = 0; i < nn+1; i++)
			pp[i] = new int[m];

		int k = 0;
		for (int i = 0; i < nn; i++)
			for (int j = 0; j < m; j++)
				pp[i][j] = a[k++];

		for (int i = 0; i < c; i++)
			pp[nn][i] = a[k++];
		/*for (int i = c; i < m; i++)
			pp[nn][i] = 88;*/

		nn++;
	}
		
}




int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn; cin.get();

		switch (tn)
		{
		case 1:
		{
			int *p, **p1;
			int a;
			p1 = &p;
			p = &a;
			a = 100;
			cout << *(*p1) << endl;
		}
		break;
		case 2:
		{
			int a[4][2];
			//for (int i = 0; i < 4; i++)
				//cout << a[i] << endl;

			cout << a[0] << endl; //используя для матрицы одинарный индекс получаем только адреса 
			cout << a[0] + 2 << endl;
		}
		break;
		case 3:
		{
			int n, m;
			cin >> n >> m;
			int **p = new int*[n];

			for (int i = 0; i < n; i++)
				p[i] = new int[m]; //массивы строк между собой не связаны, т.е. адреса отдельных строк не последовательны

			//p[0][0] = 1000;

			int k = 1;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					p[i][j] = k++;
					cout << p[i][j] << " ";
				}
				cout << endl;
			}

			for (int i = 0; i < n; i++)
				delete[] p[i];
			delete[] p;
		}
		break;
		case 4:
		{
			int n, m;
			cin >> n >> m;
			int **p = new int*[n];
			for (int i = 0; i < n; i++)
				p[i] = new int[m];
			cout << endl;

			fill_matrix(p, n, m);
			add_first_line(p, n, m);
			add_line(p, n, m);
			add_any_line(p, n, m, 3);
			add_any_col(p, n, m, 6);
			print_matrix(p, n, m);
			erase_line(p, n, m, 5);
			erase_any_col(p, n, m, 7);
			print_matrix(p, n, m);
			delete_matrix(p, n, m);
		}
		break;
		case 5:
		{
			int *a, **p;
			int n, nn, m = 0;
			cin >> n >> nn;
			
			//m = n / nn;

			createArray(a, n);
			fillArray(a, n);
			printArray(a, n);
			cout << endl;

			reform_array(a, n, p, nn, m);
			print_matrix(p, nn, m); //nn only!

			deleteArray(a);
			delete_matrix(p, nn, m); //nn
		}
		break;
		case 6:
		{

		}
		break;
		case 7:
		{

		}
		break;
		case 8:
		{

		}
		break;
		case 9:
		{

		}
		break;
		case 10:
		{

		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}