//
// Created by lee on 2020/12/31.
//
#pragma once

#include <iostream>

using namespace std;

class Identity {
public:
    virtual void OpenMenu() = 0;

    string m_Name;
    string m_Pwd;
};
