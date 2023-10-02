#include <iostream>
#include <string>
#include <vector>
#include <limits> // must include to clear or ignore user input invalid
using namespace std;
// OOP
class TelePhoneBill
{
private:
    string _time;
    int callDuration;
    string _day, _day1;
    vector<string> daysInTheWeek = {"MO", "TU", "WE", "TH", "FR", "SA", "SU"};

public:
    bool getUserInput()
    {
        bool isDayFound = false; // Initialize isDayFound

        while (true)
        {
            cout << "\nEnter the Day the Call was made: (Mo - Su): ";

            if (cin >> _day)
            {
                // Convert input to uppercase
                for (char &c : _day)
                {
                    c = toupper(c);
                }

                // Check if the day is valid
                for (const string &word : daysInTheWeek)
                {
                    // compare the first two letters in user input string
                    if (_day.substr(0, 2) == word)
                    {
                        isDayFound = true;
                        _day1 = word;
                        break;
                    }
                }

                if (isDayFound)
                {
                    return true;
                }
                else
                {
                    cerr << "Invalid day. Please try again." << endl;
                }
            }
            else
            {
                cerr << "Invalid Input!" << '\n';
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }

    bool parseTime()
    {
        while (true)
        {
            cout << "\nCall Start Time: (HH:MM): ";
            if (cin >> _time)
            {
                if (_time.length() == 5 && _time[2] == ':' &&
                    (isdigit(_time[0]) && isdigit(_time[1])) &&

                    (isdigit(_time[3]) && isdigit(_time[4])))
                {

                    int hours = stoi(_time.substr(0, 2));
                    int minutes = stoi(_time.substr(3, 5));

                    if (hours >= 0 && hours <= 24 && minutes >= 0 && minutes <= 60)
                    {
                        return true;
                    }
                }
                cerr << "\nInvalid Format!";
                cerr << "\n24:60\n";
            }
            else
            {
                cerr << "\nInvalid Input!";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }

    bool getDuration()
    {

        while (true)
        {
            cout << "\nCall Duration in Minutes: ";
            if (cin >> callDuration)
            {
                if (callDuration < 1)
                {
                    cerr << "\nInvalid!";
                }
                return true;
            }
            else
            {
                cerr << "\nInvalid Input!";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }

    void calculateTimeGap()
    {
        // Variables for computing the bill
        int totalMinutes;
        double totalBill;

        // Extract hours and minutes from _time
        int startTimeHr = stoi(_time.substr(0, 2));
        int startTimeMn = stoi(_time.substr(3, 2));

        // Calculate end time
        int endTimeHr = startTimeHr;
        int endTimeMn = startTimeMn + callDuration;

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
        switch (_day[0]) // "monday "
        {
        case 'M':
        case 'T':
        case 'W':
        case 'F':
            if (startTimeHr >= 8 && startTimeHr <= 18)
            {
                appliedPrice = " 0.40$/min";
                totalBill = callDuration * 0.40;
                break;
            }
            else if ((startTimeHr >= 1 && startTimeHr < 8) || (startTimeHr > 18 && startTimeHr < 24))
            {
                appliedPrice = " 0.25$/min";
                totalBill = callDuration * 0.25;
                break;
            }
        case 'S':
            appliedPrice = " 0.15$/min";
            totalBill = callDuration * 0.15;
            break;
        }

        cout << processMessage;
        cout << "\n\nDay: " << _day1;
        cout << "\n\nApplied:" << appliedPrice;
        cout << "\n\nCall Duration: " << callDuration << " Minutes.";
        cout << "\n\nFrom: " << _time;
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
        // encapsulated the functions
        getUserInput();
        parseTime();
        getDuration();
        calculateTimeGap();
    }
};

int main()
{
    // collection of valid inputs
    char validChoices[2] = {'Y', 'N'};
    // class instance
    TelePhoneBill tel;

    while (true)
    {
        cout << "\nDo you want to continue? (y/n): ";
        char choice;
        cin >> choice;

        // transform user char input to uppercase
        choice = toupper(choice);

        // variable for the loop to run
        bool isChoiceValid = false;
        for (char &c : validChoices)
        {
            if (c == choice)
            {
                isChoiceValid = true;
                if (choice == 'Y')
                {
                    tel.runProcess(); //
                }
                else if (choice == 'N')
                {
                    cout << "\nThank You for using! (r) Group 3!";
                    cout << "\nExiting Program.";
                    return 0;
                }
            }
        }

        if (!isChoiceValid)
        {
            cerr << "\nInvalid Choice!";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return 0;
}
