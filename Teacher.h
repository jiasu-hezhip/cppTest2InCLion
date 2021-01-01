//
// Created by lee on 2020/12/31.
//
#include <iostream>
using namespace std;
#include "Identity.h"
class Teacher : public Identity{
public:
    int m_EmpId;

    Teacher();
    Teacher(int empId,string name,string pwd);
    virtual void OpenMenu()=0;
    void ValidOrder();
    void ShowOrder();
};
