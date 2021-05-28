//
//  thirdBattle.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//
// Students can remove the final initial return of the functions

#ifndef thirdBattle_h
#define thirdBattle_h

#include "SLLDataController.h"
#include "ArrayDataController.h"
#include <vector>
#include <string>

// Function Prototypes
bool operator<(const Soldier soldier1, const Soldier soldier2);
SoldierNode* addNode(SoldierNode *head, SoldierNode *&newNode);

//////////////////////////////////////////////////////
/// TASK 1
//////////////////////////////////////////////////////

bool push(Array& array, Soldier soldier){
    //Return true if push successfully, false otherwise
    //TODO
    if(array.arr == NULL)
    {
        initArray(array, 3);
    }
    
    return insertAt(array, soldier, array.size);
}

bool pop(Array& array){
    //Return true if pop successfully, false otherwise
    //TODO
    
    return removeAt(array, array.size - 1);
}

Soldier top(Array& array){
    //TODO

    if(array.size == 0)
    {
        return Soldier();
    }
    else
    {
        return array.arr[array.size - 1];
    }
    
    // return Soldier();//return this if cannot get top
}

//////////////////////////////////////////////////////
/// TASK 2
//////////////////////////////////////////////////////

bool enqueue(SLinkedList& list, Soldier soldier){
    //Return true if enqueue successfully, false otherwise
    //TODO
    
    return insertAt(list, soldier, list.size);
}

bool dequeue(SLinkedList& list){
    //Return true if dequeue successfully, false otherwise
    //TODO
    
    return removeAt(list, 0);
}

Soldier front(SLinkedList& list){
    //TODO
    
    if(list.size == 0)
    {
        return Soldier();
    }
    else 
    {
        return list.head->data;
    }
    
    // return Soldier();//Return this if cannot get front
}

//////////////////////////////////////////////////////
/// TASK 3
//////////////////////////////////////////////////////

void reverse(SLinkedList& list){
    //TODO

    SoldierNode *tempHead, *tempNode;
    tempHead = list.head;
    list.head = NULL;
    while(tempHead != NULL)
    {
        tempNode = tempHead;
        tempHead = tempHead->next;

        tempNode->next = list.head;
        list.head = tempNode;
    }
}

//////////////////////////////////////////////////////
/// TASK 4
//////////////////////////////////////////////////////

SLinkedList merge(SLinkedList& list1, SLinkedList& list2){
    //TODO

    SLinkedList retList;

    while(list1.head != NULL || list2.head != NULL)
    {
        if(list1.head == NULL)
        {
            retList.head = addNode(retList.head, list2.head);
        }
        else if(list2.head == NULL)
        {
            retList.head = addNode(retList.head, list1.head);
        }
        else
        {
            if(list1.head->data < list2.head->data)
            {
                retList.head = addNode(retList.head, list1.head);
            }
            else
            {
                retList.head = addNode(retList.head, list2.head);
            }
        }
        retList.size++;
    }

    reverse(retList);
    
    return retList;
}

//You can write your own functions here
bool operator<(const Soldier soldier1, const Soldier soldier2)
{
    if(soldier1.HP < soldier2.HP)
    {
        return true;   
    }
    else if(soldier1.HP == soldier2.HP)
    {
        if(soldier1.isSpecial == soldier2.isSpecial)
        {
            if(soldier1.ID < soldier2.ID)
            {
                return true;
            }
        }
        else if(soldier1.isSpecial == false)
        {
            return true;
        }
    }
    
    return false;
}

SoldierNode* addNode(SoldierNode *head, SoldierNode *&newNode)
{
    SoldierNode *tempNode = newNode;
    newNode = newNode->next;
    tempNode->next = head;
    return tempNode;
}

//End your own functions

#endif /* thirdBattle_h */
