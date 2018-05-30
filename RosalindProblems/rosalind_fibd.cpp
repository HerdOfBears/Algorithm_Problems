#include <iostream>
#include <fstream>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;


int main(){

    freopen("C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/rosalind_fibd.txt","r",stdin);

    int months; //= 6;
    int dmonths;// = 3;
    scanf("%d %d",&months,&dmonths );
    cout << "months = " << months << " dmonths = " << dmonths << "\n";
    long double arr[dmonths] = { 0 };
    int n_cycle = 0;
    long double temp_total = 0;
    long double temp_repr = 0;
    int num_born = 0;

    // initial
    long double reproducers = 0;
    long double total = 1;

    for (int idx=0; idx < months; idx++){
        cout << "idx = " << idx << "\n";
        cout << "before growth " << "\n";
        cout << "total = " << total << " num reproducers = " << reproducers << "\n";

        if ( (idx != 0) && ((idx+1)%dmonths == 0) && (n_cycle ==0) ){
            n_cycle = 1;
        }

        arr[(idx%dmonths)] = (total - reproducers);
        //cout << "STORE = " << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
        temp_repr = reproducers;
        temp_total = total;

        reproducers = temp_total;
        total = total + temp_repr;

        if (n_cycle == 1){
            total = total - arr[((idx+1)%dmonths)];
            reproducers = reproducers - arr[((idx+1)%dmonths)];
            arr[((idx+1)%dmonths)] = 0;
            //cout << "STORE af = " <<arr[0] << " " << arr[1] << " " << arr[2] << "\n";
        }

//        temp_total = total;

 //       total = total + temp_repr;
//        reproducers = temp_total;


        cout << "after growth " << "\n";
        cout << "total = " << total << " num reproducers = " << reproducers << "\n\n";



    }
    setprecision(21);
    cout << "total_temp = "<<setprecision(21) << temp_total << " num reproducers_temp = " << temp_repr << "\n";
    cout << "total = " << total << " num reproducers = " << reproducers << "\n";

    return 0;
}
