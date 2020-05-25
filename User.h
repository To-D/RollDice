#include <string>
#include <vector>

#ifndef User_H
#define User_H

using namespace std;

class User{
    public:
    User(string name,double credit);
    ~User();
    string getName();
    void addCredit(double credit, string way);
    void reduceCredit(double credit, string way);
    double getCredit();
    void creditLog(string operation);

    private:
    string name;
    double credit;
    vector<string> creditRecords;
    string getTime();
};

#endif
