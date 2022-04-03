#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[9] = {-1, -1, -1, 0, 0, 1, 1, 1};
bool hasWord(int y, int x, const string& word, vector<string>& board){
//    /
    cout << y << " " << x << " " << word << endl;
    if(y < 0 || y > 3 || x < 0 || x > 3)
        return false;
//    cout << board[y][x] << " " << word[0] << endl;
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
    cout << hasWord(1, 2, word[2], boards[0]) << endl;
    for(int i = 0; i < nWord; ++i){
        cout << word[i] << endl;
    }
    sort(word.begin(), word.end());
    for(int i = 0; i < nWord; ++i){
        cout << word[i] << endl;
    }

    assert(0);

    vector<int> score(nBoard, 0), count(nBoard, 0);
    vector<string> longest(nBoard, "");
    for(int i = 0; i < nWord; ++i){
        for(int j = 0; j < nBoard; ++j){
            for(int k = 0; k < 4; ++k){
                for(int l = 0; l < 4; ++l){
                    if(hasWord(k, l, word[i], boards[j])){
                        cout << j << "번째 보드에서 " << word[i] << "찾음" << endl;
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




//
//int main(void){
//    vector<string> color = {"black","brown","red","orange","yellow","green","blue","violet","grey","white"};
//    vector<__int64_t> value;
//    vector<__int64_t> mul;
//    __int64_t ret;
//    for(int i = 0; i < 10; ++i){
//        value.push_back(i);
//        mul.push_back(static_cast<__int64_t>(pow(10, i)));
//    }
//
////    for(int i = 0; i < 10; ++i){
////        cout << value[i] << endl;
////        cout << mul[i] << endl;
////    }
////
//    string input1, input2, input3;
//    cin >> input1 >> input2 >> input3;
////    cout << input1 << endl << input2 << endl << input3 << endl;
//    ret = (static_cast<__int64_t>((value[distance(color.begin(), find(color.begin(), color.end(), input1))]) *10) + static_cast<__int64_t>(value[distance(color.begin(), find(color.begin(), color.end(), input2))])) *  static_cast<__int64_t>(mul[distance(color.begin(), find(color.begin(), color.end(), input3))]);
//    cout << ret << endl;
//
//}


//int main(void){
//    int w, b;
//    vector<string> word;
//
//}


//int fastMaxSum (const vector<int>& A, int lo, int hi){
//    if(lo == hi) return A[lo];
//    int mid = (lo+hi) / 2;
//
//    int left = MIN, right = MIN, sum = 0;
//    for(int i = mid; i >= lo; --i){
//        sum += A[i];
//        left = max(left, sum);
//    }
//    sum = 0;
//
//}

//void printDecimal(int a, int b){
//    int iter = 0;
//    while(a>0){
//        if(iter++ == 1) cout << '.';
//        cout << a/b;
//        a = (a%b) * 10;
//    }
//}
//
//
//int main(void){
//    printDecimal(1, 11);
//}




//int
//
//int main(){
//    int nA, nM;
//    cin >> nA;
//    vector<int> A(nA, 0);
//    for(int i = 0; i < nA; ++i) {
//        cin >> A[i];
//    }
//    cin >> nM;
//    vector<int> M(nM, 0);
//    for(int j = 0; j < nM; ++j){
//        cin >> M[j];
//    }
//
//    sort(A.begin(), A.end());
//    sort(M.begin(), M.end());
//    while(true){
//
//    }
//}

//int main(void){
//
//}
//
//vector<double> movingAverage1(const vector<double>& A, int M){
//    vector<double> ret(A.size(), 0);
//
//    for(int i = 0, i < A.size()-M, ++i){
//        for(int j = 0; j < M; ++j){
//            ret[i] += A[i+j];
//        }
//        ret[i] /= M;
//    }
//    return ret;
//}
//
//n^2
//2^12
//GHz
//11050
/*int main(void){
    int N, K, res =1;
    cin >> N >> K;
    for(int i = N; i > N-K; --i){
        res *= i;
    }
    cout << res << endl;
    for(int i = 1; i <= K; ++i){
        res /= i;
    }

    cout << res << endl;
}*/




//1259
/*int main(void){
    int input, i;
    string sinput;
    while(true){
        cin >> input;
        if (!input) break;
        sinput = to_string(input);
        for(i = 0; i < sinput.length()/2; ++i){
            if(sinput[i] != sinput[sinput.length()-i-1]){
                break;
            }
        }
        if(i == static_cast<int>(sinput.length()/2)){
            cout << "yes" <<endl;
        }
        else{
            cout << "no" << endl;
        }

    }
}*/




//2920
//
//int main() {
//    int in[8];
//    int state = 0;
//    for(int i = 0; i < 8; ++i){
//        cin >> in[i];
//    }
//
//    for(int i = 0; i < 7; ++i){
//        if(in[i] > in[i+1]){
//            state = state | 1;
//        }
//        if(in[i] < in[i+1]){
//            state = state | 2;
//        }
//    }
//    if(state == 3){
//        cout << "mixed" << endl;
//    }
//    if(state == 2){
//        cout << "ascending" << endl;
//    }
//    if(state == 1){
//        cout << "descending" << endl;
//    }
//    return 0;
//}


//2475
//int main(){
//    int in[5];
//    for(int i = 0; i < 5; ++i){
//        cin >> in[i];
//    }
//    int res = 0;
//    for(int i = 0; i < 5; ++i) {
//        res += pow(in[i], 2);
//    }
//    cout << res % 10 << endl;
//}


