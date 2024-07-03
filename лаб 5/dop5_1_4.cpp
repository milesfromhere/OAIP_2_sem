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
    std::cout << "Введите Ф.И.О. клиента: ";
    getline(std::cin >> std::ws, client.name);

    std::cout << "Введите тип счета (0 - Сберегательный, 1 - Текущий, 2 - Депозит и т.д.): ";
    int type;
    std::cin >> type;
    client.accType = static_cast<AccountType>(type);

    std::cout << "Введите номер счета: ";
    std::cin >> client.accountNumber;

    std::cout << "Введите сумму на счете: ";
    std::cin >> client.balance;

    std::cout << "Введите дату последнего изменения (День Месяц Год): ";
    std::cin >> lastModifiedDay >> lastModifiedMonth >> lastModifiedYear;

    client.lastModifiedYear = lastModifiedYear;
    client.lastModifiedMonth = lastModifiedMonth;
    client.lastModifiedDay = lastModifiedDay;
}

void OutputClientInfo(const BankClient& client)
{
    std::string accountTypes[] = { "Сберегательный", "Текущий", "Депозит", "Другой" };

    std::cout << "Ф.И.О.: " << client.name << std::endl;
    std::cout << "Тип счета: " << accountTypes[client.accType] << std::endl;
    std::cout << "Номер счета: " << client.accountNumber << std::endl;
    std::cout << "Сумма на счете: " << client.balance << std::endl;
    std::cout << "Дата последнего изменения: " << client.lastModifiedDay << "/" << client.lastModifiedMonth << "/" << client.lastModifiedYear << std::endl;
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
        std::cout << "Клиенты с суммой на счете больше " << threshold << " не найдены." << std::endl;
    }
}

int main()
{
    setlocale(LC_ALL, "ru");

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    BankClient clients[10];
    int numClients = 0;

    std::cout << "Введите информацию о клиентах банка: " << std::endl;
    for (int i = 0; i < 3; i++)
    {
        InputClientInfo(clients[i]); 
        numClients++;
    }

    std::cout << "Информация о клиентах банка: " << std::endl;
    for (int i = 0; i < numClients; i++)
    {
        OutputClientInfo(clients[i]); 
    }

    std::cout << "Введите пороговое значение для поиска и удаления клиентов с суммой на счете больше: ";
    double threshold;
    std::cin >> threshold;

    SearchAndDeleteClientsByBalance(clients, numClients, threshold); 

    std::cout << "Новая информация о клиентах банка: " << std::endl;
    for (int i = 0; i < numClients; i++)
    {
        OutputClientInfo(clients[i]); 
    }

    return 0;
}
