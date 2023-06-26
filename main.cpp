#include<head.h>

extern bool readFile(list<User_login>& userList,const string& fileName);
extern void merge(list<User_login>& userList);
extern bool writeFile(const list<User_login>& userList,const string& fileName);


int main(int argc, char const *argv[])
{
    list <User_login> userList;
    string inputFile="user_login.txt";
    string outputFile="result.txt";

    readFile(userList,inputFile);
    merge(userList);
    writeFile(userList,outputFile);
    return 0;
}
