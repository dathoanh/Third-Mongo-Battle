//
//  SLLDataControler.h
//  KTLT ASS 3
//
//  Completed by Đào Hoành Đạt on 21/05/2021.
//

// Students can remove the final initial return of the functions

#ifndef SLLDataController_h
#define SLLDataController_h

#include "dataStructure.h"
#include <vector>
#include <string>

// Own function prototypes

SoldierNode* getPrevSoldier(const SLinkedList& list, const int pos);

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

    if(pos < 0 || pos > list.size) return false;
    SoldierNode *newNode = new SoldierNode(element, NULL);
    if(newNode == NULL) return false;

    if(list.size == 0)
    {
        list.head = newNode;
    }
    else
    {
        SoldierNode *prevNode;
        if(pos == 0)
        {
            newNode->next = list.head;
            list.head = newNode;
        }
        else
        {
            prevNode = getPrevSoldier(list, pos);
            newNode->next = prevNode->next;
            prevNode->next = newNode;
        }

    }

    list.size++;
    
    return true;
}

bool removeAt (SLinkedList& list, int idx){
    //Remove element at index idx in the SLL
    //Return true if remove successfully, false otherwise
    //TODO

    if(idx < 0 || idx >= list.size) return false;

    SoldierNode *prevNode, *currNode;

    if(idx == 0)
    {
        currNode = list.head;
        list.head = currNode->next;
    }
    else 
    {
        prevNode = getPrevSoldier(list, idx);
        currNode = prevNode->next;
        prevNode->next = currNode->next;
    }
    
    currNode->next = NULL;

    delete currNode;
    list.size--;

    return true;
}

bool removeFirstItemWithHP (SLinkedList& list, int HP){
    //Remove the first element with HP equals to HP
    //Return true if remove successfully, false otherwise
    //TODO

    if(list.size == 0) return false;

    SoldierNode *prevNode, *currNode;
    currNode = list.head;

    while(currNode != NULL)
    {
        if(currNode->data.HP == HP)
        {
            if(currNode == list.head)
            {
                list.head = currNode->next;
            }
            else
            {
                prevNode->next = currNode->next;
            }

            currNode->next = NULL;
            delete currNode;
            list.size--;
            return true;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
    
    return false;
}

int indexOf(SLinkedList& list, Soldier soldier){
    //Find index of soldier (start from 0)
    //Return -1 if the soldier does not exist
    //TODO

    if(list.size == 0) return -1;

    SoldierNode *tempNode = list.head;
    int index = 0;
    while(tempNode != NULL)
    {
        if(tempNode->data.ID == soldier.ID)
        {
            if( tempNode->data.HP == soldier.HP &&
                tempNode->data.isSpecial == soldier.isSpecial)
                {
                    return index;
                }
        }
        index++;
        tempNode = tempNode->next;
    }
    
    return -1;
    
}

int size(SLinkedList& list){
    //Return size of the list
    //TODO
    
    return list.size;
}

bool empty(SLinkedList& list){
    //Check whether the list is empty
    //TODO
    
    if(list.size == 0) 
        return true;
    else 
        return false;
}

void clear(SLinkedList& list){
    //Delete all of the elements in list
    //TODO
    
    SoldierNode *delNode;

    while(list.head != NULL)
    {
        delNode = list.head;
        list.head = delNode->next;

        delNode->next = NULL;

        delete delNode;
        list.size--;
    }

}

string getIDAt(SLinkedList& list, int pos){
    //Get ID of the Soldier at pos
    //TODO

    if(pos < 0 || pos >= list.size) return "-1";

    SoldierNode *tempNode;
    if(pos == 0)
    {
        tempNode = list.head;
    }
    else
    {
        tempNode = getPrevSoldier(list, pos)->next;
    }
    
    return tempNode->data.ID;
}

int getHPAt(SLinkedList& list, int pos){
    //Get HP of the Soldier at pos
    //TODO

    if(pos < 0 || pos >= list.size) return -1;

    SoldierNode *tempNode;
    if(pos == 0)
    {
        tempNode = list.head;
    }
    else
    {
        tempNode = getPrevSoldier(list, pos)->next;
    }
    
    return tempNode->data.HP;
}

bool setHPAt(SLinkedList& list, int HP, int pos){
    //Set value of HP at pos
    //TODO
    //Return true if set successfully, false otherwise
    
    if(pos < 0 || pos >= list.size) return false;

    SoldierNode *tempNode;
    if(pos == 0)
    {
        tempNode = list.head;
    }
    else
    {
        tempNode = getPrevSoldier(list, pos)->next;
    }
    tempNode->data.HP = HP;

    return true;
}

bool contains (SLinkedList& list, Soldier soldier){
    //Check if array contains soldier
    //TODO

    int index = indexOf(list, soldier);

    if(index == -1)
        return false;
    else 
        return true;
}

//You can write your own functions here
SoldierNode* getPrevSoldier(const SLinkedList& list, const int pos)
{
    SoldierNode *retNode;
    retNode = list.head;
    int index = 0;

    while(index < pos - 1)
    {
        index++;
        retNode = retNode->next;
    }

    return retNode;
}
//End your own functions

#endif /* SLLDataControler_h */
