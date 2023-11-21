#include <bits/stdc++.h>
using namespace std;


int solve (int x1, int y1, int x2, int y2) {
    int slope = (y2-y1)/(x2-x1);
    return slope;
}

int main(){

    int n, i, j, a = 0;
    int arr[5] = {0};
    bool cheio = false;
    int slope = 0, slope1;

    cin >> n;

    for (int k = 0; k < n; ++k) {

        cin >> i >> j;

        if (cheio == false && i < j) {
            arr[0] = i;
            arr[1] = j;
            cheio = true;
        }    
        
        if ( cheio == true && i < j && a == 1) {
            arr[2] = i;
            arr[3] = j;
            a = 2;
        }

        if (cheio == true && a == 2) {
         
         slope1 = solve(arr[0],arr[1],arr[2],arr[3]);
         
            if (slope1 > slope) slope=slope1;

            cout << slope1 << "\n";
            cout << slope << "\n";

            a = 0;
            cheio = false;

        }

        if (cheio == true) a = 1;

    }

    cout << slope << "\n";

}