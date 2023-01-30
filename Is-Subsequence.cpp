#include <iostream>
using namespace std;

bool isSubsequence(string s, string t)
{
    int i = 0;
    int j = 0;

    while (i < s.length() && j < t.length())
    {
        if (s[i] == t[j])
        {
            i += 1;
        }
        j += 1;
    }

    return i == s.length();
}

int main()
{
    cout<<isSubsequence("aaaaaa","bbaaaa"); 
    return 0;
}