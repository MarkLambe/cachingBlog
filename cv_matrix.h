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