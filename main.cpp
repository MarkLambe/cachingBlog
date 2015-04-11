/*
Author: Mark Lambe
Date: 24-09-14
Mark@MarkLambe.com
Use: For a blog Post for WithThunderousApplause.com, 'Taking Advantage of the Cache in C++'
*/

#include <iostream>
#include <sys/time.h>
#include <ctime>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

#include "ce_matrix.h"
#include "cf_matrix.h"
#include "cv_matrix.h"



void cf_multiply(cf_matrix *cf_1, cf_matrix *cf_2,
    cf_matrix *answer, int x, int y);

void ce_multiply(ce_matrix *ce_1, ce_matrix *ce_2,
    ce_matrix *answer, int x, int y);

void cv_multiply(cv_matrix *cv_1, cv_matrix *cv_2,
    cv_matrix *answer, int x, int y);

int main(int argc, char* argv[]){

    int option_char;
    //Start, init
    int x_size = 1000;
    int y_size = 1000;
    // Invokes member function `int operator ()(void);'
    while ((option_char = getopt (argc, argv, "s:")) != -1)
    switch (option_char)
      {  
         case 's': x_size = y_size = atoi (optarg); break;
         case '?': cout << "Use -s 1000" << endl;break;
      }

    //Let's try with vectors
    cout << endl << "Running for " << x_size << " x " << y_size << endl << endl;
    //Let's try the bad one 
    cv_matrix * cv_1 = new cv_matrix(x_size,y_size);
    cv_matrix * cv_2 = new cv_matrix(x_size,y_size);
    cv_matrix * cv_answer = new cv_matrix(x_size,y_size);

    clock_t cv_startTime;
    cv_startTime = clock();
    cv_multiply(cv_1, cv_2, cv_answer, x_size,y_size);

    //Results
    double cv_time = double( clock() - cv_startTime );
    //Clean up
    delete cv_1;
    delete cv_2;
    delete cv_answer;


    //Let's try the bad one 
    ce_matrix * ce_1 = new ce_matrix(x_size,y_size);
    ce_matrix * ce_2 = new ce_matrix(x_size,y_size);
    ce_matrix * ce_answer = new ce_matrix(x_size,y_size);

    clock_t ce_startTime;
    ce_startTime = clock();
    ce_multiply(ce_1, ce_2, ce_answer, x_size,y_size);

    //Results
    double ce_time = double( clock() - ce_startTime );
    //Clean up
    delete ce_1;
    delete ce_2;
    delete ce_answer;


    //Now let's try the good one!
    cf_matrix * cf_1 = new cf_matrix(x_size,y_size);
    cf_matrix * cf_2 = new cf_matrix(x_size,y_size);
    cf_matrix * cf_answer = new cf_matrix(x_size,y_size);

    clock_t cf_startTime;
    cf_startTime = clock();
    cf_multiply(cf_1, cf_2, cf_answer, x_size,y_size);

    //Results
    double cf_time = double( clock() - cf_startTime );
    
    //Clean up, go home
    delete cf_1;
    delete cf_2;
    delete cf_answer;

    //Print some results.
    cout << "Cache Vector took " << cv_time / CLOCKS_PER_SEC
        << " seconds" << endl;

    cout << "Cache Enemy took " << ce_time / CLOCKS_PER_SEC
        << " seconds" << endl;

    cout << "Cache Friend took " << cf_time / CLOCKS_PER_SEC
        << " seconds" << endl;

    cout << endl << "That's a total of " <<
        (cf_time + ce_time + cv_time) / CLOCKS_PER_SEC << endl;
    return 0;
}


void cf_multiply(cf_matrix *cf_1, cf_matrix *cf_2,
    cf_matrix *answer, int x, int y){
    
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            answer->data[i][j]=0;
            for(int k=0;k<y;k++){
                answer->data[i][j]=answer->data[i][j]+(cf_1->data[i][k] * cf_2->data[k][j]);
            }//k
        }//j
    }//i

}//cf_multiply


void ce_multiply(ce_matrix *ce_1, ce_matrix *ce_2,
    ce_matrix *answer, int x, int y){
    
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            answer->data[i][j]=0;
            for(int k=0;k<y;k++){
                answer->data[i][j]=answer->data[i][j]+(ce_1->data[i][k] * ce_2->data[k][j]);
            }//k
        }//j
    }//i

}//ce_multiply

void cv_multiply(cv_matrix *cv_1, cv_matrix *cv_2,
    cv_matrix *answer, int x, int y){
    
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            answer->data[i][j]=0;
            for(int k=0;k<y;k++){
                answer->data[i][j]=answer->data[i][j]+(cv_1->data[i][k] * cv_2->data[k][j]);
            }//k
        }//j
    }//i

}//ce_multiply
