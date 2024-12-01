#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;


typedef struct _Player
{
    string name;
    int hp;
    int atk;
    int defence;
    int energy;
    int maxEnergy;
    double wAtk;
    double wDef;
    int tPotion;

} Player;

int getDamage(int pAtk,double pWAtk,int oDef,double oWDef){
    int atk = pAtk*pWAtk;//floor down to int
    return (atk*atk)/(oDef*oWDef);
}

void attack(Player &p,int damage){
    p.hp -= damage;
}
int main(){
    vector<Player> p(2);
    for(int i = 0;i<p.size();i++){
        cin >> p[i].name >> p[i].hp >> p[i].atk >> p[i].defence >> p[i].maxEnergy;
        cin >> p[i].wAtk >> p[i].wDef >> p[i].tPotion;
        p[i].energy = 0;
    }

    int round = 0;
    while(p.size() > 1){
        int i = round++ % 2;
        int o = (i == 0 ? 1 : 0);
        
        bool ultimate = false;
        int mulAtk = 1;
        if(p[i].energy==p[i].maxEnergy){
            ultimate = true;
            mulAtk = 2;
        }

        double wAtk;
        double wDef;
        if(p[i].tPotion > 0){
            wAtk  = p[i].wAtk;
            wDef  = p[i].wDef;
            p[i].tPotion--;
        }else{
            wAtk  = 1;
        }
        if(p[o].tPotion > 0){
            wDef  = p[o].wDef;
            // p[o].tPotion--;
        }else{
            wDef  = 1;
        }
        
        int atk = p[i].atk * mulAtk;
        int def = p[o].defence;

        int damage = getDamage(atk,wAtk,def,wDef);
        // cout << p[i].name << "HP "<< p[i].hp << " ATK" << atk << "(" << wAtk << " " << damage << ") " << "DEF " << p[i].defence << " Engergy " << p[i].energy << "/" << p[i].maxEnergy << endl; 
        attack(p[o],damage);
        // cout << p[o].name << "HP "<< p[o].hp << " ATK " <<  p[o].atk << " DEF " << def * wDef << "(" << wDef<< ") " <<" Engergy " << p[o].energy << "/" << p[o].maxEnergy << endl; 

        if(ultimate){
            p[i].energy = 0;
            ultimate = false;
        }else{
            p[i].energy++;
        }

        if(p[o].hp <= 0)p.erase(p.begin() + o);
    }
    cout << p[0].name << " is victorious" << endl
    << "The battle took " << round << " turn(s)" << endl;
}