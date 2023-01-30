#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

// void countRev(string s, int index, string neww){
//     if(index >= s.length()){
//         if(balancedParenthensies(neww) == true){
//             cout<<neww<<endl;
//         }
//         return;
//     }
//     if(s[index] == '}'){
//         string s1 = neww;
//         s1[index] = '{';
//         countRev(s, index + 1, s1);
//     }
//     else{
//         string s1 = neww;
//         s1[index] = '}';
//         countRev(s, index + 1, s1);
//     }
//     countRev(s, index + 1, neww);
// }

int countRev(string s)
{
    if (s.length() % 2 == 1)
    {
        return -1;
    }
    int open = 0, close = 0, rev = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{')
        {
            open += 1;
        }
        else
        {
            if (open == 0)
            {
                close += 1;
            }
            else
            {
                open -= 1;
            }
        }
    }
    rev = (int)(ceil(open / 2.0) + ceil(close / 2.0));
    return rev;
}

int main(){
    cout<< countRev("}{{}}{{{");
    return 0;
}