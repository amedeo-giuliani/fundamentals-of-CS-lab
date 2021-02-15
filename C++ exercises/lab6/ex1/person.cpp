#include "person.h"

Person::Person(string name, string surname, int birth_day, int birth_month, int birth_year)
{
    n = name;
    s = surname;
    bd = birth_day;
    bm = birth_month;
    by = birth_year;
}

int Person::age(int curr_day, int curr_month, int curr_year)
{
    int age;

    age = curr_year - by;

    if ((bm >= curr_month) && (bd >= curr_day))
        age--;

    return age;
}
