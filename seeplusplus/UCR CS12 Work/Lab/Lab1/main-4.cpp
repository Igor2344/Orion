#include <iostream>
#include <vector>
// FIXME include vector library
using namespace std;

// parameter order will always be jersey #s then ratings

 void outputRoster(const vector<int> &jersey, const vector<int> &rating){
      int playerNum = 1;
      cout << "ROSTER" << endl;
      for (unsigned i = 0; i < jersey.size(); i++) {
         cout << "Player " << playerNum << " -- Jersey number: " << jersey.at(i) << ", Rating: " << rating.at(i) << endl;
         playerNum++;
      }
      cout << endl;
   }
   
   void addPlayer(vector<int> &jersey, vector<int> &rating) {
      int number;
      int rating2;
      
      cout << "Enter another player's jersey number:" << endl;
      cin >> number;
      jersey.push_back(number);
      cout << "Enter another player's rating:" << endl;
      cin >> rating2;
      rating.push_back(rating2);
   }
   
   void removePlayer(vector<int> &jersey, vector<int> &rating) {
       unsigned indexToRemove = jersey.size();
       int jerseyNumber;
       
       cout << "Enter a jersey number:" << endl;
       cin >> jerseyNumber;
       
       for (unsigned i = 0; i < jersey.size(); ++i) {
          if (jersey.at(i) == jerseyNumber) {
             indexToRemove = i;
          }
       } 
       
       if (indexToRemove < jersey.size()) {
       for (unsigned i = indexToRemove; i < jersey.size() - 1; ++i) {
          jersey.at(i) = jersey.at(i + 1);
          rating.at(i) = rating.at(i + 1);
       }
       
       jersey.pop_back();
       rating.pop_back();
   }
   
   }
   
   void updatePlayerRating(const vector<int> &jersey, vector<int> &rating){
      int updateNum;
      int newRating;
      
      cout << "Enter a jersey number:" << endl;
      cin >> updateNum;
       
      for (unsigned int i = 0; i < jersey.size(); i++) {
         if (jersey.at(i) == updateNum) {
            cout << "Enter a new rating for player:" << endl;
            cin >> newRating;
            rating.at(i) = newRating;
         }
      }
   }
            
   void outputPlayersAboveRating(const vector<int> &jersey, const vector<int> &rating) {
   int min;
   int player = 1;
   
   cout << "Enter a rating:" << endl;
   cin >> min;
   
   cout << "ABOVE " << min << endl;
   
   for (unsigned i = 0; i < jersey.size(); i++) {
      if (rating.at(i) > min) {
         cout << "Player " << player << " -- Jersey number: " << jersey.at(i) << ", Rating: " << rating.at(i) << endl;
      }
      player++;
   }
   cout << endl;
   }
      
   

int main() {
   
   vector<int>jersey(5);
   vector<int>rating(5);
   int playerNum = 1;
   char menu;

   int jerseyNum = 0;
   int Rating = 0;
      for (unsigned i = 0; i < jersey.size(); i++) {
         cout << "Enter player " << playerNum << "'s jersey number:" << endl;
         cin >>jerseyNum;
         jersey.at(i) = jerseyNum;
         cout << "Enter player " << playerNum << "'s rating:" << endl;
         cin >> Rating;
         rating.at(i) = Rating;
         cout << endl;
         playerNum++;
      }
      
      outputRoster(jersey, rating);
      
         cout << "MENU" << endl;
         cout << "a - Add player" << endl;
         cout << "d - Remove player" << endl;
         cout << "u - Update player rating" << endl;
         cout << "r - Output players above a rating" << endl;
         cout << "o - Output roster" << endl;
         cout << "q - Quit" << endl;
         cout << endl;
         cout << "Choose an option:" << endl;
      
      cin >> menu;
      
      while (menu != 'q') {
      if (menu == 'o') {
         outputRoster(jersey, rating);
      }
      else if (menu == 'a') {
         addPlayer(jersey, rating);
         cout << endl;
         
      }
      else if (menu == 'd') {
         removePlayer(jersey, rating);
      }
      else if (menu == 'u') {
         updatePlayerRating(jersey, rating);
      }
      else if (menu == 'r') {
         outputPlayersAboveRating(jersey,rating);
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
         cin >> menu;
   }
   
      
   return 0;
}
  