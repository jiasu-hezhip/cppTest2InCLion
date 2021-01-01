#include <iostream>
#include <fstream>
#include <string>
#include "Identity.h"
#include "GlobalFile.h"
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"

using namespace std;

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
                person->OpenMenu();
                return;
            }
        }
    }
    if (type == 2) {

    }
    if (type == 3) {

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
