//Rumana Khan 
//CPP File for ItemType Class

#include <fstream>
#include "ItemType.h"

ItemType::ItemType()
{
    value = 0;
}

RelationType ItemType::ComparedTo(ItemType otherItem) const
{
    if (value < otherItem.value)
        return LESS;
    else if (value > otherItem.value)
        return GREATER;
    else return EQUAL;
}

void ItemType::Initialize(int number)
{
    value = number;
}

void ItemType::Print(std::ofstream& out) const
{
    out << value << " ";
}

Appointment::Appointment()
{
    year = 1999;
    day = 1;
    month = 1;
    desc = "Default";
}

Appointment::Appointment(int newMonth, int newDay, int newYear, string d)
{
    year = newYear;
    day = newDay;
    month = newMonth;
    desc = d;
}
