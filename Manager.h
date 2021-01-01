//
// Created by lee on 2020/12/31.
//
#include <iostream>
#include "Identity.h"
using namespace std;
class Manager : public Identity {
public:
    Manager();
    Manager(string name ,string pwd);
    virtual void OpenMenu()=0;
    void AddPersion();
    void ShowPersion();
    void ShowComputer();
    void CleanFile();

};
