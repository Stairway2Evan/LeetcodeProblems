#include <iostream>
#include <string>

using namespace std;

class Solution {
private:

public:
	string longestPalindrome(string s) {
		if (s.length() <= 1) return s; //  Trivial case
		int maxLength = 1;
		int numChars = s.length();
		int start, end = 0;

		//  Case where palindrome length is odd (center will be a character, n possible centers)
		for (int currChar = 0; currChar < numChars; currChar++) {
			int left = currChar, right = currChar;
			while (left >= 0 && right < numChars) {
				if (s[left] == s[right]) {
					left--;
					right++;
				}
			}
			int length = right - left - 1;
			if (length > maxLength) {
				maxLength = length;
				start = left + 1;
				end = right - 1;
			}
		}

		//  Case where palindrome length is even (center will be between characters, n - 1 possible centers)
		for (int currChar = 0; currChar < numChars; currChar++) {
			int left = currChar, right = currChar + 1;
			while (left >= 0 && right < numChars) {
				if (s[left] == s[right]) {
					left--;
					right++;
				}
			}
			int length = right - left - 1;
			if (length > maxLength) {
				maxLength = length;
				start = left + 1;
				end = right - 1;
			}
		}
		
		return s.substr(start, maxLength);
	}
};

int main() {
	Solution s1;
	string myString = "abccabaccb";
	cout << s1.longestPalindrome(myString);

	return 0;
}