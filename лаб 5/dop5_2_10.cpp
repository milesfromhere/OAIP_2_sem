#include <iostream>
#include <string>
#include <windows.h>

enum Gender
{
    MAN,
    WOMEN,
    UNDEFINED,
    NUM_GENDER
};

union DateOfBirth
{
    struct
    {
        int day;   
        int month; 
        int year;  
    };
    int date; 
};

struct Information
{
    std::string name; 
    std::string address; 
    DateOfBirth dateOfBirth; 
    Gender gender; 
};

void Write_man(Information& info)
{
    std::cout << "������� ��� ����������: ";
    getline(std::cin >> std::ws, info.name);

    std::cout << "������� ���� �������� ����������: ";
    std::cin >> info.dateOfBirth.day;

    std::cout << "������� ����� �������� ����������: ";
    std::cin >> info.dateOfBirth.month;

    std::cout << "������� ��� �������� ����������: ";
    std::cin >> info.dateOfBirth.year;

    std::cin.ignore(); 

    std::cout << "������� ����� ����������: ";
    getline(std::cin >> std::ws, info.address);

    std::cout << "������� ������ ���������� (1 - �������, 2 - �������): ";
    int gender;
    std::cin >> gender;
    info.gender = static_cast<Gender>(gender - 1); 
}

void Output_man(const Information& info)
{
    std::string array_gender[NUM_GENDER] = { "�������", "�������", "�� ���������" };

    std::cout << "���: " << info.name << ". ���: " << array_gender[info.gender] << std::endl;
    std::cout << "���� ��������: " << info.dateOfBirth.day << ":" << info.dateOfBirth.month << ":" << info.dateOfBirth.year << std::endl;
    std::cout << "�����: " << info.address << std::endl;
}

void deleteMan(Information& info)
{
    info.name.clear(); 
    info.address.clear(); 
    info.dateOfBirth.day = 0;
    info.dateOfBirth.month = 0;
    info.dateOfBirth.year = 0;
    info.gender = UNDEFINED;
}

void Search_man(Information info[], int search_man, int num_man)
{
    int check = 0; 
    for (int i = 0; i < num_man; i++)
    {
        if (search_man == info[i].dateOfBirth.year)
        {
            deleteMan(info[i]); 
            Output_man(info[i]); 
            check++; 
        }
    }
    if (check == 0)
    {
        std::cout << "��������� � ����� �������� '" << search_man << "' �� ������." << std::endl;
    }
}

int main()
{
    setlocale(LC_ALL, "ru");

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Information info[10];
    int num_man = 0;

    std::cout << "������� ���������� � �����������: " << std::endl;
    for (int i = 0; i < 3; i++)
    {
        Write_man(info[num_man]); 
        num_man++;
    }

    std::cout << "���������� � �����������: " << std::endl;
    for (int i = 0; i < num_man; i++)
        Output_man(info[i]); 

    std::cout << "������� ��� �������� ����������(��), ��������(��) �� ������ ����� � �������: " << std::endl;
    std::cout << "���������� � ���: " << std::endl;
    int search_man;
    std::cin >> search_man;
    Search_man(info, search_man, num_man); 

    return 0;
}
