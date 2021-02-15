#include <iostream>
#include "person.h"

using namespace std;

int main()
{
    string name, surname;
    cout << "Insert name: ";
    cin >> name;

    cout << "Insert surname: ";
    cin >> surname;

    int birth_day, birth_month, birth_year;

    cout << "Insert birth day: ";
    cin >> birth_day;

    cout << "Insert birth month: ";
    cin >> birth_month;

    cout << "Insert birth year: ";
    cin >> birth_year;

    Person* p = new Person(name,surname,birth_day,birth_month,birth_year);

    int curr_day, curr_month, curr_year;

    cout << "Insert current day: ";
    cin >> curr_day;

    cout << "Insert current month: ";
    cin >> curr_month;

    cout << "Insert current year: ";
    cin >> curr_year;

    cout << "Your age is: " << p->age(curr_day,curr_month,curr_year) << endl;

    return 0;
}

