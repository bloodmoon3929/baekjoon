#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int xs, ys, xe, ye, dx, dy,result_x,result_y;
double predistance;
pair<int, int> near_point;


double Distance(int x, int y) 
{
    double tmp = pow((x - xs), 2) + pow((y - ys), 2);
    return tmp;
}


void Compare() 
{
    double x = xe; double y = ye;
    while (true) 
    {
        x += dx;
        y += dy;

        double tmp = Distance(x, y);
        if (tmp > predistance)
            break;
        else 
        {
            predistance = tmp;
            result_x = x; 
            result_y = y;
        }
    }

}

void GCD() 
{
    int small = min(dx, dy);

    if (small == 0) 
    {
        if (dx == 0)
            dy = 1;
        else
            dx = 1;
        return;
    }

  
    while (small) 
    {
        if (dx%small == 0 && dy%small == 0) 
            break;
        else
            small--;
    }

    if (small > 1) 
        dx /= small; 
        dy /= small;
}

int main() 
{
    cin >> xs >> ys;
    cin >> xe >> ye >> dx >> dy;

    predistance = Distance(xe, ye);
    result_x = xe;
    result_y = ye;

    GCD();
    Compare();


    cout << result_x << " " << result_y;
}