#include <iostream>
#include <set>
#include <map>
#include <list>
#include <string>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

//#define STL_SET
//#define STL_MAP
//#define DICTIONARY

void main()
{
    setlocale(LC_ALL, "");
#ifdef STL_SET
    std::set<int> set = { 50, 25, 75, 16, 32, 64, 128, 8 };
    for (std::set<int>::iterator it = set.begin(); it != set.end(); ++it)
    {
        cout << *it << tab;
    }
    cout << endl;
    int value;
    cout << "Введите значение: "; cin >> value;
    set.insert(value);
    for (int i : set)cout << i << tab; cout << endl;
    std::set<int>::iterator position = set.find(75);
    set.insert(1024);
    for (int i : set)cout << i << tab; cout << endl;
    for (std::set<int>::iterator it = set.lower_bound(20); it != set.upper_bound(80); ++it)
    {
        cout << *it << tab;
    }
    cout << endl;
#endif // STL_SET
     
#ifdef STL_MAP
    std::multimap<int, std::string> week =
    {
        std::pair<int, std::string>(0, "Sunday"),
        std::pair<int, std::string>(1, "Monday"),
        std::pair<int, std::string>(2, "Tuesday"),
        {3, "Wednesday"},
        {4, "Thursday"},
        {5, "Friday"},
        {6, "Saturday"}

    };
    for (std::map<int, std::string>::iterator it = week.begin(); it != week.end(); ++it)
    {
        cout << it->first << tab << it->second << endl;
    }
#endif // STL_MAP

#ifdef DICTIONARY
    std::map<std::string, std::list<std::string>> dictionary =
    {
        std::pair < std::string, std::list<std::string>>("squad", {"группа", "команда", "отделение"}),
        std::pair < std::string, std::list<std::string>>("flock", {"клок", "пучок"}),
        {"plural", {"монжественный", "бесчисленный", "многочисленный"}},
        {"space", {"космос", "пробел", "пространство"}}
    };
    for (std::map<std::string, std::list<std::string>>::iterator it = dictionary.begin(); it != dictionary.end(); ++it)
    {
        cout << it->first << ":\t";
        for (std::list<std::string>::iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
        {
            cout << *jt << ", ";
        }
        cout << "\b\b;";
        cout << endl;
    }
    cout << "\n--------------------------------------------------------\n";

    for (std::pair<std::string, std::list<std::string>> i : dictionary)
    {
        cout << i.first << ":\t ";
        for (std::string j : i.second)
        {
            cout << j << ", ";
        }
        cout << "\b\b;";
        cout << endl;
    }

#endif // DICTIONARY



}


