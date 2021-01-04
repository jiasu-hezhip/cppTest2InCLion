//
// Created by lee on 2021/1/4.
//
#pragma once
#include "GlobalFile.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
class OrderFile {

public:
    OrderFile();
    void UpdateOrder();
    int m_Size;
    map<int,map<string,string>> m_OrderData;
};

