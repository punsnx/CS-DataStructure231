#include <iostream>
#include <string>
using namespace std;

int getDataTypeSize(const string& dataType) {
    if (dataType == "char") return 1;
    if (dataType == "short") return 2;
    if (dataType == "int") return 4;
    if (dataType == "long") return 8;
    if (dataType == "double") return 8;
    if (dataType == "float") return 4;
    return -1;
}

int main() {
    string dataType;
    int startAddress;
    int arraySize[3];
    int accessPosition[3];

    cin >> dataType;
    cin >> startAddress;
    cin >> arraySize[0] >> arraySize[1] >> arraySize[2];
    cin >> accessPosition[0] >> accessPosition[1] >> accessPosition[2];

    int typeSize = getDataTypeSize(dataType);
    if (typeSize == -1) {
        cout << "Invalid Type" << endl;
        return 0;
    }

    if (arraySize[0] <= 0 || arraySize[1] <= 0 || arraySize[2] <= 0 || 
        arraySize[0] > 500 || arraySize[1] > 500 || arraySize[2] > 500) {
        cout << "Invalid Argument" << endl;
        return 0;
    }

    long long totalSize = static_cast<long long>(arraySize[0]) * arraySize[1] * arraySize[2] * typeSize;

    if (accessPosition[0] < 0 || accessPosition[1] < 0 || accessPosition[2] < 0 || 
        accessPosition[0] >= arraySize[0] || accessPosition[1] >= arraySize[1] || accessPosition[2] >= arraySize[2]) {
        cout << "Segmentation Fault" << endl;
        return 0;
    }

    int offset = (accessPosition[0] * arraySize[1] * arraySize[2] +
                  accessPosition[1] * arraySize[2] +
                  accessPosition[2]) * typeSize;

    int accessAddress = startAddress + offset;

    cout << totalSize << " B, Accessing Address " << accessAddress << endl;

    return 0;
}