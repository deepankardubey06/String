#include <iostream>
#include <vector>
#include <string>
using namespace std;

int getLps(string s){
	int i = 1;
	int index = 0;
	int n = s.length();

	while(i < s.length()){
		if(s[i] == s[index]){
			++i;
			++index;
		}
		else{
			i = i - index + 1;
			index = 0;
		}
	}
	return index>n/2? index/2:index;
}

int main(){
	cout<<getLps("ababab")<<endl;
	cout<<getLps("level");
	return 0;
}