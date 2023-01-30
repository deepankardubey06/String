#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Approach - 1
//  void longestPalindrome(string str){

//     string maxi = "";

//     for(int i=0; i<str.length(); i++){
//         for(int j=0; j<str.length(); j++){
//             string s1 = str.substr(i, j + 1);
//             string s2 = s1;
//             reverse(s2.begin(), s2.end());
//             if(s1 == s2){
//                 // cout<<s1<<endl;
//                 if(s1.length() > maxi.length()){
//                     maxi = s1;
//                 }
//             }
//         }
//     }
//     cout<<maxi<<endl;
// }

void printString(int start, int end, string str)
{
    for (int i = start; i <= end; i++)
    {
        cout << str[i];
    }
    cout << endl;
}

// Approach - 2
void longestPalindrome(string str)
{
    int start = 0;
    int maxLength = 1;

    int dp[str.length()][str.length()];

    for (int i = 0; i < str.length(); i++)
    {
        dp[i][i] = 1;
    }

    for (int i = 0; i < str.length() - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            dp[i][i + 1] = 1;
            start = i;
            maxLength = 2;
        }
        else
        {
            dp[i][i + 1] = 0;
        }
    }

    for (int k = 3; k <= str.length(); k++)
    {
        for (int i = 0; i < str.length() - k + 1; i++)
        {
            int j = i + k - 1;
            if(dp[i+1][j-1] && str[i] == str[j]){
                dp[i][j] = 1;
                if(k > maxLength){
                    start = i;
                    maxLength = k;
                }
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    printString(start, start + maxLength - 1, str);
}

int main()
{
    // longestPalindrome("vnrtysfrzrmzlygfv");
    longestPalindrome("aaaabbaa");
    // aaaabbaa
    return 0;
}