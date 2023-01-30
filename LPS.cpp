#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestPrefix(string s) {
        int i = 1;
        int index = 0;
        vector<int> lps(s.length());

        while(i < s.length()){
            if(s[i] == s[index]){
                lps[i] = index + 1;
                i++;
                index++;
            }
            else{
                if(index != 0){
                    index = lps[index - 1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        int val = lps[s.length()-1];
        return s.substr(0,val);
}

int main(){
	cout<<longestPrefix("ababab")<<endl;
	return 0;
}