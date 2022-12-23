#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <string>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n----------------------------------\n"

const std :: map<int, std::string> violation =
{
    {0, "Проезд на красный,"},
    {1, "Превышение скорости,"},
    {2, "Парковка в неположенном месте,"},
    {3, "Проезд по встречной полосе,"},
    {4, "Оскорбление офицера,"},
    {5, "Проезд в нетрезвом виде,"},
    {6, "Дрифт на перекрестке,"},
};

class Crime
{
    int id;
    std::string place;
public:
    Crime(int violation, const std::string& place):id(violation), place(place) {}
    ~Crime(){}
    
    friend std::ostream& operator<< (std::ostream& os, const Crime& obj);
};
std::ostream& operator<< (std::ostream& os, const Crime& obj)
{
    return os << violation.at(obj.id) << " " << obj.place;
 
}

void print(std::map<std::string, std::list<Crime>> base)
{
    for (std::map<std::string, std::list<Crime>>::iterator it = base.begin(); it != base.end(); ++it)
    {
        cout << it->first << ":\n";
        for (std::list<Crime>::iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
        {
            cout << *jt << endl;
        }
        cout << delimiter << endl;
    }
}

void save(std::map<std::string, std::list<Crime>> base)
{
    std::string file = "Police_Base.txt";
    std::ofstream printfile;
    printfile.open(file, std::ofstream::app);

    if (!printfile.is_open())
    {
        cout << "File open error" << endl;
    }
    else
    {
        for (std::map<std::string, std::list<Crime>>::iterator it = base.begin(); it != base.end(); ++it)
        {
            printfile << it->first << ":\n";
            for (std::list<Crime>::iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
            {
                printfile << *jt << endl;
            }
            printfile << delimiter << endl;
        }
    }
    printfile.close();
}

void load()
{
    std::string file = "Police_Base.txt";
    std::ifstream file_in;
    file_in.open(file);

    if (!file_in.is_open())
    {
        cout << "File open error" << endl;
    }
    else
    {
        cout << "файл открыт" << endl;
        char key;
        while (file_in.get(key))
        {
            cout << key;
        }
    }
    file_in.close();
}

void main()
{
    setlocale(LC_ALL, "");
    std::map<std::string, std::list<Crime>> base =
    {
        {"a777bb", {Crime(0, "Улица Ленина"), Crime(6, "Улица Космонавтов"), Crime(3, "Улица Октябрьская")}},
        {"m123ab", {Crime(2, "Площадь Революции")}},
        {"a234bb", {Crime(5, "Улица Ленина"), Crime(4, "Улица Ленина")}}

    };
    //print(base);
    save(base);
    load();
}


