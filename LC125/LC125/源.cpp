#include<string>
using namespace std;


class Solution {
public:
	bool isPalindrome(string s) {
		int low = 0, high = s.length() - 1;
		while (low < high)
		{
			while (!isalnum(s[low])&&low<high)
			{
				low++;
			}
			while (!isalnum(s[high])&&low<high)
			{
				high--;
			}
			if (low >= high)
			{
				return true;
			}
			s[low] = tolower(s[low]);
			s[high] = tolower(s[high]);
			if (s[low] != s[high])
			{
				return false;
			}
			low++;
			high--;
		}
		return true;
	}
};