//Rumana Khan 
//
//Implementation file for UnsortedType.h

#include "UnsortedType.h"

UnsortedType::UnsortedType()
{
    length = 10;
    size = 10;
    ItemType info[10] = {};
}

UnsortedType::UnsortedType(int s)
{
    length = s;
    size = s;
    ItemType info[s];
}

UnsortedType::~UnsortedType()
{
    delete [] info;
}

UnsortedType::UnsortedType(const UnsortedType &D)
{
    length = D.length;
    size = D.size;

    //allocate new array 
    list  = new ItemType[MAX_ITEMS];

    //copy the list from D
    for (int i = 0; i < length; i++)
    {
        info[i] = D.info[i];
    }
}

UnsortedType& UnsortedType::operator = (const UnsortedType &D)
{
    if (this != &D)
    {
        //FIRST deleted the existing array 
        delete [] info;

        length = D.length;
        size = D.size;
        list = new ItemType[MAX_ITEMS];

        for(int i = 0; i < length; i++)
        {
            info[i] = D.info[i];
        }
        return *this;
    }
}

bool UnsortedType::IsFull() const
{
    if (size > MAX_ITEMS)
        return 1;
    else 
        return 0;
}

int UnsortedType::GetLength() const
{
    return length;
}

ItemType UnsortedType::GetItem(ItemType item, bool& found)
{
    bool moreToSearch;
    int location = 0;
    found = false;

    moreToSearch = (location < length);

    while(moreToSearch && !found)
    {
        switch (item.ComparedTo(info[location]))
        {
            case LESS    :
            case GREATER :location++;
                          moreToSearch = (location < length);
                          break;
            case EQUAL   :found = true;
                          item = info[location];
                          break;
        }
    }
    return item;
}

void UnsortedType::MakeEmpty()
{
    length = 0;
}

void UnsortedType::PutItem(ItemType item)
{
   // info[length] = item;
   // length++;

    //Modified 
    ItemType * arr = new ItemType[MAX_ITEMS];
    ItemType * ptr = NULL;
    ptr = new ItemType[MAX_ITEMS * 2];

    for (int i = 0; i < MAX_ITEMS * 2; i++)
    {
        ptr[i] = arr[i];
    }

    delete [] ptr;
    arr = ptr;

    ptr[length] = item;
    length++;

}

void UnsortedType::DeleteItem(ItemType item)
{
    int location = 0;

    while(item.ComparedTo(info[location]) != (EQUAL))
        location++;

    info[location] = info[length - 1];
        length--;
}

void UnsortedType::ResetList()
{
    currentPos = -1;
}

ItemType UnsortedType::GetNextItem()
{
    currentPos++;
    return info[currentPos];
}

ItemType UnsortedType::operator[](int index)
{
    return info[index];
}

