//Rumana Khan 
//H File for ItemType 

#include <fstream>
using namespace std;

const int MAX_ITEMS = 5;
enum RelationType {LESS, GREATER, EQUAL};

class ItemType
{
public:
    ItemType();
    RelationType ComparedTo(ItemType) const;
    void Print(std::ofstream&) const;
    void Initialize(int number);
private:
    int value;
};

class Appointment : public ItemType
{
public:
    Appointment();
    Appointment(int newMonth, int newDay, int newYear, string d);

private:
    int year;
    int month;
    int day;
    string desc;

};
