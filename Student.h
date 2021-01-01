//
// Created by lee on 2020/12/31.
//
#pragma once
#include <iostream>
#include "Identity.h"
using namespace std;
class Student :public Identity{
public:
    //学号
    int m_Id;
    //默认构造
    Student();
    //有参构造
    Student(int id,string name,string pwd);
    //菜单界面
    void OpenMenu();
    //申请预约
    void ApplyOrder();
    //查看自身预约
    void ShowMyOrder();
    //查看所有人的预约
    void ShowAllOrder();
    //取消预约
    void CancerOrder();
};
