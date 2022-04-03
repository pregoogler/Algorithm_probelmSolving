///*
//::: SourceCode CopyRight @ Yongil Kim
//::: Apr.2020 SNU MiLab
//::: miles94@snu.ac.kr
//*/
//#include <stdlib.h>
//#include <iostream>
//#include <ctime>
//#include <cmath>
//using namespace std;
//
//class arr {
//public:
//        arr();
//        ~arr();
//        void sort(void (*f)(int*, unsigned int));
//        void sort(void(*f)(int*, int, int));
//        void init(int n);
//        void reset();
//        void check();
//        void print();
//private:
//        int* input_array;
//        int* ref_array;
//        int size;
//};
//void swap(int& a, int& b);
//void bubble_sort_descending(int* array, unsigned int size);
//void insertion_sort_descending(int* array, unsigned int size);
//void selection_sort_descending(int* array, unsigned int size);
//
//int main(void) {
//        srand((unsigned int)time(NULL));
//
//        int size;
//        cout << "Give me the size : ";
//        cin >> size;
//
//        int type_sort;
//        cout << "Give me the type of algorithm (0: Bubble, 1: Insertion, 2: Selection): ";
//	    cin >> type_sort;
//
//
//        arr mysort;
//	    mysort.init(size);
//
//
//	    if (type_sort ==0){
//            mysort.sort(bubble_sort_descending);
//            mysort.print();
//	        mysort.reset();
//        }
//        else if (type_sort ==1){
//	        mysort.sort(insertion_sort_descending);
//            mysort.print();
//	        mysort.reset();
//        }
//        else if (type_sort ==2){
//	        mysort.sort(selection_sort_descending);
//	        mysort.print();
//	        mysort.reset();
//        }
//
//
//        return 0;
//}
//
//
//arr::arr() {}
//arr::~arr() {
//        delete[] input_array;
//        delete[] ref_array;
//}
//
//void arr::init(int size) {
//        this->size = size;
//        input_array = new int[size];
//        ref_array = new int[size];
//        for (int i = 0; i < size; i++) {
//                int rnd_num;
//                cin >> rnd_num;
//                input_array[i] = rnd_num;
//                ref_array[i] = rnd_num;
//        }
//}
//
//void arr::reset() {
//        if (ref_array == nullptr) ref_array = new int[size];
//        for (int i = 0; i < size; i++)
//                ref_array[i] = input_array[i];
//        cout << "Reset" << endl << endl;
//
//}
//
//void arr::check() {
//        bool check = true;
//        if (ref_array == nullptr)
//                cout << "Error! The array has no element." << endl;
//        else {
//                for (int i = 0; i < size - 1; i++) {
//                        if (ref_array[i] < ref_array[i + 1])
//                                check = false;
//                }
//        }
//        if (check) cout << "Correct!" << endl;
//        else cout << "Wrong!" << endl;
//}
//
//void arr::sort(void(*f)(int*, unsigned int)) {
//        f(ref_array, size);
//}
//
//void arr::sort(void(*f)(int*, int, int)) {
//        f(ref_array, 0, (int)(size - 1));
//}
//
//
//void arr::print() {
//    for (int i = 0; i < size; i++){
//       cout << ref_array[i]  ;
//       cout << " "  ;
//       }
//       cout << " "<<endl;
//}
//
//
//void swap(int& a, int& b) {
//        int tmp = a;
//        a = b;
//        b = tmp;
//}
//
//
/*###################################################################################
//##########################  Incremental Algorithm ###################################
//#####################################################################################
//*/
//
//
//void bubble_sort_descending(int* array, unsigned int size) {
//    for (unsigned int i = 0; i < size - 1; i++)
//    {
//        //#######################################################
//        //Implement here
//        for(int j = i; j < size-1; ++j) {
//            if (array[j] < array[j + 1]) {
//                swap(array[j], array[j + 1]);
//            }
//        }
//        //#######################################################
//    }
//}
//
//void insertion_sort_descending(int* array, unsigned int size) {
//	for (unsigned int i = 1; i < size; i++)
//	{
//		//#######################################################
//        //Implement here
//        int j = i-1;
//        int temp = array[i];
//        while(1){
//            if(j > 0)
//                break;
//            if(array[j] >= array[j+1])
//                break;
//            array[j+1] = array[j];
//            j--;
//
//        }
//        //#######################################################
//	}
//}
//
//void selection_sort_descending(int* array, unsigned int size) {
//	for (unsigned int i = 0; i < size - 1; i++)
//	{
//		//#######################################################
//        //Implement here
//        int max = -1000000;
//        int max_idx = -1;
//        for(int j = i+1; j < size; ++j){
//            if(array[j] > max){
//                max_idx = j;
//                max = array[j];
//            }
//        }
//        swap(array[max_idx], array[i]);
//
//        //#######################################################
//	}
//}
//
//


#include <iostream>
#include <string>
using namespace std;

char board[4][4];

int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

bool hasWord(int y, int x, string word);
int main(void){
    int stringNum;
    int boardNum;

    cin >> stringNum;
    string * strings = new string[stringNum];
    for(int i = 0; i < stringNum; ++i){
        cin >> strings[i];
    }
    cin >> boardNum;
    int * maxPoint = new int[boardNum];
    string * longest = new string[boardNum];
    int * foundCount = new int[boardNum];
    for(int bNum = 0; bNum < boardNum; ++bNum) {
        for (int i = 0; i < 4; ++i) {
            cin >> board[i];
        }
        maxPoint[bNum] = 0;
        longest[bNum] = "";
        foundCount[bNum] = 0;
        bool state;
        for (int k = 0; k < stringNum; ++k) {
            state = false;
            for (int i = 0; i < 4; ++i) {
                if(state) break;
                for (int j = 0; j < 4; ++j) {
                    if(state) break;
                    if (hasWord(i, j, strings[k])) {
//                        cout << strings[k] << endl;
                        if(strings[k].length() == 3 || strings[k].length() == 4)
                            maxPoint[bNum] += 1;
                        else if(strings[k].length() == 5)
                            maxPoint[bNum] += 2;
                        else if(strings[k].length() == 6)
                            maxPoint[bNum] += 3;
                        else if(strings[k].length() == 7)
                            maxPoint[bNum] += 5;
                        else if(strings[k].length() == 8)
                            maxPoint[bNum] += 11;
                        if(longest[bNum].length() < strings[k].length())
                            longest[bNum] = strings[k];
                        if(longest[bNum].length() == strings[k].length()){
                            if(longest[bNum] > strings[k])
                                longest[bNum] = strings[k];
                        }
                        foundCount[bNum] += 1;
                        state = true;

                    }
                }
            }
        }
    }

    for(int i = 0; i < boardNum; ++i){
        cout << maxPoint[i] << " " << longest[i] << " " << foundCount[i] <<endl;
    }
}
void printBoard(){
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j <4; ++j){
            cout << board[i][j];
        }
        cout << endl;
    }
}
//char temp;
bool hasWord(int y, int x, string word){
    if(word.length() == 1){
        if(board[y][x] == word[0])
            return true;
        return false;
    }
    if(word[0] == board[y][x]){
        board[y][x] = '*';
        for(int i = 0; i < 8; ++i){
            if (y + dy[i] >= 0 && y + dy[i] < 4 && x + dx[i] >= 0 && x + dx[i] < 4) {
                printBoard();
                cout << "--------" << endl;
                if (hasWord(y + dy[i], x + dx[i], word.substr(1))) {
//                    cout << temp << endl;
                    board[y][x] = word[0];
                    return true;
                }

            }

        }
        board[y][x] = word[0];
    }
    return false;
}