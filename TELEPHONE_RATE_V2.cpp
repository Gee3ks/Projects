#include <iostream>
#include <string>
#include <vector>
#include <limits> // must include to clear or ignore user input invalid
using namespace std;
// OOP
class TelePhoneBill
{
private:
    string _TIME;
    int CALL_DURATION;
    string _DAY, _DAY1;
    vector<string> DAYS_IN_THE_WEEK = {"MO", "TU", "WE", "TH", "FR", "SA", "SU"};

public:
    bool getUserInput()
    {
        // bool isDayFound = false; // Initialize isDayFound

        while (true)
        {
            cout << "\nEnter the Day the Call was made: (Mo - Su): ";

            if (cin >> _DAY)
            {
                // Convert input to uppercase
                for (char &c : _DAY)
                {
                    c = toupper(c);
                }

                // Check if the day is valid
                for (const string &word : DAYS_IN_THE_WEEK)
                {
                    // compare the first two letters in user input string
                    if (_DAY.substr(0, 2) == word)
                    {

                        _DAY1 = word;
                        return true;
                    }
                }
                cerr << "\nInvalid day! | ";
            }

            cerr << "Invalid Input!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    bool parseTime()
    {
        while (true)
        {
            cout << "\nCall Start Time: (HH:MM): ";
            if (cin >> _TIME)
            {
                if (_TIME.length() == 5 && _TIME[2] == ':' &&
                    (isdigit(_TIME[0]) && isdigit(_TIME[1])) &&

                    (isdigit(_TIME[3]) && isdigit(_TIME[4])))
                {

                    int hours = stoi(_TIME.substr(0, 2));
                    int minutes = stoi(_TIME.substr(3, 5));

                    if (hours >= 0 && hours <= 24 && minutes >= 0 && minutes <= 60)
                    {
                        return true;
                    }
                }
                cerr << "\nInvalid Format! (HH:MM) | ";
            }

            cerr << "Invalid Input!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    bool getDuration()
    {

        while (true)
        {
            cout << "\nCall Duration in Minutes: ";
            if (cin >> CALL_DURATION && CALL_DURATION != 0)
            {
                return true;
            }
            cerr << "\nInvalid Input!";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    void calculateTimeGap()
    {
        // Variables for computing the bill
        int totalMinutes;
        double totalBill;

        // Extract hours and minutes from _time
        int startTimeHr = stoi(_TIME.substr(0, 2));
        int startTimeMn = stoi(_TIME.substr(3, 2));

        // Calculate end time
        int endTimeHr = startTimeHr;
        int endTimeMn = startTimeMn + CALL_DURATION;

        // Adjust end time if it exceeds 60 minutes
        if (endTimeMn >= 60)
        {
            endTimeHr += endTimeMn / 60;
            endTimeMn %= 60;
        }

        // Calculate the total minutes for billing
        totalMinutes = (endTimeHr - startTimeHr) * 60 + (endTimeMn - startTimeMn);

        // Calculate total bill based on totalMinutes and any billing logic
        // Example: totalBill = totalMinutes * rate;

        // Message for printing the results
        string processMessage = "\n***** SHOWING RESULTS ****";
        string appliedPrice = "";
        switch (_DAY[0]) // "monday "
        {
        case 'M':
        case 'T':
        case 'W':
        case 'F':
            if (startTimeHr >= 8 && startTimeHr <= 18)
            {
                appliedPrice = " 0.40$/min";
                totalBill = CALL_DURATION * 0.40;
                break;
            }
            else if ((startTimeHr >= 1 && startTimeHr < 8) || (startTimeHr > 18 && startTimeHr < 24))
            {
                appliedPrice = " 0.25$/min";
                totalBill = CALL_DURATION * 0.25;
                break;
            }
        case 'S':
            appliedPrice = " 0.15$/min";
            totalBill = CALL_DURATION * 0.15;
            break;
        }

        cout << processMessage;
        cout << "\n\nDay: " << _DAY1;
        cout << "\n\nApplied:" << appliedPrice;
        cout << "\n\nCall Duration: " << CALL_DURATION << " Minutes.";
        cout << "\n\nFrom: " << _TIME;
        cout << " - " << (endTimeHr < 10 ? "0" : "") << endTimeHr << ":"
             << (endTimeMn < 10 ? "0" : "") << endTimeMn;
        cout << "\n\nTotal Bill: " << totalBill << "$" << '\n';
        cout << "\n\n**********************";
    }
    void runProcess()
    {
        cout << "\nWelcome to Telephone Billing System!\n\n";
        cout << "****** Rates ****** ";
        cout << "\nWeek day | Mon - Fri | (Between 8AM - 6PM) = .40$/min ";
        cout << "\nWeek day | Mon - Fri (Before 8 am or After 6PM) = .25$/min";
        cout << "\nWeekends | Sat - Sun (Any time of the Day) = .25$/min";
        cout << "\n_____________________________________________\n";
        // Encapsulate Functions / Class Methods
        getUserInput();
        parseTime();
        getDuration();
        calculateTimeGap();
    }
};

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
    // class instance
    TelePhoneBill tel;

    do
    {
        tel.runProcess();

    } while (repeat("\nDo you want to calculate another call? (y/n): "));
    cout << "\nExiting Program.";
    return 0;
}
