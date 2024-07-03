#include <iostream>
#include <string>
#include <windows.h>

enum FormOfGovernment
{
    MONARCHY,
    REPUBLIC,
    DICTATORSHIP,
    THEOCRACY,
    OTHER
};

struct Country
{
    std::string name;           
    std::string capital;        
    int population;             
    double area;                
    FormOfGovernment government; 
};


void InputCountryInfo(Country& country)
{
    std::cout << "Введите название государства: ";
    getline(std::cin >> std::ws, country.name);

    std::cout << "Введите столицу государства: ";
    getline(std::cin >> std::ws, country.capital);

    std::cout << "Введите численность населения: ";
    std::cin >> country.population;

    std::cout << "Введите площадь государства: ";
    std::cin >> country.area;

    std::cout << "Введите форму правления (0 - Монархия, 1 - Республика, 2 - Диктатура, 3 - Теократия и т.д.): ";
    int gov;
    std::cin >> gov;
    country.government = static_cast<FormOfGovernment>(gov);
}

void OutputCountryInfo(const Country& country)
{
    std::string governmentTypes[] = { "Монархия", "Республика", "Диктатура", "Теократия", "Другая" };

    std::cout << "Название: " << country.name << std::endl;
    std::cout << "Столица: " << country.capital << std::endl;
    std::cout << "Численность населения: " << country.population << std::endl;
    std::cout << "Площадь: " << country.area << std::endl;
    std::cout << "Форма правления: " << governmentTypes[country.government] << std::endl;
}

void SearchCountryByCapital(const Country countries[], int numCountries, const std::string& capital)
{
    bool found = false;

    for (int i = 0; i < numCountries; i++)
    {
        if (countries[i].capital == capital)
        {
            OutputCountryInfo(countries[i]);
            found = true;
            break;
        }
    }

    if (!found)
    {
        std::cout << "Государство с столицей '" << capital << "' не найдено." << std::endl;
    }
}

void DeleteCountryByName(Country countries[], int& numCountries, const std::string& name)
{
    for (int i = 0; i < numCountries; i++)
    {
        if (countries[i].name == name)
        {
            countries[i] = countries[numCountries - 1];
            numCountries--;
            std::cout << "Информация о государстве '" << name << "' удалена." << std::endl;
            return;
        }
    }

    std::cout << "Государство '" << name << "' не найдено." << std::endl;
}

int main()
{
    setlocale(LC_ALL, "ru");

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Country countries[10];
    int numCountries = 0;

    std::cout << "Введите информацию о государствах: " << std::endl;
    for (int i = 0; i < 3; i++)
    {
        InputCountryInfo(countries[i]);
        numCountries++;
    }

    std::cout << "Информация о государствах: " << std::endl;
    for (int i = 0; i < numCountries; i++)
    {
        OutputCountryInfo(countries[i]);
    }

    std::cout << "Введите столицу государства для поиска: ";
    std::string searchCapital;
    getline(std::cin >> std::ws, searchCapital);

    SearchCountryByCapital(countries, numCountries, searchCapital);

    std::cout << "Введите название государства для удаления: ";
    std::string countryName;
    getline(std::cin >> std::ws, countryName);

    DeleteCountryByName(countries, numCountries, countryName);

    std::cout << "Новая информация о государствах: " << std::endl;
    for (int i = 0; i < numCountries; i++)
    {
        OutputCountryInfo(countries[i]);
    }

    return 0;
}
