#include <iostream>
#include <fstream>
#include <string>
#include "Identity.h"
#include "GlobalFile.h"
#include "Student.h"
#include "Manager.h"
#include "Teacher.h"

using namespace std;

//教师菜单界面
void TeacherMenu(Identity * &teacher){
    while (true){
        teacher->OpenMenu();
        Teacher * tea = (Teacher*) teacher;
        int select;
        cin>>select;
        if (select == 1){
            tea->ShowOrder();
        }
        if (select == 2){
            tea->ValidOrder();
        }
        if (select == 0){
            delete teacher;
            cout<<"注销成功"<<endl;
            return;
        }
    }
}

//学生子菜单界面
void StudentMenu(Identity * &student){
    while (true){
        //调用管理员子菜单
        student->OpenMenu();
        Student * stu = (Student*) student;
        int select;
        cin >> select;
        if (select == 1){//申请预约
            stu->ApplyOrder();
        }
        if (select == 2){//查看自身预约
            stu->ShowMyOrder();
        }
        if (select == 3){//查看所有人预约
            stu->ShowAllOrder();
        }
        if (select == 4){//取消预约
            stu->CancerOrder();
        }
        if (select == 0){//注销账号
            delete student;
            cout<<"注销成功"<<endl;
            return;
        }
    }
}



//管理员子菜单界面
void ManagerMenu(Identity * &manager){
    while (true){
        //调用管理员子菜单
        manager->OpenMenu();
        Manager * man = (Manager*) manager;
        int select;
        cin >> select;
        if (select == 1){//添加账号
            man->AddPersion();
        }
        if (select == 2){//查看账号
            man->ShowPersion();
        }
        if (select == 3){//查看机房
            man->ShowComputer();
        }
        if (select == 4){//清空预约
            man->CleanFile();
        }
        if (select == 0){//注销账号
            delete manager;
            cout<<"注销成功"<<endl;
            return;
        }
    }
}


void Login(string fileName, int type) {
    Identity *person = NULL;//父类指针子类引用
    ifstream ifs;
    ifs.open(fileName, ios::in);
    if (!ifs.is_open()) {
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }

    int id = 0;
    string name;
    string pwd;

    if (type == 1) {
        cout << "请输入学号" << endl;
        cin >> id;
    }
    if (type == 2) {
        cout << "请输入工号" << endl;
        cin >> id;
    }
    cout << "请输入用户名：" << endl;
    cin >> name;
    cout << "请输入密码" << endl;
    cin >> pwd;
    //身份验证
    if (type == 1) {
        int fId;
        string fName;
        string fPwd;
        while (ifs>>fId && ifs >> fName && ifs >> fPwd){
            if (fId == id && fName == name && fPwd == pwd){
                cout<< "身份验证成功"<<endl;
                person = new Student(id,name,pwd);
                StudentMenu(person);
                return;
            }
        }
    }
    if (type == 2) {
        int fId;
        string fName;
        string fPwd;
        while (ifs>>fId && ifs >> fName && ifs >> fPwd){
            if (fId == id && fName == name && fPwd == pwd){
                cout<< "身份验证成功"<<endl;
                person = new Teacher(id,name,pwd);
                TeacherMenu(person);
                return;
            }
        }
    }
    if (type == 3) {
        string fName;
        string fPwd;
        while (ifs >> fName && ifs >> fPwd){
            if (fName == name && fPwd == pwd){
                cout<< "身份验证成功"<<endl;
                person = new Manager (name,pwd);
                ManagerMenu(person);
                return;
            }
        }
    }
    cout<<"验证登录失败"<<endl;
}


int main() {

    int select = 0;

    while (true) {
        cout << "--------------机房预约系统--------------" << endl;
        cout << "请选择您的身份" << endl;
        cout << "1.学生" << endl;
        cout << "2.老师" << endl;
        cout << "3.管理员" << endl;
        cout << "0.退出" << endl;

        cin >> select;

        switch (select) {
            case 0:
                cout << "欢迎下次使用" << endl;
                return 0;
            case 1:
                Login(STUDENT_FILE, 1);
                break;
            case 2:
                Login(TEACHER_FILE, 2);
                break;
            case 3:
                Login(ADMIN_FILE, 3);
                break;
            default:
                cout << "-------------------------------" << endl;
                cout << "输入有误" << endl;
                break;
        }
    }


    return 0;
}
