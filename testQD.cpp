#include <iostream>
#include <vector>
#include <math.h>

#include "QuyDaoWMR.h"

using namespace std;

int main()
{
    int mode;
    int check;
    vector<float> xRef;
    vector<float> yRef;
    QuyDao qd1 = QuyDao();

    cout << "Input Mode(1, 2, 3, or 4): ";
    cin >> mode;

    check = qd1.TrajectoryMode(mode);
    if (check != 0)
    {
        return 0;
    }
    xRef = qd1.GetxRef();
    yRef = qd1.GetyRef();
    for (int count = 0; count < xRef.size(); count++)
    {
        cout << "xRef(" << count << "): " << xRef[count] << endl;
        cout << "yRef(" << count << "): " << yRef[count] << endl
             << endl;
    }
    return 0;
}