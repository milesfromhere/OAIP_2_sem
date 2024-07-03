#include <iostream>
#include <Windows.h>
#include <string>
#include <cstring> // ��� ������ � �������� strcpy
#include <ctime> // ��� ������ � ��������

using namespace std;

#pragma warning(disable : 4996)

// ���������� ���������� ��� ������ � ������
FILE* file; // ��������� �� ����
errno_t err; // ���������� ��� ��������� ������

// ���������� �������
void Write_new_client(int);
void Out_account();
void Delete_account(int);
void Search_account(int);

// ��������� ��� �������� ������ � �������
struct Client_bank
{
    union
    {
        char Name[50]; // ���
        char Name_product[50]; // ������������ ������
    };
    char type_account[20]; // ��� ��������
    int number_account; // ����� ��������
    int balance_on_account; // ������ �� ��������
    char last_change[20]; // ���� ���������� ���������
};

// ������� ������� ���������
int main()
{
    // ��������� ������� ������ ��� ����������� ������ ��������� �� ��������� � �������
    setlocale(LC_ALL, "ru");

    // ��������� ������� �������� ��� ����������� �����-������ �� ���������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // ���������� ����������
    int quanlity_client, key = 0; // ���������� �������� � ���� ��������
    int number_account; // ����� ����� �������

    // ����� ��������������� ��������� � ���� ��������
    cout << "����� ���������� � ���� ������ ������ ��������! ����� ������������� �����-���� ��������, �������������� ������� ����." << endl;
    cout << "1 - �������� � ���� ������ ����� ��������." << endl;
    cout << "2 - ������� ���� ��������." << endl;
    cout << "3 - ������� ������� �������." << endl;
    cout << "4 - ����� ������� ������� (����� �������� ������������ �� ������ �����)." << endl;
    cout << "5 - ����� �� ����." << endl;

    // �������� ���� ���������
    while (key != 5)
    {
        // ������ ����� ����� ��������
        cout << "������� ����: ";
        cin >> key;

        // ��������� �������� � ����������� �� ���������� �����
        switch (key)
        {
        case 1:
            // ������ ����� �������� � ���� ������
            cout << "������� ���������� �����, ������� �� ������� ������� � ����: ";
            cin >> quanlity_client;
            Write_new_client(quanlity_client);
            break;

        case 2:
            // ����� ���� �������� �� ���� ������
            Out_account();
            break;

        case 3:
            // �������� �������� �������
            cout << "������� ����� ����� ��������, ������� �� ������� �������: ";
            cin >> number_account;
            Delete_account(number_account);
            break;

        case 4:
            // ����� �������� ������� �� ������ �����
            cout << "������� ����� ����� ��������, ������� �� ������� �����: ";
            cin >> number_account;
            Search_account(number_account);
            break;

        case 5:
            // ����� �� ���������
            return 0;
        }
    }
}

// ������� ��� ������ ����� �������� � ���� ������
void Write_new_client(int quanlity_client)
{
    Client_bank write; // �������� ������� ��������� Client_bank ��� �������� ������ � �������

    // �������� ����� ��� ������ � ������ "wb" (������� ����� ����� �������)
    err = fopen_s(&file, "base.bin", "wb");
    if (err != 0 || !file)
    {
        cout << "������ �������� �����" << endl;
        return;
    }
    fclose(file); // �������� �����

    // ��������� �������� ����� ��� ���������� ������ � ����� (����� "ab")
    err = fopen_s(&file, "base.bin", "ab");
    if (err != 0 || !file)
    {
        cout << "������ �������� �����" << endl;
        return;
    }

    cin.ignore(); // ������������� ������� ����� ������ �� ������� ������

    // ���� ����� ������ � ������ �������
    for (int p = 0; p < quanlity_client; p++)
    {
        cout << "������� ���: ";
        cin.getline(write.Name, sizeof(write.Name)); // ���� ���

        // ���� � ����� ���� ��������
        cout << "��� ��������: " << endl;
        cout << "1 - C������" << endl;
        cout << "2 - ��������" << endl;
        cout << "3 - ����������" << endl;
        cout << "4 - ���������" << endl;
        int type_account_key;
        cin >> type_account_key;
        switch (type_account_key)
        {
        case 1:
            strcpy(write.type_account, "C������");
            break;
        case 2:
            strcpy(write.type_account, "��������");
            break;
        case 3:
            strcpy(write.type_account, "����������");
            break;
        case 4:
            strcpy(write.type_account, "���������");
            break;

        default:
        {
            exit(1);
        }

        }

        // ���� ������ �������� � �������
        cout << "����� ��������: ";
        cin >> write.number_account;
        cout << "������ �� ��������: ";
        cin >> write.balance_on_account;

        cin.ignore(); // ������������� ������� ����� ������ �� ������� ������

        // ��������� �������� ������� � �������������� � ������
        time_t now = time(0);
        strftime(write.last_change, sizeof(write.last_change), "%Y-%m-%d %X", localtime(&now)); // �������������� ������� � ������ � ���� last_change

        // ������ ������ � ������� � ����
        fwrite(&write, sizeof(write), 1, file);
    }

    fclose(file); // �������� �����
}

// ������� ��� ������ ���� �������� �� ���� ������
void Out_account()
{
    Client_bank write; // �������� ������� ��������� Client_bank ��� �������� ������ � �������

    // �������� ����� ��� ������ � ������ "rb" (������ ������)
    err = fopen_s(&file, "base.bin", "rb");
    if (err == 0 && file)
    {
        cout << "\n";
        while (fread(&write, sizeof(write), 1, file) == 1) // ������ ������ � �������� �� �����
        {
            // ����� ������ � �������
            cout << "���: " << write.Name << "\n"
                << "��� ��������: " << write.type_account << "\n"
                << "����� ��������: " << write.number_account << "\n"
                << "������ �� ��������: " << write.balance_on_account << "\n"
                << "��������� ���������: " << write.last_change << "\n\n";
        }
        fclose(file); // �������� �����
    }
    else
    {
        cout << "������ �������� �����" << endl;
    }
}

// ������� ��� �������� �������� ������� �� ������ �����
void Delete_account(int account_number)
{
    FILE* file; // ��������� �� ����
    err = fopen_s(&file, "base.bin", "rb+"); // �������� ����� ��� ������ � ������
    if (err != 0 || !file)
    {
        cout << "������ �������� ��������� �����\n";
        return;
    }

    Client_bank read; // �������� ������� ��������� Client_bank ��� �������� ������ � �������
    long int position = 0; // ������� � �����
    bool found = false; // ���� ��� ����������� ��������
    while (fread(&read, sizeof(read), 1, file) == 1) // ������ ������ � �������� �� �����
    {
        if (account_number == read.number_account) // ���� ����� ����� ���������
        {
            found = true; // ��������� �����
            break;
        }
        position = ftell(file); // ��������� ������� ������� � �����
    }

    if (found) // ���� ������� ������
    {
        fseek(file, position, SEEK_SET); // ����������� ��������� ����� �� ������� ��������
        Client_bank empty = {}; // �������� ������� ������� ��������� ��� ������ ������ ����������
        fwrite(&empty, sizeof(empty), 1, file); // ������ ������� ������� � ����
        cout << "������� � ������� " << account_number << " ������� ������\n";
    }
    else
    {
        cout << "������� � ������� " << account_number << " �� ������\n";
    }

    fclose(file); // �������� �����
}

// ������� ��� ������ �������� ������� �� ������ �����
void Search_account(int account_number)
{
    bool flag = false; // ���� ��� ����������� ���������� ��������
    Client_bank write; // �������� ������� ��������� Client_bank ��� �������� ������ � �������
    err = fopen_s(&file, "base.bin", "rb"); // �������� ����� ��� ������
    if (err == 0 && file)
    {
        while (fread(&write, sizeof(write), 1, file) == 1) // ������ ������ � �������� �� �����
        {
            if (account_number == write.number_account) // ���� ����� ����� ���������
            {
                // ����� ������ � �������
                cout << "���: " << write.Name << "\n"
                    << "��� ��������: " << write.type_account << "\n"
                    << "����� ��������: " << write.number_account << "\n"
                    << "������ �� ��������: " << write.balance_on_account << "\n"
                    << "��������� ���������: " << write.last_change << "\n\n";
                flag = true; // ��������� �����
                break;
            }

            else
            {
                cout << "������� �� ������ " << endl;
                return;
            }
        }
        fclose(file); // �������� �����
    }
}
