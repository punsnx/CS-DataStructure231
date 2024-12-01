#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
    char name[10];
    int count;
    int found;
} Node;

void bubbleSort(short *list, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (list[j] > list[j + 1]) {
                short tmp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = tmp;
            }
        }
    }
}

int linearSearch(short query, short *data, int size, int *count) {
    for (int i = 0; i < size; i++) {
        (*count)++;
        if (data[i] == query) return 1;
    }
    return 0;
}

int sentinelSearch(short query, short *data, int size, int *count) {
    for (int i = size - 1; i >= 0; i--) {
        (*count)++;
        if (data[i] == query) return 1;
    }
    return 0;
}

int binarySearch(short query, short *data, int size, int *count) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        (*count)++;
        int mid = low + (high - low) / 2;
        if (data[mid] == query) return 1;

        if (data[mid] < query) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return 0;
}

int main() {
    short data[400000];
    int size = 0;
    Node search[3] = {{"Linear", 0, 0}, {"Sentinel", 0, 0}, {"Binary", 0, 0}};

    char line[100000];
    fgets(line, sizeof(line), stdin);

    char *token = strtok(line, " ");
    while (token != NULL) {
        data[size++] = (short)atoi(token);
        token = strtok(NULL, " ");
    }

    short query;
    scanf("%hd", &query);

    if (size == 0) return 0;

    // Linear search
    search[0].found = linearSearch(query, data, size, &search[0].count);

    // Sentinel search
    search[1].found = sentinelSearch(query, data, size, &search[1].count);

    // Binary search after sorting
    bubbleSort(data, size);
    search[2].found = binarySearch(query, data, size, &search[2].count);

    int min = 2147483647;
    int found = 0;
    for (int i = 0; i < 3; i++) {
        if (search[i].count < min) min = search[i].count;
        if (search[i].found) found = 1;
    }

    if (found) {
        for (int i = 0; i < 3; i++) {
            if (search[i].count == min) printf("%s ", search[i].name);
        }
        printf("\n%d\n", min);
    } else {
        printf("Not Found\n");
    }

    return 0;
}