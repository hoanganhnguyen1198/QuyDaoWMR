#ifndef __QUYDAOWMR_H__
#define __QUYDAOWMR_H__

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class QuyDao
{
private:
    vector<float> xRef;
    vector<float> yRef;

public:
    QuyDao();
    ~QuyDao();

    int UpdatexRef(vector<float>ref_x);
    int UpdateyRef(vector<float>ref_y);

    vector<float> GetxRef();
    vector<float> GetyRef();

    int TrajectoryMode(int mode);
};
#endif