/**Matias Merko
 * mmerko@jacobs-university.de
 * */
#include <iostream>
#include <deque>
using namespace std;
class WindGauge
{
public:
    WindGauge(int period = 12){};
    void currentWindSpeed(int speed);
    int highest() const;
    int lowest() const;
    int average() const;
    void printhistory();
    void dump(WindGauge);

private:
    int totalspeed;
    int period;
    deque<int> history;
};