#include <iostream>
#include <vector>
#include <string>
using namespace std;

string getLps(string s){
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
	int maxi = 0;
	for(int i=0; i<lps.size(); i++){
		maxi = max(maxi, lps[i]);
	}
	string res = s.substr(0,maxi);
	return res;
}

int main(){
	cout<<getLps("ababab");

	for(int i=0; i<arr.size(); i++){
		cout<<arr[i]<<" ";
	}

	return 0;
}