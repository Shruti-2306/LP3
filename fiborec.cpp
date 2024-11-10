#include <iostream>
using namespace std;

auto fibonacciRecursive(int n) -> int {
    // Time Complexity: O(2^n)
    // The function makes two recursive calls for each non-base case, leading to exponential growth in the number of calls.

    if (n <= 1)  // Base case: O(1) check
        return n;

    // Recursive calls:
    // fibonacciRecursive(n - 1) and fibonacciRecursive(n - 2)
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);  // Each call performs two sub-calls
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // Output: O(1)
    cout << "Fibonacci (Recursive) of " << n << " is: " << fibonacciRecursive(n) << endl;
    return 0;
}
