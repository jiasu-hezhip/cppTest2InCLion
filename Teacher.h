//
// Created by lee on 2020/12/31.
//
#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;
#include "Identity.h"
#include "OrderFile.h"
class Teacher : public Identity{
public:
    int m_EmpId;

    Teacher();
    Teacher(int empId,string name,string pwd);
    void OpenMenu();
    void ValidOrder();
    void ShowOrder();
};
