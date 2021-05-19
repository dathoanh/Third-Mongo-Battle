//
//  SLLDataControler.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//

// Students can remove the final initial return of the functions

#ifndef SLLDataController_h
#define SLLDataController_h

#include "dataStructure.h"
#include <vector>
#include <string>

//Functions used to manage Singly Linked List
void print(SLinkedList& list){
    if (!list.size) {
        std::cout << "List is empty" << endl;
        return;
    }
    SoldierNode* head = list.head;
    while (head){
        std::cout << head->data.ID << "->";
        head = head->next;
    }
    std::cout << "NULL"<<endl;
}

bool insertAt (SLinkedList& list, Soldier element, int pos){
    //Insert element into a pos in the SLL
    //Return true if insert successfully, false otherwise
    //TODO
    
    return false;
}

bool removeAt (SLinkedList& list, int idx){
    //Remove element at index idx in the SLL
    //Return true if remove successfully, false otherwise
    //TODO
    
    return false;
}

bool removeFirstItemWithHP (SLinkedList& list, int HP){
    //Remove the first element with HP equals to HP
    //Return true if remove successfully, false otherwise
    //TODO
    
    return false;
}

int indexOf(SLinkedList& list, Soldier soldier){
    //Find index of soldier (start from 0)
    //Return -1 if the soldier does not exist
    //TODO
    
    return -2;
    
}

int size(SLinkedList& list){
    //Return size of the list
    //TODO
    
    return -1;
}

bool empty(SLinkedList& list){
    //Check whether the list is empty
    //TODO
    
    return false;
}

void clear(SLinkedList& list){
    //Delete all of the elements in list
    //TODO
    
}

string getIDAt(SLinkedList& list, int pos){
    //Get ID of the Soldier at pos
    //TODO
    
    return "";
}

int getHPAt(SLinkedList& list, int pos){
    //Get HP of the Soldier at pos
    //TODO
    
    return -1;
}

bool setHPAt(SLinkedList& list, int HP, int pos){
    //Set value of HP at pos
    //TODO
    //Return true if set successfully, false otherwise
    
    return false;
}

bool contains (SLinkedList& list, Soldier soldier){
    //Check if array contains soldier
    //TODO
    
    return false;
}

//You can write your own functions here

//End your own functions

#endif /* SLLDataControler_h */
