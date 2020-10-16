#ifndef __INTLIST_H__
#define __INTLIST_H__

#include <ostream>

using namespace std;

struct IntNode {
    int data;
    IntNode *next;
    IntNode(int data) : data(data), next(nullptr) {}
};


class IntList {

 private:
   IntNode *head;

 public:

   /* Initializes an empty list.
   */
   IntList() : head(nullptr) {}

   /* Inserts a data value to the front of the list.
   */
   void push_front(int val) {
      if (!head) {
         head = new IntNode(val);
      } else {
         IntNode *temp = new IntNode(val);
         temp->next = head;
         head = temp;
      }  
   }
   
   /* Outputs to a single line all of the int values stored in the list, each separated by a space. 
      This function does NOT output a newline or space at the end.
   */
   friend ostream & operator<<(ostream &out, const IntList &rhs) {
      if (rhs.head) {
         IntNode *curr = rhs.head;
         out << curr->data;
         for (curr = curr->next ; curr ; curr = curr->next) {
            out << ' ' << curr->data;
         }
      }
      return out;
   }
   
   
   /* Update all nodes previous to the node containing the passed in integer to be the distance from that node 
      (1 for the node directly preceding it)
      No return value. Works by calling a recursive function (defined below).
   */
   void distanceFrom(int);

 private:


   /* Recursive helper functions that will (1) find the key passed in and then 
      (2) recursively update the nodes preceding it to contain their distance from the node containing the key.
      If the key is not found, update with the distance from the end, with the last node having the value of 1.
   */
   int searchAndModify(IntNode *, int);
};



#endif