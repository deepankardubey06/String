#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

void validShuffle(string s1, string s2, string goal){
    map<char, int> m;
    for(int i = 0; i < s1.length(); i++){
        if(m.find(s1[i]) == m.end()){
            m[s1[i]] = 1;
        }
        else{
            m[s1[i]] += 1;
        }
    }
    for (int i = 0; i < s2.length(); i++)
    {
        if (m.find(s2[i]) == m.end())
        {
            m[s2[i]] = 1;
        }
        else
        {
            m[s2[i]] += 1;
        }
    }
    string ans = "Yes";
    for(int i=0; i<goal.length(); i++){
        if(m.find(goal[i]) == m.end()){
            ans = "No";
            break;
        }
        else{
            m[goal[i]] -= 1;
            if(m[goal[i]] < 0){
                ans = "No";
                break;
            }
        }
    }
    cout<<ans<<endl;
}

int main(){
    validShuffle("XY", "12", "Y21XX"); 
    return 0;
}