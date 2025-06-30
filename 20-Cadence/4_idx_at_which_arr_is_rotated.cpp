#include<iostream>
#include<vector>

using namespace std;

int pivot(vector<int>& vi){


    int si =0; int ei = vi.size()-1;

    while(ei >= si){
        if(si == ei) return si;
        int mid = si + (ei-si)/2;

        if(vi[mid] >= vi[si]){
            si = mid;
        }
        else {
            ei = mid;
        }
    }

    return -1;
}


int main(){

    int arr[8] = {4,5,6,7,8,1,2,3};

    vector<int> vi;
    for(int i=0; i< sizeof(arr)/4; i++){
        vi.push_back(arr[i]);
    }

    cout << pivot(vi)<<endl;

    return 0;
}
