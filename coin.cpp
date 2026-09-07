#include <iostream>
#include <vector>
using namespace std;

void findCombinations(const vector<int>& coins, int N, int sum,
                      int index, vector<int>& current, int& count) {
    if (sum == 0) {
        count++;
        cout << "{ ";
        for (int coin : current)
            cout << coin << " ";
        cout << "}\n";
        return;
    }

    for (int i = index; i < N; i++) {
        if (coins[i] <= sum) {
            current.push_back(coins[i]);
            
            findCombinations(coins, N, sum - coins[i], i, current, count);
            current.pop_back();
        }
    }
}

int main() {
    int N, targetSum;

    cout << "Enter the number of coin types: ";
    cin >> N;
    if ( N <= 0) {
        cout << "Invalid number of coins.\n";
        return 1;
    }

    vector<int> coins(N);
    cout << "Enter the coin values (space-separated): ";
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }

    cout << "Enter the target sum: ";
    cin >> targetSum;

    vector<int> current;
    int count = 0;

    cout << "\nPossible combinations:\n";
    findCombinations(coins, N, targetSum, 0, current, count);

    cout << "\nTotal number of ways = " << count << endl;

    return 0;
}