/*
Author: Mark Lambe
Date: 24-09-14
Mark@MarkLambe.com
Use: For a blog Post for WithThunderousApplause.com, 'Taking Advantage of the Cache in C++'
*/
#ifndef CV_MATRIX_H
#define CV_MATRIX_H

#include <iostream>
#include <vector>
using namespace std;

class cv_matrix{
private:
public:
    std::vector< std::vector<double> > data; 

    cv_matrix(int x, int y);
    ~cv_matrix();
    void print();
};



#endif