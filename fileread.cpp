#include<head.h>
bool read(list<User_login>& userList,const string& fileName){
    ifstream file(fileName);
    if(!file.is_open()){
        cerr<<"Failed to open the file"<<endl;
        return false;
    }
    string line;
    
    while(getline(file,line)){
        std::istringstream iss(line);
        string userName;
        getline(iss,userName,',');

        userList.emplace_back(userName,1);
    }
    file.close();
    return true;
}

void merge(list<User_login>& userList){
    
}