//
//  ArrayDataController.h
//  KTLT ASS 3
//
//  Completed by Đào Hoành Đạt on 22/05/2021.
//  Update print and setHPat function on 21/05/2021.
//

// Students can remove the final initial return of the functions

#ifndef ArrayDataController_h
#define ArrayDataController_h

#include "dataStructure.h"
#include <vector>
#include <string>

// Function prototypes
void ensureCapacity(Array& array, int newCap);
bool operator==(const Soldier firstSoldier, const Soldier secondSoldier);
void copySoldier(Soldier *newArr, const Soldier *oldArr, size_t oldSize);

//Functions used to manage Array
void print(Array& array){
    if (!array.size) {
        std::cout << "Array is empty" << endl;
        return;
    }
    std::cout <<"[";
    for(int i=0;i<array.size;i++){
        std::cout << array.arr[i].ID << " ";
    }
    std::cout <<"]" << endl;
}

void initArray (Array& array, int cap){
    //Init a new array with capacity equals to cap
    //TODO

    array.capacity = cap;
    array.arr = new Soldier[cap];
    
}

bool insertAt(Array& array, Soldier element, int pos){
    //Insert element into a pos in the array
    //Return true if insert successfully, false otherwise
    //TODO

    if(pos < 0 || pos > array.size || array.arr == NULL) 
    {
        return false;
    }

    int index = array.size;
    while(index > pos)
    {
        array.arr[index] = array.arr[index - 1];
        index--;
    }

    array.arr[pos] = element;
    
    array.size++;
    
    if(array.size == array.capacity)
    {
        int newCap = (array.capacity * 3) / 2 + 1;
        ensureCapacity(array, newCap);
    }

    return true;
}

bool removeAt (Array& array, int idx){
    //Remove element at index idx in the array
    //Return true if remove successfully, false otherwise
    //TODO

    if(idx < 0 || idx >= array.size)
    {
        return false;
    }

    while(idx < array.size)
    {
        array.arr[idx] = array.arr[idx + 1];
        idx++;
    }
    
    array.size--;
    return true;
}

bool removeFirstItemWithHP (Array& array, int HP){
    //Remove the first element with HP equals to HP
    //Return true if remove successfully, false otherwise
    //TODO

    if(array.size == 0) return false;

    for(int i = 0; i < array.size; i++)
    {
        if(array.arr[i].HP == HP)
        {
            while(i < array.size)
            {
                array.arr[i] = array.arr[i + 1];
                i++;
            }
            array.size--;
            return true;
        }
    }
    
    return false;
}

void ensureCapacity(Array& array, int newCap){
    //Extend the capacity of the array
    //TODO

    Soldier *newArr = new Soldier[newCap];
    copySoldier(newArr, array.arr, array.size);
    delete []array.arr;
    array.arr = newArr;
    array.capacity = newCap;
    
}

int indexOf(Array& array, Soldier soldier){
    //Find index of soldier (start from 0)
    //Return -1 if the soldier does not exist
    //TODO

    for(int i = 0; i < array.size; i++)
    {
        if(array.arr[i] == soldier)
        {
            return i;
        }
    }
    
    return -1;
}

int size(Array& array){
    //Return size of the array
    //TODO
    
    return array.size; 
}

bool empty(Array& array){
    //Check whether the array is empty
    //TODO
    
    if(array.size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

string getIDAt(Array& array, int pos){
    //Get ID of the Soldier at pos
    //TODO

    if(pos < 0 || pos >= array.size) return "-1";
    
    return array.arr[pos].ID;
}

int getHPAt(Array& array, int pos){
    //Get HP of the Soldier at pos
    //TODO

    if(pos < 0 || pos >= array.size) return -1;
    
    return array.arr[pos].HP;
}

bool setHPAt(Array& array, int HP, int pos){
    //Set value of HP at pos
    //TODO
    //Return true if set successfully, false otherwise
    
    if(pos < 0 || pos >= array.size)
    {
        return false;
    }
    else
    {
        array.arr[pos].HP = HP;
    }

    return true;
}

void clear(Array& array){
    //Delete all of the elements in array
    //TODO

    if(array.size == 0) return;

    delete []array.arr;
    array.arr = NULL;
    array.capacity = 0;
    array.size = 0;
    
}

bool contains (Array& array, Soldier soldier){
    //Check if array contains soldier
    //TODO

    int index = indexOf(array, soldier);
    if(index == -1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

//You can write your own functions here

bool operator==(const Soldier firstSoldier, const Soldier secondSoldier)
{
    if( firstSoldier.ID == secondSoldier.ID &&
        firstSoldier.HP == secondSoldier.HP &&
        firstSoldier.isSpecial == secondSoldier.isSpecial)
        {
            return true;
        }
    
    return false;
}

void copySoldier(Soldier *newArr, const Soldier *oldArr, size_t oldSize)
{
    for(size_t i = 0; i < oldSize; i++)
    {
        newArr[i] = oldArr[i];
    }
}

//End your own functions

#endif /* ArrayDataController_h */
