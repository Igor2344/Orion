//Topic.cpp

#include "Topic.h"
#include <iostream>

using namespace std;

Topic::Topic()
:Message()
{ }

Topic::Topic(const string &athr,  const string &sbjct, const string &body, unsigned eyedee)
:Message(athr, sbjct, body, eyedee)
{ }

Topic::~Topic(){
    return;
}

bool Topic::isReply() const{
    return false;
}

string Topic::toFormattedString() const{
    ostringstream oss;
    oss << "<begin_topic>" << endl;
    oss << ":id: " << id << endl;
    oss << ":subject: " << subject << endl;
    oss << ":from: " << author << endl;
    if(childList.size() != 0){
        oss << ":children:";
        for(unsigned i = 0; i < childList.size(); i++){
            oss << " " << childList.at(i)->getID();
        }
        oss << endl;
    }
    oss << ":body: " << body << endl;
    oss << "<end>" << endl;
    return oss.str();
}