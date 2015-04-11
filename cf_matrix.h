/*
Author: Mark Lambe
Date: 24-09-14
Mark@MarkLambe.com
Use: For a blog Post for WithThunderousApplause.com, 'Taking Advantage of the Cache in C++'
*/
#ifndef CF_MATRIX_H
#define CF_MATRIX_H

#include <iostream>

using namespace std;
class cf_matrix{
private:
public:
    int x_size;
    int y_size;
    double ** data;
    double * store;

    cf_matrix(int x, int y);
    ~cf_matrix();
    void print();
};



#endif