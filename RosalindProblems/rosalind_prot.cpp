#include <iostream>
#include <fstream>

using namespace std;

int check_if_stop(string codon){
    // These are stop codons.
    // STOP recoded as 1
    // Not here? return 0
    if (codon == "UGA"){ return 1;}
    if (codon == "UAA"){ return 1;}
    if (codon == "UAG"){ return 1;}
    return 0;
}


int main(){

    char codon_to_aa[61][4];
    freopen("C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/codon_to_AA.txt","r",stdin);
    char a[3];
    char b[1];
    for (int idx=0; idx<61;idx++){
        scanf("%c%c%c %1c",&a[0],&a[1],&a[2],&b);
        cout <<"a = " << a[2]<<"\n";
        cout <<"b = " << b<<"\n";
        codon_to_aa[idx][0] = a[0];
        codon_to_aa[idx][1] = a[1];
        codon_to_aa[idx][2] = a[2];
        codon_to_aa[idx][3] = b[0];
    }
    cout << "codon_to_aa[0][0] and [0][1] = " << codon_to_aa[1][0] <<codon_to_aa[1][1] <<codon_to_aa[1][2] << " " << codon_to_aa[1][3] <<"\n";
    return 0;
}
