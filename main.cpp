#include<head.h>
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
