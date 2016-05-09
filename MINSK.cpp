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
        
        root ();
    };
    
    void root()
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
    float i1, i2;
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
        
        root();
    };
    
    void root()
    {
        float f, g, h;
        
        f = ((3 * c / a) - ((b * b) / (a * a))) / 3;
        g = (((2 * b * b * b) / (a * a * a)) - ((9 * b * c) / (a * a)) + ((27 * d) / a)) / 27;
        h = (((g * g) / 4) + ((f * f * f) / 27));
        
        if(h > 0)
        {
            float r, s, t, u;
            
            cout << "\nOnly one real and two imaginary roots are possible:\n";
            
            r = ((-g / 2) + sqrt(h));
            s = cbrt(r);
            t = ((-g / 2) - sqrt(h));
            u = cbrt(t);
            
            real1 = ((s + u) - (b / (3 * a)));
            
            real2 = (((-(s + u)) / 2) - (b / (3 * a)));
            
            i1 = ((s - u) * sqrt(3)) / 2;
            
            cout << "\nReal root: " << real1;
            cout << "\nComplex root 1: " << real2 << " + i " << i1;
            cout << "\nComplex root 2: " << real2 << " - i " << i1;
        }
        else if(h <= 0)
        {
            if(f == 0 && g == 0)
            {
                cout << "\nAll roots are real and equal:";
                
                real1 = -(cbrt(d / a));
                
                cout << "\nRoot 1 = Root 2 = Root 3 : " << real1;
            }
            else
            {
                float i, j, k, l, m, n, p;
                
                cout << "\nAll 3 roots are real:";
                
                i = sqrt(((g * g) / 4) - h);
                j = cbrt(i);
                k = acos(-(g / (2 * i)));
                l = -j;
                m = cos(k / 3);
                n = sqrt(3) * sin(k / 3);
                p = -(b / (3 * a));
                
                real1 = (2 * j) * cos(k / 3) - (b / (3 * a));
                real2 = (l * (m + n)) + p;
                real3 = (l * (m - n)) + p;
                
                cout << "\nRoot 1: " << real1;
                cout << "\nRoot 2: " << real2;
                cout << "\nRoot 3: " <<real3;
            }
        }
    };
};

class Prime
{
    int n;
public:
    void setValue()
    {
        D:
        cout << "\nPrime number is the number which number has no factor.";
        cout << "\nEnter the number to check whether that number is prime or not: ";
        cin >> n;
        
        if(n <= 0)
        {
            cout << "\nWe can check for only positive numbers (zero excluded).\nPlease enter appropriate number.\n";
            goto D;
        }
        
        checkPrime();
    };
    
    void checkPrime()
    {
        int i, squareRoot;
        if (n == 1 || n == 2)
        {
            cout << "\nNumber " << n << " is a prime number.";
        }
        else if (n % 2 == 0)
        {
            cout << "\nNumber " << n << " is not a prime number.";
        }
        else
        {
            squareRoot = (sqrt(n));
            
            //cout << squareRoot;
            for(i = 2; i <= squareRoot; i++)
            {
                if(n % i == 0)
                {
                    cout << "\nNumber " << n << " is not a prime number.";
                    return;
                }
                else
                {
                    continue;
                }
            }
            cout << "\nNumber " << n << " is a prime number.";
        }
    };
};

int main()
{
   int ch;
   char c;
   
   C:
   cout << "\nWhat do you want to solve?\n";
   cout << "\n1. Quadratic equation? (Press 1)";
   cout << "\n2. Cubical equation? (Press 2)";
   cout << "\n3. Checking of prime number? (Press 3)\n";
   
   cin >> ch;
   
   switch(ch)
   {
        case 1:
            //Quadratic equation
            Quadratic quadratic;
            quadratic.setValue();
            break;
        case 2:
            //Cubic equation
            Cubic cubic;
            cubic.setValue();         
            break;
        case 3:
            //Prime number
            Prime prime;
            prime.setValue();
            break;
        default:
            cout << "\n\nPlease enter appropriate choice.\n";
            goto C;
   };
   
   cout << "\n\nDo you want to solve one more thing? (Press Y/y or N/n)\n";
   cin >> c;
   
   if (c == 'y' || c == 'Y')
   {
       goto C;
   }
   else
   {
       return 0;
   }
   
   return 0;
}