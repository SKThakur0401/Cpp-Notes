#include<iostream>
#include<cmath>
using namespace std;

class polynomial
{
    int maxIndex;
    int *arr;

    public:
    polynomial()
    {
        maxIndex=10;
        arr = new int[maxIndex];
        for (int i = 0; i < maxIndex; i++)
        {
            arr[i]=0;
        }
    } 

    void insert(int element, int index)         //puts the "element" on the index "index" removing the previously stored value
    {
        while(index> maxIndex)
        {
            int * newArr = new int[maxIndex*2];
            for (int i = 0; i < maxIndex; i++)
            {
                newArr[i]= arr[i];
            }
            delete [] arr;
            arr = newArr;
            maxIndex*=2;
            for (int i = (maxIndex)/2  ; i < maxIndex; i++)
            {
                arr[i]=0;
            }
            
        }
        arr[index]= element;
    }
    void print()        //Prints the polynomial expression
    {
        for (int i = 0; i < maxIndex; i++)
        {
            cout<<arr[i]<<"x^"<<i<<  "  +  ";
        }
        cout <<endl;
        cout <<endl;
    }



    void increment(int amount, int index)   //A bit different from "insert" ,, it adds amount to the existing value in that index ... USED IN POLYNOMIAL MULTIPLICATION (*) FUNCTION
    {
        while(index> maxIndex)
        {
            int * newArr = new int[maxIndex*2];
            for (int i = 0; i < maxIndex; i++)
            {
                newArr[i]= arr[i];
            }
            delete [] arr;
            arr = newArr;
            maxIndex*=2;
            for (int i = (maxIndex)/2  ; i < maxIndex; i++)
            {
                arr[i]=0;
            }
            
        }
        arr[index]+= amount;
    }


// Code for sum and difference are almost same

    polynomial operator+(polynomial const & p1)         //Code for sum of polynomial
    {
        int maxima = max(this->maxIndex, p1.maxIndex);

        polynomial p3;
        for (int i = 0; i < maxima; i++)
        {
            p3.insert(arr[i] + p1.arr[i] ,i);
        }
        return p3;
    }


    polynomial operator-(polynomial const & p1)
    {
        int maxima = max(this->maxIndex, p1.maxIndex);

        polynomial p3;
        for (int i = 0; i < maxima; i++)
        {
            p3.insert(arr[i] - p1.arr[i] ,i);
        }
        return p3;
    }


    polynomial operator*(polynomial const & p1)
    {
        polynomial p3;
        for (int i = 0; i < maxIndex; i++)
        {
            for (int j = 0; j < this->maxIndex; j++)
            {
                p3.increment(arr[i]* p1.arr[j],i+j);
            }
            
        }
        return p3;
    }


    polynomial(polynomial const & p2)       //OUR COPY CONSTRUCTOR,, FOR DEEP COPY
    {
        this->maxIndex= p2.maxIndex;
        this->arr = new int[maxIndex];
        for (int i = 0; i < maxIndex; i++)
        {
            this->arr[i]= p2.arr[i];
        }
        
    }

    void operator=(polynomial const & p2)       //DEEP COPY ASSIGNMENT OPERATOR
    {
        this->maxIndex= p2.maxIndex;
        this->arr = new int[maxIndex];
        for (int i = 0; i < maxIndex; i++)
        {
            this->arr[i]= p2.arr[i];
        }
    }
};


int main(){
    polynomial arr;
    arr.insert(4,1);
    arr.insert(21,3);
    arr.insert(11,0);
    arr.insert(4,4);
    arr.insert(111,12);
    arr.insert(99,11);


    polynomial ar;
    ar.insert(4,1);
    ar.insert(21,3);
    ar.insert(11,0);
    ar.insert(4,4);
    ar.insert(111,12);
    ar.insert(99,11);

    polynomial sumPoly= ar+arr;

    sumPoly.print();        //SO, IT IS RETURNING THE SUM OF THE ABOVE TWO POLYNOMIAL :)

    polynomial differencePoly= ar-arr;
    differencePoly.print();     //SINCE, "ar" and "arr" has all nums same , the difference shld be "0" 
                                // for all powers of "x"





    polynomial p1;
    p1.insert(1,0);
    p1.insert(1,1);
    p1.insert(1,2);

    polynomial p2;
    p2.insert(1,0);
    p2.insert(1,1);


    polynomial product = p1*p2;
    product.print();            // OUR POLYNOMIAL MULTIPLICATION FUNCTION WORKS FINE :)

    polynomial p3(p2);
    p3.print();

    p3.insert(3829,2);
    p3.print();
    p2.print();
    
    return 0;
}