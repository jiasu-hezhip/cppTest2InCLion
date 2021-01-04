//
// Created by lee on 2020/12/31.
//

#include "Student.h"

void Student::CancerOrder() {
    OrderFile orderFile;
    if (orderFile.m_Size == 0){
        cout<<"无预约记录"<<endl;
        return;
    }
    vector<int> v;
    int index = 1;
    for (int i = 0; i < orderFile.m_Size; ++i) {
        if (atoi(orderFile.m_OrderData[i]["stuId"].c_str()) == this->m_Id){
            if (orderFile.m_OrderData[i]["status"] == "1" || orderFile.m_OrderData[i]["status"] == "2"){
                v.push_back(i);
                cout<<index++<<"、";
                cout<<"预约星期："<<orderFile.m_OrderData[i]["date"]<<" ";
                cout<<"预约时段："<<(orderFile.m_OrderData[i]["interval"] == "1" ? "上午":"下午")<<" ";
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
    }
    cout<<"请输入要取消的记录，0代表返回"<<endl;
    int select;
    while (true){
        cin >> select;
        if (select >= 0 && select <= v.size()){
            if (select == 0){
                break;
            } else{
                orderFile.m_OrderData[v[select-1]]["status"] = "0";
                orderFile.UpdateOrder();
                cout<<"已取消预约"<<endl;
                break;
            }
        }
        cout<<"输入有误"<<endl;
    }

}

void Student::ShowAllOrder() {
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

void Student::ShowMyOrder() {

    OrderFile orderFile;
    if (orderFile.m_Size == 0){
        cout<<"无预约记录"<<endl;
        return;
    }
    for (int i = 0; i < orderFile.m_Size; ++i) {
        if (atoi(orderFile.m_OrderData[i]["stuId"].c_str()) == this->m_Id){
            cout<<"预约星期："<<orderFile.m_OrderData[i]["date"]<<" ";
            cout<<"预约时段："<<(orderFile.m_OrderData[i]["interval"] == "1" ? "上午":"下午")<<" ";
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

}

void Student::ApplyOrder() {

    cout<<"请输入申请时间（周一至周五）:"<<endl;
    cout<<"1.周一"<<endl;
    cout<<"2.周二"<<endl;
    cout<<"3.周三"<<endl;
    cout<<"4.周四"<<endl;
    cout<<"5.周五"<<endl;

    int date,interval,room;

    while (true){
        cin >> date;
        if (date >= 1&&date <= 5){
            break;
        }
        cout<<"输入有误，重新输入"<<endl;
    }

    cout<<"请输入申请时间段"<<endl;
    cout<<"1.上午"<<endl;
    cout<<"2.下午"<<endl;
    while (true){
        cin >> interval;
        if (interval >= 1&&interval <= 2){
            break;
        }
        cout<<"输入有误，重新输入"<<endl;
    }

    cout<<"请选择机房："<<endl;
    cout<<"1号，容量"<<vCom[0].m_MaxNum<<endl;
    cout<<"2号，容量"<<vCom[1].m_MaxNum<<endl;
    cout<<"3号，容量"<<vCom[2].m_MaxNum<<endl;
    while (true){
        cin >> room;
        if (room >= 1&&room <= 3){
            break;
        }
        cout<<"输入有误，重新输入"<<endl;
    }

    cout<<"预约成功，审核中"<<endl;

    ofstream ofs(ORDER_FILE,ios::app);
    ofs << "date:" << date <<" ";
    ofs << "interval:" << interval <<" ";
    ofs << "stuId:" << this->m_Id <<" ";
    ofs << "stuName:" << this->m_Name<<" ";
    ofs << "roomId:" << room <<" ";
    ofs << "status:" << 1 <<" ";

}

Student::Student(int id, string name, string pwd) {
    this->m_Name = name;
    this->m_Id = id;
    this->m_Pwd = pwd;

    ifstream ifs;
    ifs.open(COMPUTER_FILE,ios::in);

    ComputerRoom computerRoom;
    while (ifs >> computerRoom.m_ComId && ifs >> computerRoom.m_MaxNum){
        vCom.push_back(computerRoom);
    }

}

Student::Student() {

}

void Student::OpenMenu(){
    cout<<"欢迎学生:"<< this->m_Name<<"登录"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<"1.申请预约"<<endl;
    cout<<"2.查看自身预约"<<endl;
    cout<<"3.查看所有预约"<<endl;
    cout<<"4.取消预约"<<endl;
    cout<<"0.注销登录"<<endl;
    cout<<"--------------------------------"<<endl;

}
