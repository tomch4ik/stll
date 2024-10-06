#include <iostream>
#include <list>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;


struct Car
{
    string name;
    int year;
    double price;
    double volume;

    void print() const
    {
        cout << "Name: " << name << endl;
        cout << "Year: " << year << endl;
        cout << "Volume: " << volume << endl;
        cout << "Price: " << price << endl;
    }
};
class Dealer
{
private:
    vector<Car> cars;

public:
    void addCar(const string& name, int year, double volume, double price)
    {
        cars.push_back({ name, year, volume, price });
    }
    void deletecar(int index)
    {
        if (index >= 0 && index < cars.size())
        {
            cars.erase(cars.begin() + index);
            cout << "Car deleted" << endl;
        }
    }
    void printcars() const
    {
        if (cars.empty())
        {
            cout << "car not found" << endl;
        }
        else
        {
            for (auto& car : cars)
            {
                car.print();
            }
        }
    }
    void sortyear()
    {
        sort(cars.begin(), cars.end(), [](const Car& a, const Car& b)
            {
                return a.year < b.year;
            });
        cout << "Sort by year" << endl;
    }
    void searchname(const string& name) const
    {
        for (const auto& car : cars)
        {
            if (car.name == name)
            {
                car.print();
                return;
            }
        }
        cout << "Car not found" << endl;
    }
    void sortprice()
    {
        sort(cars.begin(), cars.end(), [](const Car& a, const Car& b)
            {
                return a.price < b.price;
            });
        cout << "Sort by price" << endl;
    }
    void sortvolume()
    {
        sort(cars.begin(), cars.end(), [](const Car& a, const Car& b)
            {
                return a.volume < b.volume;
            });
        cout << "Sort by volume" << endl;
    }

};

int main()
{
    Dealer dealer;
    int choice;

    cout << "Menu: " << endl;
    cout << "1 - Add car" << endl;
    cout << "2 - Delete car" << endl;
    cout << "3 - Show car" << endl;
    cout << "4 - Sort" << endl;
    cout << "5 - Sort by price" << endl;
    cout << "6 - Sort by volume" << endl;
    cout << "7 - Sort by name" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        string name;
        int year;
        double volume, price;
        cout << "Name: ";
        cin >> name;
        cout << "Year: ";
        cin >> year;
        cout << "Volume: ";
        cin >> volume;
        cout << "Price: ";
        cin >> price;
        dealer.addCar(name, year, volume, price);
        cout << "Car added" << endl;
        break;
    }
    case 2:
    {
        int index;
        cout << "input index to delete car: ";
        cin >> index;
        dealer.deletecar(index);
        break;
    }
    case 3:
    {
        dealer.printcars();
        break;
    }
    case 4:
    {
        dealer.sortyear();
        dealer.printcars();
        break;
    }
    case 5:
    {
        dealer.sortprice();
        dealer.printcars();
        break;
    }
    case 6:
    {
        dealer.sortvolume();
        dealer.printcars();
        break;
    }
    case 7:
    {
        string name;
        cout << "Car name for search: ";
        cin >> name;
        dealer.searchname(name);
        break;
    }
    default:
        cout << "Error" << endl;

    }
}