#include "cv_matrix.h"


cv_matrix::cv_matrix(int x, int y){
    data.resize(x);
    for(int i = 0;i < x;i++ ){
        data[i].resize(y);
        for(int j = 0;j < y;j++){
            data[i][j] = (1234 * (i+1)) / (5 + j);
        }//y
    }//i
}

cv_matrix::~cv_matrix(){

}

void cv_matrix::print(){
    for(int i = 0; i < data.size();i++){
        for(int j = 0; j < data[i].size();j++){
            cout << " " << data[i][j] << " ";
        }//j
        cout << endl;
    }//i
}