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
        cout << "\nThe general quadratic formula is:\nax^2 + bx + c = 0\n";
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

class Cubic
{
    float a, b, c, d;
    float real1, real2, real3;
public:
    void setValue()
    {
        cout << "\nGeneral cubical equation is:\nax^3 + bx^2 + cx + d = 0\n";
        cout << "\nThere are some conditions to be an equation a cubical equation:\n1. \'a\' must NOT be equal to 0.\n";
        cout << "\nPlease enter the values for a, b, c and d:";
        
        B:
        cout << "\na: ";
        cin >> a;
        
        if(a == 0)
        {
            cout << "This value of \'a\' is violating 1st condition.\nPlease enter the appropriate value of \'a\'.\n\'a\' must NOT be equal to 0.\n";
            goto B;
        }
        
        cout << "\nb: ";
        cin >> b;
        
        cout << "\nc: ";
        cin >> c;
        
        cout << "\nd: ";
        cin >> d;
        
        root(a, b, c, d);
    };
    
    void root(float a, float b, float c, float d)
    {
        cout << a << b << c << d;
    };
};

int main()
{
   //cout << "Hello World" << endl; 
   
   //Quadratic equation
   Quadratic quadratic;
   quadratic.setValue();
   
   //Cubic equation
   Cubic cubic;
   cubic.setValue();
   
   return 0;
}
