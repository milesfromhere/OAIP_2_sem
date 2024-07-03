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
    std::cout << "������� �������� �����������: ";
    getline(std::cin >> std::ws, country.name);

    std::cout << "������� ������� �����������: ";
    getline(std::cin >> std::ws, country.capital);

    std::cout << "������� ����������� ���������: ";
    std::cin >> country.population;

    std::cout << "������� ������� �����������: ";
    std::cin >> country.area;

    std::cout << "������� ����� ��������� (0 - ��������, 1 - ����������, 2 - ���������, 3 - ��������� � �.�.): ";
    int gov;
    std::cin >> gov;
    country.government = static_cast<FormOfGovernment>(gov);
}

void OutputCountryInfo(const Country& country)
{
    std::string governmentTypes[] = { "��������", "����������", "���������", "���������", "������" };

    std::cout << "��������: " << country.name << std::endl;
    std::cout << "�������: " << country.capital << std::endl;
    std::cout << "����������� ���������: " << country.population << std::endl;
    std::cout << "�������: " << country.area << std::endl;
    std::cout << "����� ���������: " << governmentTypes[country.government] << std::endl;
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
        std::cout << "����������� � �������� '" << capital << "' �� �������." << std::endl;
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
            std::cout << "���������� � ����������� '" << name << "' �������." << std::endl;
            return;
        }
    }

    std::cout << "����������� '" << name << "' �� �������." << std::endl;
}

int main()
{
    setlocale(LC_ALL, "ru");

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Country countries[10];
    int numCountries = 0;

    std::cout << "������� ���������� � ������������: " << std::endl;
    for (int i = 0; i < 3; i++)
    {
        InputCountryInfo(countries[i]);
        numCountries++;
    }

    std::cout << "���������� � ������������: " << std::endl;
    for (int i = 0; i < numCountries; i++)
    {
        OutputCountryInfo(countries[i]);
    }

    std::cout << "������� ������� ����������� ��� ������: ";
    std::string searchCapital;
    getline(std::cin >> std::ws, searchCapital);

    SearchCountryByCapital(countries, numCountries, searchCapital);

    std::cout << "������� �������� ����������� ��� ��������: ";
    std::string countryName;
    getline(std::cin >> std::ws, countryName);

    DeleteCountryByName(countries, numCountries, countryName);

    std::cout << "����� ���������� � ������������: " << std::endl;
    for (int i = 0; i < numCountries; i++)
    {
        OutputCountryInfo(countries[i]);
    }

    return 0;
}
