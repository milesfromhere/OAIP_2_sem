#include <iostream>
#include <string>
#include <windows.h>

enum AccountType
{
    SAVINGS,
    CURRENT,
    FIXED_DEPOSIT,
    OTHER
};

struct BankClient
{
    std::string name;       
    AccountType accType;    
    int accountNumber;      
    double balance;         
    unsigned int lastModifiedDay : 5;   
    unsigned int lastModifiedMonth : 4; 
    unsigned int lastModifiedYear : 11; 
};

void InputClientInfo(BankClient& client)
{
    int lastModifiedDay, lastModifiedMonth, lastModifiedYear;
    std::cout << "������� �.�.�. �������: ";
    getline(std::cin >> std::ws, client.name);

    std::cout << "������� ��� ����� (0 - ��������������, 1 - �������, 2 - ������� � �.�.): ";
    int type;
    std::cin >> type;
    client.accType = static_cast<AccountType>(type);

    std::cout << "������� ����� �����: ";
    std::cin >> client.accountNumber;

    std::cout << "������� ����� �� �����: ";
    std::cin >> client.balance;

    std::cout << "������� ���� ���������� ��������� (���� ����� ���): ";
    std::cin >> lastModifiedDay >> lastModifiedMonth >> lastModifiedYear;

    client.lastModifiedYear = lastModifiedYear;
    client.lastModifiedMonth = lastModifiedMonth;
    client.lastModifiedDay = lastModifiedDay;
}

void OutputClientInfo(const BankClient& client)
{
    std::string accountTypes[] = { "��������������", "�������", "�������", "������" };

    std::cout << "�.�.�.: " << client.name << std::endl;
    std::cout << "��� �����: " << accountTypes[client.accType] << std::endl;
    std::cout << "����� �����: " << client.accountNumber << std::endl;
    std::cout << "����� �� �����: " << client.balance << std::endl;
    std::cout << "���� ���������� ���������: " << client.lastModifiedDay << "/" << client.lastModifiedMonth << "/" << client.lastModifiedYear << std::endl;
}

void DeleteClientInfo(BankClient& client)
{
    client.name.clear();    
    client.accType = OTHER; 
    client.accountNumber = 0; 
    client.balance = 0.0;   
    client.lastModifiedDay = 0;     
    client.lastModifiedMonth = 0;   
    client.lastModifiedYear = 0;    
}

void SearchAndDeleteClientsByBalance(BankClient clients[], int numClients, double threshold)
{
    bool found = false; 

    for (int i = 0; i < numClients; i++)
    {
        if (clients[i].balance > threshold)
        {
            OutputClientInfo(clients[i]); 
            DeleteClientInfo(clients[i]); 
            found = true;         }
    }

    if (!found)
    {
        std::cout << "������� � ������ �� ����� ������ " << threshold << " �� �������." << std::endl;
    }
}

int main()
{
    setlocale(LC_ALL, "ru");

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    BankClient clients[10];
    int numClients = 0;

    std::cout << "������� ���������� � �������� �����: " << std::endl;
    for (int i = 0; i < 3; i++)
    {
        InputClientInfo(clients[i]); 
        numClients++;
    }

    std::cout << "���������� � �������� �����: " << std::endl;
    for (int i = 0; i < numClients; i++)
    {
        OutputClientInfo(clients[i]); 
    }

    std::cout << "������� ��������� �������� ��� ������ � �������� �������� � ������ �� ����� ������: ";
    double threshold;
    std::cin >> threshold;

    SearchAndDeleteClientsByBalance(clients, numClients, threshold); 

    std::cout << "����� ���������� � �������� �����: " << std::endl;
    for (int i = 0; i < numClients; i++)
    {
        OutputClientInfo(clients[i]); 
    }

    return 0;
}
