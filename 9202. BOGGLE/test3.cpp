#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[9] = {-1, -1, -1, 0, 0, 1, 1, 1};
bool hasWord(int y, int x, const string& word, vector<string>& board){
    if(y < 0 || y > 3 || x < 0 || x > 3)
        return false;
    if(board[y][x] != word[0])
        return false;
    if(word.length() == 1)
        return true;
    for(int i = 0; i < 8; ++i){
        int nextX = x+dx[i], nextY = y+dy[i];
        if(hasWord(nextY, nextX, word.substr(1), board))
            return true;
    }
    return false;
}

int main(void){
    int nWord, nBoard, tmp;
    vector<string> word(nWord);
    cin >> nWord;
    for(int i = 0; i < nWord; ++i){
        cin >> word[i];
    }
    cin >> nBoard;
    vector< vector<string> > boards(nBoard, vector<string>(4));

    for(int i = 0; i < nBoard; ++i){
        for(int j = 0; j < 4; ++j){
            cin >> boards[i][j];
        }
    }

    sort(word.begin(), word.end());

    vector<int> score(nBoard, 0), count(nBoard, 0);
    vector<string> longest(nBoard, "");
    for(int i = 0; i < nWord; ++i){
        for(int j = 0; j < nBoard; ++j){
            for(int k = 0; k < 4; ++k){
                for(int l = 0; l < 4; ++l){
                    if(hasWord(k, l, word[i], boards[j])){
                        count[j] += 1;
                        if(word[i].length() == 1 || word[i].length() == 2)
                            score[j] += 0;
                        else if(word[i].length() == 3 || word[i].length() == 4)
                            score[j] += 1;
                        else if(word[i].length() == 5)
                            score[j] += 2;
                        else if(word[i].length() == 6)
                            score[j] += 3;
                        else if(word[i].length() == 7)
                            score[j] += 5;
                        else if(word[i].length() == 8)
                            score[j] += 11;
                        if(longest[j].length() < word[i].length())
                            longest[j] = word[i];
                    }
                }
            }
        }
    }
    for(int i = 0; i < nBoard; ++i){
        cout << score[i] << " " << longest[i] << " " << count[i] << endl;
    }
}
