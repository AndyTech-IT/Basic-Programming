#include <iostream>
#include <Windows.h>
#include <string.h>
#include <string>
#include <regex>
#include <math.h>

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

	namespace Denis
		{
			// Ввести строку с клавиатуры. Найти самое длинное слово в строке с учетом пробелов и знаков препинания «.!,?:;». 
			// Заменить в этом слове все строчные буквы прописными (кириллица и латиница).
			// Вывести полученную строку. Пример «Стол скатерть стул» преобразуется в «Стол СКАТЕРТЬ стул».
			void LR_5_1()
			{
				char line[] = { "Стол скатерть стул ggggggggggggggggggggggggggggggggg" };
				string stop_chars = " .!,?:;";
				char* longest_start = &line[0];
				int longest_len = 0;
				char* curent_start = &line[0];
				int curent_len = 1;
				bool begin_from_next = false;

				for (char* c = begin(line); c < end(line); c++)
				{
					char C = *c;
					if (stop_chars.find(C) != -1 || C == '\0')
					{
						if (curent_len > longest_len)
						{
							longest_start = curent_start;
							longest_len = curent_len;
						}
						begin_from_next = true;
					}
					else
					{
						if (begin_from_next)
						{
							curent_len = 1;
							curent_start = c;
							begin_from_next = false;
						}
						else
							curent_len++;
					}
				}

				for (char* c = longest_start; c < longest_start + longest_len; c++)
				{
					*c = toupper(*c);
				}

				cout << line << endl;
			}

			void LR_5_2()
			{
				string line = "Я люблю программировать";
				//getline(cin, line);
				string invert_line_witout_space = "";
				for (int i = line.length() - 1; i >= 0; i--)
				{
					char c = line[i];
					if (c != ' ')
						invert_line_witout_space += c;
				}

				string invert_line = "";
				int read_index = 0;
				for (int i = 0; i < line.length(); i++)
				{
					invert_line += line[i] == ' ' ?
						' ' :
						invert_line_witout_space[read_index++];
				}
				cout << invert_line << endl;
			}
		}

	namespace Dasha
		{
			bool is_simple(int a)
			{
				int col = 0;
				for (int j = 1; j <= a; j++)
				{
					if (a % j == 0)
						col++;
					if (col > 2)
						return false;
				}
				return true;
			}

			void LR_3_1()
			{
				int a, b, col;
				cout << "Введите a:";
				cin >> a;
				cout << "Введите b:";
				cin >> b;
				for (int i = a + 1; i < b; i++)
				{
					if (is_simple(i))
						cout << i << " ";
				}
			}

			void LR_3_2()
			{
				int x, y;
				cout << "Введите ширину таблицы : "; cin >> x;
				cout << "Введите высоту таблицы : "; cin >> y;
				for (int i = 1; i < (x + 1); i++) {
					for (int j = 1; j < (y + 1); j++) {
						cout << i * j << "\t";
					}
					cout << endl;
				}
			}

			void LR_4_1()
			{
				int sum = 0;
				const int size = 8;
				bool flag = false;
				int mas[size] = { 3, -6, 3, 3, 3, -7, 9, 4 };
				for (int i = 0; i < size; i++)
				{
					if (flag && (mas[i] < 0))
						break;
					if (flag)
						sum += mas[i];
					if (mas[i] < 0)
						flag = true;
				}
				cout << sum << "\n\n";
			}
		}

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

	#pragma region LR 1

	#pragma region Practice

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
	void LR_1_P_1()
	{
		Point3 points[6]{ {1, 2, 3}, {1, 2, -2} , {1, 1, 0}, {1, 1, 1}, {1, 0, 0}, {-1, -2, 1} };
		Print(points, 6);
		cout << endl;
		Point3 nearest[] = { Get_Niarest_To_Center(points, 6) };
		cout << "Nearest is ";
		Print(nearest, 1);
		cout << endl;
	}

	#define Work_Binary(operation, bin_int, prefix, postfix)	\
						operation prefix bin_int.b1 postfix;	\
						operation prefix bin_int.b2 postfix;	\
						operation prefix bin_int.b3 postfix;	\
						operation prefix bin_int.b4 postfix;	\
						operation prefix bin_int.b5 postfix;	\
						operation prefix bin_int.b6 postfix;	\
						operation prefix bin_int.b7 postfix; 	\
						operation prefix bin_int.b8 postfix;	\
						operation prefix bin_int.b9 postfix;	\
						operation prefix bin_int.b10 postfix;	\
						operation prefix bin_int.b11 postfix;	\
						operation prefix bin_int.b12 postfix;	\
						operation prefix bin_int.b13 postfix;	\
						operation prefix bin_int.b14 postfix;	\
						operation prefix bin_int.b15 postfix;	\
						operation prefix bin_int.b16 postfix;  


	union Int_With_Binary
	{	
		struct Bin_Int {
			unsigned short int b1 : 1;
			unsigned short int b2 : 1;
			unsigned short int b3 : 1;
			unsigned short int b4 : 1;
			unsigned short int b5 : 1;
			unsigned short int b6 : 1;
			unsigned short int b7 : 1;
			unsigned short int b8 : 1;
			unsigned short int b9 : 1;
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

	void LR_1_P_2()
	{
		Int_With_Binary test;
		cin >> test.Decemal;
		Work_Binary(cout << ,test.Binary);
		cout << endl;
	}

	#pragma endregion


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
		cout << "Person: " << p->Name.SecondName << ' ' << p->Name.FirstName << ' ' << (p->Name.Has_MidleName ? p->Name.MidleName : "") << endl;
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

	void Create_Person(Linked_PersonPointers*& head, Linked_PersonPointers*& tail)
	{
		Person* creating_person = Enter_Person_Data();

		if (head == NULL)
		{
			head = Add_In_List(creating_person);
			tail = head;
		}
		else
			tail = Add_In_List(creating_person, tail);
	}

	void Delete_Person(Linked_PersonPointers*& head, Linked_PersonPointers*& tail)
	{
		cout << "Enter deleting person number: ";
		int index;
		cin >> index;
		Remove_From_List(index, head, tail);
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
		cout << "Enter Second Name: ";
		string second_name;
		cin >> second_name; 
		while (curent)
		{
			if (curent->Person->Name.SecondName.find(second_name) != -1)
				Print(curent->Person);
			curent = curent->Next;
		}
	}

	void Update_PersonMenu(Linked_PersonPointers* head = NULL, Linked_PersonPointers* tail = NULL)
	{
		int i_c;
		cout << "0) Close programm" << endl;
		cout << "1) Create new Person" << endl;
		cout << "2) Sort Persons list" << endl;
		cout << "3) Edit existing Person" << endl;
		cout << "4) Delete person" << endl;
		cout << "5) Show by FIO" << endl;
		cout << "6) Search Person by FIO" << endl;
		cout << "Enter command number: ";
		cin >> i_c;
		cout << endl;

		switch ((PersonMenuCommand)i_c)
		{
		case Sem_2::PersonMenuCommand::Exit:
			return;

		case Sem_2::PersonMenuCommand::Create:
			Create_Person(head, tail);
			break;
		case Sem_2::PersonMenuCommand::Sort:
			Sort(head, tail);
			break;
		case Sem_2::PersonMenuCommand::Edit:
			Edit_Person(head, tail);
			break;
		case Sem_2::PersonMenuCommand::Delete:
			Delete_Person(head, tail);
			break;
		case Sem_2::PersonMenuCommand::Show_All:
			Print(head);
			break;
		case Sem_2::PersonMenuCommand::Search:
			Search(head);
			break;
		default:
			cout << endl << "Wrong Command!";
			break;
		}
		cout << endl;
		Update_PersonMenu(head, tail);
	}

	void LR_1()
	{
		//LR_1_P_1();
		//LR_1_P_2();
		Update_PersonMenu();
	}

	#pragma endregion



#pragma endregion

}


const auto RusCharset = 1251;

void main() 
{
	// 3 Вариант
	SetConsoleCP(RusCharset);
	SetConsoleOutputCP(RusCharset);
	setlocale(LC_ALL, "rus");

	Sem_2::LR_1();
	cout << endl;

	system("pause");
}


