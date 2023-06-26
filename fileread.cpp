#include<head.h>
bool readFile(list<User_login>& userList,const string& fileName){
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
    // userList.sort();
    // for(list<User_login>::iterator it=userList.begin();it!=userList.end();it++){
    //     it->count=count(userList.begin(),userList.end(),it->name);
    // }
    // userList.erase(unique(userList.begin(),userList.end()),userList.end());
    unordered_map<string,int> nameCounts;
    for(const User_login&user:userList){
        nameCounts[user.name]++;
    }
    for(User_login& user:userList){
        user.count=nameCounts[user.name];
    }
    userList.erase(unique(userList.begin(),userList.end(),[](const User_login&a,const User_login&b){
        return a.name==b.name;
    }),userList.end());
}