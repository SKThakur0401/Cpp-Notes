/*

Question: 

Input: Given T test cases. 

For each test cases, k is given. k is the number of ingredients. 

Following k, there are k lines. Each line has 3 numbers. They represent protein, fat and carbohydrate content in the kth ingredient. 

Following these k lines, 3 lines are given. Each line has 3 numbers. They represent protein, fat and carbohydrate. For these 3 targets, we need to find out the ingredients to be added to exactly match the target. 

Output: for the 3 lines in each test case, print space separated numbers denoting the ingredients to be added to get the exact match. 
The ingredients must be printed in the sorted order. If there are many combinations, print the one which minimum number of ingredients. 

Sample input/output: 

1              //testcases 
5             // 5 ingredients 
1 2 3       //1st ingredient 
4 5 6      //2nd .. 
7 8 9 
9 18 12 
5 7 9       //5th ingredient 
5 7 9       //1st target 
11 13 15  //2nd target 
52 14 3  // 3rd target 

Expected output: 

5 
2 3 
-1 

Note: -1, when no combination(s) found
*/

#include<iostream>
#include<vector>
#include<set>
using namespace std;


void solve(vector<vector<int> > &ingredients, vector<vector<int> > &targets, vector<int> &current, vector<int> &best, int targetP, int targetF, int targetC, int sumP, int sumF, int sumC, int idx){

    if(targetP == sumP && targetF == sumF && targetC == sumC){
        if(best.empty() || current.size() < best.size()){
            best = current;
            return;
        }
    }
    if(idx == ingredients.size()) return;

//  Include current
    current.push_back(idx);
    solve(ingredients, targets, current, best, targetP, targetF, targetC, sumP+ ingredients[idx][0], sumF+ ingredients[idx][1], sumC+ ingredients[idx][2], idx+1);

//  Backtracking
    current.pop_back();

//  Not including
    solve(ingredients, targets, current, best, targetP, targetF, targetC, sumP, sumF, sumC, idx+1);
}


int main(){

    cout<< "Give input : " <<endl;
    int t; cin>>t;
    while(t--){
        int k; cin>>k;

        // for(int i=0; i<k; i++){

        //     int arr[k][3];

        //     cin>>arr[k][0];
        //     cin>>arr[k][1];
        //     cin>>arr[k][2];
        // }

        vector<int> vi(26);

        vector<vector<int> > ingredients(k, vector<int>(3));
        for(int i=0; i<k; i++){
            cin>>ingredients[i][0]>>ingredients[i][1]>>ingredients[i][2];
        }

        vector<vector<int> > targets(3, vector<int>(3));

        for(int i=0; i<3; i++){
            cin>>targets[i][0]>>targets[i][1]>> targets[i][2];
        }



        // Process output

        for (int i = 0; i < 3; i++) {
            vector<int> best, current;
            solve(ingredients, targets, current, best, targets[i][0], targets[i][1], targets[i][2], 0, 0, 0, 0);

            // Print result
            if (best.empty()) {
                cout << "-1\n";
            } else {
                for (int j = 0; j < best.size(); j++) {
                    cout << best[j]+1 << (j == best.size() - 1 ? "\n" : " ");
                }
            }
        }



        // // Process and print output
        // cout<< "OUTPUT PRINTER:" <<endl;
        // cout<< "Ingredient list:" <<endl;

        // for(auto ingredient : ingredients){
        //     cout<< ingredient[0]<<" "<<ingredient[1]<<" "<<ingredient[2]<<endl;
        // }

        // cout<< "Target list" <<endl;

        // for(auto target : targets){
        //     cout<< target[0]<<" "<<target[1]<<" "<<target[2] <<endl;
        // }
    }

    return 0;
}
