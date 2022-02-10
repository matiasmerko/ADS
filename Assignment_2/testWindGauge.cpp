/**Matias Merko
 * mmerko@jacobs-university.de
 * */
#include "WindGauge.h"
#include <iostream>
int main()
{
    WindGauge w;
    //Adding 15,16,12,15,15
    w.currentWindSpeed(15);
    w.currentWindSpeed(16);
    w.currentWindSpeed(12);
    w.currentWindSpeed(15);
    w.currentWindSpeed(15);
    w.printhistory();
    //dumping the gauge
    w.dump(w);
    cout << endl;
    //adding 16, 17, 16, 16, 20, 17, 16, 15, 16, and 20
    w.currentWindSpeed(16);
    w.currentWindSpeed(17);
    w.currentWindSpeed(16);
    w.currentWindSpeed(16);
    w.currentWindSpeed(20);
    w.currentWindSpeed(17);
    w.currentWindSpeed(16);
    w.currentWindSpeed(15);
    w.currentWindSpeed(16);
    w.currentWindSpeed(20);
    w.printhistory();
    //dumping
    w.dump(w);
    return 0;
}