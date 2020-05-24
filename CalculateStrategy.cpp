#include "CalculateStrategy.h"

double SumAndDivide::calculateResult( int res1, int res2){
    return (res1 + res2)%6;
}

double ProductAndDivide::calculateResult( int res1, int res2){
    return (res1 * res2)%6;
}

double Average::calculateResult( int res1, int res2){
    return (double)(res1 + res2)/2;
}