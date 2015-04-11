/*
Author: Mark Lambe
Date: 24-09-14
Mark@MarkLambe.com
Use: For a blog Post for WithThunderousApplause.com, 'Taking Advantage of the Cache in C++'
*/
#ifndef CE_MATRIX_H
#define CE_MATRIX_H

#include <iostream>

using namespace std;
class ce_matrix{
private:
public:
    int x_size;
    int y_size;
    double ** data;

    ce_matrix(int x, int y);
    ~ce_matrix();
    void print();
};



#endif