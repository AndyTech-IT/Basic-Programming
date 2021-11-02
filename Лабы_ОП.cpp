#include <iostream>
#include <Windows.h>

using namespace std;

#pragma region LR 2
enum class Month 
{
	January = 1, // Начинаем с 1 (по умолчанию начинается с 0)
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};
void LR_2_2()
{
	int month_num = 0;
	bool selected = false;

	char* month_name;
	char* season_name;

	cout << "Введите номер месяца: ";
	cin >> month_num;

	switch ((Month)month_num)
	{
	case Month::January:
		month_name = new char[] {"Январь"};
		season_name = new char[] {"Зима"};
		break;

	case Month::February:
		month_name = new char[] {"Февраль"};
		season_name = new char[] {"Зима"};
		break;

	case Month::March:
		month_name = new char[] {"Март"};
		season_name = new char[] {"Весна"};
		break;

	case Month::April:
		month_name = new char[] {"Апрель"};
		season_name = new char[] {"Весна"};
		break;

	case Month::May:
		month_name = new char[] {"Май"};
		season_name = new char[] {"Весна"};
		break;

	case Month::June:
		month_name = new char[] {"Июнь"};
		season_name = new char[] {"Лето"};
		break;

	case Month::July:
		month_name = new char[] {"Июль"};
		season_name = new char[] {"Лето"};
		break;

	case Month::August:
		month_name = new char[] {"Август"};
		season_name = new char[] {"Лето"};
		break;

	case Month::September:
		month_name = new char[] {"Сентябрь"};
		season_name = new char[] {"Осень"};
		break;

	case Month::October:
		month_name = new char[] {"Октябрь"};
		season_name = new char[] {"Осень"};
		break;

	case Month::November:
		month_name = new char[] {"Ноябрь"};
		season_name = new char[] {"Осень"};
		break;

	case Month::December:
		month_name = new char[] {"Декабрь"};
		season_name = new char[] {"Зима"};
		break;

	default:
		cout << "Ошибка";
		return;
	}

	// Вывод результата
	printf(" Месяц: %s \n Время года: %s \n", month_name, season_name);

	// Очистка памяти
	delete[] month_name;
	delete[] season_name;
}
#pragma endregion

#pragma region LR 3
void LR_3_1() 
{
	int summ = 0;
	int end = 0;
	int interval = 0;

	cout << "Введите конечное число: ";
	cin >> end;

	cout << "Введите интервал: ";
	cin >> interval;

	// Вычисление суммы
	for (int i = interval; i <= end; i += interval) 
	{
		// Вывод действий по порядку
		i == interval 
		?	cout << i 
		:	cout << " + " << i;

		summ += i;
	}
	// Вывод результата
	cout << " = " << summ;
}

void LR_3_2() 
{
	int height = 0;

	cout << "Введите высоту пирамиды: ";
	cin >> height;

	for (int i = 0; i < height; i++) 
	{
		// Количество символов в строке
		int len = 1 + i * 2;
		// Строка символов
		char* line = new char[len+1] {}; // +1 тк надо ещё одну ячейку под \0 который завершает строку корректно
		// Заполнение строки символами
		for (int j = 0; j < len; j++) 
		{
			line[j] = '^';
		}
		// Вывод строки
		printf(" %*s \n", height + len / 2, line);

		// Очистка памяти
		delete[] line;
	}
}
#pragma endregion

#pragma region LR 4
void LR_4_1() 
{
	int arr_size = 0;
	int* arr;

	int zero_count = 0;

	bool found_start = false;
	int start = 0;

	bool found_end = false;
	int end = 0;

	const int max = 100;
	const int min = -100;

	int summ = 0;

	cout << "Введите размер массива: ";
	cin >> arr_size;

	arr = new int[arr_size] {};
	// Заполнение массива случайными числами не равными 0
	for (int i = 0; i < arr_size;	) 
	{
		int value = rand() % (abs(max - min) + 1) + min; // Случайное число на интервале: [min; max]
		if (value != 0)
		{
			arr[i] = value; 
			i++;	// Пока не получится число не равное 0 перехода не будет
		}
	}

	cout << "Введите число нулевых элементов: ";
	cin >> zero_count;

	bool first_iteration = true;
	for (int i = 0; i < zero_count;	)
	{
		// Вывод сообщения при первой итерации
		if (first_iteration) 
		{
			cout << "Введите индексы нулевых элементов:\n";
			first_iteration = false;
		}

		int index = 0;
		cin >> index;

		if (0 <= index 
		&&	index < arr_size)
		{
			arr[index] = 0;
			i++;	// Пока не получит индекс в пределах масива перехода не будет
		}
		else
		{
			cout << "Индекс за пределами массива!" << endl;
		}
	}

	// Вывод массива и поиск нулей
	cout << '|';	// Первая граница
	for (int i = 0; i < arr_size; i++)
	{
		printf("% -4d|", arr[i]);		// Вывод числа и границы
		if (found_start == false 
		&&	arr[i] == 0)				// Первый ноль найден!
		{
			start = i;
			found_start = true;
		}
		else
			if (arr[i] == 0)			// Второй ноль найден
			{
				end = i;
				found_end = true;
			}
	}
	cout << endl;

	// Вывод результата
	cout << "Сумма";
	if (found_start == false)	// Нулей нет
	{
		cout << " = 0";
	}
	else 
	{
		if (found_end == false)	// Ноль одит
		{
			end = start;
			start = 0;
		}
		else
		{
			start++;	// Убираем начальный ноль из суммы
		}

		// Вычисление суммы
		for (int i = start; i < end; i++) 
		{
			i == start ? cout << ' ' << arr[i] : cout << " + " << arr[i];	// Вывод порядка действий
			summ += arr[i];
		}

		cout << " = " << summ;	// Результат
	}

	// Очистка памяти
	delete[] arr;
}

void LR_4_2() 
{
	int rows = 0;
	int cols = 0;
	int** arr;

	cout << "Введите число строк: ";
	cin >> rows;

	cout << "Введите число столбцов: ";
	cin >> cols;

	// Инициализация
	arr = new int* [rows];

	// Число зависываемое в ячейку
	int num = 0;
	for (int row = 0; row < rows; row++) 
	{
		arr[row] = new int[cols];

		if (row % 2 == 0)
		{
			for (int col = 0; col < cols; col++)		// Если чётная строка: слева на право
			{
				arr[row][col] = num++;
			}
		}
		else
		{
			for (int col = cols - 1; col >= 0; col--)	// Если не чётная строка: справа на лево
			{
				arr[row][col] = num++;
			}
		}
	}

	// Верхняя граница таблицы
	for (int i = 0; i < cols; i++) {
		cout << "-----";
	}
	cout << "-\n"; // Хвост..

	for (int row = 0; row < rows; row++) {
		cout << '|'; // Первая граница столбца

		// Строка
		for (int col = 0; col < cols; col++) 
			printf("%-4d|", arr[row][col]);		// Число и перегородка:	"12  |"
		cout << '\n'; // Переход на след строку...

		// Граница
		for (int i = 0; i < cols; i++)
			cout << "-----";
		cout << "-\n"; // Хвост..
	}

	// Очистка памяти
	for (int row = 0; row < rows; row++)
	{
		delete[] arr[row];
	}
	delete[] arr;
}
#pragma endregion



void main() 
{
	SetConsoleCP(RUSSIAN_CHARSET);
	SetConsoleOutputCP(RUSSIAN_CHARSET);
	setlocale(LC_ALL, "rus");

	LR_4_2();
	cout << endl;

	system("pause");
}


