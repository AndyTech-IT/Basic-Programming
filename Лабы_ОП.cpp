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

#pragma region PR 3

#include <string.h>
#include <string>

void PR_3_1() {
	string line = "";
	cout << "Введите строку: ";
	getline(cin, line);

	for (char &c : line)
	{
		if ('а' <= c && c <= 'я'
		||	'А' <= c && c <= 'Я'
		||	'ё' == c || c == 'Ё')
		{
			c = '+';
			continue;
		} 

		if ('a' <= c && c <= 'z'
		||	'A' <= c && c <= 'Z')
		{
			c = '-';
			continue;
		}

		if (c != ' ')
		{
			c = '=';
			continue;
		}
	}

	cout << "Итоговая строка : " << line << endl;
}
#include <regex>

void PR_3_2() {
	string line = "";
	cout << "Введите строку: ";
	getline(cin, line);

	regex other_regexp("[0-9\!-\-@\^\_%;:?№]");

	line = regex_replace(line, other_regexp, "=");

	regex en_regexp("[a-zA-Z]");
	
	line = regex_replace(line, en_regexp, "-");

	regex ru_regexp("[а-яА-ЯёЁ]");

	line = regex_replace(line, ru_regexp, "+");

	cout << "Итоговая строка : " << line << endl;
}
#pragma endregion


#pragma region LR 5

void LR_5_1() {
	string line = "";
	string symbols = " «.!,?:;\'\"";

	cout << "Введите строку: " << endl;
	getline(cin, line);

	bool found = true;	// Первый символ тоже надо

	for (char& c : line) 
	{
		char* index = strchr((char*)symbols.c_str(), c);
		if (index != nullptr)
		{
			found = true;
			continue;
		} 
		if (found)
		{
			c = toupper(c);

			found = false;
			continue;
		}

	}
	cout << line;
}

void LR_5_2() {
	string line = "";
	string symbols = " «.!,?:;\'\"\0";

	string long_word = "";
	string short_word = "";

	cout << "Введите строку: " << endl;
	getline(cin, line);
	line += '\0'; // Добавляем тк при считаовании его нет, а он нужен!

	bool write = true;	// Первый символ тоже надо
	string word = "";	// Буфер

	for (char& c : line) {
		char* index = strchr((char*)symbols.c_str(), c);
		if (index != nullptr)	// с - разделительный символ
		{
			if (write)	// Мы закончили слово
			{
				int len = word.length();
				if (len > long_word.length())
				{
					long_word = word;
				}

				if (len < short_word.length() || short_word.length() == 0)
				{
					short_word = word;
				}

				write = false;
			}
			continue;	// Скипаем хвост
		}

		if (write == false)	// Начало слова
		{
			word = "";
			write = true;
		}

		if (write)	// Запись слова в буфер
			word += c;
	}

	// Вывод результата
	cout << "Короткое слово: " << short_word << endl;
	cout << "Длинное слово: " << long_word;
}

#pragma endregion

#pragma region PR 4
int Fibonachi(int end)
{
	if (end <= 0)
	{
		return 0;
	}
	if (end == 1 || end == 2)
	{
		return 1;
	}
	return Fibonachi(end - 1) + Fibonachi(end - 2);
}

void PR_4() 
{
	int n;
	cout << "Номер числа фибоначи: ";
	cin >> n;
	int result = Fibonachi(n);
	cout << "Число фибоначи под номером " << n << " = " << result;
}
#pragma endregion

#pragma region LR 6
int MaxChainLenght(string str) 
{
	char chain_c = str[0];
	int max_len = 0;
	int curent_len = 0;
	for (char c : str) 
	{
		if (c == chain_c) 
		{
			curent_len++;
		}
		else
		{
			chain_c = c;
			max_len = curent_len > max_len ? curent_len : max_len;
			curent_len = 1;
		}
	}
	return max_len;
}

void LR_6_1() 
{
	string str;
	cout << "Введите строку: ";
	getline(cin, str);
	str += '\0';

	int max_len = MaxChainLenght(str);

	cout << "Длинна максимальной последовательности символов = " << max_len;
}

float GetAvarage_InRange(int arr[], int size, int index1, int index2) 
{
	int begin = max(min(index1, index2), 0) + 1;
	int end = min(max(index1, index2), size) - 1;
	if (end - begin <= 0)
		return 0;

	double summ = 0;
	for (int i = begin; i < end; i++)
		summ += arr[i];
	return summ / (end - begin);
}

void LR_6_2() 
{
	int size;
	cout << "Введите размер массива: ";
	cin >> size;

	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		cout << "Введите число " << i + 1 << " : ";
		cin >> arr[i];
	} 

	int i1, i2;

	cout << "Введите интервал(2 числа): ";
	cin >> i1 >> i2;

	double avarage = GetAvarage_InRange(arr, size, i1, i2);
	cout << "Среднее значение в интервале = " << avarage;
}

#pragma endregion

#pragma region PR 5

void F1()
{
	int a;
	int* a_ptr = &a;
	cout << "Enter a: ";
	cin >> a;
	cout << *a_ptr << endl << endl;
}
void F2()
{
	int a, b;
	cout << "Enter a, b: ";
	cin >> a >> b;
	int* pa = &a, * pb = &b;
	int summ = *pa + *pb;
	int razn = *pa - *pb;
	pa = &summ;
	pb = &razn;
	cout << "Summ = " << *pa << endl;
	cout << "Razn = " << *pb << endl;
}

void Add10(double& t)
{
	t += 10;
}

void F3()
{
	double t;
	cout << "Enter t: ";
	cin >> t;
	Add10(t);
	cout << "Result = " << t << endl;
}

const int Z = 10;

void RondomizeFilling(int* m)
{
	for (int i = 0; i < Z; i++)
	{
		*(m + i) = rand() % 100 + 1;
	}
}

void F4()
{
	int mass[Z];
	RondomizeFilling(mass);
	for (int i = 0; i < Z; i++)
	{
		cout << *(mass + i) << ' ';
	}
	cout << endl;
}

#pragma endregion

#pragma region LR 7

int FindeAvarage(double mass[], double& size)
{
	double avarage = 0;
	for (int i = 0; i < size; i++)
		avarage += *(mass + i);
	avarage /= size;
	int count = 0;
	for (int i = 0; i < size; i++)
		*(mass + i) < avarage ? count++ : NULL;
	size = avarage;
	return count;
}

void LR_7()
{
	int size;
	double* mass;
	cout << "Enter size: ";
	cin >> size;
	double avarage = size;
	mass = new double[size];
	for (int i = 0; i < size; i++)
	{
		cout << "Enter number " << i + 1 << " : ";
		cin >> *(mass + i);
	}
	int count_lower_avarage = FindeAvarage(mass, avarage);
	cout << "Numbers lower then " << avarage << " : " << count_lower_avarage << endl;
}

#pragma endregion

#pragma region LR 8

char* Cut_String(const char text[], char* &first_halh)
{
	int len = strlen(text);
	int first_half_len = len / 2;
	int second_half_len = len - first_half_len;

	first_halh = new char[first_half_len + 1]{'\0'};
	char* second_half = new char[second_half_len + 1]{'\0'};

	for (int i = 0; i < len; i++)
	{
		char c = *(text + i);
		if (i < first_half_len)
			*(first_halh + i) = c;
		else
			*(second_half + i - first_half_len) = c;			
	}
	*(first_halh + first_half_len) = '\0';
	*(second_half + second_half_len) = '\0';
	return second_half;
}

void LR_8()
{
	string line;
	cout << "Enter some text:";
	getline(cin, line);
	char* first_half;
	char* second_half;

	second_half = Cut_String(line.c_str(), first_half);

	cout << "First half: " << first_half << "\nSecond half: " << second_half;

	delete[] second_half, first_half;
}
#pragma endregion

#pragma region PR 6

void PrintBits(unsigned char data)
{
	unsigned char p = 1; // переменная для проверки разрядов
	static int size = sizeof(char) * 8; // количество бит в числе

	for (int i = 0; i < size; i++, p<<=1)
		data & p ? cout << 1 : cout << 0; // проверка разряда

	cout << endl;
}

void SwitchBit_byAdress(unsigned char& data, int n) 
{
	data ^= (1 << (n - 1));
}

void PR_6_1()
{
	unsigned char a = 0; //число, которое переводится в двоичный код
	PrintBits(a);
	int n = 0;
	while (true)
	{
		cout << "Enter n : ";
		cin >> n;
		if (n == 0)
			break;
		if (0 < n && n <= 8)
		{
			SwitchBit_byAdress(a, n);
			PrintBits(a);
		}
		else
			cout << "Wrong byte adress!" << endl;
	}
}

void PR_6_2()
{
	unsigned int a; //число, которое переводится в двоичный код

	unsigned int p = 1 << 4*7; // переменная для проверки разрядов

	int size = sizeof(int) * 8; // количество бит в числе

	cout << "Enter a number: ";
	cin >> a;

	bool first = false;

	for (int i = size - 1; i > 2; i--, p>>=1) 
	{
		if (a & p)
		{
			first = true;
			cout << 1;
		} 
		else if (first)
			cout << 0; 
	}
}

#pragma endregion



const auto RusCharset = 1251;

void main() 
{
	// 3 Вариант
	SetConsoleCP(RusCharset);
	SetConsoleOutputCP(RusCharset);
	setlocale(LC_ALL, "rus");

	PR_6_2();
	cout << endl;

	system("pause");
}


