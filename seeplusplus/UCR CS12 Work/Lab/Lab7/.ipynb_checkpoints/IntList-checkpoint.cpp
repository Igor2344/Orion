#include "IntList.h"

IntList::IntList(){
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList(){
    while(head != nullptr){
        IntNode *next = head->next;
        delete head;
        head = next;
    }
}

IntList::IntList(const IntList &cpy){
    head = nullptr;
    tail = nullptr;
    if(cpy.head != nullptr){
        IntNode *tempt = cpy.head;
        while(tempt->next != nullptr){
            push_back(tempt->data);
            tempt = tempt->next;
        }
        push_back(tempt->data);
    }
}

IntList & IntList::operator=(const IntList &rhs){
    if(this != &rhs){
        clear();
        if(rhs.head != nullptr){
            IntNode *tempt = rhs.head;
            while(tempt->next != nullptr){
                push_back(tempt->data);
                tempt = tempt->next;
            }
            push_back(tempt->data);
        }
    }
    return *this;
}

void IntList::clear(){
    while(head != nullptr){
        pop_front();
    }
    tail = nullptr;
}

void IntList::selection_sort(){
    IntNode *i = nullptr;
    IntNode *point = nullptr;
    int min;
    for(i = head; i != nullptr; i = i->next){
        for(point = i; point != nullptr; point = point->next){
            if(point->data < i->data){
                min = point->data;
                point->data = i->data;
                i->data = min;
            }
        }
    }
}

void IntList::insert_ordered(int value){
    if(head == nullptr){
        push_front(value);
    }
    else{
        IntNode *prev = head;
        if(tail->data <= value){
            push_back(value);
            return;
        }
        for(IntNode *cur = head->next; cur != nullptr; cur = cur->next){
            if(cur->data >= value && prev->data < value){
                IntNode *ins = new IntNode(value);
                prev->next = ins;
                ins->next = cur;
                return;
            }
            prev = prev->next;
        }
        push_front(value);
    }
}

void IntList::remove_duplicates(){
    if(head != nullptr){
        if(head->next != nullptr){
            IntNode *num = head;
            IntNode *cur = nullptr;
            IntNode *prev = nullptr;
            while(num != tail){
                cur = num->next;
                prev = num;
                while(cur != nullptr){
                    if(cur->data == num->data){
                        if(cur == tail){
                            tail = prev;
                            prev->next = nullptr;
                            delete cur;
                            cur = prev->next;
                        }
                        else{
                            prev->next = cur->next;
                            delete cur;
                            cur = prev->next;
                        }
                    }
                    else{
                        cur = cur->next;
                        prev = prev->next;
                    }
                }
                if(num != tail){
                    num = num->next;
                }
            }
        }
    }
}

void IntList::push_front(int value){
    if(head == nullptr){
        head = new IntNode(value);
        tail = head;
    }
    else{
        IntNode *tempNext = head;
        head = new IntNode(value);
        head->next = tempNext;
    }
}

void IntList::pop_front(){
    if(head == tail){
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else if(head != nullptr){
        IntNode *tempNext = head->next;
        delete head;
        head = tempNext;
    }
}

void IntList::push_back(int value){
    if(head == nullptr){
        head = new IntNode(value);
        tail = head;
    }
    else{
        IntNode *addNode = new IntNode(value);
        tail->next = addNode;
        tail = addNode;
    }
}

bool IntList::empty() const{
    return head == nullptr;
}

const int & IntList::front()const{
    return head->data;
}

const int & IntList::back()const{
    return tail->data;
}

ostream & operator<<(ostream &out, const IntList &list){
    if(list.head != nullptr){
        IntNode *temp = list.head;
        while(temp != list.tail){
            out << temp->data << " ";
            temp = temp->next;
        }
        out << temp->data;
    }
    return out;
}