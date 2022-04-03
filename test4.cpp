#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>


int main(void){
    int nWord, nBoard, tmp;
    vector<string> word(nWord);
    cin >> nWord;
    for(int i = 0; i < nWord; ++i){
        cin >> word[i];
    }

    for(int i = 0; i < nWord; ++i){
        cout << word[i] << endl;
    }
    sort(word.begin(), word.end());
    for(int i = 0; i < nWord; ++i){
        cout << word[i] << endl;
    }
}
