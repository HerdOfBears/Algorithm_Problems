#include <algorithm>
#include <iostream>

using namespace std;

int main(){

/*    int arr[6];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 3;
    arr[4] = 4;
    arr[5] = 5;

    cout << "lower = " << ( lower_bound(arr, arr+6, 1) - arr ) << "\n";
    cout << "upper = " << ( upper_bound(arr, arr+6, 1) - arr ) << "\n";
*/
    string s1 = "ABACEECAATFG"; // LCS = CAAT
    string s2 = "CAAT";
    int temp_N =0;
    int max_len = 0;
    for (int idx=0;idx<12;idx++){
        if ( s1[idx] == s2[temp_N] ){
            temp_N += 1;
            if ( temp_N > max_len ){
                max_len = temp_N;
                if (max_len == 4){
                    cout << "s2 is in s1!!" << "\n";
                    break;
                }
            }

            continue;
        }
        temp_N = 0;
    }

    return 0;
}
