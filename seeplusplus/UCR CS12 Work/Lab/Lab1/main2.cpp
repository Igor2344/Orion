#include <iostream>
#include <vector>
using namespace std;

unsigned int i;
// parameter order will always be jersey #s then ratings
void outputRoster(const vector<int> &j, const vector<int> &r){
    int playerNum = 1;
    cout << "ROSTER" << endl;
    for (i = 0; i < j.size(); i++) {
        cout << "Player " << playerNum << " -- Jersey number: " << j.at(i) << ", Rating: " << r.at(i) << endl;
        playerNum++;
    }
    cout << endl;
}
   
void addPlayer(vector<int> &j, vector<int> &r) {
    int jtemp;
    int rtemp;
      
    cout << "Enter another player's jersey number:" << endl;
    cin >> jtemp;
    j.push_back(jtemp);
    cout << "Enter another player's rating:" << endl;
    cin >> rtemp;
    r.push_back(rtemp);
}
   
void removePlayer(vector<int> &j, vector<int> &r) {
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
   
void updatePlayerRating(const vector<int> &j, vector<int> &r){
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
            
void outputPlayersAboveRating(const vector<int> &j, const vector<int> &r) {
    int rtemp;
    int count = 1;
   
    cout << "Enter a rating:" << endl;
    cin >> rtemp;
   
    cout << "ABOVE " << rtemp << endl;
   
    for ( i = 0; i < j.size(); i++) {
        if (r.at(i) > rtemp) {
            cout << "Player " << count << " -- Jersey number: " << j.at(i) << ", Rating: " << r.at(i) << endl;
        }
        count = count +1;
    }
    cout << endl;
}
      
   

int main() {
   vector<int>jerseys(5);
   vector<int>ratings(5);
   char resp;
   int ccount = 1;
    
      for (i = 0; i < jerseys.size(); i++) {
         cout << "Enter player " << ccount << "'s jersey number:" << endl;
         cin >>jerseys.at(i);
         cout << "Enter player " << ccount << "'s rating:" << endl;
         cin >> ratings.at(i);
         cout << endl;
         ccount++;
      }
      
      outputRoster(jerseys, ratings);
      
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
      
      while (resp != 'q') {
          if (resp == 'o') {
             outputRoster(jerseys, ratings);
          }
          else if (resp == 'a') {
             addPlayer(jerseys, ratings);
             cout << endl;
          }
          else if (resp == 'd') {
             removePlayer(jerseys, ratings);
          }
          else if (resp == 'u') {
             updatePlayerRating(jerseys, ratings);
          }
          else if (resp == 'r') {
             outputPlayersAboveRating(jerseys, ratings);
          }
         
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
   }
   return 0;
}
  