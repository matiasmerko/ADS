/**Matias Merko
 * mmerko@jacobs-university.de
 * */
#include "WindGauge.h"
//adding current wind speed to the history
void WindGauge::currentWindSpeed(int speed)
{
    history.push_back(speed);
    if (history.size() > 12)
    {
        history.pop_front();
    }
}
//Returning highest speed
int WindGauge::highest() const
{
    int max = history[0];
    for (unsigned int i = 0; i < history.size(); i++)
    {
        if (history[i] > max)
        {
            max = history[i];
        }
    }
    return max;
}
//Returning lowest speed
int WindGauge::lowest() const
{
    int min = history[0];
    for (unsigned int i = 0; i < history.size(); i++)
    {
        if (history[i] < min)
        {
            min = history[i];
        }
    }
    return min;
}
//returning average speed
int WindGauge::average() const
{
    int sum = 0;
    int avg;
    int count = 0;
    for (unsigned int i = 0; i < history.size(); i++)
    {
        count++;
        sum += history[i];
    }
    avg = sum / count;
    return avg;
}
//printing the history
void WindGauge::printhistory()
{
    for (unsigned int i = 0; i < history.size(); i++)
    {
        cout << history[i] << ' ';
    }
    cout << endl;
}
//printing the highest,lowest and average wind speed
void WindGauge::dump(WindGauge obj)
{
    cout << "Highest:" << obj.highest() << "\nLowest:" << obj.lowest()
         << "\nAverage:" << obj.average();
}