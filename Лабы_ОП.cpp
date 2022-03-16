#include <iostream>
#include <Windows.h>
#include <string.h>
#include <string>
#include <regex>
#include <math.h>
#include <stdio.h>
#include <exception>
#include <fstream>

using namespace std;

namespace Sem_1
{

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
					? cout << i
					: cout << " + " << i;

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
				char* line = new char[len + 1]{}; // +1 тк надо ещё одну ячейку под \0 который завершает строку корректно
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
			for (int i = 0; i < arr_size; )
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
			for (int i = 0; i < zero_count; )
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
					&& index < arr_size)
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
					&& arr[i] == 0)				// Первый ноль найден!
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


		void PR_3_1() {
			string line = "";
			cout << "Введите строку: ";
			getline(cin, line);

			for (char& c : line)
			{
				if ('а' <= c && c <= 'я'
					|| 'А' <= c && c <= 'Я'
					|| 'ё' == c || c == 'Ё')
				{
					c = '+';
					continue;
				}

				if ('a' <= c && c <= 'z'
					|| 'A' <= c && c <= 'Z')
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

		char* Cut_String(const char text[], char*& first_halh)
		{
			int len = strlen(text);
			int first_half_len = len / 2;
			int second_half_len = len - first_half_len;

			first_halh = new char[first_half_len + 1]{ '\0' };
			char* second_half = new char[second_half_len + 1]{ '\0' };

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

			for (int i = 0; i < size; i++, p <<= 1)
				data& p ? cout << 1 : cout << 0; // проверка разряда

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

			unsigned int p = 1 << 4 * 7; // переменная для проверки разрядов

			int size = sizeof(int) * 8; // количество бит в числе

			cout << "Enter a number: ";
			cin >> a;

			bool first = false;

			for (int i = size - 1; i > 2; i--, p >>= 1)
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

}

namespace Sem_2 
{
	#pragma region PR 0

	enum class MenuCommand
	{
		Exit,
		Add,
		Delete,
		Show_All,
		Sort,
		Show_Chipest
	};

	enum class PartType
	{
		CPU = 1,
		VideoCard,
		AudioCard,
		RAM,
		Сooler,
		HDD,
		SSD
	};

	MenuCommand ShowMenu()
	{
		cout << "Actions list:" << endl;
		cout << "0) Exit" << endl;
		cout << "1) Add new" << endl;
		cout << "2) Delete by number" << endl;
		cout << "3) Show all" << endl;
		cout << "4) Sort by price" << endl;
		cout << "5) Show chipest in groups" << endl;
		cout << "Select action: ";

		int comand_num;
		cin >> comand_num;
		cout<< endl;

		if (comand_num < 0 || 5 < comand_num)
		{
			cout << "Wrong command number!" << endl;
			return ShowMenu();
		}

		return (MenuCommand)comand_num;
	}

	PartType ShowPartTypes()
	{
		cout << "Part types list:" << endl;
		cout << "1) CPU" << endl;
		cout << "2) VideoCard" << endl;
		cout << "3) AudioCard" << endl;
		cout << "4) RAM" << endl;
		cout << "5) Сooler" << endl;
		cout << "6) HDD" << endl;
		cout << "7) SSD" << endl;
		cout << "Select type: ";

		int type_num;
		cin >> type_num;

		if (type_num < 1 || 7 < type_num)
		{
			cout << "Wrong command number!" << endl;
			return ShowPartTypes();
		}

		return (PartType)type_num;
	}

	string Get_PartType_Name(PartType type)
	{
		switch (type)
		{
		case PartType::CPU:
			return "CPU";
			break;
		case PartType::VideoCard:
			return "Video Card";
			break;
		case PartType::AudioCard:
			return "Audio Card";
			break;
		case PartType::RAM:
			return "RAM";
			break;
		case PartType::Сooler:
			return "Сooler";
			break;
		case PartType::HDD:
			return "HDD";
			break;
		case PartType::SSD:
			return "СSSD";
			break;
		default:
			return "";
		}
	}

	void Add(string *names, PartType *types, double *prices, int& count, const int max_count)
	{
		if (count == max_count)
		{
			cout << "Cant add new part!" << endl;
			return;
		}

		cout << "Enter new part name: ";
		cin >> names[count];

		types[count] = ShowPartTypes();

		cout << "Enter part price: ";
		cin >> prices[count];

		count++;
	}

	void Delete(string* names, PartType* types, double* prices, int& count, const int max_count)
	{
		int number;
		switch (count)
		{
		case 0:
			cout << "Array is empty!" << endl;
			return;
		case 1:
			number = 0;
		default:
			cout << "Enter deleting part number (" << 1 << " - " << count << "):" << endl;;
			cin >> number;
			break;
		}

		if (number < 1 || count < number)
		{
			cout << "Wrong number!";
			return Delete(names, types, prices, count, max_count);
		}

		cout << "You shure? " << names[number - 1] << " will deleted!" << endl;
		cout << "Y or N: ";
		char agree;
		cin >> agree;

		if (agree != 'Y' && agree != 'y')
			return;

		for (int i = number; i < count; i++)
		{
			names[i - 1] = names[i];
			types[i - 1] = types[i];
			prices[i - 1] = prices[i];
		}

		count--;
	}

	void ShowAll(string* names, PartType* types, double* prices, int& count, const int max_count)
	{
		if (count == 0)
		{
			cout << "Array is empty!" << endl;
			return;
		}

		cout << "Parts table:" << endl;
		printf_s("-----------------------------------------------\n");
		for (int i = 0; i < count; i++)
		{
			printf_s("| %20s | %10s | %07g |\n", names[i].c_str(), Get_PartType_Name(types[i]).c_str(), prices[i]);
			printf_s("-----------------------------------------------\n");
		}
	}


	void Sort(string* names, PartType* types, double* prices, int& count, const int max_count)
	{
		for (int i = 0; i < count; i++)
		{
			for (int j = 0; j < count - i - 1; j++)
				if (prices[j] < prices[j + 1])
				{
					string temp_n = names[j];
					PartType temp_t = types[j];
					double temp_p = prices[j];

					names[j] = names[j + 1];
					types[j] = types[j + 1];
					prices[j] = prices[j + 1];

					names[j + 1] = temp_n;
					types[j + 1] = temp_t;
					prices[j + 1] = temp_p;
				}
		}
	}

	void Show_Chipest(string* names, PartType* types, double* prices, int& count, const int max_count)
	{
		int tupes_min_nums[7] = {-1, -1, -1, -1, -1, -1, -1};
		for (int i = 0; i < count; i++)
		{
			int group_index = (int)types[i] - 1;
			int min_index = tupes_min_nums[group_index];
			if (min_index == -1 || prices[min_index] > prices[i])
				tupes_min_nums[group_index] = i;
		}

		for (int i = 0; i < 7; i++)
		{
			int index = tupes_min_nums[i];
			if (index != -1)
			{
				cout << "Chipest " << Get_PartType_Name(types[index]) << " part: " << endl;
				cout << "\t" << names[index] << " by cost " << prices[index] << endl;
			}
			
		}
	}

	void PR_0()
	{
		const int MAX_COUNT = 10;
		string names[MAX_COUNT];
		PartType types[MAX_COUNT];
		double prices[MAX_COUNT];
		int curent_count = 0;

		while (true)
		{
			switch (ShowMenu())
			{
			case MenuCommand::Add:
				Add(names, types, prices, curent_count, MAX_COUNT);
				break;
			case MenuCommand::Delete:
				Delete(names, types, prices, curent_count, MAX_COUNT);
				break;
			case MenuCommand::Show_All:
				ShowAll(names, types, prices, curent_count, MAX_COUNT);
				break;
			case MenuCommand::Sort:
				Sort(names, types, prices, curent_count, MAX_COUNT);
				break;
			case MenuCommand::Show_Chipest:
				Show_Chipest(names, types, prices, curent_count, MAX_COUNT);
				break;
			case MenuCommand::Exit:
			default:
				return;
			}
			cout << endl;
		} 
	}

	#pragma endregion

	namespace LR_1
	{
	#pragma region General

		struct Point3
		{
			int x;
			int y;
			int z;
		};

		void Print(Point3 points[], int count)
		{
			for (int i = 0; i < count; i++)
			{
				cout << "Vector " << i << ": (" << points[i].x << ", " << points[i].y << ", " << points[i].z << ");" << endl;
			}
		}

		Point3 Get_Niarest_To_Center(Point3 points[], int count)
		{
			double shortest_distance = -1;
			Point3 nearest_point;
			int i = 0;
			do {
				Point3 point = points[i];
				double distance = sqrt(pow(point.x, 2) + pow(point.y, 2) + pow(point.z, 2));
				if (shortest_distance == -1 || shortest_distance > distance)
				{
					shortest_distance = distance;
					nearest_point = point;
				}
				i++;
			} while (i < count);
			return nearest_point;
		}

		void General_1()
		{
			Point3 points[6]{ {1, 2, 3}, {1, 2, -2} , {1, 1, 0}, {1, 1, 1}, {1, 0, 0}, {-1, -2, 1} };
			Print(points, 6);
			cout << endl;
			Point3 nearest[] = { Get_Niarest_To_Center(points, 6) };
			cout << "Nearest is ";
			Print(nearest, 1);
			cout << endl;
		}

		union Int_With_Binary
		{
			struct Bin_Int 
			{
				unsigned short int b1  : 1;
				unsigned short int b2  : 1;
				unsigned short int b3  : 1;
				unsigned short int b4  : 1;
				unsigned short int b5  : 1;
				unsigned short int b6  : 1;
				unsigned short int b7  : 1;
				unsigned short int b8  : 1;
				unsigned short int b9  : 1;
				unsigned short int b10 : 1;
				unsigned short int b11 : 1;
				unsigned short int b12 : 1;
				unsigned short int b13 : 1;
				unsigned short int b14 : 1;
				unsigned short int b15 : 1;
				unsigned short int b16 : 1;
			} Binary;
			int Decemal;
		};

		void General_2()
		{
			Int_With_Binary test;
			cin >> test.Decemal;

			cout << test.Binary.b16;
			cout << test.Binary.b15;
			cout << test.Binary.b14;
			cout << test.Binary.b13;
			cout << test.Binary.b12;
			cout << test.Binary.b11;
			cout << test.Binary.b10;
			cout << test.Binary.b9;
			cout << test.Binary.b8;
			cout << test.Binary.b7;
			cout << test.Binary.b6;
			cout << test.Binary.b5;
			cout << test.Binary.b4;
			cout << test.Binary.b3;
			cout << test.Binary.b2;
			cout << test.Binary.b1;

			cout << endl;
		}

	#pragma endregion


	#pragma region Individual

		const int SIZE = 10;
		struct Person
		{
			struct
			{
				string SecondName;
				string FirstName;
				bool Has_MidleName = false;
				string MidleName;
			} Name;
			string Adress;
			string Phone_Number;
		};

		string Get_FIO(const Person p)
		{
			return p.Name.SecondName + ' ' + p.Name.FirstName + ' ' + (p.Name.Has_MidleName ? p.Name.MidleName : "");
		}

		void Print(Person p)
		{
			cout << "Person: " << Get_FIO(p) << endl;
			cout << "- Adress:\t" << p.Adress << endl;
			cout << "- Phone:\t" << p.Phone_Number << endl;
		}

		Person Enter_Person_Data()
		{
			Person creating_person;
			cout << "Enter second name: ";
			cin >> creating_person.Name.SecondName;
			cout << "Enter first name: ";
			cin >> creating_person.Name.FirstName;

			cout << "Has middle name? (Y/N): ";
			char c;
			cin >> c;

			if (c == 'Y' || c == 'y')
			{
				cout << "Enter midle name: ";
				cin >> creating_person.Name.MidleName;
				creating_person.Name.Has_MidleName = true;
			}

			cout << "Enter adress: ";
			cin >> creating_person.Adress;
			cout << "Enter phone number: ";
			cin >> creating_person.Phone_Number;

			return creating_person;
		}


		enum class MenuCommand
		{
			Exit,
			Create,
			Sort,
			Edit,
			Delete,
			Show_All,
			Search
		};

		MenuCommand Choose_Command()
		{
			cout << "0) Exit" << endl;
			cout << "1) Create new Person" << endl;
			cout << "2) Sort Persons list" << endl;
			cout << "3) Edit existing Person" << endl;
			cout << "4) Delete Person" << endl;
			cout << "5) Print all Persons" << endl;
			cout << "6) Search Person by FIO" << endl;

			int i;
			cout << "Enter command number: ";
			cin >> i;
			cout << endl;

			if (i < 0 || 6 < i)
			{
				cout << "Wrong command!" << endl;
				return Choose_Command();
			}
			else
				return (MenuCommand)i;
		}


		void Create_Person(Person* arr, int& count)
		{
			if (count == SIZE)
			{
				cout << "Array is full!" << endl;
				return;
			}

			Person p = Enter_Person_Data();
			arr[count++] = p;
		}


		void Sort(Person* arr, const int count)
		{
			for (int loop = 0; loop < count; loop++)
			{
				for (int i = 0; i < count - loop - 1; i++)
				{
					string fio1 = Get_FIO(arr[i]);
					string fio2 = Get_FIO(arr[i+1]);
					if (fio1 > fio2)
					{
						Person temp = arr[i];
						arr[i] = arr[i + 1];
						arr[i + 1] = temp;
					}
				}
			}
		}


		void Edit(Person* arr, const int count)
		{
			cout << "Enter Person number: ";
			int i;
			cin >> i;
			if (i < 0 || count < i)
			{
				cout << "Index out of range!" << endl;
				return;
			}

			arr[i] = Enter_Person_Data();
		}


		void Delete(Person* arr, int& count)
		{
			cout << "Enter Person number: ";
			int index;
			cin >> index;
			if (index < 0 || count < index)
			{
				cout << "Index out of range!" << endl;
				return;
			}

			cout << "Delete person:" << endl;
			Print(arr[index]);
			cout << "Y/N: ";
			char c;
			cin >> c;

			if (c != 'y' && c != 'Y')
			{
				cout << "Canceling.." << endl;
				return;
			}

			count--;

			for (int i = index; i < count; i++)
			{
				arr[i] = arr[i + 1];
			}

			cout << "Deleted" << endl;
		}


		void Print_All(const Person* arr, const int count)
		{
			if (count == 0)
			{
				cout << "Array is empty!" << endl;
				return;
			}

			cout << "Persons in array:" << endl;
			for (int i = 0; i < count; i++)
			{
				Print(arr[i]);
			}
		}


		void Search(const Person* arr, const int count)
		{
			cout << "Enter part of FIO: ";
			char finding[255];
			cin.ignore();
			cin.getline(finding, 254);

			for (int i = 0; i < count; i++)
			{
				string fio = Get_FIO(arr[i]);
				if (fio.find(finding) != -1)
					Print(arr[i]);
			}
		}


		void Loop()
		{
			MenuCommand c;
			Person arr[SIZE];
			int count = 0;

			while (true)
			{
				c = Choose_Command();
				switch (c)
				{
				case MenuCommand::Create:
					Create_Person(arr, count);
					break;
				case MenuCommand::Sort:
					Sort(arr, count);
					Print_All(arr, count);
					break;
				case MenuCommand::Edit:
					Edit(arr, count);
					break;
				case MenuCommand::Delete:
					Delete(arr, count);
					break;
				case MenuCommand::Show_All:
					Print_All(arr, count);
					break;
				case MenuCommand::Search:
					Search(arr, count);
					break;

				case MenuCommand::Exit:
					return;
				default:
					throw "Wrong command!";
				}

				cout << endl;
			}
		}

		void Individual()
		{
			Loop();
		}

	#pragma endregion


	#pragma region Additional

		struct Line_OR_Int_Array
		{
			static const int arr_size = 10;
			static const int line_size = 20;
			int curent_size = arr_size;
			union {
				int Numbers[Line_OR_Int_Array::arr_size];
				char Lines[Line_OR_Int_Array::arr_size][Line_OR_Int_Array::line_size];
			} Data;
			bool Is_Line = false;
		};

		void Additional()
		{
			Line_OR_Int_Array arr;

			cout << "Enter Data type (S, N): ";
			char c;
			cin >> c;
			if (c == 'N' || c == 'n')
			{
				cout << "Enter -1 to finish entering." << endl;
				arr.Is_Line = false;
				for (int i = 0; i < Line_OR_Int_Array::arr_size; i++)
				{
					cout << "Enter " << i + 1 << " number: ";
					cin >> arr.Data.Numbers[i];
					if (arr.Data.Numbers[i] == -1)
					{
						arr.curent_size = i;
						break;
					}
				}
			}

			if (c == 'S' || c == 's')
			{
				cout << "Enter Stop to finish entering." << endl;
				arr.Is_Line = true;
				for (int i = 0; i < Line_OR_Int_Array::arr_size; i++)
				{
					cout << "Enter " << i + 1 << " line: ";
					cin >> arr.Data.Lines[i];
					if (!strcmp(arr.Data.Lines[i], "stop") || !strcmp(arr.Data.Lines[i], "Stop"))
					{
						arr.curent_size = i;
						break;
					}
				}
			}

			cout << "Entering finished." << endl;

			if (arr.Is_Line)
				for (int i = 0; i < arr.curent_size; i++)

					cout << "Line " << i + 1 << " : " << arr.Data.Lines[i] << endl;
			else
				for (int i = 0; i < arr.curent_size; i++)
					cout << "Number " << i + 1 << " : " << arr.Data.Numbers[i] << endl;
		}

#pragma endregion


		void All()
		{
			cout << "General 1:" << endl;
			General_1();

			cout << endl << "General 2:" << endl;
			General_2();

			cout << endl << "Individual:" << endl;
			Individual();

			cout << endl << "Additional:" << endl;
			Additional();
		}
	}

	namespace LR_2
	{
		using Person = LR_1::Person;
		using MenuCommand = LR_1::MenuCommand;


	#pragma region General

		struct DemoList
		{
			DemoList* Next = NULL;
			DemoList* Previous = NULL;

			int Data;
		};

		enum class List_Command
		{
			Exit,
			Next,
			Back,
			Add_In_Tail,
			Edit_Curent

		};

		List_Command Show_Menu()
		{
			cout << endl;
			cout << "0) Exit" << endl;
			cout << "1) Next" << endl;
			cout << "2) Back" << endl;
			cout << "3) Add" << endl;
			cout << "4) Edit" << endl;
			int i;
			cout << "Command number: ";
			cin >> i;
			if (i < 0 || i > 4)
			{
				cout << "Wrong command number!" << endl;
				return Show_Menu();
			}
			else
				return (List_Command)i;
		}

		void Next(DemoList*& curent)
		{
			if (curent == NULL)
			{
				cout << "Curent is EMPTY!" << endl;
				return;
			}

			if (curent->Next)
				curent = curent->Next;
			else
				cout << "Next is missing!" << endl;
		}
		void Back(DemoList*& curent)
		{
			if (curent == NULL)
			{
				cout << "Curent is EMPTY!" << endl;
				return;
			}

			if (curent->Previous)
				curent = curent->Previous;
			else
				cout << "Previous is missing!" << endl;
		}

		void Add_In_Tail(DemoList*& head, DemoList*& tail)
		{
			if (tail && head)
			{
				tail->Next = new DemoList();
				tail->Next->Previous = tail;
				tail = tail->Next;
			}
			else
			{
				head = new DemoList();
				tail = head;
			}

			cout << "Enter new data: ";
			cin >> tail->Data;
		}
		void Edit_Data(DemoList*& curent)
		{
			if (curent)
			{
				cout << "Enter new data: ";
				cin >> curent->Data;
			}
			else
			{
				cout << "Curent is EMPTY!" << endl;
			}
		}

		void List_Manager(DemoList* head = NULL, DemoList* tail = NULL, DemoList* curent = NULL)
		{
			if (curent == NULL)
				if (head)
					curent = head;
				else
					cout << "Curent is EMPTY!" << endl;

			if (curent)
				cout << "Curent data: " << curent->Data << endl;

			List_Command command = Show_Menu();
			switch (command)
			{
			case List_Command::Exit:
				return;
			case List_Command::Next:
				Next(curent);
				break;
			case List_Command::Back:
				Back(curent);
				break;
			case List_Command::Add_In_Tail:
				Add_In_Tail(head, tail);
				break;
			case List_Command::Edit_Curent:
				Edit_Data(curent);
				break;;
			default:
				throw "Enum value out of range!";
				break;
			}
			cout << endl;
			List_Manager(head, tail, curent);
		}

		void Get(DemoList*& head)
		{
			if (head)
			{
				cout << "Data = " << head->Data << endl;
				DemoList* temp_head = head;
				if (head->Next)
					head = head->Next;
				else
					head = NULL;
				delete temp_head;
			}
		}

		void Set(DemoList*& head)
		{
			if (head)
			{
				head->Previous = new DemoList();
				head->Previous->Next = head;
				head = head->Previous;
			}
			else
				head = new DemoList();

			cout << "Enter new data: ";
			cin >> head->Data;
		}

		void Stack_Manager(DemoList* head = NULL)
		{
			cout << "Get or Set data or Exit? (G/S/E): ";
			char c;
			cin >> c;
			if (c == 'G' || c == 'g')
				Get(head);

			if (c == 'S' || c == 's')
				Set(head);

			if (c == 'E' || c == 'e')
				return;

			Stack_Manager(head);
		}

		void Set(DemoList*& head, DemoList*& tail)
		{
			if (head)
			{
				head->Previous = new DemoList();
				head->Previous->Next = head;
				head = head->Previous;
			}
			else
			{
				head = new DemoList();
				tail = head;
			}

			cout << "Enter new data: ";
			cin >> head->Data;
		}

		void Get(DemoList*& head, DemoList*& tail)
		{
			if (tail)
			{
				cout << "Data = " << tail->Data << endl;

				DemoList* temp_tail = tail;
				if (tail->Previous)
					tail = tail->Previous;
				else
				{
					tail = NULL;
					head = NULL;
				}
				delete temp_tail;
			}
			else
				cout << "Queue is empty!" << endl;
		}

		void Queue_Manager(DemoList* head = NULL, DemoList* tail = NULL)
		{
			cout << "Get or Set data or Exit? (G/S/E): ";
			char c;
			cin >> c;
			if (c == 'G' || c == 'g')
				Get(head, tail);

			if (c == 'S' || c == 's')
				Set(head, tail);

			if (c == 'E' || c == 'e')
				return;
			Queue_Manager(head, tail);
		}

		void General_1()
		{
			cout << "Queue:" << endl;
			Queue_Manager();

			cout << endl << "Stack:" << endl;
			Stack_Manager();
		}

	#pragma endregion


	#pragma region Individual + Additional

		struct Linked_PersonPointers
		{
			Linked_PersonPointers* Next = NULL;
			Linked_PersonPointers* Previos = NULL;
			Person* Person;
		};

		struct Persons_Tree
		{
			Persons_Tree* Left = NULL;
			Persons_Tree* Right = NULL;
			Person* Curent;
		};

		Persons_Tree* Build_Tree(Linked_PersonPointers* item)
		{
			Persons_Tree* root = new Persons_Tree();
			Persons_Tree* branch = root;
			while (item)
			{
				if (branch->Curent == NULL)
				{
					branch->Curent = item->Person;
				}
				else
				{
					string fio1 = branch->Curent->Name.SecondName + branch->Curent->Name.FirstName + branch->Curent->Name.MidleName;
					string fio2 = item->Person->Name.SecondName + item->Person->Name.FirstName + item->Person->Name.MidleName;
					if (fio1 > fio2)
					{
						if (branch->Left == NULL)
							branch->Left = new Persons_Tree();
						branch = branch->Left;
						continue;
					}
					else
					{
						if (branch->Right == NULL)
							branch->Right = new Persons_Tree();
						branch = branch->Right;
						continue;
					}
				}

				item = item->Next;
				branch = root;
			}
			return root;
		}

		Linked_PersonPointers* Tree_To_List(Persons_Tree* tree, Linked_PersonPointers* tail = NULL)
		{
			if (tree == NULL)
			{
				return NULL;
			}

			if (tree->Left)
			{
				tail = Tree_To_List(tree->Left, tail);
			}

			if (tail)
			{
				tail->Next = new Linked_PersonPointers();
				tail->Next->Previos = tail;
				tail = tail->Next;
			}
			else
				tail = new Linked_PersonPointers();

			tail->Person = tree->Curent;

			if (tree->Right)
			{
				tail = Tree_To_List(tree->Right, tail);
			}

			return tail;

		}

		enum class PersonMenuCommand
		{
			Exit,
			Create,
			Sort,
			Edit,
			Delete,
			Show_All,
			Search
		};

		void Print(Person* p)
		{
			cout << "Person: " << LR_1::Get_FIO(*p) << endl;
			cout << "- Adress:\t" << p->Adress << endl;
			cout << "- Phone:\t" << p->Phone_Number << endl;
		}

		void Print(Linked_PersonPointers* head)
		{
			if (head == NULL)
			{
				cout << "List is empty!" << endl;
				return;
			}
			Print(head->Person);
			if (head->Next)
			{
				cout << endl;
				Print(head->Next);
			}
		}

		Linked_PersonPointers* Add_In_List(Person*& p, Linked_PersonPointers* tal = NULL)
		{
			Linked_PersonPointers* next = new Linked_PersonPointers;
			next->Previos = tal;
			next->Person = p;
			if (tal != NULL)
				tal->Next = next;
			return next;
		}

		Linked_PersonPointers* Get_Linc_On_Index(int index, Linked_PersonPointers*& head)
		{
			Linked_PersonPointers* curent = head;
			int i = 0;
			while (curent != NULL)
			{
				if (i == index)
					break;
				i++;
				curent = curent->Next;
			}
			return curent;
		}

		void Remove_From_List(int index, Linked_PersonPointers*& head, Linked_PersonPointers*& tail)
		{
			if (head == NULL)
			{
				cout << "List is empty!" << endl;
				return;
			}

			Linked_PersonPointers* deleting_person = Get_Linc_On_Index(index, head);

			if (deleting_person)
			{
				cout << "Do you want to remove: " << endl;
				Print(deleting_person->Person);
				cout << "Y/N: ";
				char c;
				cin >> c;
				if (c != 'Y' && c != 'y')
					return;
				if (deleting_person->Next && deleting_person->Previos)
				{
					deleting_person->Previos->Next = deleting_person->Next;
					deleting_person->Next->Previos = deleting_person->Previos;
				}
				else if (deleting_person->Next)
				{
					deleting_person->Next->Previos = NULL;
					head = deleting_person->Next;
				}
				else if (deleting_person->Previos)
				{
					deleting_person->Previos->Next = NULL;
					tail = deleting_person->Previos;
				}
				else
				{
					head = NULL;
					tail = NULL;
				}
				delete deleting_person;
			}
			else
			{
				cout << "Index out of range!" << endl;
			}
		}

		Person* Enter_Person_Data()
		{
			Person* creating_person = new Person();
			cout << "Enter second name: ";
			cin >> creating_person->Name.SecondName;
			cout << "Enter first name: ";
			cin >> creating_person->Name.FirstName;
			cout << "Has middle name? (Y/N): ";
			char c;
			cin >> c;
			if (c == 'Y' || c == 'y')
			{
				cout << "Enter midle name: ";
				cin >> creating_person->Name.MidleName;
				creating_person->Name.Has_MidleName = true;
			}
			cout << "Enter adress: ";
			cin >> creating_person->Adress;
			cout << "Enter phone number: ";
			cin >> creating_person->Phone_Number;
			return creating_person;
		}

		void Add_Person(Linked_PersonPointers*& head, Linked_PersonPointers*& tail, Person* p)
		{
			if (head == NULL)
			{
				head = Add_In_List(p);
				tail = head;
			}
			else
				tail = Add_In_List(p, tail);
		}

		void Create_Person(Linked_PersonPointers*& head, Linked_PersonPointers*& tail)
		{
			Person* creating_person = Enter_Person_Data();
			Add_Person(head, tail, creating_person);
		}

		void Delete_Person(Linked_PersonPointers*& head, Linked_PersonPointers*& tail)
		{
			cout << "Enter deleting person number: ";
			int index;
			cin >> index;
			Remove_From_List(index, head, tail);
			cout << "Deleted!" << endl;
		}

		void Edit_Person(Linked_PersonPointers*& head, Linked_PersonPointers*& tail)
		{
			int i;
			cout << "Editing person number: ";
			cin >> i;
			Linked_PersonPointers* editing_person = Get_Linc_On_Index(i, head);
			if (editing_person)
				editing_person->Person = Enter_Person_Data();
			else
				cout << "Index out of range!" << endl;
		}

		void Sort(Linked_PersonPointers*& head, Linked_PersonPointers*& tail)
		{
			if (head == NULL)
			{
				cout << "List is empty!";
				return;
			}

			Persons_Tree* root = Build_Tree(head);
			tail = Tree_To_List(root);

			Linked_PersonPointers* curent = tail;
			while (true)
			{
				if (curent->Previos == NULL)
				{
					head = curent;
					break;
				}
				curent = curent->Previos;
			}
		}

		void Search(Linked_PersonPointers* curent)
		{
			cout << "Enter FIO patern: ";
			char find[255];
			cin.ignore();
			cin.getline(find, 254);
			bool is_finded = false;
			while (curent)
			{
				string fio = LR_1::Get_FIO(*curent->Person);
				if (fio.find(find) != -1)
				{
					Print(curent->Person);
					is_finded = true;
				}
				curent = curent->Next;
			}
			if (is_finded == false)
				cout << "Nothing!" << endl;
		}

		void Update_PersonMenu(Linked_PersonPointers* head = NULL, Linked_PersonPointers* tail = NULL)
		{
			switch (LR_1::Choose_Command())
			{
			case MenuCommand::Create:
				Create_Person(head, tail);
				break;
			case MenuCommand::Sort:
				Sort(head, tail);
				Print(head);
				break;
			case MenuCommand::Edit:
				Edit_Person(head, tail);
				break;
			case MenuCommand::Delete:
				Delete_Person(head, tail);
				break;
			case MenuCommand::Show_All:
				Print(head);
				break;
			case MenuCommand::Search:
				Search(head);
				break;


			case MenuCommand::Exit:
				return;
			default:
				throw "Wrong command!";
				break;
			}
			cout << endl;
			Update_PersonMenu(head, tail);
		}


		void Individual_Additional()
		{
			Update_PersonMenu();
		}

	#pragma endregion


		void All()
		{
			cout << "General 1 + 2:" << endl;
			General_1();

			cout << endl << "Individual + Additional:" << endl;
			Individual_Additional();
		}
	}

	namespace LR_3
	{
	#pragma region General
		int* Read_Numbers_From_File(const char file_name[], int& size)
		{
			int* data = NULL;
			FILE* file = NULL;
			fopen_s(&file, file_name, "r");
			if (file)
			{
				fscanf_s(file, "%d", &size);
				data = new int[size];
				for (int i = 0; i < size; i++)
				{
					fscanf_s(file, "%d", &data[i]);
				}
				fclose(file);
			}
			return data;
		}

		void Write_Numbers_In_File(const char file_name[], const int data[], const int size)
		{
			FILE* file = NULL;
			fopen_s(&file, file_name, "w");
			if (file)
			{
				fprintf_s(file, "%d\n", size);
				for (int i = 0; i < size; i++)
				{
					fprintf_s(file, " %d", data[i]);
				}
				fclose(file);
			}
		}


		void General_1()
		{
			int size = 0;
			int* numbers = Read_Numbers_From_File("LR_3_General_1_IN.txt", size);

			if (numbers == NULL)
			{
				cout << "File is empty!" << endl;
				return;
			}

			for (int loop = 0; loop < size; loop++)
			{
				for (int i = 0; i < size - loop - 1; i++)
				{
					if (numbers[i] > numbers[i + 1])
					{
						int temp = numbers[i];
						numbers[i] = numbers[i + 1];
						numbers[i + 1] = temp;
					}
				}
			}

			Write_Numbers_In_File("LR_3_General_1_OUT.txt", numbers, size);
		}

		struct Student
		{
			int Index;
			string SecondName;
			double Avarage_Mark;
		};

		Student* Read_Students(const char file_name[], int& count)
		{
			Student* data = NULL;
			ifstream input;
			input.open(file_name);
			if (input.is_open())
			{
				input >> count;
				data = new Student[count];
				for (int i = 0; i < count; i++)
				{
					input >> data[i].Index;
					input >> data[i].SecondName;
					input >> data[i].Avarage_Mark;
				}

				input.close();
			}
			return data;
		}

		void Print_Table(const Student students[], const int count)
		{
			char sep[] = "+------+----------------------+-----+\n";
			cout << sep;
			printf_s("| %4s | %20s | %3s |\n", "№", "Second name", "AVG");
			cout << sep;
			for (int i = 0; i < count; i++)
			{
				printf_s("| %4d | %20s | %2.1f |\n", students[i].Index, students[i].SecondName.c_str(), students[i].Avarage_Mark);
			}
			cout << sep;
		}

		void SaveGoodStudents(const Student students[], const int count, const char file_name[])
		{
			ofstream out;
			out.open(file_name);
			if (out.is_open()) 
			{
				for (int i = 0; i < count; i++)
				{
					if (students[i].Avarage_Mark > 4)
					{
						out << students[i].Index << " " << students[i].SecondName << endl;
					}
				}
				out.close();
			}
		}

		void General_2()
		{
			int count = 0;
			Student* students = Read_Students("LR_3_General_2_IN.txt", count);
			if (students == NULL)
			{
				cout << "File is empty!" << endl;
				return;
			}
			Print_Table(students, count);
			SaveGoodStudents(students, count, "LR_3_General_2_OUT.txt");
		}

	#pragma endregion

#pragma region Individual

		enum class MenuCommand
		{
			Exit,
			Create,
			Sort,
			Edit,
			Delete,
			Show_All,
			Search,
			Save_As,
			Load_As,
			Save,
			Load,
		};

		MenuCommand Show_Menu()
		{
			cout << "0) Exit" << endl;
			cout << "1) Create" << endl;
			cout << "2) Sort" << endl;
			cout << "3) Edit" << endl;
			cout << "4) Delete" << endl;
			cout << "5) Show_All" << endl;
			cout << "6) Search" << endl;
			cout << "7) Save_As" << endl;
			cout << "8) Load_As" << endl;
			cout << "9) Save" << endl;
			cout << "10) Loads" << endl;
			cout << "Chouse command: ";
			int i;
			cin >> i;
			return (MenuCommand)i;
		}

		void Save(LR_2::Linked_PersonPointers* head, const char filename[] = "LR_3_Individual.txt")
		{
			ofstream out;
			out.open(filename);
			if (out.is_open())
			{
				LR_2::Linked_PersonPointers* curent = head;
				while (curent)
				{
					LR_2::Person p = *curent->Person;
					out << p.Adress << ' ' << p.Name.FirstName << ' ' << p.Name.SecondName << ' ' << p.Name.Has_MidleName << ' ' << p.Name.MidleName << ' ' << p.Phone_Number;
					curent = curent->Next;
					if (curent)
						out << endl;
				}
				out.close();
			}
		}

		void Load(LR_2::Linked_PersonPointers*& head, LR_2::Linked_PersonPointers*& tail, const char filename[] = "LR_3_Individual.txt")
		{
			ifstream input;
			input.open(filename);
			if (input.is_open())
			{
				while (input.eof() == false)
				{
					LR_2::Person *p = new LR_2::Person;
					input >> p->Adress;
					input >> p->Name.FirstName;
					input >> p->Name.SecondName;
					input >> p->Name.Has_MidleName;
					if (p->Name.Has_MidleName)
						input >> p->Name.MidleName;
					input >> p->Phone_Number;
					LR_2::Add_Person(head, tail, p);
				}
				input.close();
			}
		}

		void Save_As(LR_2::Linked_PersonPointers* head)
		{
			if (head == NULL)
			{
				cout << "List is Empty!" << endl;
				return;
			}

			cout << "Enter SaveFile Name: ";
			string filename;
			cin >> filename;
			filename += ".txt";
			Save(head, filename.c_str());
		}

		void Load_As(LR_2::Linked_PersonPointers*& head, LR_2::Linked_PersonPointers*& tail)
		{
			cout << "Enter LoadFile Name: ";
			string filename;
			cin >> filename;
			filename += ".txt";
			Load(head, tail, filename.c_str());
		}

		void Individual()
		{
			LR_2::Linked_PersonPointers* head = NULL;
			LR_2::Linked_PersonPointers* tail = NULL;
			while (true)
			{
				switch (Show_Menu())
				{
				case MenuCommand::Create:
					LR_2::Create_Person(head, tail);
					break;
				case MenuCommand::Delete:
					LR_2::Delete_Person(head, tail);
					break;
				case MenuCommand::Edit:
					LR_2::Edit_Person(head, tail);
					break;
				case MenuCommand::Search:
					LR_2::Search(head);
					break;
				case MenuCommand::Show_All:
					LR_2::Print(head);
					break;
				case MenuCommand::Sort:
					LR_2::Sort(head, tail);
					LR_2::Print(head);
					break;

				case MenuCommand::Save_As:
					Save_As(head);
					break;
				case MenuCommand::Load_As:
					Load_As(head, tail);
					break;

				case MenuCommand::Save:
					Save(head);
					break;
				case MenuCommand::Load:
					Load(head, tail);
					break;

				case MenuCommand::Exit:
					return;
				default:
					cout << "Wrong command!";
				}
			}
		}

	#pragma endregion

	#pragma region Additional

		enum class DemoMenuCommand
		{
			Exit,
			Add,
			Del,
			Print,
			Save,
			Load
		};

		void Additional()
		{
			const int size = 10;
			const int str_size = 255;
			char string_array[size][str_size];
			int count = 0;
			while (true)
			{
				cout << "0) Exit" << endl;
				cout << "1) Add" << endl;
				cout << "2) Del" << endl;
				cout << "3) Print" << endl;
				cout << "4) Save" << endl;
				cout << "5) Load" << endl;
				cout << "Chouse command: ";
				int c;
				cin >> c;
				switch ((DemoMenuCommand)c)
				{
				case DemoMenuCommand::Exit:
					return;
				case DemoMenuCommand::Add:
					if (count != size)
						cin >> string_array[count++];
					else
						cout << "Array is full!";
					break;
				case DemoMenuCommand::Del:
				{
					if (count == 0)
					{
						cout << "Array is Empty!" << endl;
						break;
					}

					int n;
					cout << "Deleting index: ";
					cin >> n;

					if (count == 1 && n == 0)
					{
						count = 0;
						break;
					}

					char* str1 = string_array[n];
					char* str2 = string_array[--count];
					for (int i = 0; i < str_size; i++)
					{
						str1[i] = str2[i];
					}
					break;
				}
				case DemoMenuCommand::Print:
					if (count == 0)
					{
						cout << "Array is Empty!" << endl;
						break;
					}
					for (int i = 0; i < count; i++)
						cout << i + 1 << ") " << string_array[i] << endl;
					cout << endl;
					break;
				case DemoMenuCommand::Save:
				{
					FILE* file = NULL;
					freopen_s(&file, "LR_3_Additional.txt", "w", stdout);
					if (file)
					{
						cout << count << endl;
						for (int i = 0; i < count; i++)
						{
							cout << string_array[i] << endl;
						}
						fclose(file);
						freopen_s(&file, "CON", "w", stdout);
					}
					break;
				}
				case DemoMenuCommand::Load:
				{
					FILE* file = NULL;
					freopen_s(&file, "LR_3_Additional.txt", "r", stdin);
					if (file)
					{
						cin >> count;
						for (int i = 0; i < count; i++)
						{
							cin >> string_array[i];
						}
						fclose(file);
						freopen_s(&file, "CON", "r", stdin);
					}
					break;
				}
				default:
					break;
				}
			}
		}

	#pragma endregion


		void All()
		{
			cout << "General 1:" << endl;
			General_1();

			cout << "General 2:" << endl;
			General_2();

			cout << "Individual:" << endl;
			Individual();

			cout << "Additional:" << endl;
			Additional();
		}
	}
}


#include "test.h";

const auto RusCharset = 1251;

void main() 
{
	// 3 Вариант
	SetConsoleCP(RusCharset);
	SetConsoleOutputCP(RusCharset);
	setlocale(LC_ALL, "rus");

	Sem_2::LR_3::All();
	cout << endl;

	system("pause");
}


