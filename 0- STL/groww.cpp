// Problem Statement


// We have an organization, where every employee report to a single manager and managers can have multiple subordinate reporting to him/her, The top most manager (ideally CEO) does not report to anyone, below is how the organization structure looks like

//           1
//        /  |  \
//      2    3   4
//     / \       
//    5   6 

// Here employees are represented as numbers. You will be given a list of pairs where in each pair, the first number represents the manager and the second number
// represents the employee reporting to him. Our goal here is to find the maximum chain length from top most manager (I.e CEO) to its bottom most employee

// { [1,2], [2,5], [2,6], [1,3], [1,4]}

// Here the organization structure looks like 

//           1
//        /  |  \
//      2    3   4
//     / \       
//    5   6 

// Now the max length is 3 (either you take path 1 -> 2 -> 5 or 1->2 -> 6

// class TreeNode
//  // data
// vector<TreeNode>

#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<set>
using namespace std;

int findCeo(set<int> st, vector<pair<int,int> > vi){

    set<int>::iterator it = st.begin();

    while(it != st.end()){
        bool isReporting = false;
        for(int i=0; i < vi.size(); i++){
            if(vi[i].second == (*it)) isReporting = true;
        }
        if(isReporting == false) return (*it);
        it++;
    }

    return -1;
}

int findLength(int reportingManager, unordered_map<int, vector<int> > & um){

    if(um[reportingManager].size() == 0) return 1;

    int len=0;

    for(int i=0; i < um[reportingManager].size(); i++){
        len =  max(len , 1 + findLength(um[reportingManager][i], um));
    }
    return len;
}


int main(){

    // { [1,2], [2,5], [2,6], [1,3], [1,4]}

    vector<pair<int,int> > vi;

    vi.push_back({1,2});        // 1 -> 2,3,4
    vi.push_back({2,5});        // 2 -> 5,6
    vi.push_back({2,6});
    vi.push_back({1,3});
    vi.push_back({1,4});
    vi.push_back({5,7});
    vi.push_back({7,14});
    vi.push_back({4,8});

    unordered_map<int, vector<int> > um;

    set<int> st;

    for(int i=0; i< vi.size(); i++){
        st.insert(vi[i].first);
        st.insert(vi[i].second);
    }

    int ceo = findCeo(st, vi);

    cout<< "CEO is - "<< ceo <<endl;

    for(int i=0; i < vi.size(); i++){
        um[vi[i].first].push_back(vi[i].second);
    }


    int ans = findLength(ceo, um);

    cout<<endl;

    cout<< ans<<endl;

    return 0;
}

