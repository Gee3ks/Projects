#include <iostream>
#include <limits>
using namespace std;

class Crud
{
private:
    const int TIME_PERIOD = 5;

public:
    int calculatePopulation(long int initialSize, long int days)
    {
        if (days < 10)
            return days < 0 ? 0 : initialSize;
        long int a = initialSize, b = initialSize;
        for (int i = 10; i <= days; i += TIME_PERIOD)
            a = (b += a) - a;
        return b;
    }

    double getValue(string prompt)
    {
        double value(0);
        do
        {
            cout << prompt;
            if (cin >> value && value != 0)
            {
                break;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "\nInvalid Input!";
        } while (value <= 0);
        return value;
    }
};

// Function repeat
bool repeat(string prompt)
{
    string repeat = "";
    do
    {
        cout << prompt;
        cin >> repeat;

    } while (repeat != "y" && repeat != "n");
    return repeat == "y";
}

int main()
{
    Crud crud;
    double INITIAL_SIZE;
    int DAYS;
    do
    {
        INITIAL_SIZE = crud.getValue("\nEnter initial size of the green crud in pounds: ");
        DAYS = crud.getValue("\nEnter the days: ");

        cout << "\nAfter " << DAYS << " days the total Green Crud population is " << crud.calculatePopulation(INITIAL_SIZE, DAYS) << " lbs\n";
    } while (repeat("\nDo you want to continue? (y/n): "));
    cout << "\nExiting Program.";
    return 0;
}
