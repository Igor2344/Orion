#include <iostream>

using namespace std;

bool validCard(int cardNumber)
{
	int rev = cardNumber;
	int sum1 = 0;
	int sum2 = 0;
	int temp = 0;
	bool truf = true;

	while (rev > 0) // rev = 1 rev%10 = 1
	{
		if (truf) 
		{
			sum1 += rev % 10;
		}
		else 
		{
			if ((rev % 10) * 2 > 9) 
			{
				temp = (rev % 10) * 2; // 14%10 == 4
				sum2 += temp / 10; // 14/10 == 1
				temp = temp % 10; // temp = 4
				sum2 += temp;
			}
			else 
			{
				sum2 += (rev % 10) * 2;
			}
		}
		truf = !truf;
		rev = rev / 10;
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
	if (validCard(499273986))
	{
		cout << "499273986 passes the test";
	}
	else {
		cout << "499273986 does not pass the test";
	}
	if (validCard(499287456335339716))
	{
		cout << "499287456335339716 passes the test";
	}
	else {
		cout << "499287456335339716 does not pass the test";
	}
}