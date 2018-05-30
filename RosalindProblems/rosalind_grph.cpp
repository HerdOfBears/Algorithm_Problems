#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;


int main(){


    freopen("C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/rosalind_grph.txt", "r", stdin);
    // complication: we are not explicitly told the number of strings we must compare.
    // This makes defining an array difficult
    // So let's read through the file once, counting the number of ">".
    int N = 0;
    int r1 = 1;
    char L;
    // Count number of strings we are given.
    while(r1){
        if ( L == '>' ){
            N += 1;
        }

        if ( scanf("%c", &L) == EOF ){
            r1 = 0;
            break;
        }
    }
    cout << "N = " << N << "\n";
    // total length of all strings concatenated is 10,000
    int len_str = (10000/N)+1000; // assuming characters are uniformly distributed among the strings.
    char dna_strings[N][len_str];
    vector<int> graph[N]; // to hold adjacency lists.

    // start back at top of file
    freopen("C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/rosalind_grph.txt", "r", stdin);

    /// Read in strings.
    // One complication: we need to skip any line that begins with ">"
    //char test[101][1001] = { 'o' };
    char a;
    int counter = 0;
    int k = -1; // track number of strings
    int total_L = 0;
//    int r1;
    int r2 = 1;
    //char L;
    L = 'o'; // 'clear' L.
    cout << "check 1" << "\n";
    int dna_string_lengths[N];
    char IDs[N][4];

    while (r2){

        if (L == '>'){
            total_L = 0;
            k = k + 1;
            scanf("Rosalind_%4c",&IDs[k][0],&IDs[k][1],&IDs[k][2],&IDs[k][3]); /// This might work. Or it will fuck everything up.
        }

        scanf("%c", &L );

        while ( (L != '>') ){
            //cout << "L = " << L << "\n";
            if ( (L == 'G') or (L == 'C') or (L == 'T') or (L == 'A') ){
                dna_strings[k][total_L] = L;
                total_L = total_L + 1;
            }
            if ( L == '>' ){
                break;
            }
            if ( scanf("%c", &L) == EOF ){
                r2 = 0;
                break;
            }
        }
        dna_string_lengths[k] = total_L;

    }
    cout << "Done reading in strings" << "\n";
    cout << "k = " << k << "\n";
    cout << "dna_strings[k] = \n" << dna_strings[k] << "\n";
    cout << "length of dna_strings[k] = " << dna_string_lengths[k] << "\n";
    // Success!
    // Now
    // each dna string is the array dna_strings, and
    // each string's respective length is in dna_string_lengths.

    // complication: still need the ID for each string.
    // i.e. the "Rosalind_####" ID. We need to return a list of overlapping pairs.
    /// Check overlap
    // For each string, check whether it's suffix overlaps with
    // the prefix of any other string. Keep track of all pairs of overlap.
    cout << "ck1\n";
    int length_idx1;
    // this nest of for loops is O((n^2))
    for ( int idx1=0; idx1<N; idx1++ ){
        //cout <<"idx1 = "<<idx1 << "\n";
        for ( int idx2=0; idx2<N; idx2++){
            // Don't check for overlap with ourself.
            if ( idx2 == idx1 ){
                continue;
            }
            length_idx1 = dna_string_lengths[idx1];
            if ( (dna_strings[idx1][length_idx1-3]==dna_strings[idx2][0])
                 && (dna_strings[idx1][length_idx1-2]==dna_strings[idx2][1])
                 && (dna_strings[idx1][length_idx1-1]==dna_strings[idx2][2]) ){

                    // if the (3 letter prefix of s2)==(3 letter suffix of s1), add s2 to the adjacency list of s1.
                    graph[idx1].push_back(idx2);

            }
        }
    }

    cout << "ck2\n";
    /// Now, translate from the numbers in the adjacency list to the Rosalind_#### IDs.
    //
/*
    cout << "IDs[0] = " << IDs[0][0]<<IDs[0][1]<<IDs[0][2]<<IDs[0][3]<<"\n";
    cout << "IDs[1] = " << IDs[1][0]<<IDs[1][1]<<IDs[1][2]<<IDs[1][3]<<"\n";
    cout << "IDs[2] = " << IDs[2][0]<<IDs[2][1]<<IDs[2][2]<<IDs[2][3]<<"\n";
    cout << "IDs[3] = " << IDs[3][0]<<IDs[3][1]<<IDs[3][2]<<IDs[3][3]<<"\n";
*/
    // Get each each adjacency list length so that we don't have to within the loops
    cout <<"here?";
    ofstream output_file("C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/result_grph.txt",ios_base::app);
    int adj_idx;
    for (int idx1=0; idx1<N;idx1++){

        // using .size() w/in this loop will increase my time significantly.
        for (int idx2=0; idx2<graph[idx1].size();idx2++){
            adj_idx = graph[idx1][idx2];
            output_file << "Rosalind_" << IDs[idx1][0] <<IDs[idx1][1] <<IDs[idx1][2] <<IDs[idx1][3]<< " " << "Rosalind_"<<IDs[adj_idx][0] <<IDs[adj_idx][1] <<IDs[adj_idx][2] <<IDs[adj_idx][3]<<"\n";

        }
    }
    cout << "Done writing";
    return 0;

}
