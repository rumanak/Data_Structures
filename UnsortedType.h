/*
 * H File for UnsortedType
 * Name:Rumana Khan
 * Date Last Modified: 2/11/2020
 * Known Bug: N/A
 */

#ifndef _UNSORTEDTYPE_
#define _UNSORTEDTYPE_

#include "ItemType.h"

using namespace std;

class UnsortedType :public ItemType
{
public:
    //Default Constructor
    UnsortedType();
   
    //Constructor with int s for size
    UnsortedType(int s);
   
    //Destructor
    ~UnsortedType();

    //Copy Constructor
    UnsortedType(const UnsortedType &);

    //Assignment operator
    UnsortedType& operator= (const UnsortedType &);
    
    //Function: Returns the list to empty
    void MakeEmpty();

    //Function: Determines whether list is full
    bool IsFull() const;

    //Function: Determines number of elements
    int GetLength() const;

    //Function: Retrieves List item if keys match
    ItemType GetItem(ItemType, bool&);

    //Function: Adds item to this list
    void PutItem(ItemType item);

    //Function: Deletes item from list
    void DeleteItem(ItemType item);

    //Function: Resets the List
    void ResetList();

    //Function: Gets the next item in the list
    ItemType GetNextItem();

    //Function: Overloads []
    ItemType operator [] (int index);

    int length;
    ItemType info[MAX_ITEMS];
    ItemType* list;
    int currentPos;
    int size;


};


#endif // _UNSORTEDTYPE_H_
