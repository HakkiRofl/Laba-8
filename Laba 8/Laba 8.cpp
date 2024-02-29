// Laba 8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>

using namespace std;

#define N 50

struct StringType* readline_arrays(const char* file_name, int* len_text);
int* find_symbol(char* text, int len, int* len_array, char symbol); // возвращает новосозданный массив find_symbols
void read_arrays_of_symbols(const char *name, int* array, int len);
void read_text(struct StringType* arrays_of_array, int len_arrays);

struct StringType
{
    char* text;
    int len;
};

int main()
{
    setlocale(LC_ALL, "Russian");
    const char* file_name = "example.txt"; // Путь к файлу
    int* len_upper_letters = new int{ 0 }; // Длина массива больших букв
    int* len_lower_letters = new int{ 0 }; // Длина массива мелких букв


    int* len_text = new int{ 0 }; // Длина текста, кол-во строк???
    struct StringType* text = readline_arrays(file_name, len_text); // Функция чтения строка, возвращает массив указателей на строки
    
    cout << "Исходный текст:" << endl;
    read_text(text, *len_text); // Функция построчного чтения, нужно передать указатель на массив и размер массива
    
    delete len_lower_letters, len_upper_letters;
    
}

struct StringType* readline_arrays(const char *file_name, int* len_text) 
{
    ifstream file(file_name, ios_base::in);
    if (file.is_open())
    {
        int* count_arrays = new int{ 1 };// Длина массива указателей на строку
        StringType* array_of_arrays;
        array_of_arrays = (StringType*)malloc(*count_arrays * sizeof(StringType)); // Массив указателей

        int* len_array = new int{ 1 }; // Длина строки символов
        char* array = (char*)malloc(*len_array * sizeof(char)); // Массив символов строки

        char letter; // Статическая переменная хранящая символ строки

        fstream file(file_name, fstream::in);
        
        while (file >> noskipws >> letter) 
        {
            if (letter != '\n')
            {
                //cout << letter;
                *len_array += 1;
                array = (char*)realloc(array, *len_array * sizeof(char)); // Пересоздание массива символов с увеличением кол-ва символов на 1
                array[*len_array - 2] = letter; // Запись в массив прочитанного символа
            }
            else
            {
                array[*len_array - 1] = '\0';
                array_of_arrays[*count_arrays - 1].text = array;
                array_of_arrays[*count_arrays - 1].len = *len_array;
                *len_array = 1;
                *count_arrays += 1;
                array_of_arrays = (StringType*)realloc(array_of_arrays, *count_arrays * sizeof(StringType));
                array = (char*)malloc(*len_array * sizeof(char));
            }
        }
        array[*len_array - 1] = '\0';
        array_of_arrays[*count_arrays - 1].text = array;
        array_of_arrays[*count_arrays - 1].len = *len_array;
        *len_text = *count_arrays;
        delete count_arrays, len_array;
        return array_of_arrays;
    }
    else
    {
        cout << "Не удалось открыть файл!\n";
        exit;
    }


    
}

/*
int** find_symbol(char** text, int* count_arrays, int* len_text, char symbol)
{
    int* len_array = new int{ 1 };
    int** array_of_arrays = (int**)malloc(*count_arrays * sizeof(int*));
    for (int i = 0; i < *count_arrays;  i++)
    {
        int* array = (int*)malloc(*len_array * sizeof(int));

        for (int g = 0; g < ; g++)
        {
            if (*text[i] == symbol)
            {
                array[*len_array] = i;
                *len_array += 1;
                array = (int*)realloc(array, (*len_array + 1) * sizeof(int));
            }
        }
        return array;
    }

}
*/


void read_arrays_of_symbols(const char *name, int* array, int len)
{
    cout << endl << name;
    for (int i = 0; i < len; i++)
        cout << endl << array[i];
}

void read_text(struct StringType* arrays_of_array, int len_arrays)
{
    for (int i = 0; i < len_arrays; i++)
        printf("%s (%i)\n", arrays_of_array[i].text, arrays_of_array[i].len);
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
