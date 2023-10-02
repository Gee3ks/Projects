// Header
// Directives
#include <iostream>  // Directives for input and output
#include <cmath>     // math library (sqrt(), pow()).
using namespace std; // Reduce verbosity of the program

// Class Triangle
class Triangle
{
private:
    // Private Class Properties
    double BASE, HEIGHT, HYPOTENUSE;

public:
    // Class Constructor
    // Initialize values to zero.
    Triangle() : BASE(0), HEIGHT(0), HYPOTENUSE(0) {}

    // class Methods

    // Function to solve for Hypotenuse
    double getH(double _base, double _height)
    {

        BASE = _base;
        HEIGHT = _height;
        HYPOTENUSE = sqrt(pow(BASE, 2) + pow(HEIGHT, 2));
        return HYPOTENUSE;
    }
    // Function to make a triangle based on the user input values
    void printTriangle()
    {
        // Decorators
        for (int i = 1; i <= HEIGHT; ++i)
        {
            // Print Spaces
            for (int j = 1; j <= HEIGHT - i; ++j)
            {
                cout << " ";
            }

            // Print Asterisks
            for (int k = 1; k <= i; ++k)
            {
                cout << "*";
            }

            // Move to the next line
            cout << '\n';
        }
        // Prints the class Properties in a formatted way.
        cout << "\nBase: " << BASE;
        cout << "\nHeight: " << HEIGHT;
        cout << "\nHypotenuse: " << HYPOTENUSE << '\n';
    }
};

// Main funtion
int main()
{
    // Variable for the program to run
    char repeat;
    do
    {
        cout << "\n------------T R I A N G L E ------------\n";
        double base, height;
        cout << "\nEnter the base: ";
        cin >> base;
        cout << "Enter the height: ";
        cin >> height;
        // Triangle Class Instance
        Triangle t1;
        t1.getH(base, height); // Access Triangle Class Method
        t1.decorate();

        // Prompt user if they want to continue the program (y/n).
        cout << "\nDo you want to continue? (y/n): ";
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');
    cout << "\nExiting Program.\n";
    return 0;
}
