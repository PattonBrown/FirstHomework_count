#include"head.h"
bool writeFile(const list<User_login>& userList,const string& fileName){
    ofstream file(fileName);
    if(!file.is_open()){
        cerr<<"Failed to open the file"<<endl;
        return false;
    }
    for(User_login user:userList){
        file<<user.name<<","<<user.count<<endl;
    }
    file.close();
    return true;
}