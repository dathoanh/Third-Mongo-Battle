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
    
    return SLinkedList();
}

//You can write your own functions here

//End your own functions

#endif /* thirdBattle_h */
