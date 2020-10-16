//Message.cpp

#include "Message.h"
#include <iostream>

using namespace std;

Message::Message(){
    author = "NoName";
    subject = "NoSubject";
    body = "NoBody";
}

Message::Message(const string &athr, const string &sbjct, const string &body){
    author = athr;
    subject = sbjct;
    this->body = body;
}

void Message::display() const{
    cout << subject << endl << "from " << author << ": " << body << endl;
}