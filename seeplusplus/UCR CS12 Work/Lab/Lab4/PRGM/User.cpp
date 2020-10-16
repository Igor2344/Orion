//User.cpp
#include "User.h"

User::User(){
    username = "";
    password = "";
}

User::User(const string &uname, const string &pass){
    username = uname;
    password = pass;
}

string User::getUsername() const{
    return username;
}

bool User::check(const string &uname, const string &pass) const{
    if((uname == username && pass == password) && (username != "" && password != "")){
        return true;
    }
    return false;
}

bool User::setPassword(const string &oldpass, const string &newpass){
    if((oldpass == password) && username != "" && password != ""){
        password = newpass;
        return true;
    }
    return false;
}