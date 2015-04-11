/*
Author: Mark Lambe
Date: 24-09-14
Mark@MarkLambe.com
Use: For a blog Post for WithThunderousApplause.com, 'Taking Advantage of the Cache in C++'
*/
#include "ce_matrix.h"


ce_matrix::ce_matrix(int x, int y){
    x_size = x;
    y_size = y;
    data = new double*[x];
    for (int i = 0; i < x; i++){
        data[i] = new double[y];
        for(int j = 0; j < y; j++){
            data[i][j] = (1234 * (i+1)) / (5 + j);
        }//j
    }//i
}

ce_matrix::~ce_matrix(){
    delete data;
}

void ce_matrix::print(){
    for(int i = 0; i < x_size;i++){
        for(int j = 0; j < y_size;j++){
            cout << " " << data[i][j] << " ";
        }//j
        cout << endl;
    }//i
}