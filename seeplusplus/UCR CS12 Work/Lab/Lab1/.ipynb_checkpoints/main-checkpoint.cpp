#include <iostream>
#include <vector>
using namespace std;

unsigned int i;
// parameter order will always be jersey #s then ratings
void outputRoster(const vector<int> & j, const vector<int> & r)
{
    cout << "ROSTER" << endl;
    for (i = 0; i <j.size(); ++i)
    {
        cout << "Player " << i + 1 << " -- Jersey number: " << j.at(i) << ", Rating: " << r.at(i) << endl;
    }
    cout << endl;
    
}

void addPlayer(vector<int> & j, vector<int> & r){
    int jtemp;
    int rtemp;
    cout << "Enter another player's jersey number:" << endl;
    cin >> jtemp;
    j.push_back(jtemp);
    cout << "Enter another player's rating:" << endl;
    cin >> rtemp;
    cout << endl;
    r.push_back(rtemp);
    
}
void removePlayer(vector<int> & j, vector<int> & r){
    int jtemp;
    cout << "Enter a jersey number: " << endl;
    cin >> jtemp;
    for(i = 0; i < j.size(); ++i){
        if(j.at(i) == jtemp){
            for(i = i; i < j.size()-1; ++i){
                j.at(i) = j.at(i+1);
                r.at(i) = r.at(i+1);
            }
            //j.at(i) = j.at(j.size()-1);
            //r.at(i) = r.at(r.size()-1);
            j.pop_back();
            r.pop_back();
        }
    }
}

void updatePlayerRating(const vector<int> & j, vector<int> & r){
    int jtemp;
    cout << "Enter a jersey number: " << endl;
    cin >> jtemp;
    for(i = 0; i < j.size(); ++i){
        if(j.at(i) == jtemp){
            cout << "Enter a new rating for player: " << endl;
            cin >> r.at(i);
        }
    }
}

void outputPlayersAboveRating(const vector<int> & j, const vector<int> & r){
    int rtemp;
    int count = 1;
    cout << "Enter a rating: " << endl;
    cin >> rtemp;
    cout << "ABOVE " << rtemp << endl;
    for(i = 0; i < r.size(); ++i){
        if(r.at(i) > rtemp){
            cout << "Player " << count << " -- Jersey numer: " << j.at(i) << ", Rating: " << r.at(i) << endl;
        }
        count = count + 1;
    }
}


int main() {
    
   /* Type your code here. */
    vector<int> jerseys(5);
    vector<int> ratings(5);
    char resp;
    int ccount = 1;
    
    for(i = 0; i < 5; ++i){
        cout << "Enter player " << ccount << "'s jersey number:" << endl;
        cin >> jerseys.at(i);
        cout << "Enter player " << ccount << "'s rating:" << endl;
        cin >> ratings.at(i);
        cout << endl;
        ccount = ccount + 1;
    }
    
    outputRoster(jerseys, ratings);
    
    while(resp != 'q'){
        cout << "MENU" << endl;
        cout << "a - Add player" << endl;
        cout << "d - Remove player" << endl;
        cout << "u - Update player rating" << endl;
        cout << "r - Output players above a rating" << endl;
        cout << "o - Output roster" << endl;
        cout << "q - Quit" << endl;
        cout << endl;
        cout << "Choose an option:" << endl;
        cin >> resp;
        if(resp == 'a')
        {
            addPlayer(jerseys, ratings);
        }
        else if(resp == 'd')
        {
            removePlayer(jerseys, ratings);
        }
        else if(resp == 'u')
        {
            updatePlayerRating(jerseys, ratings);
        }
        else if(resp == 'r')
        {
            outputPlayersAboveRating(jerseys, ratings);
        }
        else if(resp == 'o')
        {
            outputRoster(jerseys, ratings);
        }
        else
        {
            resp = 'q';
        }
    }
    
    
   return 0;
}