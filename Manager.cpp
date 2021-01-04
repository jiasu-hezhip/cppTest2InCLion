//
// Created by lee on 2020/12/31.
//


#include "Manager.h"

Manager::Manager() {

}

Manager::Manager(string name, string pwd) {
    this->m_Name = name;
    this->m_Pwd = pwd;
    this->InitVector();

    ifstream ifs;
    ifs.open(COMPUTER_FILE,ios::in);
    ComputerRoom computerRoom;
    while (ifs>>computerRoom.m_ComId&&ifs>>computerRoom.m_MaxNum){
        vCom.push_back(computerRoom);
    }
    ifs.close();
    //cout<<vCom.size()<<endl;
}

void Manager::AddPersion() {

    cout<<"请输入要添加的账户类型"<<endl;
    cout<<"1.添加学生"<<endl;
    cout<<"2.添加老师"<<endl;
    string filrName;
    string tip;
    string erroeTip;
    ofstream ofs;
    int select;
    cin >> select;
    if (select == 1){
        filrName = STUDENT_FILE;
        tip = "请输入学生编号";
        erroeTip = "学号重复！";
    } else{
        filrName = TEACHER_FILE;
        tip = "请输入教师编号";
        erroeTip = "教师号重复";

    }

    ofs.open(filrName,ios::out|ios::app);
    int id;
    string name;
    string pwd;

    cout<<tip<<endl;

    while (true){
        cin>>id;
        bool res = CheckRepeat(id,select);
        if (res){
            cout<<erroeTip<<endl;
        } else{
            break;
        }
    }
    cout<<"请输入名字"<<endl;
    cin>>name;
    cout<<"请输入密码"<<endl;
    cin>>pwd;

    ofs << id << " " << name<<" " <<pwd<<endl;
    cout<<"添加成功"<<endl;
    ofs.close();

    this->InitVector();

}

void PrintStudent(Student & s){
    cout<<s.m_Id<<" "<<s.m_Name<<" "<<s.m_Pwd<<endl;
}

void PrintTeacher(Teacher & t){
    cout<<t.m_EmpId<<" "<<t.m_Name<<" "<<t.m_Pwd<<endl;
}

void Manager::ShowPersion() {
    cout<<"请选择查看类型"<<endl;
    cout<<"1.学生"<<endl;
    cout<<"2.老师"<<endl;
    int select;
    cin>>select;
    if (select == 1){
        for_each(vStu.begin(),vStu.end(),PrintStudent);
    } else{
        for_each(vTea.begin(),vTea.end(),PrintTeacher);
    }
}

void Manager::ShowComputer() {
    for (vector<ComputerRoom>::iterator  it = vCom.begin(); it!= vCom.end(); ++it) {
        cout<<"机房："<<it->m_ComId<<" 最大容量："<<it->m_MaxNum<<endl;
    }
}

void Manager::CleanFile() {
    ofstream ofs(ORDER_FILE,ios::trunc);
    ofs.close();
    cout<<"清空成功"<<endl;
}

void Manager::OpenMenu() {
    cout<<"欢迎管理员:"<< this->m_Name<<"登录"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<"1.添加账号"<<endl;
    cout<<"2.查看账号"<<endl;
    cout<<"3.查看机房"<<endl;
    cout<<"4.清空预约"<<endl;
    cout<<"0.注销登录"<<endl;
    cout<<"--------------------------------"<<endl;

}

void Manager::InitVector() {
    vStu.clear();
    vTea.clear();
    ifstream ifs;
    ifs.open(STUDENT_FILE,ios::in);
    if (!ifs.is_open()){
        cout<<"文件打开失败"<<endl;
        return;
    }
    Student s;
    while (ifs >> s.m_Id && ifs>>s.m_Name && ifs>> s.m_Pwd){
         vStu.push_back(s);
    }
    //cout<<"学生数量"<<vStu.size()<<endl;
    ifs.close();

    ifs.open(TEACHER_FILE,ios::in);
    if (!ifs.is_open()){
        cout<<"文件打开失败"<<endl;
        return;
    }
    Teacher t;
    while (ifs >> t.m_EmpId && ifs>>t.m_Name && ifs>> t.m_Pwd){
        vTea.push_back(t);
    }
    //cout<<"老师数量"<<vTea.size()<<endl;
    ifs.close();
}

bool Manager::CheckRepeat(int id, int type) {
    if (type == 1){
        for (vector<Student>::iterator it=vStu.begin();it!=vStu.end(); ++it) {
            if (id == it->m_Id){
                return true;
            }
        }
    } else{
        for (vector<Teacher>::iterator it=vTea.begin();it!=vTea.end(); ++it) {
            if (id == it->m_EmpId){
                return true;
            }
        }
    }
    return false;
}
