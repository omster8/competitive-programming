#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
    double x1, y1, r1, x2, y2, r2, radiiDist, circle1Angle, circle2Angle, circle1SectorArea, circle2SectorArea, answer;
    double pi = 3.14159265358979323846;
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);
    radiiDist = sqrt(pow((x2-x1),2) + pow((y2-y1),2));
    if (radiiDist >= (r1+r2)) {
        answer = 0;
    } else if (radiiDist+r2 <= r1) {
        answer = pi*pow(r2,2);
    } else if (radiiDist+r1 <= r2) {
        answer = pi*pow(r1,2);
    } else {
        circle1Angle = 2 * (180/pi)*(acos((pow(r2,2) - pow(r1,2) - pow(radiiDist,2)) / (-2 * r1 * radiiDist)));
        circle2Angle = 2 * (180/pi)*(acos((pow(r1,2) - pow(r2,2) - pow(radiiDist,2)) / (-2 * r2 * radiiDist)));
        circle1SectorArea = (((pi / 360) * circle1Angle * pow(r1,2)) - ((1.0 / 2) * pow(r1,2) * sin((pi/180)*(circle1Angle))));
        circle2SectorArea = (((pi / 360) * circle2Angle * pow(r2,2)) - ((1.0 / 2) * pow(r2,2) * sin((pi/180)*(circle2Angle))));
        answer = circle1SectorArea+circle2SectorArea;
    }
    printf("%lf", answer);
    return 0;
}