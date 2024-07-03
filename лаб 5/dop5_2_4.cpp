#include <iostream>
#include <Windows.h>
#include <string>
#include <cstring> // Для работы с функцией strcpy
#include <ctime> // Для работы с временем

using namespace std;

#pragma warning(disable : 4996)

// Объявление переменных для работы с файлом
FILE* file; // Указатель на файл
errno_t err; // Переменная для обработки ошибок

// Объявление функций
void Write_new_client(int);
void Out_account();
void Delete_account(int);
void Search_account(int);

// Структура для хранения данных о клиенте
struct Client_bank
{
    union
    {
        char Name[50]; // ФИО
        char Name_product[50]; // Наименование товара
    };
    char type_account[20]; // Тип аккаунта
    int number_account; // Номер аккаунта
    int balance_on_account; // Баланс на аккаунте
    char last_change[20]; // Дата последнего изменения
};

// Главная функция программы
int main()
{
    // Установка русской локали для корректного вывода сообщений на кириллице в консоли
    setlocale(LC_ALL, "ru");

    // Установка кодовой страницы для корректного ввода-вывода на кириллице
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Объявление переменных
    int quanlity_client, key = 0; // Количество клиентов и ключ операции
    int number_account; // Номер счета клиента

    // Вывод приветственного сообщения и меню действий
    cout << "Добро пожаловать в базу данных нашего банкинга! Чтобы воспроизвести какие-либо действия, воспользуйтесь ключами ниже." << endl;
    cout << "1 - Записать в базу данных новых клиентов." << endl;
    cout << "2 - Вывести всех клиентов." << endl;
    cout << "3 - Удалить аккаунт клиента." << endl;
    cout << "4 - Найти аккаунт клиента (поиск аккаунта производится по номеру счета)." << endl;
    cout << "5 - Выход из базы." << endl;

    // Основной цикл программы
    while (key != 5)
    {
        // Запрос ввода ключа операции
        cout << "Введите ключ: ";
        cin >> key;

        // Обработка операций в зависимости от введенного ключа
        switch (key)
        {
        case 1:
            // Запись новых клиентов в базу данных
            cout << "Введите количество людей, которых вы желаете занести в базу: ";
            cin >> quanlity_client;
            Write_new_client(quanlity_client);
            break;

        case 2:
            // Вывод всех клиентов из базы данных
            Out_account();
            break;

        case 3:
            // Удаление аккаунта клиента
            cout << "Введите номер счета аккаунта, который вы желаете удалить: ";
            cin >> number_account;
            Delete_account(number_account);
            break;

        case 4:
            // Поиск аккаунта клиента по номеру счета
            cout << "Введите номер счета аккаунта, который вы желаете найти: ";
            cin >> number_account;
            Search_account(number_account);
            break;

        case 5:
            // Выход из программы
            return 0;
        }
    }
}

// Функция для записи новых клиентов в базу данных
void Write_new_client(int quanlity_client)
{
    Client_bank write; // Создание объекта структуры Client_bank для хранения данных о клиенте

    // Открытие файла для записи в режиме "wb" (очистка файла перед записью)
    err = fopen_s(&file, "base.bin", "wb");
    if (err != 0 || !file)
    {
        cout << "Ошибка открытия файла" << endl;
        return;
    }
    fclose(file); // Закрытие файла

    // Повторное открытие файла для добавления данных в конец (режим "ab")
    err = fopen_s(&file, "base.bin", "ab");
    if (err != 0 || !file)
    {
        cout << "Ошибка открытия файла" << endl;
        return;
    }

    cin.ignore(); // Игнорирование символа новой строки во входном потоке

    // Цикл ввода данных о каждом клиенте
    for (int p = 0; p < quanlity_client; p++)
    {
        cout << "Введите ФИО: ";
        cin.getline(write.Name, sizeof(write.Name)); // Ввод ФИО

        // Ввод и выбор типа аккаунта
        cout << "Тип аккаунта: " << endl;
        cout << "1 - Cрочный" << endl;
        cout << "2 - Льготный" << endl;
        cout << "3 - Депозитный" << endl;
        cout << "4 - Кредитный" << endl;
        int type_account_key;
        cin >> type_account_key;
        switch (type_account_key)
        {
        case 1:
            strcpy(write.type_account, "Cрочный");
            break;
        case 2:
            strcpy(write.type_account, "Льготный");
            break;
        case 3:
            strcpy(write.type_account, "Депозитный");
            break;
        case 4:
            strcpy(write.type_account, "Кредитный");
            break;

        default:
        {
            exit(1);
        }

        }

        // Ввод номера аккаунта и баланса
        cout << "Номер аккаунта: ";
        cin >> write.number_account;
        cout << "Баланс на аккаунте: ";
        cin >> write.balance_on_account;

        cin.ignore(); // Игнорирование символа новой строки во входном потоке

        // Получение текущего времени и форматирование в строку
        time_t now = time(0);
        strftime(write.last_change, sizeof(write.last_change), "%Y-%m-%d %X", localtime(&now)); // Форматирование времени и запись в поле last_change

        // Запись данных о клиенте в файл
        fwrite(&write, sizeof(write), 1, file);
    }

    fclose(file); // Закрытие файла
}

// Функция для вывода всех клиентов из базы данных
void Out_account()
{
    Client_bank write; // Создание объекта структуры Client_bank для хранения данных о клиенте

    // Открытие файла для чтения в режиме "rb" (только чтение)
    err = fopen_s(&file, "base.bin", "rb");
    if (err == 0 && file)
    {
        cout << "\n";
        while (fread(&write, sizeof(write), 1, file) == 1) // Чтение данных о клиентах из файла
        {
            // Вывод данных о клиенте
            cout << "ФИО: " << write.Name << "\n"
                << "Тип аккаунта: " << write.type_account << "\n"
                << "Номер аккаунта: " << write.number_account << "\n"
                << "Баланс на аккаунте: " << write.balance_on_account << "\n"
                << "Последнее изменение: " << write.last_change << "\n\n";
        }
        fclose(file); // Закрытие файла
    }
    else
    {
        cout << "Ошибка открытия файла" << endl;
    }
}

// Функция для удаления аккаунта клиента по номеру счета
void Delete_account(int account_number)
{
    FILE* file; // Указатель на файл
    err = fopen_s(&file, "base.bin", "rb+"); // Открытие файла для чтения и записи
    if (err != 0 || !file)
    {
        cout << "Ошибка открытия исходного файла\n";
        return;
    }

    Client_bank read; // Создание объекта структуры Client_bank для хранения данных о клиенте
    long int position = 0; // Позиция в файле
    bool found = false; // Флаг для обнаружения аккаунта
    while (fread(&read, sizeof(read), 1, file) == 1) // Чтение данных о клиентах из файла
    {
        if (account_number == read.number_account) // Если номер счета совпадает
        {
            found = true; // Установка флага
            break;
        }
        position = ftell(file); // Получение текущей позиции в файле
    }

    if (found) // Если аккаунт найден
    {
        fseek(file, position, SEEK_SET); // Перемещение указателя файла на позицию удаления
        Client_bank empty = {}; // Создание пустого объекта структуры для записи вместо удаленного
        fwrite(&empty, sizeof(empty), 1, file); // Запись пустого объекта в файл
        cout << "Аккаунт с номером " << account_number << " успешно удален\n";
    }
    else
    {
        cout << "Аккаунт с номером " << account_number << " не найден\n";
    }

    fclose(file); // Закрытие файла
}

// Функция для поиска аккаунта клиента по номеру счета
void Search_account(int account_number)
{
    bool flag = false; // Флаг для обнаружения найденного аккаунта
    Client_bank write; // Создание объекта структуры Client_bank для хранения данных о клиенте
    err = fopen_s(&file, "base.bin", "rb"); // Открытие файла для чтения
    if (err == 0 && file)
    {
        while (fread(&write, sizeof(write), 1, file) == 1) // Чтение данных о клиентах из файла
        {
            if (account_number == write.number_account) // Если номер счета совпадает
            {
                // Вывод данных о клиенте
                cout << "ФИО: " << write.Name << "\n"
                    << "Тип аккаунта: " << write.type_account << "\n"
                    << "Номер аккаунта: " << write.number_account << "\n"
                    << "Баланс на аккаунте: " << write.balance_on_account << "\n"
                    << "Последнее изменение: " << write.last_change << "\n\n";
                flag = true; // Установка флага
                break;
            }

            else
            {
                cout << "Аккаунт не найден " << endl;
                return;
            }
        }
        fclose(file); // Закрытие файла
    }
}
