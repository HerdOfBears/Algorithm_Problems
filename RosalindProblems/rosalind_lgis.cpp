// Author: Jyler
// Date: Feb 2018
// Rosalind Problem: Longest Increasing (and Decreasing) Subsequence
// Given: n<=10,000. A permutation of length n.
// Output: Longest increasing subsequence of the permutation, followed by the longest decreasing subsequence of the permutation.


/**
NOT WORKING!!!!!!!! AHHHHHHHHH!!!!!!!!
**/


#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

/*
First idea:
Compare last two elements of a stack(?) to the new element.
If larger than last, push.
If larger than second-to-last, and smaller than last, pop(last), push(new).
Otherwise nothing.
*/

vector<int>increasing_sub[1];
vector<int>decreasing_sub[1];

struct Node{
    int a;
    int b;

    bool operator<(const Node &x )const{
        return a<x.a;
    }

    bool operator<(const &y)const{
        return a<y;
    }
};

int longest_increasing_subseq( int arr[], int strt, int N ){

    int length_v = 0;

    for (int idx = strt; idx < N; idx++){

        if ( idx == strt ){
            increasing_sub[0].push_back(arr[idx]);
            length_v += 1;
            continue;
        }
        if ( length_v == 1 ){
            if ( arr[idx] > increasing_sub[0][0] ){
                increasing_sub[0].push_back(arr[idx]);
                length_v += 1;
            }
        }

        if ( arr[idx] > increasing_sub[0][(length_v-1)] ){
            increasing_sub[0].push_back(arr[idx]);
            length_v += 1;
            continue;
        }
        if ( (arr[idx] < increasing_sub[0][(length_v-1)]) && (arr[idx] > increasing_sub[0][(length_v-2)]) ){
            increasing_sub[0].pop_back();
            increasing_sub[0].push_back(arr[idx]);
        }

    }
    cout << "length_v = " << length_v << "\n";
    if (length_v == 4){
        cout << "len 4:\n" << "increasing_sub[0] = " << increasing_sub[0][0] << " " << increasing_sub[0][1] << " " << increasing_sub[0][2] << " "<<increasing_sub[0][3] <<"\n";
        cout << "START = " << strt << "\n";
    }
    return length_v;
}

void init(){
    increasing_sub[0].clear();
    decreasing_sub[0].clear();
}

int longest_decreasing_subseq( int arr[], int strt, int N ){

    int length_vd = 0;
    for (int idx = strt; idx < N; idx++){
        //cout << "pie[idx] dec = " << pie[idx] << "\n";
        if ( idx == strt ){
            decreasing_sub[0].push_back(arr[idx]);
            length_vd += 1;
            continue;
        }
        //cout << "length_vd = " << length_vd <<"\n";
        //cout << "decreasing_sub[0][0] = " << decreasing_sub[0][0] << "\n";
        if ( length_vd == 1 ){
            if ( arr[idx] < decreasing_sub[0][0] ){
                decreasing_sub[0].push_back(arr[idx]);
                length_vd += 1;
              //  cout << "goodbye\n";
            }
        }

        if ( arr[idx] < decreasing_sub[0][(length_vd-1)] ){
            //cout << "hello?\n";
            decreasing_sub[0].push_back(arr[idx]);
            length_vd += 1;
            continue;
        }
        if ( (arr[idx] > decreasing_sub[0][(length_vd-1)]) && (arr[idx] < decreasing_sub[0][(length_vd-2)]) ){
            //cout << "pop\n";
            decreasing_sub[0].pop_back();
            decreasing_sub[0].push_back(arr[idx]);
        }
    }
    return length_vd;
}

int main(){

    int N;

    //vector<int>increasing_sub[1];
    //vector<int>decreasing_sub[1];

    freopen("C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/ex_lgis2.txt","r",stdin);
    scanf("%d", &N);
    int pie[N]; // array containing the permutation list of length N.
    int pie_rev[N];

    // read into pie

    for (int idx=0; idx<N; idx++){
        scanf("%d", &pie[idx]);
    }
    cout << "pie = " << pie << "\n";

    for (int idx=0; idx<N; idx++){
        pie_rev[(N-1-idx)] = pie[idx];
    }

/*
    Node XY[N];
    for (int idx1 = 0; idx1<N; idx1++){
        XY[idx1].a = pie[idx1];
        XY[idx1].b = idx1;
    }
    cout << "XY[0] = " << XY[0].a << " " << XY[0].b << "\n";

    sort( XY, XY + N );

    int temp_longest = 1;
    int longest_incr_subs = 0;
    int longest_decr_subs = 0;
    int longest_incr_subs_idx;
    int longest_decr_subs_idx;
    cout << "start finding" << "\n";
    // now loop through the sorted list of tuples and check the Node.b position for the longest increasing subsequence.
    for (int idx1 = 1; idx1 < N; idx1++){
        if ( XY[idx1].b > XY[idx1-1].b ){
            cout << "XY[idx1].b = " << XY[idx1].b << "\n";
            cout << "XY[idx1].a = " << XY[idx1].a << "\n";
            temp_longest += 1;
            if ( temp_longest >= longest_incr_subs ){
                longest_incr_subs = temp_longest;
                longest_incr_subs_idx = idx1-2; //
            }
        }
        temp_longest = 1; // restart counting the longest subsequence.
    }

    temp_longest = 1;
    // (N-1) is the last index, but we want to start at the penultimate index, similar to above.
    for (int idx1 = (N-2); idx1 > 0; idx1=idx1-1){
        if ( XY[idx1].b < XY[idx1+1].b ){
            temp_longest += 1;
            if ( temp_longest >= longest_decr_subs ){
                longest_decr_subs = temp_longest;
                longest_decr_subs_idx = idx1;
            }
        }
        temp_longest = 1; // restart counting the longest subsequence.
    }

    // Check longest subsequence
    cout << "longest_incr_subs = " << longest_incr_subs << "\n";
    cout << "longest incr_subs idx = " << longest_incr_subs_idx << "\n";
    for (int idx1 = longest_incr_subs_idx; idx1 < (longest_incr_subs_idx + longest_incr_subs+1); idx1++){
        cout << XY[idx1].b << " ";
    }
    cout << "\n";
*/
/*
    int length_v = 0;
    for (int idx = 0; idx < N; idx++){

        if ( idx == 0 ){
            increasing_sub[0].push_back(pie[idx]);
            length_v += 1;
            continue;
        }
        cout << "increasing_sub[0][0] = " << increasing_sub[0][0] << "\n";
        if ( length_v == 1 ){
            if ( pie[idx] > increasing_sub[0][0] ){
                increasing_sub[0].push_back(pie[idx]);
                length_v += 1;
            }
        }

        if ( pie[idx] > increasing_sub[0][(length_v-1)] ){
            increasing_sub[0].push_back(pie[idx]);
            length_v += 1;
            continue;
        }
        if ( (pie[idx] < increasing_sub[0][(length_v-1)]) && (pie[idx] > increasing_sub[0][(length_v-2)]) ){
            increasing_sub[0].pop_back();
            increasing_sub[0].push_back(pie[idx]);
        }
    }
*/
    /// Get the increasing subsequence
// the longest increasing subsequence is equal to the longest decreasing subsequence for the reverse list
    //longest_increasing_subseq( pie,0, N ); // want to compare to longest_decreasing_subseq( pie_rev, N);
    //longest_decreasing_subseq( pie_rev,0, N );

    int temp_strt = 0;
    int max_len = 0;
    int where_to_start;
    int temp_len_fwd;
    int temp_len_rev;
    int rev_or_fwd = 0; // 0 = fwd , 1 = rev

    for (int idx=0;idx<N;idx++){
        cout <<"INDEX = " << idx << "\n";
        temp_len_fwd = longest_increasing_subseq(pie, idx, N);
        temp_len_rev = longest_decreasing_subseq(pie_rev, idx, N);
        if ( temp_len_fwd > max_len ){
            max_len = temp_len_fwd;
            where_to_start = idx;
            rev_or_fwd = 1;
        }

        if ( temp_len_rev > max_len ){
            max_len = temp_len_rev;
            where_to_start = idx;
            rev_or_fwd = 0;
        }
        init();
    }
    if ( rev_or_fwd == 1){
    int abc;
    cout << "\n";
    cout << "Found longest increasing using fwd string.\n";
//    cout << "length of decreasing subsequence = " << length_vd << "\n";
    longest_increasing_subseq(pie, where_to_start, N);
    cout << "max_length incr = " << max_len << "\n";
    cout << "where to STARTTTTTT = " << where_to_start <<"\n";
    for (int idx1 = 0; idx1 < (N); idx1++){
        cout << increasing_sub[0][idx1] << " ";
    }
    cout << "\n";
    cout << "ARE YOU FUCKING DONE???????????\n";
    }

    if ( rev_or_fwd == 0){
    cout << "\n";
    cout << "Found longest increasing using reverse string.\n";
//    cout << "length of decreasing subsequence = " << length_vd << "\n";
    longest_decreasing_subseq(pie_rev, where_to_start, N);
    cout << "max_length incr = " << max_len << "\n";
    for (int idx1 = 0; idx1 < (max_len); idx1++){
        cout << decreasing_sub[0][idx1] << " ";
    }
    cout << "\n";
    }

    init();
    /// Get the decreasing subsequence
    temp_strt = 0;
    max_len = 0;
    temp_len_fwd = 0;
    temp_len_rev = 0;
    rev_or_fwd = 0; // 0 = fwd , 1 = rev

    for (int idx=0;idx<N;idx++){

        temp_len_fwd = longest_decreasing_subseq(pie, idx, N);
        temp_len_rev = longest_increasing_subseq(pie_rev, idx, N);
        if ( temp_len_fwd > max_len ){
            max_len = temp_len_fwd;
            where_to_start = idx;
            rev_or_fwd = 1;
        }
        if ( temp_len_rev > max_len ){
            max_len = temp_len_rev;
            where_to_start = idx;
            rev_or_fwd = 0;
        }
        init();
    }
    init();
    if ( rev_or_fwd == 1){
    cout << "\n";
    cout << "Found longest decreasing using fwd string.\n";
    longest_decreasing_subseq(pie, where_to_start, N);
    cout << "max_length incr = " << max_len << "\n";
    for (int idx1 = 0; idx1 < (max_len); idx1++){
        cout << decreasing_sub[0][idx1] << " ";
    }
    cout << "\n";
    }

    if ( rev_or_fwd == 0){
    cout << "\n";
    cout << "Found longest decreasing using reverse string.\n";
//    cout << "length of decreasing subsequence = " << length_vd << "\n";
    longest_increasing_subseq(pie_rev, where_to_start, N);
    cout << "max_length incr = " << max_len << "\n";
    for (int idx1 = 0; idx1 < (max_len); idx1++){
        cout << increasing_sub[0][idx1] << " ";
    }
    cout << "\n";
    }    return 0;
}

