#include <string>
#include <iostream>

using namespace std;

bool validCard(string cardNumber) 
{
	string rev = "";
	int sum1 = 0;
	int sum2 = 0;
	int temp = 0;
	for (unsigned i = cardNumber.size()-1; i >= 0; i--) 
	{
		rev.push_back(cardNumber.at(i));
	}
	for (unsigned j = 0; j < rev.size(); j++) 
	{
		if (j % 2 == 0) //1st index is 0 so we want even numbers to get 1, 3, 5, 7, etc...
		{
			sum1 += rev.at(j);
		}
		else 
		{
			if (rev.at(j) * 2 > 9) 
			{
				temp = rev.at(j);
				temp = temp % 10;
				sum2 += temp;
				temp = temp % 10;
				sum2 += temp;
			}
			else 
			{
				sum2 += rev.at(j);
			}
		}
	}
	if ((sum1 + sum2) % 10 == 0) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

int main() 
{
	if (validCard("49927398716")) 
	{
		cout << "499739876 passes the test";
	}
	else {
		cout << "499739876 does not pass the test";
	}
}