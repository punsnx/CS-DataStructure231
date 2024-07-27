#include <iostream>
#include <stack>
#include <queue>
using namespace std;


int main(){
    stack<queue<string> > stackBooks;
    short n,m;
    cin >> n >> m;
    for(short i = 0;i<n;i++){
        queue<string> books;
        short k;
        cin >> k;
        for(short j = 0; j < k;j++){
            string bookName;
            cin >> bookName;
            books.push(bookName);
        }
        stackBooks.push(books);
    }
    if(m==0){
        cout << 0 << endl;
        return 0;
    }
    m = (m>n ? n : m);
    int count = 0;
    queue<string> outString;
    while(!stackBooks.empty() && m > 0){
        queue<string> *books = &stackBooks.top();
        string tmp = "";
        while(!books->empty()){
            tmp += books->front();
            books->pop();
            if(books->size() > 0)tmp +=" ";
            count++;
        }
        outString.push(tmp);
        stackBooks.pop();
        m--;
    }
    cout << count << endl;
    while(!outString.empty()){
        cout << outString.front() << endl;
        outString.pop();
    }

}