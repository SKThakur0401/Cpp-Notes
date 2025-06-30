    #include<iostream>
    #include<cmath>
    #include<vector>
    #include<queue>
    #include<stack>
    using namespace std;

    template <typename T>
    class myStack{
        int nextIdx = 0;
        int capacity =5;
        T* arr;

        public:

        myStack(){
            arr = new T[capacity];
        }

        void push(T data){
            if(nextIdx == capacity){
                T* newArr = new T[capacity*2];

                for (int i = 0; i < capacity; i++){
                    newArr[i] = arr[i];
                }
                capacity*=2;
                T* oldArr = arr;
                arr= newArr;
                delete [] oldArr;
            }

            arr[nextIdx] = data;
            nextIdx++;
        }

        T pop(){
            if(nextIdx == 0) return -69;
            
            nextIdx--;
            return arr[nextIdx];
        }

        T top(){
            if(nextIdx==0) return -69;
            return arr[nextIdx-1];
        }

        int size(){
            return nextIdx;
        }
    };


    stack<int> reverse(stack<int> st, stack<int> st2){
        if(st.size() == 1) return st;

        int topEle = st.top();
        st.pop();

        st = reverse(st, st2);

        while(!st.empty()){
            st2.push(st.top()); st.pop();
        }

        st.push(topEle);

        while(!st2.empty()){
            st.push(st2.top()); st2.pop();
        }
        return st;
    }

    template <typename T>
    class myQueue{
        T* arr;
        int firstIdx=0;
        int size =0;
        int capacity=5;

        public:
        myQueue(){
            arr = new T[capacity];
        }

        void push(T data){
            if(size == capacity){
                T* newArr = new T[capacity*2];
                for(int i=0; i<capacity; i++){
                    newArr[i] = arr[(firstIdx+i)%capacity];
                }
                delete [] arr;
                arr = newArr;
                firstIdx=0;
                capacity*=2;
            }

            arr[(firstIdx+size)%capacity] = data;
            size++;
        }

        T pop(){
            if(size==0) return -1;

            size--;
            int popableIdx = firstIdx;
            firstIdx= (firstIdx+1)%capacity;
            return arr[popableIdx];
        }

        T top(){
            if(size==0) return -1;
            return arr[firstIdx];
        }

        int getSize(){return size;}
        bool isEmpty(){return size == 0;}


    };

    int main(){
    
        stack<int> st;
        st.push(1);
        st.push(3);
        st.push(5);
        st.push(7);
        // st.push(8);
        // st.push(9);
        // st.push(11);
        // st.push(13);

        // st.pop();
        // st.pop();
        // st.pop();
        // st.push(1);
        // st.push(3);
        // st.push(5);

        stack<int> st2;

        // st = reverse(st, st2);

        while(st.size()){
            cout<<st.top()<<"   "<<st.size()<<endl;
            st.pop();
        }
    }
    
