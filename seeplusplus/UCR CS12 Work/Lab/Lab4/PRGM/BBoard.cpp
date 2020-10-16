//BBoard.cpp
#include "BBoard.h"

using namespace std;

BBoard::BBoard(){
    title = "default";
    currentUser = User();
    userList.clear();
    messageList.clear();
}

BBoard::BBoard(const string &boardTitle){
    title = boardTitle;
    currentUser = User();
    userList.clear();
    messageList.clear();
    
}

bool BBoard::loadUsers(const string &nameFile){
    ifstream inFS;
    string tname;
    string tpass;
    inFS.open(nameFile);
    if (!inFS.is_open()) {
        return false;
    }
    else{
        inFS >> tname;
        while(tname != "end"){
            inFS >> tpass;
            User rUser = User(tname, tpass);
            userList.push_back(rUser);
            inFS >> tname;
        }
        inFS.close();
        return true;
    }
}


bool BBoard::login(){
    string usaName;
    string usaPass;
    cout << "Welcome to CS12 Bulletin Board" << endl;
    while(usaName != "Q" && usaName != "q"){
        cout << "Enter your username ('Q' or 'q' to quit): ";
        cin >> usaName;
        if(usaName == "Q" || usaName == "q"){
            cout << "Bye!" << endl;
            return false;
        }
        else{
            cout << endl << "Enter your password: ";
            cin >> usaPass;
            if(usaPass == "Q" || usaPass == "q"){
                cout << "Bye!" << endl;
                return false;
            }
            else{
                for(unsigned i = 0; i < userList.size(); ++i){
                    if(userList.at(i).check(usaName, usaPass)){
                        currentUser = userList.at(i);
                        cout << endl << "Welcome back " << currentUser.getUsername() << "!" << endl << endl;
                        return true;
                    }
                }
                cout << endl << "Invalid Username or Password!" << endl << endl;
            }
        }
    }
    return true;
}

void BBoard::run(){
    string resp;
    if(currentUser.getUsername() != ""){
        while(resp != "q" && resp != "Q"){
            cout << "Menu" << endl;
            cout << "- Display Messages ('D' or 'd')" << endl;
            cout << "- Add New Message ('N' or 'n')" << endl;
            cout << "- Quit ('Q' or 'q')" << endl;
            cout << "Choose an action: " << endl;
            cin >> resp;
            if(resp == "d" || resp == "D"){
                displayB();
            }
            else if(resp == "N" || resp == "n"){
                addMessage();
            }
            else if(resp == "Q" || resp =="q"){
                cout << "Bye!" << endl;
            }
        }
    }
}
void BBoard::displayB() const{
    if(messageList.size() == 0){
        cout << "Nothing to Display." << endl << endl;
    }
    else{
        for(unsigned i = 0; i < messageList.size(); ++i){
            cout << "---------------------------------------------------------" << endl;
            cout << "Message #" << i+1 << ": ";
            messageList.at(i).display();
        }
        cout << "---------------------------------------------------------" << endl << endl;
    }
}

void BBoard::addMessage(){
    string subj;
    string body1;
    cout << "Enter Subject: " << endl;
    cin.ignore();
    getline(cin, subj);
    cout << "Enter Body: " << endl;
    getline(cin, body1);
    cout << "Message Recorded!" << endl << endl;
    Message inMessage = Message(currentUser.getUsername(), subj, body1);
    messageList.push_back(inMessage);
}