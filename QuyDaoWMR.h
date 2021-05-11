#ifndef __QUYDAOWMR_H__
#define __QUYDAOWMR_H__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class QuyDao
{
private:
    vector<int> xRef;
    vector<int> yRef;

public:
    QuyDao();
    ~QuyDao();
    int UpdatexRef(vector<int>ref_x);
    int UpdateyRef(vector<int>ref_y);
    vector<int> GetxRef();
    vector<int> GetyRef();
    int TrajectoryMode(int mode);
};
#endif