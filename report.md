# 综合实训作业一  

**姓名：李映进          班级：大数据12102     学号：2109230222  **

**声明： 本次作业采用c++语言编写，采用了list，unordered_map等stl容器（梁老师课上允许） **  

## 一、实验目的

> （1）掌握 git 的使用； 
>
> （2）掌握 vscode 的使用； 
>
> （3）掌握使用 Makefile 进行工程编译的方法； 
>
> （4）掌握编程文档的撰写方法；
>
>  （4）复习文件编程；
>
>  （5）复习单链表的编程；

## 二、实验流程

本次实验首先定义了 **head.h**、**fileread.cpp**、**filewrite.cpp**、**main.cpp** 用于实现文件的读写以及字符串的处理操作。  

### 具体步骤

* 首先**readFile**函数逐行读取**user_login.txt**中的登录信息:  

  > 使用**getline**函数实现读取每行信息中的登录人名，然后将读取的人名添加到链表**userList**中；  

* 然后使用**merge**函数统计每个人名对应的登录次数，得出结果链表**userList**：  

  > 使用**unordered_map**统计每个人名出现的次数，然后使用**erase**和**unique**函数对链表中的重复人名进行去重，得到结果链表**userList**；

* 最后使用**writeFile**函数将结果链表写入到文件**result.txt**文件中：  

  > 写入文件时采用**“人名，登录次数”**的格式进行写入。

## 三、核心实现代码

* **readFile**:  

  > ```
  > bool readFile(list<User_login>& userList,const string& fileName){
  >     ifstream file(fileName);
  >     if(!file.is_open()){
  >         cerr<<"Failed to open the file"<<endl;
  >         return false;
  >     }
  >     string line;
  >     while(getline(file,line)){
  >         std::istringstream iss(line);
  >         string userName;
  >         getline(iss,userName,',');
  > 
  >         userList.emplace_back(userName,1);
  >     }
  >     file.close();
  >     return true;
  > }
  > ```

* **merge**:  

  > ```
  > void merge(list<User_login>& userList){
  >     unordered_map<string,int> nameCounts;
  >     for(const User_login&user:userList){
  >         nameCounts[user.name]++;
  >     }
  >     for(User_login& user:userList){
  >         user.count=nameCounts[user.name];
  >     }
  >     userList.erase(unique(userList.begin(),userList.end(),[](const User_login&a,const User_login&b){
  >         return a.name==b.name;
  >     }),userList.end());
  > }
  > ```

* **writefile**:  

  > ```
  > bool writeFile(const list<User_login>& userList,const string& fileName){
  >     ofstream file(fileName);
  >     if(!file.is_open()){
  >         cerr<<"Failed to open the file"<<endl;
  >         return false;
  >     }
  >     for(User_login user:userList){
  >         file<<user.name<<","<<user.count<<endl;
  >     }
  >     file.close();
  >     return true;
  > }
  > ```

## 四、实验结果

1. 实验结果展示如下*（可ctrl+单击打开）*：  

   >[![result-png.jpg](https://i.postimg.cc/kgYNBGnW/result-png.jpg)](https://postimg.cc/zyWHQJHf)

2. 实验代码*(github仓库地址）*：  

   > [实验代码](https://github.com/PattonBrown/FirstHomework_count.git)

3. 提交日志*（可ctrl+单击打开）*：  

   > [![log-png.jpg](https://i.postimg.cc/QCLPWSqG/log-png.jpg)](https://postimg.cc/WFnSBGKX)

## 五、总结

通过本次实验，我掌握了git和vscode 的使用，并且可以 正确使用Makefile 进行工程编译 ，同时对c++中stl的使用更加熟练。