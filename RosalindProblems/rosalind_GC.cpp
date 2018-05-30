#include <vector>
#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;


int main(){

    freopen("C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/rosalind_gc.txt","r",stdin);

    int counter=0;
    int total_L = 0;
    char L;
    double GC_cont = 0;
    double temp_GC_cont = 0;
    int rosa_id;
    int temp_rosa_id;
    int r=1;
    char rosa[4];
    char temp_rosa[4];

    while ( r ){
        //scanf("%c", &L ); // read in character
        //cout << "1st L = " << L << "\n";
        if (L == '>'){
//            cout << "total_L = " << total_L << "\n";
//            cout << "temp_GC_cont = " << temp_GC_cont << "\n";
            temp_GC_cont = 0;
            total_L = 0;

            if ( counter == 0){
                scanf("Rosalind_%4c", &rosa );
                cout << "ID = " << rosa[0] << rosa[1] <<rosa[2]<<rosa[3] <<"\n";
          //      scanf("%s",&rosa_id );
            }
            if ( counter > 0 ){
                scanf("Rosalind_%4c", &temp_rosa );
                cout << "temp ID = " << temp_rosa[0] <<temp_rosa[1]<<temp_rosa[2]<<temp_rosa[3] << "\n";
            }
            counter = counter + 1;
        }

        scanf("%c", &L );

        while ( (L != '>') ){
            //cout << "L = " << L << "\n";
            if ( (L == 'G') or (L == 'C') or (L == 'T') or (L == 'A') ){
                total_L = total_L + 1;

                if ( (L == 'G') or (L == 'C') ){
                    if ( counter == 1 ){
                        GC_cont = GC_cont + 1;
                    }
                    if ( counter > 1 ){
                        temp_GC_cont = temp_GC_cont + 1;
                    }
                }
            }
            if ( L == '>' ){
                break;
            }
            if ( scanf("%c", &L) == EOF ){
                r = 0;
                break;
            }
        }
        if ( counter == 1 ){
            GC_cont = (GC_cont/total_L) * 100;
            cout << "GC_cont = " << GC_cont << "\n";
        }
        if ( counter > 1 ){
            //cout << "Total L = " << total_L << "\n";
            temp_GC_cont = (temp_GC_cont/total_L) * 100;
  //          cout << "temp_GC_cont = " << temp_GC_cont << "\n";
            //cout << "temp_GC_cont = " << temp_GC_cont << "\n";
            //cout << "GC_cont = " << GC_cont << "\n";
            if (temp_GC_cont > GC_cont){
                GC_cont = temp_GC_cont;
                rosa[0] = temp_rosa[0];
                rosa[1] = temp_rosa[1];
                rosa[2] = temp_rosa[2];
                rosa[3] = temp_rosa[3];
            }
        }
    }
    cout << "Sequence with highest GC content = Rosalind_" << rosa[0]<<rosa[1]<<rosa[2]<<rosa[3] << "\n";
    cout << "GC Content = " << GC_cont << "\n";
    cout << "Counter = " << counter << "\n";

    ofstream output_file("C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/result_GC.txt",ios_base::app);
    output_file << "Rosalind_" << rosa[0]<<rosa[1]<<rosa[2]<<rosa[3]<<"\n";
    output_file << GC_cont;

    cout << "Done";
    return 0;
}
