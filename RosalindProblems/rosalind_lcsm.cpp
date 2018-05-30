// author: Jyler
// Date: Feb 2018
// Rosalind Problem: Finding a Shared Motif.
// Description: find longest common substring.
// k<=100 strings, each length <=1000 characters.

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct Node{
    int a;
    int b;
    int len;

    bool operator<(const Node &x )const{
        return a<x.a;
    }

    bool operator<(const &y)const{
        return a<y;
    }

};

int recode_char( char Z ){

    if ( Z == 'A' ){
        return 1;
    }
    if ( Z == 'T' ){
        return 2;
    }
    if ( Z == 'C' ){
        return 3;
    }
    if ( Z == 'G' ){
        return 4;
    }
    return -1;
}

// complexity = O(n)
// Gets the length of the string
int length_str( char temp[] ){
    // i --> for switching between counting rows and columns..
    int n = 0;
    //cout << "in functn: " << temp << "\n";

    // The strings are made from a 4 letter alphabet, {"A","T","C","G"}
    while ( (temp[n] == 'A') or (temp[n] == 'C') or (temp[n] == 'T') or (temp[n] == 'G') ){
       n += 1;
    }

    return n;
}

int length_str_rows( char temp[][1001] ){

    int n = 0;
    //cout << "temp[] = " << temp[0][0];
    // The strings are made from a 4 letter alphabet, {"A","T","C","G"}
    while ( (temp[n][0] == 'A') or (temp[n][0] == 'C') or (temp[n][0] == 'T') or (temp[n][0] == 'G') ){
       n += 1;
    }

    return n;
}

int main(){

    freopen("C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/rosalind_lcsm.txt", "r", stdin);

    /// Read in strings.
    // One complication: we need to skip any line that begins with ">"
    char test[101][1001] = { 'o' };
    char a;
    int counter = 0;
    int k = -1; // track number of strings
    int total_L = 0;
    int rl = 1;
    char L;
    cout << "check 1" << "\n";

    while (rl){

        if (L == '>'){
            total_L = 0;
            k = k + 1;
        }

        scanf("%c", &L );

        while ( (L != '>') ){
            //cout << "L = " << L << "\n";
            if ( (L == 'G') or (L == 'C') or (L == 'T') or (L == 'A') ){
                test[k][total_L] = L;
                total_L = total_L + 1;
            }
            if ( L == '>' ){
                break;
            }
            if ( scanf("%c", &L) == EOF ){
                rl = 0;
                break;
            }
        }

    }
    cout << "Done reading in strings" << "\n";
    cout << "k = " << k << "\n";
    cout << "test[k] = \n" << test[k] << "\n";

    // How large a collection of strings are we dealing with here?
    int number_strings;
    number_strings = length_str_rows(test);
    cout<< "number strins = " << number_strings << "\n";
    /// Store the lengths because they are constantly needed
    // Getting them again and again becomes a waste of time (especially when each string is at most 1000 chars)
    int str_lengths[101] = { 0 };
    for (int idx1 = 0; idx1 < number_strings; idx1++){
        str_lengths[idx1] = length_str(test[idx1]);
    }

    /// Search for longest common substring (LCS).
    // Everything is sorted, and indices are paired with (recoded) letters.
    // Now, search through.
    // The length of the LCS is constrained by the length of the shortest string.
    // So, let's use the shortest string as our 'reference' to find the LCS.
    // Then compare all of the others to the reference.

    // Find shortest str.
    int shortest_str_len = 2000;
    int shortest_str_idx;
    for (int idx1 = 0; idx1 < number_strings; idx1 ++){
        if ( str_lengths[idx1] < shortest_str_len ){
            shortest_str_len = str_lengths[idx1];
            shortest_str_idx = idx1;
        }
    }
    //cout << "len of test[0] = " << str_lengths[56] << "\n";
    cout << "len shortest = " << shortest_str_len << "\n";
    string shortest_str = test[shortest_str_idx];
    cout << "number of strings = " << number_strings << "\n";
    // The current LCS is defined in terms of a start index in the shortest string and a length.
    // Now we need to check this LCS against all of the other strings in the collection.
    // If it is all of the strings, then it is the LCS.
    // If not, then we have to return the two smallest strings, and find a different common substring (one character smaller than before).

    /// Basic idea:
    // choose s1 O(n)
    // choose k-th string O(n)
    // iterate k-th string to see if s1 is a substring of it. O(n)
    // Time complexity at most O(n^3)

    // Get starting position, which defines the substring, t, we are looking for in the others.
    int LCS_pos;
    int len_LCS = 0;
    int how_many_times;

    for (int idx1=0; idx1 < (shortest_str_len); idx1++){
        cout << "idx1 = " << idx1 << "\n";

        int r; // r is used to return whether t is a substring of sk.
        int temp_len_LCS = 20000;
        how_many_times = 0;

        // Get the k-th string, sk, we want to check if t is in sk.
        for (int idx2=0; idx2 < number_strings; idx2++){
            r = 0;
            // Don't compare the shortest string to itself.
            if ( (idx2 == shortest_str_idx) ){
                continue;
            }

            int temp_N = 0;
            int max_length = 0;

            // check if string t is a substring of sk. In O(n) time complexity!
            for (int idx3=0; idx3 < str_lengths[idx2]; idx3++){
                if ( test[idx2][idx3] == shortest_str[idx1 + temp_N] ){
                    if ( temp_N > max_length ){
                        max_length = temp_N;
                    }

                    temp_N += 1;
                    continue;
                }
                temp_N = 0;
            }

            // max_length is a property of substring 't' vs. a specific string 'sk'. It is the maximum length of equal characters.
            // temp_len_LCS tries to find the smallest max_length between the k strings. It is the minimum max_length

            /*
            Originally I thought this conditional was necessary.
            But it isn't.
            As of 2018/02/26, I do not know why this isn't req'd.
            My original thought:
            this conditional would find the shortest, maximum common subtring between k strings
            given a string 't'.
            But that ends up being incorrect, and we need only to redefine temp_len_LCS as max_length????
            */
            if ( max_length < temp_len_LCS ){
                temp_len_LCS = max_length;
            }


            /*
            // Deprecated?
            if ( r == 1 ){
                cout << "chk44\n";
                how_many_times += 1;
            }
            */

            // the longest common substring of each sk, is the
            // longest length of string t present in all of them.

            temp_len_LCS = max_length; // THIS LINE IS NECESSARY. BUT WHY?

        }

        // Now we want to maximize over all possible strings t in the strings sk.
        if ( temp_len_LCS > len_LCS ){
            len_LCS = temp_len_LCS;
            LCS_pos = idx1;
        }

    }

    ofstream output_file("C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/result_lcsm.txt",ios_base::app);
    cout << "LCS = ";
    cout << "len_LCS = " << len_LCS << "\n";
    for (int idx = LCS_pos; idx < (LCS_pos + len_LCS+1); idx++){
        //output_file << shortest_str[idx];
        cout << shortest_str[idx] << " ";
    }
    cout << "\nDone" << "\n";


    return 0;
}
