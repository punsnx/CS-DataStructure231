#include <iostream>
#include <vector>
using namespace std;

int hashFunction(int key, int tableSize) {
    return key % tableSize;
}

void insertIntoHashTable(vector<int>& hashTable, int key) {
    int tableSize = hashTable.size();
    int hashIndex = hashFunction(key, tableSize);

    while (hashTable[hashIndex] != -1) {
        hashIndex = (hashIndex + 1) % tableSize;
    }

    hashTable[hashIndex] = key;
}

int main() {
    int n;
    cin >> n;

    vector<int> input(n);
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }

    int tableSize = n;
    while (true) {
        bool isPrime = true;
        for (int i = 2; i * i <= tableSize; ++i) {
            if (tableSize % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) break;
        ++tableSize;
    }

    vector<int> hashTable(tableSize, -1);

    for (int i = 0; i < n; ++i) {
        insertIntoHashTable(hashTable, input[i]);
    }

    for (int i = 0; i < tableSize; ++i) {
        if (i > 0) cout << " ";
        if (hashTable[i] == -1) {
            cout << "-";
        } else {
            cout << hashTable[i];
        }
    }
    cout << endl;

    return 0;
}