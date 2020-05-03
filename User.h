#include <string>

#ifndef User_H
#define User_H

using namespace std;

class User{
    public:
    User(string name);
    ~User();
    string getName();

    private:
    string name;
};

#endif