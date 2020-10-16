#include "IntList.h"

void IntList::removeOdds() {
    if(head != nullptr){
//        if(head->next != nullptr){ // atleast 2 nodes in list
            IntNode *curr = head->next;
            IntNode *prev = head;
            while(curr != nullptr){
                if(curr->data%2 != 0){
                    if(curr->next == nullptr){ // if at last node
                        prev->next = nullptr;
                        delete curr;
                        curr = prev->next;
                    }
                    else{
                        prev->next = curr->next;
                        delete curr;
                        curr = prev->next;
                    }
                }
                else{
                    curr = curr->next;
                    prev = prev->next;
                }
            }
            if(head->data%2 != 0){ // checks head for odd after every other number guaranteed even or deleted
                curr = head;
                head = curr->next;
                delete curr;
                curr = nullptr;
            }
//        }
//         else{ //only 1 node in list
//             if(head->data%2 != 0){
//                 delete head;
//                 head = nullptr;
//                 head->next = nullptr;
//             }
//         }
    }
}