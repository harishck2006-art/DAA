#include <iostream>
#include <queue>
using namespace std;

int n, W;

struct Item {
    int weight, profit;
    float ratio;
};

struct Node {
    int level, weight, profit;
    float bound;
};

// Global item array
Item items[20];

// Function to sort items by ratio (bubble sort)
void sortItems() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

// Bound function
float bound(Node u) {
    if (u.weight >= W)
        return 0;

    float profitBound = u.profit;
    int totalWeight = u.weight;
    int i = u.level + 1;

    while (i < n && totalWeight + items[i].weight <= W) {
        totalWeight += items[i].weight;
        profitBound += items[i].profit;
        i++;
    }

    if (i < n) {
        profitBound += (W - totalWeight) * items[i].ratio;
    }

    return profitBound;
}

// Comparator for priority queue (max heap)
struct compare {
    bool operator()(Node a, Node b) {
        return a.bound < b.bound;
    }
};

int knapsack() {
    priority_queue<Node, vector<Node>, compare> pq;

    Node u, v;

    u.level = -1;
    u.weight = 0;
    u.profit = 0;
    u.bound = bound(u);

    pq.push(u);

    int maxProfit = 0;

    while (!pq.empty()) {
        u = pq.top();
        pq.pop();

        if (u.bound <= maxProfit)
            continue;

        v.level = u.level + 1;

        if (v.level >= n)
            continue;

        // Include item
        v.weight = u.weight + items[v.level].weight;
        v.profit = u.profit + items[v.level].profit;

        if (v.weight <= W && v.profit > maxProfit)
            maxProfit = v.profit;

        v.bound = bound(v);
        if (v.bound > maxProfit)
            pq.push(v);

        // Exclude item
        v.weight = u.weight;
        v.profit = u.profit;

        v.bound = bound(v);
        if (v.bound > maxProfit)
            pq.push(v);
    }

    return maxProfit;
}

int main() {
    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter weight and profit:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].profit;
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    cout << "Enter capacity: ";
    cin >> W;

    sortItems();

    int result = knapsack();

    cout << "Maximum Profit = " << result;

    return 0;
}

[24bcs170@mepcolinux Ex9]$./a.out
Enter number of items: 4
Enter weight and profit:
7 21
8 34
4 22
5 56
Enter capacity: 10
Maximum Profit = 78[24bcs170@mepcolinux Ex9]$./a.out
Enter number of items: 10
Enter weight and profit:
12 150
15 200
20 250
8  100
25 300
10 120
5  60
18 190
7  80
14 160
Enter capacity: 50
Maximum Profit = 630
