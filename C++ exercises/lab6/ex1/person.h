#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person
{
public:
    Person(string name, string surname, int birth_day, int birth_month, int birth_year);
    int age(int curr_day, int curr_month, int curr_year);
private:
    string n, s;
    int bd,bm,by;
};

#endif // PERSON_H
