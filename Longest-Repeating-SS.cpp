#include<iostream>
#include<map>
using namespace std;

void LongestRepeatingSubsequence(string str)
{
    // Code here
    int count = 0;
    //  string ans;
    map<string, int> m;

    for (int i = 0; i < str.length(); i++)
    {
        for (int j = 0; j < str.length() - i; j++)
        {
            string s1 = str.substr(i, j + 1);
            // cout<<s1<<endl;
            if (m.find(s1) == m.end())
            {
                m[s1] = 1;
            }
            else
            {
                m[s1] += 1;
            }
        }
    }

    for (auto itr = m.begin(); itr != m.end(); itr++)
    {
        cout<<itr->first<<" "<<itr->second<<endl;
    }
}

int main(){
    LongestRepeatingSubsequence("aab"); 
    return 0;
}