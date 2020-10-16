//BBoard.cpp
#include "BBoard.h"
#include <fstream>
#include <iostream>

using namespace std;

BBoard::BBoard(){
    title = "default";
    current_user = nullptr;
    user_list.clear();
    message_list.clear();
}

BBoard::BBoard(const string &boardTitle){
    title = boardTitle;
    current_user = nullptr;
    user_list.clear();
    message_list.clear();
    
}

BBoard::~BBoard(){
    for(unsigned i = 0; i < message_list.size(); i++){
        delete message_list.at(i); //should this be deleting or setting the pointers to null??
    }
    message_list.clear();
}

bool BBoard::loadUsers(const string &nameFile){
    ifstream inFS;
    string tname;
    string tpass;
    inFS.open(nameFile);
    if (!inFS.is_open()){
        return false;
    }
    else{
        inFS >> tname;
        while(tname != "end"){
            inFS >> tpass;
            User rUser = User(tname, tpass);
            user_list.push_back(rUser);
            inFS >> tname;
        }
        inFS.close();
        return true;
    }
}

bool BBoard::loadMessages(const string &datafile){
    fstream inFS;
    stringstream sstream;
    unsigned messageNum = 0;
    string templ;
    string mtype;
    vector<unsigned> children;
    int count = 0;
    unsigned cid = 0;
    string athr;
    string sbjct;
    string bdy;
    unsigned eyedee;

    inFS.open(datafile);
    if (!inFS.is_open()){
        return false;
    }
    Topic *newT = 0;
    Reply *newR = 0;
    inFS >> messageNum;
    if(messageNum != 0){
    for(unsigned x = 0; x < messageNum; x++){
            inFS >> templ;
            mtype = templ;
            athr = "";
            sbjct = "";
            bdy = "";
            eyedee = 0;

                while(templ != "<end>")
                {
                    if(templ != ":body:" && templ != ":children")
                        inFS >> templ;

                    if(templ == ":id:")
                    {
                        inFS.ignore();
                        inFS >> eyedee;
                    }
                    else
                        if(templ == ":subject:")
                        {
                            inFS.ignore();
                            getline(inFS, sbjct);
                        }
                        else
                            if(templ == ":from:")
                            {
                                inFS.ignore();
                                inFS >> athr;
                            }
                            else
                                if(templ == ":children:")
                                {
                                    inFS.ignore();

                                    while(templ != ":body:")
                                    {
                                        inFS >> templ;

                                        sstream.clear();
                                        sstream.str(templ);
                                        sstream >> cid;
                                        children.push_back(cid);
                                    }

                                }
                                else
                                    if(templ == ":body:")
                                    {
                                        inFS.ignore();
                                        getline(inFS, templ);
                                        bdy += templ;

                                        while(templ != "<end>")
                                        {
                                            getline(inFS, templ);
                                            if(templ != "<end>")
                                                bdy += "\n" + templ;
                                        }
                                    }
                }

                if(mtype == "<begin_topic>")
                    {
                        newT = new Topic(athr, sbjct, bdy, eyedee);
                        message_list.push_back(newT);
                    }
                    else
                        if(mtype == "<begin_reply>")
                        {
                            newR = new Reply(athr, sbjct, bdy, eyedee);
                            message_list.push_back(newR);
                        }

                children.push_back(0);
            }

            for(unsigned i = 0; i < children.size() - 1; i++)
            {
                if(children.at(i) != 0)
                {
                    message_list.at(count)->addChild(message_list.at(children.at(i) - 1));
                }
                else
                    if(children.at(i) == 0 && children.at(i + 1) != 0)
                    {
                        count++;
                    }
            }
        }
        return true;
}

bool BBoard::saveMessages(const string &messageSaveFile){
    ofstream outFS;
    outFS.open(messageSaveFile);
    if(!outFS.is_open()){
        return false;
    }
    else{
        outFS << message_list.size() << endl;
        for(unsigned i = 0; i < message_list.size(); i++){
            outFS << message_list.at(i)->toFormattedString();
        }
        outFS.close();
        return true;
    }
}


void BBoard::login(){
    string usaName;
    string usaPass;
    cout << "Welcome to CS12 Bulletin Board" << endl;
    while(usaName != "Q" && usaName != "q"){
        cout << "Enter your username ('Q' or 'q' to quit): ";
        cin >> usaName;
        if(usaName == "Q" || usaName == "q"){
            cout << "Bye!" << endl;
            return;
        }
        else{
            cout << "Enter your password: ";
            cin >> usaPass;
            if(usaPass == "Q" || usaPass == "q"){
                cout << "Bye!" << endl;
                return;
            }
            else{
                for(unsigned i = 0; i < user_list.size(); ++i){
                    if(user_list.at(i).check(usaName, usaPass)){
                        current_user = &user_list.at(i);
                        cout << endl << "Welcome back " << current_user->getUsername() << "!" << endl << endl;
                        return;
                    }
                }
                cout << endl << "Invalid Username or Password!" << endl << endl;
            }
        }
    }
    return;
}

void BBoard::run(){
    string resp;
    if(current_user->getUsername() != ""){
        while(resp != "q" && resp != "Q"){
            cout << endl << "Menu" << endl;
            cout << "- Display Messages ('D' or 'd')" << endl;
            cout << "- Add New Topic ('N' or 'n')" << endl;
            cout << "- Add Reply to a Topic ('R' or 'r')" << endl;
            cout << "- Quit ('Q' or 'q')" << endl;
            cout << "Choose an action: ";
            getline(cin, resp);
            if(resp == "d" || resp == "D"){
                displayB();
            }
            else if(resp == "N" || resp == "n"){
                addTopic();
            }
            else if(resp == "R" || resp == "r"){
                addReply();
            }
            else if(resp == "Q" || resp =="q"){
                cout << "Bye!" << endl;
            }
        }
    }
}

const User * BBoard::getUser(const string &name, const string &pass) const{
    for(unsigned i = 0; i < user_list.size(); i++){
        if(user_list.at(i).check(name, pass)){
            return &user_list.at(i);
        }
    }
    return nullptr;
}

void BBoard::displayB() const{
    if(message_list.size() == 0){
        cout << "Nothing to Display." << endl << endl;
    }
    else{
        for(unsigned i = 0; i < message_list.size(); ++i){
            
            if(!message_list.at(i)->isReply()){
                cout << "---------------------------------------------------------" << endl;
                message_list.at(i)->print(0);
            }
        }
        cout << "---------------------------------------------------------" << endl << endl;
    }
}

void BBoard::addTopic(){
    string sbjct;
    string bdy;
    string btemp;
    cout << "enter subject: " << endl;
    
    getline(cin, sbjct);
    cout << "enter body: " << endl;
    cin.ignore();
    getline(cin, bdy);
    getline(cin, btemp);
    while(btemp != ""){
        bdy += "\n" + btemp;
        getline(cin, btemp);
    }
    Topic *newT = new Topic(current_user->getUsername(), sbjct, bdy, message_list.size()+1);
    message_list.push_back(newT);
}

void BBoard::addReply(){
    unsigned rid;
    string sbjct;
    string bdy;
    string btemp;
    cout << "enter the ID of the message to reply to " << endl;
    cin >> rid;
    if(rid > message_list.size()){
        cout << "invalid message ID ";
    }
    while(rid > message_list.size()){
        cin >> rid;
        if(rid > message_list.size()){
            cout << "invalid message ID ";
        }
    }
    sbjct = message_list.at(rid-1)->getSubject();
    cout << "enter body: " << endl;
    cin.ignore();
    getline(cin, bdy);
    getline(cin, btemp);
    while(btemp != ""){
        bdy += "\n" + btemp;
        getline(cin, btemp);
    }
    Reply *newT = new Reply(current_user->getUsername(), sbjct, bdy, message_list.size());
    message_list.push_back(newT);
    message_list.at(rid-1)->addChild(newT);
}