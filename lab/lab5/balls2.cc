#include <iostream>
#include <vector>
using namespace std;

typedef struct _Ball
{
    int idx;
    int w;
    int p;
} Ball;

void printList(vector<int> &list){
    for(int i = 0;i < list.size();i++){
        cout << list.at(i);
        if(i < list.size()-1)cout << " ";
        else cout << endl;
    }
}

void play(vector<Ball> &balls, vector<int> &picked, int score, int weight, int maxW, int winP, int &total, int &win, int startIndex)
{
    if (score >= winP && weight <= maxW){
        printList(picked);
        win++;
    }

    for (int i = startIndex; i < balls.size(); i++){
        picked.push_back(balls.at(i).idx);
        play(balls, picked, score + balls.at(i).p, weight + balls.at(i).w, maxW, winP, total, win, i + 1);
        picked.pop_back();
    }
    total++;
}

int main()
{
    int nBall, maxWeight, winPoint;
    cin >> nBall >> maxWeight >> winPoint;

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
    int score = 0, weight = 0, total = 0, win = 0;

    play(balls, picked, score, weight, maxWeight, winPoint, total, win, 0);
    cout << total << " " << win << endl;
    printf("%.5f\n", win / (double)total);
}