// Headers / Directives
#include <iostream>
#include <cmath>
using namespace std;

// Generic Function for getting value
double getValue(string message)
{
    double VALUE;
    do
    {
        cout << message;
        cin >> VALUE;
    } while (VALUE < 0);
    return VALUE;
}

// Function for solving for hypotenuse
double getHypotenuse(double BASE, double HEIGHT)
{
    double HYPOTENUSE = sqrt(pow(BASE, 2) + pow(HEIGHT, 2));
    return HYPOTENUSE;
}

// calling main function
int main(void)
{
    string message = "\n------------T R I A N G L E-------------\n";
    string repeat;
    do
    {
        cout << message;
        double BASE = getValue("Enter the Base: ");
        double HEIGHT = getValue("Enter the Height: ");
        double HYPOTENUSE = getHypotenuse(BASE, HEIGHT);

        cout << "\nBASE: " << BASE;
        cout << "\nHEIGHT: " << HEIGHT;
        cout << "\nHYPOTENUS: " << HYPOTENUSE;

        // prompt user if they want continue the program
        cout << "\n\nDo you want to continue? (y/n): ";
        cin >> repeat;
    } while (repeat == "y" || repeat == "Y");
    cout << "\nExiting Program.";
}
