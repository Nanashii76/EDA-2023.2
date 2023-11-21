#include <bits/stdc++.h>
using namespace std;

int main(){

    long long n;
    string name;
    cin >> n;

    vector<string> names;
    vector<string> names2;

    for (long long i = 0; i < n; ++i) {
        cin >> name;

        if (name[0] == '!') {
            name.erase(remove(name.begin(),name.end(),'!'));
            names2.push_back(name);
        } else {
            names.push_back(name);
        }
    
    }

    for (long long j = 0; j < names2.size(); ++j) {
        for (long long k = 0; k < names.size(); ++k) {
            
            if (names[k] == names2[j]) {
                cout << names[k] << "\n";
                return 0;
            }

        }
    }
        
    cout << "satisfiable" << "\n";

}

