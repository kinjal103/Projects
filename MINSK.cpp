#include <iostream>
#include <cmath>

using namespace std;

class Quadratic
{
    float a, b, c;
    float real1, real2;
    float i1, i2;

public:
    void setValue()
    {
        cout << "\nThe general quadratic formula is:\nax^2 + bx + c\n";
        cout << "\nSome conditions for being the quadratic equation valid:\n1. a must NOT ne equal to 0.\n2. b^2 >> 4ac is NOT valid.\n";
        cout << "\nPlease enter the values for a, b and c: ";
        
        A:
        cout << "\na: ";
        cin >> a;
        
        if (a == 0)
        {
            cout << "\nIt is violating the 1st condition.\n\'a\' MUST NOT be equal to 0.\nPlease enter appropriate value.\n";
            goto A;
        }
        
        cout << "\nb: ";
        cin >> b;
        
        cout << "\nc: ";
        cin >> c;
        
        root (a, b, c);
    };
    
    void root(float, float, float)
    {
        double b2, _4ac;
        
        b2 = b * b;
        _4ac = 4 * a * c;
        
        if((b2 - _4ac) == b2)
        {
            cout << "\nIt is violating the 2nd condition.\n\'b2\' MUST NOT be very large as compare to \'4ac\'.\nPlease enter appropriate value.\n";    
            setValue();
        }
        else
        {
            float delta;
            
            delta = b2 - _4ac;
            
            //two real roots
            
            if(delta > 0)
            {
                delta = sqrt(delta);
                real1 = (-b - delta) / (2 * a);
                real2 = (-b + delta) / (2 * a);
                
                cout << "\nTwo real roots are: ";
                cout << "\nRoot 1 = " << real1;
                cout << "\nRoot 2 = " << real2;
            }
            
            //two complex roots
            
            else if(delta < 0)
            {
                delta = (-1) * delta;
                delta = sqrt(delta);
                
                real1 = (-b) / (2 * a);
                i1 = delta / (2 * a);
                
                cout << "\nRoots are complex numbers.";
                cout << "\nRoot 1: " << real1 << " + " << i1 << "i";
                cout << "\nRoot 2: " << real1 << " - " << i1 << "i";
            }
            
            //One real root
            
            else
            {
                real1 = -b / (2 * a);
                
                cout << "\nOnly one real root is possible.";
                cout << "\nRoot is: " << real1;
            }
        }
    };
};

using namespace std;

int main()
{
   cout << "Hello World" << endl; 
   
   //Quadratic equation
   Quadratic quadratic;
   quadratic.setValue();
   
   return 0;
}

