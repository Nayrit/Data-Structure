#include<bits/stdc++.h>
using namespace std;
int boardSize=7;
vector<int> diceRolls ={1,2,5,4,3};
int can_win_game(){
    int currPos = 0;
    for(int i=0; i<diceRolls.size(); i++){
        if(diceRolls[i] > boardSize - currPos){
            currPos -= diceRolls[i];
            cout<<currPos<< " ";
        }
        else{
            currPos += diceRolls[i];
            cout<<currPos<< " ";
        }
        if(currPos==boardSize){
            return 1;
        }
    }
    return 0;
}
int main(){
    int result = can_win_game();    
    if(result){
        cout<<"Winn"<<endl;
    }
    else
        cout<<"lose"<<endl;

}