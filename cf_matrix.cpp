/*
Author: Mark Lambe
Date: 24-09-14
Mark@MarkLambe.com
Use: For a blog Post for WithThunderousApplause.com, 'Taking Advantage of the Cache in C++'
*/
#include "cf_matrix.h"


cf_matrix::cf_matrix(int x, int y){
    x_size = x;
    y_size = y;
    store = new double[x * y];
    data = new double*[y];
    for (int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            store[j + (x * i)] = 
                (1234 * (i+1)) / (5 + j);
        }//j
        data[i] = &store[x * i];
    }//i
}

cf_matrix::~cf_matrix(){
    delete this->store;
    delete this->data;
}

void cf_matrix::print(){
    for(int i = 0; i < x_size;i++){
        for(int j = 0; j < y_size;j++){
            cout << " " << data[i][j] << " ";
        }//j
        cout << endl;
    }//i
}