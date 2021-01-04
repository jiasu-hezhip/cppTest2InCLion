//
// Created by lee on 2020/12/31.
//
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "GlobalFile.h"
#include "Identity.h"
#include "Student.h"
#include "Teacher.h"
#include "ComputerRoom.h"

using namespace std;
class Manager : public Identity {
public:
    Manager();
    Manager(string name ,string pwd);
    void OpenMenu();
    void AddPersion();
    void ShowPersion();
    void ShowComputer();
    void CleanFile();

    void InitVector();
    bool CheckRepeat(int id,int type);
    vector<Student> vStu;
    vector<Teacher> vTea;
    vector<ComputerRoom> vCom;
};
