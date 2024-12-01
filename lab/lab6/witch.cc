#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
typedef struct _Node{
    string name;
    string house;
}Node;

string search(vector<Node> &l,string name){
    int left = 0;
    int right = l.size() - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(l[mid].name == name){
            return l[mid].house;
        }else if (l[mid].name > name){
            left = mid + 1;
        }else {
            right = mid - 1;
        }
    }
    return "Contact not found.";
    

}
int main(){
    vector<Node> addressBook;
    // vector<string> query;

    string line,name,house;
    while(getline(cin,line)){
        if(line[0] == '-')break;
        istringstream in(line);
        getline(in,name, ' ');
        getline(in,house, ' ');
        Node witch = {name, house};
        addressBook.push_back(witch);
    }
    while(getline(cin,line)){
        // query.push_back(search(addressBook,line));
        cout << search(addressBook,line) << endl;
    }

    // for(string s : query){
    //     cout << s << endl;
    // }
    
}