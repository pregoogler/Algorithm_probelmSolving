#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

bool hasWord(int y, int x, string word){

}

int main(void){
    int nWord, nBoard, tmp;
    vector<string> word(nWord);
    cin >> nWord;
    for(int i = 0; i < nWord; ++i){
        cin >> word[i];
    }

//    for(int i = 0; i < nWord; ++i){
//        cout << word[i] << endl;
//    }

    cin >> nBoard;
//    cout << nBoard << endl;
    vector< vector<string> > boards(nBoard, vector<string>(4));

    for(int i = 0; i < nBoard; ++i){
        for(int j = 0; j < 4; ++j){
            cin >> boards[i][j];
        }
    }

    for(int i = 0; i < nBoard; ++i){
        for(int j = 0; j < 4; ++j){
            cout << boards[i][j] << endl;
        }
    }


}
