#ifndef __QUYDAOWMR_H__
#define __QUYDAOWMR_H__

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class QuyDao
{
private:
    vector<float> xRef; // Reference x
    vector<float> yRef; // Reference y

public:
    QuyDao(); // Constructor
    ~QuyDao(); // Destructor

    int UpdatexRef(vector<float>ref_x); // Update input ref_x into xRef
    int UpdateyRef(vector<float>ref_y); // Update input ref_y into yRef

    vector<float> GetxRef(); // Return yRef
    vector<float> GetyRef(); // Return xRef

    int TrajectoryMode(int mode); // Select mode for the trajectory of the WMR (4 modes in total)
};
#endif