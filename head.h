#include<iostream>
#include<list>
#include<fstream>
#include<sstream>
#include<string>
#include<algorithm>
#include <unordered_map>
using namespace std;

struct User_login
{
    string name;
    int count;

    User_login(const std::string& n, int count) : name(n), count(count) {}
};

