// 1. We will focus on number of unit operations and not time directly.

// 2. Focus only on highest power.... and not on lower power terms..(bcoz we are         assuming the worst case here, for calculation of time complexity so lower powers won't be able to make noticable change because "n" will be very large)

// 3. We don't care about the coefficient much.




// This notation is called "big - O" notation.
// time complexity is usually of the order , O(log n) , O(n), O(n*(log n) ) , O(n^2) , O(n^3) , O(2^n)
// I wrote some example "orders of time complexity" in increasing order of their complexity.

// A program with time complexity O(log n)  is much better than one with O(n) ,,, bcoz e.g. , for a program with "1024" inputs, O(n) program will have to perform "1024" operations , whereas O(log n) will perform "10" operations only. so it is exponentially better than n......in our example case, 100 times :)


// O(log n) ----> binary search
// O(n) ----> Linear search, Factorial function
// O(n*(logn)) ----> Merge sort
// O(n^2) ----> Selection sort, Insertion sort
// O(2^n) ----> Fibonacci series    (A horrifying time complexity!!! Even finding the 50th term in a fibonacci series is impossible)


// So, merge sort is better than selection and insertion sort, so to get the minimum time complexity, we will like to use merge sort :)

// Note : Instead of using Linear search(O(n^2)), in many cases I'd like to use (Merge sort + Binary search) ==> O(n*(logn) + logn) ==> O(n*(logn)) .... which is better than O(n^2) from Linear search

