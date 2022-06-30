#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <vector>
typedef long long int ll;
using namespace std;

vector<int> arr;

int count_digits(ll n)
{
    // Convert to string.
    string num = to_string(n);
    
    // Return the size of string.
    return num.size();
}

class BloomFilter{
    private: 
        ll n=1000;
        int arr[1000]={0};
        int h1(ll num){
            return num%n;
        }
        int h2(ll num){
            return (num/n)%n;
        }
        int h3(ll num){
            return (num/n*n)%n;
        }
        int h4(ll num){
            return (num/n*n*n)%n;
        }
    public:
        void add(ll num){
            arr[h1(num)]++;
            arr[h2(num)]++;
            arr[h3(num)]++;
            arr[h4(num)]++;
        }
        bool check(ll num){
            // Only if all 4 conditions are satisfied, we can say the number probably already exists.
            return arr[h1(num)] && arr[h2(num)] && arr[h3(num)] && arr[h4(num)];
        }
        void remove(ll num){
            arr[h1(num)]--;
            arr[h2(num)]--;
            arr[h3(num)]--;
            arr[h4(num)]--;
        }
};
  
int main(){
    //driver fxn
    int query;
    BloomFilter bmf;
    while(true){
        cout<<"Please enter your preferred action.\n0 - Insert Phone Number\n1 - Lookup Phone Number\n2 - Remove Phone Number\n3 - Exit"<< endl;
        cin>>query;
        if (query == 0) {
            cout<<"Please enter the number you want to insert. (12 digits)"<<endl;
            ll number;
            cin>>number;
            if(count_digits(number) == 12) {
                if(bmf.check(number)){
                    cout<<number<<" already exists in the directory."<<endl;
                }
                else{
                    bmf.add(number);
                    cout<<number<<" is inserted."<<endl;
                }
            }
            else cout<<"Please enter a valid 12 digit number."<<endl;   
        }
        else if (query == 1) {
            cout << "Please enter the number you want to look up in the directory. (12 digits)"<<endl;
            ll number;
            cin >> number;
            if (count_digits(number) == 12) {
                if(bmf.check(number)) cout<<number<<" is probably present."<<endl; // probably is used as Bloom Filter can give a False Positive result sometimes.
                else cout<<number<<" is absent."<<endl; // probably is not used as Bloom Filter never gives a False Negative result.
            }
            else cout<<"Please enter a valid 12 digit number."<<endl;
        }
        else if (query == 2) {
            cout<<"Please enter the number you want to look up in the directory. (12 digits)"<<endl;
            ll number;
            cin>>number;
            if (count_digits(number) == 12) {
                if(bmf.check(number)){
                    bmf.remove(number);
                    cout<<number<<" is removed from the directory."<<endl;
                }
                else{
                    cout<<number<<" doesn't exist in the directory."<<endl;
                }
            }
            else cout<<"Please enter a valid 12 digit number."<<endl;
        }
        else if (query == 3) {
            break;
        }
        else cout<<"Please enter a valid option."<<endl;
    }
}