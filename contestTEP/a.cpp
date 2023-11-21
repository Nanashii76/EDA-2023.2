#include <bits/stdc++.h>
using namespace std;

int main() {

    string a,b;
    int suma = 0, sumb = 0;
    cin >> a >> b;

    for (int i = 0; a[i] != '\0'; ++i) {
        suma += a[i] - '0';
        sumb += b[i] - '0';
    }

    if (suma > sumb) cout << suma << "\n";
    else cout << sumb << "\n";

}