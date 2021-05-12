#include <iostream>
#include <math.h>
#include "QuyDaoWMR.h"

using namespace std;

QuyDao::QuyDao()
{
}
QuyDao::~QuyDao()
{
    xRef.clear();
    yRef.clear();
}

int QuyDao::UpdatexRef(vector<float> ref_x)
{
    xRef.clear();
    xRef = ref_x;
    return 0;
}
int QuyDao::UpdateyRef(vector<float> ref_y)
{
    yRef.clear();
    yRef = ref_y;
    return 0;
}

vector<float> QuyDao::GetxRef()
{
    return xRef;
}
vector<float> QuyDao::GetyRef()
{
    return yRef;
}

int QuyDao::TrajectoryMode(int mode) // Return 0 if mode entered is valid, return 1 if mode entered is invalid
{
    int check = 1;
    float temp = 0.000;
    float dxRef;
    float dyRef;
    switch (mode)
    {
    case 1:
        // xRef = 0.1 + 0,09*t + 0,03*u(t-2)*t + 0,03*u(t-4)*t - 0,03*u(t-7.5)*t - 0,03*u(t-9)*t;
        // dxRef = 0.09 + 0.03*u(t-2) + 0.03*u(t-4) - 0.03*u(t-7.5) - 0.03*u(t-9);
        // yRef = 0.3 + 0*t;
        // dyRef = 0;
        for (int i = 0; i < 20; i++)
        {
            if (i <= 3 || i >= 18)
            {
                dxRef = 0.09;
            }
            else if (4 <= i < 8 || 15 <= i < 18)
            {
                dxRef = 0.12;
            }
            else
            {
                dxRef = 0.15;
            }

            if (i == 0)
            {
                temp = 0.1;
                xRef.push_back(temp);
            }
            else
            {
                temp = xRef.back() + (float)(dxRef * 0.5);
                xRef.push_back(temp);
            }

            dyRef = 0.000;

            if (i == 0)
            {
                temp = 0.3;
                yRef.push_back(temp);
            }
            else
            {
                temp = yRef.back() + (float)(dyRef * 0.5);
                yRef.push_back(temp);
            }
        }
        check = 0;
        break;
    case 2:
        // xRef = 0,2 + 0,09*t - 0,09*u(t-2)*t + 0,105*cos(0,1507)*u(t-2)*t - 0,105*cos(0,1507)*u(t-4)*t + 0,12*cos(0,3015)*u(t-4)*t - 0,12*cos(0,3015)*u(t-8)*t + 0,09*u(t-8)*t;
        // dxRef = 0,09 - 0,09*u(t-2)*t + 0,105*cos(0,1507)*u(t-2) - 0,105*cos(0,1507)*u(t-4) + 0,12*cos(0,3015)*u(t-4) - 0,12*cos(0,3015)*u(t-8) + 0,09*u(t-8);
        // yRef = 0,2 + 0,09*t - 0,09*u(t-2)*t + 0,105*sin(0,1507)*u(t-2)*t - 0,105*sin(0,1507)*u(t-4)*t + 0,12*sin(0,3015)*u(t-4)*t - 0,12*sin(0,3015)*u(t-8)*t + 0,09*u(t-8)*t;
        // dyRef = 0,09 - 0,09*u(t-2) + 0,105*sin(0,1507)*u(t-2) - 0,105*sin(0,1507)*u(t-4) + 0,12*sin(0,3015)*u(t-4) - 0,12*sin(0,3015)*u(t-8) + 0,09*u(t-8);
        for (int i = 0; i < 20; i++)
        {
            if (i <= 3 || i >= 16)
            {
                dxRef = 0.09;
            }
            else if (4 <= i < 8)
            {
                dxRef = 0.105 * (float)cos(0.1507);
            }
            else
            {
                dxRef = 0.12 * (float)cos(0.3015);
            }

            if (i == 0)
            {
                temp = 0.2;
                xRef.push_back(temp);
            }
            else
            {
                temp = xRef.back() + (float)(dxRef * 0.5);
                xRef.push_back(temp);
            }

            if (i <= 3 || i >= 16)
            {
                dyRef = 0.00;
            }
            else if (4 <= i < 8)
            {
                dyRef = 0.105 * (float)sin(0.1507);
            }
            else
            {
                dyRef = 0.12 * (float)sin(0.3015);
            }

            if (i == 0)
            {
                temp = 0.2;
                yRef.push_back(temp);
            }
            else
            {
                temp = yRef.back() + (float)(dyRef * 0.5);
                yRef.push_back(temp);
            }
        }
        check = 0;
        break;
    case 3:
        // xRef = 0,2 + 0,09*t + 0,03*u(t-1)*t + 0,06*u(t-2)*t + 0,03*u(t-4)*t - 0,03*u(t-6)*t - 0,03*u(t-8)*t - 0,06*u(t-9)*t;
        // dxRef = 0,09 + 0,03*u(t-1) + 0,06*u(t-2) + 0,03*u(t-4) - 0,03*u(t-6) - 0,03*u(t-8) - 0,06*u(t-9);
        // yRef = 0.5 + 0*t;
        // dyRef = 0;
        for (int i = 0; i < 20; i++)
        {
            if (i <= 1 || i >= 18)
            {
                dxRef = 0.09;
            }
            else if (2 <= i < 4)
            {
                dxRef = 0.12;
            }
            else if (4 <= i < 8 || 13 <= i < 16)
            {
                dxRef = 0.15;
            }
            else if (8 <= i < 13)
            {
                dxRef = 0.21;
            }
            else
            {
                dxRef = 0.15;
            }

            if (i == 0)
            {
                temp = 0.2;
                xRef.push_back(temp);
            }
            else
            {
                temp = xRef.back() + (float)(dxRef * 0.5);
                xRef.push_back(temp);
            }

            dyRef = 0.000;

            if (i == 0)
            {
                temp = 0.5;
                yRef.push_back(temp);
            }
            else
            {
                temp = yRef.back() + (float)(dyRef * 0.5);
                yRef.push_back(temp);
            }
        }
        check = 0;
        break;
    case 4:
        // xRef = 0,2 + 0,09*t*[u(t-0)-u(t-0.5)] + 0.105*cos(-0,1507)*t*[u(t-0,5)-u(t-2)] + 0,12*cos(-0,3015)*t*[u(t-2)-u(t-3.5)] + 0,15*cos(-0,3015)*t*[u(t-3.5)-u(t-5)] + 0,165*cos(-0,4523)*t*[u(t-7)] + 0,135*cos(-0,1507)*t*[u(t-7)-u(t-9)]+0,12*t*u(t-9);
        // dxRef = 0,09*[u(t-0)-u(t-0.5)] + 0.105*cos(-0,1507)*[u(t-0,5)-u(t-2)] + 0,12*cos(-0,3015)*[u(t-2)-u(t-3.5)] + 0,15*cos(-0,3015)*[u(t-3.5)-u(t-5)] + 0,165*cos(-0,4523)*[u(t-7)] + 0,135*cos(-0,1507)*[u(t-7)-u(t-9)]+0,12*u(t-9);
        // yRef = 0,2 + 0,09*t - 0,09*u(t-2)*t + 0,105*sin(0,1507)*u(t-2)*t - 0,105*sin(0,1507)*u(t-4)*t + 0,12*sin(0,3015)*u(t-4)*t - 0,12*sin(0,3015)*u(t-8)*t + 0,09*u(t-8)*t;
        // dyRef = 0,09 - 0,09*u(t-2) + 0,105*sin(0,1507)*u(t-2) - 0,105*sin(0,1507)*u(t-4) + 0,12*sin(0,3015)*u(t-4) - 0,12*sin(0,3015)*u(t-8) + 0,09*u(t-8);
        for (int i = 0; i < 20; i++)
        {
            if (i < 4)
            {
                dxRef = 0.105 * (float)cos(-0.1507);
            }
            else if (4 <= i < 7)
            {
                dxRef = 0.12 * (float)cos(-0.3015);
            }
            else if (7 <= i < 10)
            {
                dxRef = 0.15 * (float)cos(-0.3015);
            }
            else if (10 <= i < 14)
            {
                dxRef = 0.165 * (float)cos(-0.4523);
            }
            else if (14 <= i < 18)
            {
                dxRef = 0.135 * (float)cos(-0.1507);
            }
            else
            {
                dxRef = 0.12;
            }

            if (i == 0)
            {
                temp = 0.2;
                xRef.push_back(temp);
            }
            else
            {
                temp = xRef.back() + (float)(dxRef * 0.5);
                xRef.push_back(temp);
            }

            if (i < 4)
            {
                dxRef = 0.105 * (float)sin(-0.1507);
            }
            else if (4 <= i < 7)
            {
                dxRef = 0.12 * (float)sin(-0.3015);
            }
            else if (7 <= i < 10)
            {
                dxRef = 0.15 * (float)sin(-0.3015);
            }
            else if (10 <= i < 14)
            {
                dxRef = 0.165 * (float)sin(-0.4523);
            }
            else if (14 <= i < 18)
            {
                dxRef = 0.135 * (float)sin(-0.1507);
            }
            else
            {
                dxRef = 0.00;
            }

            if (i == 0)
            {
                temp = 1;
                yRef.push_back(temp);
            }
            else
            {
                temp = yRef.back() + (float)(dyRef * 0.5);
                yRef.push_back(temp);
            }
        }
        check = 0;
        break;
    default:
        cout << "Invalid Trajectory Mode.\n";
        check = 1;
        break;
    }
    return check;
}