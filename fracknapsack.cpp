#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an item
struct Item {
    int value;  // Value of the item
    int weight; // Weight of the item
    double ratio; // Value-to-weight ratio

    Item(int v, int w) : value(v), weight(w), ratio(double(v) / w) {}
};

// Function to compare two items based on their value-to-weight ratio
bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

// Function to solve the fractional knapsack problem
double fractionalKnapsack(int capacity, vector<Item>& items) {
    // Sort items based on their value-to-weight ratio
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0; // Total value in the knapsack
    for (Item& item : items) {
        if (capacity == 0) break; // If the knapsack is full, exit the loop

        // If the item can be fully taken, take it
        if (item.weight <= capacity) {
            capacity -= item.weight;
            totalValue += item.value;
        }
        // If only a fraction of the item can be taken, take the fraction
        else {
            totalValue += item.value * (double(capacity) / item.weight);
            break; // Knapsack is full now
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;

    // Input number of items and the capacity of the knapsack
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    vector<Item> items;

    // Input value and weight of each item
    for (int i = 0; i < n; i++) {
        int value, weight;
        cout << "Enter value and weight of item " << i + 1 << ": ";
        cin >> value >> weight;
        items.push_back(Item(value, weight));
    }

    // Solve the fractional knapsack problem
    double maxValue = fractionalKnapsack(capacity, items);

    cout << "Maximum value in Knapsack: " << maxValue << endl;

    return 0;
}
