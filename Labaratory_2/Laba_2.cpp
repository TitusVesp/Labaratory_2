#include "Laba_2.h"

void ShowTask(int x, int rad, string** matrix, int, int);
void Zadacha8()
{
	cout << "Задаються n пар чисел, якi задають багатокутник без самоперетинiв.\n\
 Знайти його площу та периметр. Формула" << endl;
	srand(time(NULL));

	int n = 0;
	double squre = 0.0, perimeter = 0.0;

	cout << "Ведiть розмiрнiсть масиву: " << endl;
	cin >> n;

	if (2 > n) { cout << "Incorrect input N!" << endl; return; }

	double* arrX = new double[n];
	double* arrY = new double[n];

	for (int i = 0; i < n; i++)
	{
		cout << "Ведiть Х" << i << " :" << endl;
		cin >> arrX[i];
		cout << "Ведiть Y" << i << " :" << endl;
		cin >> arrY[i];
	}

	for (int i = 0; i < n - 1; i++)	squre += (((arrY[i] + arrY[i + 1]) / 2) * (arrX[i + 1] - arrX[i]));

	for (int i = 0; i < n; i++)
	{
		if (i != n - 1) perimeter += sqrt((arrX[i + 1] - arrX[i]) * (arrX[i + 1] - arrX[i]) + (arrY[i + 1] - arrY[i]) * (arrY[i + 1] - arrY[i]));
		else perimeter += sqrt((arrX[0] - arrX[i]) * (arrX[0] - arrX[i]) + (arrY[0] - arrY[i]) * (arrY[0] - arrY[i]));
	}

	if (squre <= 0 || perimeter <= 0)
	{
		cout << "Не коректне введення!" << endl;
	}
	else
	{
		cout << "Площа: " << squre << endl;
		cout << "Периметир: " << perimeter << endl;
	}

	delete[]arrX;
	delete[]arrY;
}

void Zadacha20()
{
	cout << "Задано правильний трикутник. По його поверхнi котиться коло,\n\
на ободi якого зафiксована точка.Змоделювати траєкторiю цiєї точки.  " << endl;
	int sideTriangle = 5, radius = 2, sRad = 0, n = 0;
	cout << "Input side of Triangle: " << endl;
	cin >> sideTriangle;
	cout << "Input radius of Circle: " << endl;
	cin >> radius;
	if (sideTriangle < 3 || radius < 2) { cout << "Side of Triendle is too small or radius < 2" << endl; return; }
	if (radius == 1)  n = sideTriangle * (radius * 2);
	else  n = sideTriangle * radius;
	sRad = radius;
	radius = 1.5 * radius;
	string** matrix = new string * [n];
	for (int i = 0; i < n; i++)
		matrix[i] = new string[n];

	for (int i = 0; i < n; i++)	for (int j = 0; j < n; j++) matrix[i][j] = "  ";

	ShowTask(sideTriangle, radius, matrix, sRad, n);

	

	for (int i = 0; i < n; i++)
		delete[] matrix[i];

	delete[]matrix;
}

void ShowMatrix(int n, string** matrix)
{
	system("cls");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << matrix[i][j];
		cout << endl;
	}

}

void ShowTask(int sideT, int rad, string** matrix, int sRad, int n)
{
	bool f1 = false;
	sideT--;

	for (int i = sRad; i <= (sideT + sRad); i++)
	{
		for (int j = 0; j <= i; j++)
		{
			matrix[i][j] = "  ";
			f1 = false;
		}
		for (int j = (sideT + sRad); j >= i; j--)
		{
			if (j == i || i == sRad)
			{
				matrix[i][j] = " *";
				continue;
			}
			if (f1)
			{
				matrix[i][j] = "  ";
			}
			else
			{
				matrix[i][j] = " *";
				f1 = true;
			}

		}
		cout << endl;
	}

	ShowMatrix(n, matrix);
	for (int k = 0, f = 1; k < sideT; k += rad * 2, f++)
		for (int i = 0; i <= sRad; i++)
		{
			for (int j = sRad + k - f; j <= sRad + rad * 2 + k; j++)
			{
				if (j == sRad + rad - i + k - f || j == sRad + rad + i + k - f)
					matrix[i][j] = " +";
				ShowMatrix(n, matrix);
			}
			ShowMatrix(n, matrix);
		}

	int g = 0;
	for (int k = 0, f = 1; k < sideT; k += rad * 2, f++)
		for (int i = 2 * sRad + sideT, g = 0; i >= sRad + sideT; i--)
		{
			for (int j = sRad + k - f; j <= sRad + sideT + k; j++)
			{
				if (j == sRad + rad - g + k - f || j == sRad + rad + g + k - f)
					matrix[j][i] = " +";
				ShowMatrix(n, matrix);
			}
			g++;
			ShowMatrix(n, matrix);
		}

	for (int k = 0; k < sideT; k += sRad * 2)
		for (int i = 0, d = 0; i <= sRad; i++, d++)
		{
			for (int j = sRad + k, g = k; j < sRad + sideT; j++)
			{
				if (j == sRad + rad - i - d + k || j == sRad + rad + i + k)
					matrix[j][i + g] = " +";
				ShowMatrix(n, matrix);
				g++;
			}
			ShowMatrix(n, matrix);
		}
}