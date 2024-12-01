#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <iomanip>

using namespace std;

int ball_amount, max_weight, min_score, total_weight = 0, total_score = 0, counts = 0;

void Test(int index, vector<pair<int, pair<int, int> > > &balls_gucci, vector<int> &balls_weight, vector<int> &balls_score)
{
    if (index > ball_amount || total_weight > max_weight)
    {
        return;
    }
    for (int i = index; i < ball_amount; i++)
    {
        balls_gucci.push_back(make_pair(i, make_pair(balls_weight[i], balls_score[i])));
        total_score += balls_score[i];
        total_weight += balls_weight[i];
        Test(i + 1, balls_gucci, balls_weight, balls_score);
        balls_gucci.pop_back();
        total_weight -= balls_weight[i];
        total_score -= balls_score[i];
    }
    if (total_score >= min_score && index > 0)
    {
        vector<pair<int, pair<int, int> > >::iterator itr;
        for (itr = balls_gucci.begin(); itr != balls_gucci.end(); itr++)
        {
            cout << itr->first << " ";
        }
        cout << endl;
        counts++;
    }
}

int main()
{
    cin >> ball_amount;
    cin >> max_weight;
    cin >> min_score;
    vector<int> balls_weight(ball_amount);
    for (int i = 0; i < ball_amount; i++)
    {
        cin >> balls_weight[i];
    }
    vector<int> balls_score(ball_amount);
    for (int i = 0; i < ball_amount; i++)
    {
        cin >> balls_score[i];
    }
    vector<pair<int, pair<int, int> > > balls_gucci;
    Test(0, balls_gucci, balls_weight, balls_score);
    cout << fixed << setprecision(5) << counts / pow(2, ball_amount) << endl;
}
