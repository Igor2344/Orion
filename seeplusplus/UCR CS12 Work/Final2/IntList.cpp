#include "IntList.h"

void IntList::distanceFrom(int key) {
   searchAndModify(head, key);
}


int IntList::searchAndModify(IntNode *curr, int key) {
    if(curr == nullptr){
        return 0;
    }
    if(curr->data == key){
        return 0;
    }
    curr->data = 1 + searchAndModify(curr->next, key); 
    return curr->data;
}