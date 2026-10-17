#include<iostream>
#include<string>
using namespace std;
int main(){
    string s="mynameisshubham";
    cout<<s;
    int left=0;
    int right=s.size()-1;
    while(left<right){
        swap(s[left],s[right]);
        left++;
        right--;
    }
    cout<<s;
}