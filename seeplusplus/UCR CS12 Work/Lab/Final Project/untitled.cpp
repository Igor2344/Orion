#include "BBoard.h"

using namespace std;
    BBoard::BBoard()
    {
      // current_user=NULL;
    }
    BBoard::BBoard(const string &ttl)
    {
       title=ttl;
       current_user = NULL;
    }
    BBoard::~BBoard( )
    {
       for( unsigned i = 0; i < message_list.size(); ++i )
       {
           if( message_list[i] )
               delete message_list[i];
       }
    }

    bool BBoard::loadMessages(const string& datafile)
    {
        fstream fileIn;
        ofstream fileOut;
        stringstream ss;

        unsigned messageNum = 0;

        string tempStr;
        string checkType;
        vector<unsigned> childIndex;
        int counter = 0;
        int toInt = 0;

        string a;
        string s;
        string b;
        string child;
        unsigned i;

        fileIn.open(datafile.c_str());

        if (!fileIn.is_open()){
            return false;
        }

        Topic *tempTop = 0;
        Reply *tempRep = 0;

        fileIn >> messageNum;

        if(messageNum != 0){

            for(unsigned x = 0; x < messageNum; x++){
                fileIn >> tempStr;
                checkType = tempStr;

                a = "";
                s = "";
                b = "";
                child = "";
                i = 0;

                while(tempStr != "<end>")
                {
                    if(tempStr != ":body:" && tempStr != ":children")
                        fileIn >> tempStr;

                    if(tempStr == ":id:")
                    {
                        fileIn.ignore(); //whitespace
                        fileIn >> i;
                    }
                    else
                        if(tempStr == ":subject:")
                        {
                            fileIn.ignore();
                            getline(fileIn, s);
                        }
                        else
                            if(tempStr == ":from:")
                            {
                                fileIn.ignore();
                                fileIn >> a;
                            }
                            else
                                if(tempStr == ":children:")
                                {
                                    fileIn.ignore();

                                    while(tempStr != ":body:")
                                    {
                                        fileIn >> tempStr;

                                        ss.clear();
                                        ss.str(tempStr);
                                        ss >> toInt;
                                        childIndex.push_back(toInt);
                                    }

                                }
                                else
                                    if(tempStr == ":body:")
                                    {
                                        fileIn.ignore();
                                        getline(fileIn, tempStr);
                                        b += tempStr;

                                        while(tempStr != "<end>")
                                        {
                                            getline(fileIn, tempStr);
                                            if(tempStr != "<end>")
                                                b += "\n" + tempStr;
                                        }
                                    }
                }

                if(checkType == "<begin_topic>")
                    {
                        tempTop = new Topic(a, s, b, i);
                        message_list.push_back(tempTop);
                    }
                    else
                        if(checkType == "<begin_reply>")
                        {
                            tempRep = new Reply(a, s, b, i);
                            message_list.push_back(tempRep);
                        }

                childIndex.push_back(0);
            }

            for(unsigned y = 0; y < childIndex.size() - 1; y++) //Store child Messages in respected childLists
            {
                if(childIndex.at(y) != 0)
                {
                    (message_list.at(counter))->addChild(message_list.at(childIndex.at(y) - 1));
                }
                else
                    if(childIndex.at(y) == 0 && childIndex.at(y + 1) != 0)
                    {
                        counter++;
                    }
            }
        }
        return true;
    }
