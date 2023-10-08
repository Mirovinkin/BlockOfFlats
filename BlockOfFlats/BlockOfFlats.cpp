#include <iostream>
#include <iostream>
#include <string>
#include <math.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <typeinfo>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
//#include <cstdlib>
#include <ctype.h>
#include <vector>

using namespace std;

class Human
{
private:
    string _name;
    string _surname;
    string _phoneNumber;

public:
    Human() {};
    Human(const string& Name, const string& Surname, const string& PhoneNumber, const int& ResidenceNumber) :
        _name(typeid(Name)==typeid(string) ? Name : ""),
        _surname(typeid(Surname) == typeid(string) ? Surname : ""),
        _phoneNumber(typeid(PhoneNumber) == typeid(string) ? PhoneNumber : "") {};

    string GetName() {
        return _name == "" ? "Данных Нет" : _name;
    }

    void SetName(const string& Name) {
        if (typeid(Name) == typeid(string)) {
            _name = Name;
        }
        else {
            cout << "Введен неправильный формат";
        }
    }

    string GetSurname() {
        return _surname == "" ? "Данных нет" : _surname;
    }

    void SetSurname(const string& Surname) {
        if (typeid(Surname) == typeid(string)) {
            _surname = Surname;
        }
        else {
            cout << "Введен неправильный формат";
        }
    }

    string GetPhoneNumber() {
        return _phoneNumber == "" ? "Данных нет" : _phoneNumber;
    }

    void SetPhoneNumber(const string& PhoneNumber) {
        if (typeid(PhoneNumber) == typeid(string)) {
            _phoneNumber = PhoneNumber;
        }
        else {
            cout << "Введен неправильный формат";
        }
    }

    
};
class Flat
{
private:
    vector<Human> _residents;
    int _roomTotalNumber;
    double _rent;
    int _residenceNumber;
public:
    Flat() {};
    Flat(const Human& Resident, const int& RoomTotalNumber, const double& Rent, const int& ResidenceNumber) {
        _residents.push_back(Resident);
        _roomTotalNumber = RoomTotalNumber;
        _rent = Rent;
        _residenceNumber = typeid(ResidenceNumber) == typeid(int) ? ResidenceNumber : NAN;
    }


    void AddResident(const Human& Resident) {
        _residents.push_back(Resident);
    }

    void GetResidentsData() {
        cout << "Номер квартиры:" << _residenceNumber << endl;

        for (int i = 0; i < _residents.size(); i++)
        {
            cout << "Имя:" << _residents[i].GetName() << endl;
            cout << "Фамилия:" << _residents[i].GetSurname() << endl;
            cout << "Номер телефона:" << _residents[i].GetPhoneNumber() << "\n\n";
        }
    }

    void SetRent(const double& Rent) {
        _rent = Rent;
    }
    void GetTotalRent() {
        double TotalRent = _rent;
        for (int i = 0; i <= _residents.size(); i++)
        {
            TotalRent += _rent;
        }//Видимо, double он не умеет умножать, поэтому пришлось воспользоваться циклом
        cout << "Оплата за квартиру составляет " << _rent << " рублей за 1 жильца\n";
        cout << "Общая плата за проживание составляет " << TotalRent << " рублей \n\n";
    }

    int GetResidenceNumber() {
        return _residenceNumber == NAN ? 0 : _residenceNumber;
    }

    int GetResidentsTotalNumber() {
        return _residents.size();
    }

    void SetResidenceNumber(const int& ResidenceNumber) {
        if (typeid(ResidenceNumber) == typeid(int)) {
            _residenceNumber = ResidenceNumber;
        }
        else {
            cout << "Введен неправильный формат";
        }
    }

   

};

class Block
{
private:
    vector<Flat> _flats;
public:
    Block() {};
    Block(const Flat& FlatN) {
        _flats.push_back(FlatN);
    }
    void AddFlat(const Flat& FlatN) {
        _flats.push_back(FlatN);
    }
    void GetTotalFlatNumber() {
        cout << "Общее количество квартир: " << _flats.size() << endl;
    }

    void GetTotalResidentsNumber() {
        int TotalResidents = 0;

        for (Flat item : _flats) {
            TotalResidents += item.GetResidentsTotalNumber();
        }

        cout << "Общее количество жильцов в доме: " << TotalResidents << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Rus");

    Human human1;
    human1.SetName("Иван");
    human1.SetSurname("Иванов");
    human1.SetPhoneNumber("12389021389");


    Human human2;
    human2.SetName("Дима");
    human2.SetSurname("Смирнов");
    human2.SetPhoneNumber("12389021389");

    Human human3;
    human3.SetName("Лилия");
    human3.SetSurname("Козлова");
    human3.SetPhoneNumber("12389021389");

    Human human4;
    human4.SetName("Мария");
    human4.SetSurname("Кузнецова");
    human4.SetPhoneNumber("12389021389");

    Human human5;
    human5.SetName("Нурлан");
    human5.SetSurname("Салматыев");
    human5.SetPhoneNumber("12389021389");

    Flat flat1;
    flat1.AddResident(human1);
    flat1.AddResident(human2);
    flat1.AddResident(human3);
    flat1.AddResident(human4);
    flat1.AddResident(human5);

    flat1.SetRent(1680);

    flat1.GetTotalRent();
    cout << "Общее количесто жильцов в квартире " << flat1.GetResidentsTotalNumber() << endl;


    flat1.GetResidentsData();

    Flat flat2;
    flat2.AddResident(human1);
    flat2.AddResident(human2);
    flat2.AddResident(human3);
    flat2.AddResident(human4);
    flat2.AddResident(human5);

    Block block1;
    block1.AddFlat(flat1);
    block1.AddFlat(flat2);
    block1.GetTotalFlatNumber();
    block1.GetTotalResidentsNumber();

}