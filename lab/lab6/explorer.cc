#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

typedef struct _Node{
    string name;
    int count;
    bool found;
}Node;

void bubbleSort(vector<short> &list) {
    for(int i = 0; i < list.size() - 1; i++) {
        for(int j = 0; j < list.size() - i - 1; j++) {
            if(list[j] > list[j + 1]) {
                int tmp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = tmp;
            }
        }
    }
}

bool linearSearch(short query,vector<short> &data,int &count){
    for(int i = 0;i<data.size();i++){
        count++;
        if(data[i] == query)return true;
    }
    return false;
}
bool sentinelSearch(short query,vector<short> &data,int &count){
    for(int i = data.size()-1;i>=0;i--){
        count++;
        if(data[i] == query)return true;
    }
    return false;
}

bool binarySearch(short query,vector<short> &data,int &count){
    int low = 0;
    int high = data.size()-1;

    while(low <= high){
        count++;
        int mid = low + (high - low) / 2;
        if(data[mid] == query)return true;

        if(data[mid] < query){
            low = mid+1;
        }else{
            high = mid-1;
        }
        
    } 
    return false;
}

int main(){
    vector<short> data;
    vector<Node> search(3);
    search[0].name = "Linear";
    search[1].name = "Sentinel";
    search[2].name = "Binary";
    search[0].count = 0;
    search[1].count = 0;
    search[2].count = 0;

    string line;
    getline(cin,line);
    istringstream in(line);
    string tmp;
    while(getline(in,tmp,' ')){
        short d = stoi(tmp);
        data.push_back(d);
    }
    short query;
    cin >> query;
    if(data.size() == 0) return 0;


    //Linear
    search[0].found = linearSearch(query,data,search[0].count);
    //Sentinel
    search[1].found = sentinelSearch(query,data,search[1].count);
    //binary
    bubbleSort(data);
    search[2].found = binarySearch(query,data,search[2].count);


    int min = 2147483647;
    bool found = false;
    for(int i = 0;i<search.size();i++){
        if(search[i].count < min)min = search[i].count;
        if(search[i].found == true)found = true;
    }
    if(found){
        for(int i = 0;i<search.size();i++){
            if(search[i].count == min)cout << search[i].name << " ";
        }
        cout << endl;
        cout << min << endl;
    }else{
        cout << "Not Found" << endl;
    }

    return 0;
}