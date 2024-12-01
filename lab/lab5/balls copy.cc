#include <iostream>
#include <vector>
using namespace std;

typedef struct _Ball
{
    int idx;
    int w;
    int p;
}Ball;



void printList(vector<int> &list){
    for(int i = 0;i < list.size();i++){
        cout << list.at(i);
        if(i < list.size()-1)cout << " ";
        else cout << endl;
    }
}
void printList(vector<Ball> &list){
    for(int i = 0;i < list.size();i++){
        cout << list.at(i).w;
        if(i < list.size()-1)cout << " ";
        else cout << endl;
    }
    for(int i = 0;i < list.size();i++){
        cout << list.at(i).p;
        if(i < list.size()-1)cout << " ";
        else cout << endl;
    }
}

bool inList(vector<vector<int> > &list,vector<int> &picked){
    if(picked.size() == 0)return false;
    int size;
    for(int i = 0;i<list.size();i++){
        vector<int> &p = list.at(i);
        size = picked.size();
        if(p.size() == picked.size()){
            for(int j = 0;j<p.size();j++){
                for(int k = 0;k<picked.size();k++){
                    if(p.at(j) == picked.at(k)){
                        size--;
                    }
                }
            }
        }
        if(size <= 0)return true;
    }
    if(size > 0)return false;
    else return true;
}
void play(vector<vector<int> > &tryList,vector<vector<int> > &winList,vector<int> picked,vector<Ball> balls,int score,int weight,int &maxW,int &winP,int &total,int &win){
    if(weight > maxW)return;
    if(score >= winP){
        if(!inList(winList,picked)){
            printList(picked);
            winList.push_back(picked);
            tryList.push_back(picked);
            // cout << " : " << score << " " << weight << endl;
        }
        win++;
        return;
    }
    if(balls.size()==0)return;

    int curScore = score;
    int curWeight = weight;
    vector<int> curPicked = picked;
    vector<Ball> curBalls = balls;
    for(int i = 0;i<balls.size();i++){
        score = curScore;
        weight = curWeight;
        picked = curPicked;

        score += balls.at(i).p;
        weight += balls.at(i).w;
        picked.push_back(balls.at(i).idx);
        balls.erase(balls.begin()+i);
        play(tryList,winList,picked,balls,score,weight,maxW,winP,total,win);
        balls = curBalls;
    }
    total++;
    if(!inList(tryList,picked)){
        tryList.push_back(picked);
    }

}

int main(){
    int nBall,maxWeight,winPoint;
    cin >> nBall >> maxWeight >> winPoint;

    vector<Ball> balls;

    for(int i = 0;i<nBall;i++){
        Ball ball;
        cin >> ball.w;
        ball.idx = i;
        balls.push_back(ball);
    }
    for(int i = 0;i<nBall;i++){
        cin >> balls.at(i).p;
    }

    vector<int> picked;
    int score = 0,weight = 0,total = 0,win = 0;
    vector<vector<int> > winList,tryList;
    // cout << nBall << endl;
    // cout << maxWeight << endl;
    // cout << winPoint << endl;
    // printList(balls);
    // printList(weights);
    // printList(points);
    play(tryList,winList,picked,balls,score,weight,maxWeight,winPoint,total,win);
    cout << tryList.size() << " " << winList.size() << endl;
    cout << winList.size()/(double)tryList.size();




}