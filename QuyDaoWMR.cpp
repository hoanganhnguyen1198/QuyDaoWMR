#include<iostream>
#include "QuyDaoWMR.h"

QuyDao::QuyDao()
{

}
QuyDao::~QuyDao()
{
    xRef.clear();
    yRef.clear();
}

int QuyDao::UpdatexRef(vector<int>ref_x)
{
    xRef.clear();
    xRef = ref_x;
    return 0;
}
int QuyDao::UpdateyRef(vector<int>ref_y)
{
    yRef.clear();
    yRef = ref_y;
    return 0;
}

vector<int> QuyDao::GetxRef()
{
    return xRef;
}
vector<int> QuyDao::GetyRef()
{
    return yRef;
}

int QuyDao::TrajectoryMode(int mode)
{
    
}