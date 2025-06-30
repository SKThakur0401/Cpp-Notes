
#include <iostream>
#include <vector>


using namespace std;

// void merge(vector<int> &vi, int si, int mid, int ei){
    
//     vector<int> first;
//     vector<int> second;

//     for(int i=si; i <= mid; i++){
//         first.push_back(vi[i]);
//     }
    
//     for(int i=mid+1; i<= ei; i++){
//         second.push_back(vi[i]);
//     }
    
    
//     int i=0; int j=0; int k=si;
    
//     while(i < first.size() && j < second.size()){
//         if(first[i] < second[j]){
//             vi[k] = first[i];
//             k++; i++; continue;
//         }
        
//         else{
//             vi[k] = second[j];
//             k++; j++; continue;
//         }
//     }
    
//     while(i < first.size()){
//         vi[k] = first[i];
//         i++; k++;
//     }
    
//     while(j < second.size()){
//         vi[k] = second[j];
//         j++; k++;
//     }
// }

// void mergeSort(vector<int> &vi, int si, int ei){
    
//     int mid = si + (ei-si)/2;
//     if(si >= ei) return;

//     mergeSort(vi, si, mid);
//     mergeSort(vi, mid+1, ei);
//     merge(vi, si, mid, ei);
// }

int partitioner(vector<int>&vi, int si, int ei){

    int key = vi[si];
    int smallerCount = 0;

    for(int i= si+1; i<= ei; i++){
        if(vi[i] < key) smallerCount++;
    }

    int partitionIdx = si + smallerCount;

    swap(vi[partitionIdx], vi[si]);
    // return si+ smallerCount;

    int i=si; int j=ei;

    while(i < partitionIdx && j > partitionIdx){
        if(vi[i] >= key && vi[j] < key) {
            swap(vi[i], vi[j]);
            i++; j--;
        }

        else if(vi[i] < key) i++;
        else if(vi[j] > key) j--;
    }

    return partitionIdx;
}

void quickSort(vector<int>& vi, int si, int ei){


    if(si >= ei) return;
    int partition = partitioner(vi, si, ei);

    quickSort(vi, si, partition-1);
    quickSort(vi, partition+1, ei);
}


int main()
{
    vector<int> vi;

    vi.push_back(3);
    vi.push_back(3);
    vi.push_back(7);
    vi.push_back(2);
    vi.push_back(2);
    vi.push_back(5);
    vi.push_back(5);
    vi.push_back(1);
    vi.push_back(1);
    vi.push_back(4);
    vi.push_back(4);

    
    // mergeSort(vi, 0, vi.size()-1);

    quickSort(vi, 0, vi.size()-1);

    for(int i=0; i< vi.size(); i++){
        cout<<vi[i]<< "  ";
    }
    

    return 0;
}