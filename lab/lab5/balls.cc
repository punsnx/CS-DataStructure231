#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;
int nBall, maxW, winP;

typedef struct _Ball
{
    int idx;
    int w;
    int p;
} Ball;

void printList(vector<int> &list){
    for(int i = 0;i < list.size();i++){
        cout << list.at(i) << " ";
        // if(i < list.size()-1)cout << " ";
        // else cout << endl;
    }
    cout << endl;
}


void play(vector<vector<int> > &winList,vector<Ball> &balls, vector<int> &picked, int score, int weight, int &win, int startIndex)
{
    if(weight > maxW || startIndex > nBall)return;

    if (score >= winP && !picked.empty()){
        // printList(picked);
        winList.push_back(picked);
        win++;
    }

    for (int i = startIndex; i < balls.size(); i++){
        picked.push_back(balls.at(i).idx);
        play(winList,balls, picked, score + balls.at(i).p, weight + balls.at(i).w, win, i + 1);
        if(i==nBall-1){
            while(!winList.empty()){
                if(winList.back().back() == balls.at(startIndex).idx)break;
                printList(winList.back());
                winList.pop_back();
            }
        }

        picked.pop_back();
    }

}
int main()
{
    cin >> nBall >> maxW >> winP;

    vector<Ball> balls;

    for (int i = 0; i < nBall; i++)
    {
        Ball ball;
        cin >> ball.w;
        ball.idx = i;
        balls.push_back(ball);
    }
    for (int i = 0; i < nBall; i++)
    {
        cin >> balls.at(i).p;
    }

    vector<int> picked;
    vector<vector<int> > winList;
    int score = 0, weight = 0, win = 0;

    play(winList,balls, picked, score, weight, win, 0);
    // cout << pow(2, nBall) << " " << win << endl;

    cout << fixed << setprecision(5) << win/pow(2, nBall) << endl;
}