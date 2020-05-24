#ifndef Calculate_Strategy_H
#define Calculate_Strategy_H

class CalculateStrategy{
    public:
    virtual double calculateResult(int res1,int res2) = 0;
};

class SumAndDivide : public CalculateStrategy{
    public:
    double calculateResult(int res1, int res2);
};

class ProductAndDivide : public CalculateStrategy{
    public:
    double calculateResult(int res1, int res2);
};

class Average : public CalculateStrategy{
    public:
    double calculateResult(int res1, int res2);
};

#endif