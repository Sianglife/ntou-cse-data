#include<map>
#include<string>
#include<iostream>
using namespace std;

int main() {
    map<string, string> mp;
    mp["HELLO"] = "ENGLISH";
    mp["HOLA"] = "SPANISH";
    mp["HALLO"] = "GERMAN";
    mp["BONJOUR"] = "FRENCH";
    mp["CIAO"] = "ITALIAN";
    mp["ZDRAVSTVUJTE"] = "RUSSIAN";

    string str;
    int n = 0;
    while(cin >> str) {
        n++;
        if(str == "#") {
            return 0;
        }

        if (mp.find(str) == mp.end()) {
            cout << "Case " << n << ": UNKNOWN" << '\n';
        } else {
            cout << "Case " << n << ": " << mp[str] << '\n';
        }
    }
}