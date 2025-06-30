// Find first set bit
// Send Feedback
// You are given an integer N. You need to return an integer M, in which only one bit is set which at position of lowest set bit of N (from right to left).
// Input Format :
// Integer N
// Output Format :
// Integer M
// Sample Input 1 :
// 7
// Sample Output 1 :
// 1
// Sample Input 2 :
// 12
// Sample Output 2 :
// 4


// SOLUTION: This is O(1) solution... (there is also a O(log(n)) solution that's kinda brute force u can do it )
// FIRST KNOW HOW TO REPRESENT "-ve numbers" into binary form.... here to find binary representation of say "-10" ... the answer is " 2's complement of 10" !!...
// Reminder: for finding 2's complement, we first find 1's complement....(ie. flipping all 0's and 1's) and to make it 2's complement...we add 1 to it...

// so for 10... binary representation = 1010 , ,, 1's complement = 0101 and 2's complement = 0110...

// so " 0110 " is the binary representation of " -10 " !!


// Now, here notice that.... in the 2's complement of a number... all bits are flipped after the first signed bit.... and before the first set bit... all bits are " 0's " in 2's complement and obviously the actual no. , 

// So before the "First set bit"... both actual and 2's complement has digits which are 0 only...

// And after the "First set bit"... both actual and 2's complement has opposite digits...

// Only the "First set bit " digit is "1" in both actual and 2's complement at the same time!!,, so if we perform "&" on the actual & 2's complement .... the only bit which will remain "1" is the "first set bit" ... !! therefore we can get the first set bit,



#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


int main(){

    int n; cin>>n;

    int c = n & (-n) ;

    cout<< c <<endl;

    return 0;
}

