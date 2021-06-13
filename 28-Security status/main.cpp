#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string str, ans = "";
    cin >> str;

    for(int i = 0; i < str.length(); i++){
        int num = count(str.begin(), str.end(), str[i]);
        
        if(isupper(str[i])){
            num += count(str.begin(), str.end(), str[i] + 32);
            ans += ((str[i] -  65) * num + 1) % 26 + 65;
        }
        
        else{
            num += count(str.begin(), str.end(), str[i] - 32);
            ans += ((str[i] -  97) * num + 1) % 26 + 97;
        }
    }

    cout << ans << endl;
}
