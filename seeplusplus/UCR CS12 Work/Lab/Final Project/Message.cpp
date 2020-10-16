//Message.cpp

#include "Message.h"
#include <iostream>

using namespace std;

Message::Message(){
    author = "";
    subject = "";
    body = "";
    id = 0;
}

Message::Message(const string &athr, const string &sbjct, const string &body, unsigned eyedee){
    author = athr;
    subject = sbjct;
    this->body = body;
    id = eyedee;
}

Message::~Message(){
    for(unsigned i = 0; i < childList.size(); i++){
        childList.at(i) = nullptr;
    }
}

void Message::print(unsigned ind) const{
    string space = "";
    for(unsigned i = 0; i < ind; i++){
        space += "  ";
    }
    if(ind != 0){
        cout << endl;
    }
    cout << space << "Message #" << id << ": " << subject << endl;
    cout << space << "from " << author << ": ";
    for(unsigned i = 0; i < body.size(); i++){
        cout << body.at(i);
        if(body.at(i) == '\n'){
            cout << space;
        }
    }
    cout << endl;
    if(childList.size() != 0){
        for(unsigned i = 0; i < childList.size(); i++){
            childList.at(i)->print(ind + 1);
        }
    }
}

const string & Message::getSubject() const{
    return subject;
}

unsigned Message::getID() const{
    return id;
}

void Message::addChild(Message * newMess){
    childList.push_back(newMess);
}