#include "Reply.h"
#include <iostream>

Reply::Reply()
:Message()
{ }

Reply::Reply(const string &athr, 
      const string &sbjct, 
      const string &bdy, 
      unsigned eyedee)
:Message(athr, sbjct, bdy, eyedee)
{ }

Reply::~Reply(){
    return;
}

bool Reply::isReply() const{
    return true;
}

string Reply::toFormattedString() const{
    ostringstream oss;
    oss << "<begin_reply>" << endl;
    oss << ":id: " << id << endl;
    oss << ":subject: " << getSubject() << endl;
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