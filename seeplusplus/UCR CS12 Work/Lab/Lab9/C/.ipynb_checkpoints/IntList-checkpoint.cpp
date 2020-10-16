#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(0) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

ostream & operator<<(ostream &out, IntNode *temp){
    if(temp == nullptr){
        return out;
    }
    if(temp->next != nullptr){
        out << temp->data << " ";
        out << temp->next;
    }
    else{
        out << temp->data;
    }
    return out;
}

ostream & operator<<(ostream &out, const IntList &list){
    if(list.head != nullptr){
        IntNode *temp = list.head;
        out << temp;
    }
    return out;
}

bool IntList::exists(IntNode *t, int val) const{
    if(t != nullptr){
        if(t->data == val){
            return true;
        }
        else{
            t = t->next;
            return exists(t,val);
        }
    }
    return false;
}

bool IntList::exists(int val) const{
    if(head == nullptr){
        return false;
    }
    if(head->data == val){
        return true;
    }
    else{
        IntNode *temp = head;
        return exists(temp, val);
    }
}