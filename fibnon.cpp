#include <iostream>
using namespace std;

int fibonacciIterative(int n) {
    // Time Complexity: O(n)
    // The for loop runs n-1 times, performing constant-time operations in each iteration.
    
    if (n <= 1)  // Base case: O(1) check
        return n;

    auto a = 0, b = 1;  // O(1) space for two variables
    auto fib = 1;        // O(1) space for the Fibonacci value

    // Loop runs n-2 times (from 2 to n)
    for (auto i = 2; i <= n; ++i) {  // Time Complexity: O(n)
        fib = a + b;  // Constant time operation: O(1)
        a = b;         // Constant time operation: O(1)
        b = fib;       // Constant time operation: O(1)
    }
    return fib;  // O(1) return operation
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    // Output: O(1)
    cout << "Fibonacci (Iterative) of " << n << " is: " << fibonacciIterative(n) << endl;
    return 0;
}
