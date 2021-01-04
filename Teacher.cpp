//
// Created by lee on 2020/12/31.
//

#include "Teacher.h"

Teacher::Teacher() {

}

Teacher::Teacher(int empId, string name, string pwd) {
    this->m_EmpId = empId;
    this->m_Name = name;
    this->m_Pwd = pwd;
}

void Teacher::ValidOrder() {
    OrderFile orderFile;
    if (orderFile.m_Size == 0){
        cout<<"无预约记录"<<endl;
        return;
    }
    //待审核
    cout<<"待审核预约记录如下："<<endl;
    vector<int> v;
    int index;
    for (int i = 0; i < orderFile.m_Size; ++i) {
        if (orderFile.m_OrderData[i]["status"] == "1"){
            v.push_back(i);
            cout<<"第<"<<i+1<<">条"<<endl;
            cout<<"预约星期："<<orderFile.m_OrderData[i]["date"]<<" ";
            cout<<"预约时段："<<(orderFile.m_OrderData[i]["interval"] == "1" ? "上午":"下午")<<" ";
            cout<<"预约学号："<<orderFile.m_OrderData[i]["stuId"]<<" ";
            cout<<"预约姓名："<<orderFile.m_OrderData[i]["stuName"]<<" ";
            cout<<"预约机房："<<orderFile.m_OrderData[i]["roomId"]<<" ";
            cout<<"预约状态：审核中"<<endl;
        }
    }
    cout<<"请输入审核记录号，0代表返回"<<endl;
    int select;
    cin>>select;
    while (true){
        if (select >=0 && select <= v.size()){
            if (select == 0){
                break;
            } else{
                cout<<"请输入审核结果："<<endl;
                cout<<"1.通过"<<endl;
                cout<<"2.不通过"<<endl;
                int res;
                cin>>res;
                if (res == 1){
                    orderFile.m_OrderData[v[select-1]]["status"] = "2";
                } else{
                    orderFile.m_OrderData[v[select-1]]["status"] = "-1";
                }
                orderFile.UpdateOrder();
                cout<<"审核完毕"<<endl;
                break;
            }
        }
        cout<<"输入有误，请重新输入"<<endl;
    }

}

void Teacher::ShowOrder() {
    OrderFile orderFile;
    if (orderFile.m_Size == 0){
        cout<<"无预约记录"<<endl;
        return;
    }
    for (int i = 0; i < orderFile.m_Size; ++i) {
        cout<<"第<"<<i+1<<">条"<<endl;
        cout<<"预约星期："<<orderFile.m_OrderData[i]["date"]<<" ";
        cout<<"预约时段："<<(orderFile.m_OrderData[i]["interval"] == "1" ? "上午":"下午")<<" ";
        cout<<"预约学号："<<orderFile.m_OrderData[i]["stuId"]<<" ";
        cout<<"预约姓名："<<orderFile.m_OrderData[i]["stuName"]<<" ";
        cout<<"预约机房："<<orderFile.m_OrderData[i]["roomId"]<<" ";

        string status = "预约状态：";
        if (orderFile.m_OrderData[i]["status"] == "1"){
            status += "审核中";
        }
        if (orderFile.m_OrderData[i]["status"] == "2"){
            status += "预约成功";
        }
        if (orderFile.m_OrderData[i]["status"] == "-1"){
            status += "预约失败";
        }
        if (orderFile.m_OrderData[i]["status"] == "0"){
            status += "预约已取消";
        }
        cout<<status<<endl;
    }
}

void Teacher::OpenMenu() {
    cout<<"欢迎教师:"<< this->m_Name<<"登录"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<"1.查看预约"<<endl;
    cout<<"2.审核预约"<<endl;
    cout<<"0.注销登录"<<endl;
    cout<<"--------------------------------"<<endl;

}
