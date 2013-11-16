//Name: GIACONE, JORDAN
//Date: 10-4-12
//Class: CS54, Section C
//Description: A program that adds, divides, and simplifies fractions

#include <iostream>

using namespace std;

//A fraction will be represented by the form a/b
struct Fraction
{
  //m_a represents the numerator while m_b represents the denominator.
  float m_a, m_b;
}; 

/*
 * Description: Outputs a Greeting message to the screen
 * Pre: None
 * Post: Text is output to the screen
 * Params: None
 * Return: None
 */
void greetings();

/*
 * Description: Ouputs a Goodbye message to the screen 
 * Pre: None
 * Post: Text is output to the screen
 * Params: None
 * Return: None
 */ 
void goodbyes();

/*
 * Description: Displays a menu to the screen 
 * Pre: None
 * Post: Text is output to the screen
 * Params: None
 * Return: A short representing the choice
 */
short dispMenu();

/*
 * Description: Prompts the user for to enter a fraction
 * Pre: None
 * Post: Text is output to the screen
 * Params: None
 * Return: The fraction entered by the user
 */
Fraction enterFraction();

/*
 * Description: Displays the parameter fraction to the screen
 * Pre: The parameter must be set
 * Post: Text is output to the screen
 * Params: fract - the fraction to be outputted
 * Return: None
 */
void displayFraction(const Fraction fract);

/*
 * Description: Adds two fractions together
 * Pre: fract1 and fract2 must be set
 * Post: None
 * Params: fract - the fraction to be displayed
 * Return: The unsimplified sum of fract1 and fract2
 */
Fraction addFractions(const Fraction fract1, const Fraction fract2);

/*
 * Description: Divides two fractions  
 * Pre: fract1 and fract2 must be set
 * Post: None
 * Params: fract1 - The first fraction to be added
 *         fract2 - The second fraction to be added
 * Return: The sum of fract1 and fract2
 */
Fraction divideFractions(const Fraction fract1, const Fraction fract2);

/*
 * Description: Simplifys a given fraction 
 * Pre: fract must be set
 * Post: fract will be a simplified fractoin
 * Params: fract - The fraction to be simplified
 * Return: None
 */
void simplifyFraction(Fraction& fract);

/*
 * Description: Finds the GCD (Greatest Common Divisor) of two numbers 
 * Pre: a and b must be set
 * Post: None
 * Params: a - The first number
 *         b - The second number
 * Return: The GCD of a and b
 */
int findGCD(const int a, const int b);

/*
 * Description: Displays an error to the screen 
 * Pre: None
 * Post: Displays text to the screen
 * Params: None
 * Return: None
 */
void displayError();

int main()
{
  Fraction fract1, fract2, answer;
  bool quit = false;

  greetings();

  //Set denominator to zero to show that the fractions are uninitialized
  fract1.m_b = 0;
  do
  {
    switch(dispMenu())
    {
      case 1:    
        fract1 = enterFraction();
        fract2 = enterFraction();
        break;
      case 2:
        if(fract1.m_b != 0)
        {
          displayFraction(fract1);
          cout << " + ";
          displayFraction(fract2);
          cout << " = "; 
          simplifyFraction((answer = addFractions(fract1, fract2)));
          displayFraction(answer);
        }
        else
        {
          displayError();
        }
        break;
      case 3: 
        if(fract1.m_b != 0)
        {
          displayFraction(fract1); 
          cout << " / ";
          displayFraction(fract2); 
          cout << " = ";
          simplifyFraction((answer = divideFractions(fract1, fract2)));
          displayFraction(answer);
        }
        else
        {
          displayError();
        }
        break;
      case 4: 
        if(fract1.m_b != 0)
        {
          displayFraction(fract1);
          cout << " = ";
          simplifyFraction(fract1);
          displayFraction(fract1);
          cout << endl;
          
          displayFraction(fract2);
          cout << " = ";
          simplifyFraction(fract2);
          displayFraction(fract2); 
        }
        else
        {
          displayError();
        }
        break;
      case 5:
        quit = true;
        break;
      default:
        cout << "That's an invalid response." << endl;
    }
    
    cout << endl;
  }while(!quit);

  goodbyes();
  return 0; 
}

void greetings()
{
  cout << "Hello! Welcome to the Fraction Program!" << endl;
}

void goodbyes()
{
  cout << "Thank you for using the Fraction Program!" << endl;
}

short dispMenu()
{
  short choice;

  cout << "---Menu---\n"
       << "1. Enter Fractions\n"
       << "2. Add Fractions\n"
       << "3. Divide Fractions\n"
       << "4. Simplify Fractions\n"
       << "5. Quit" << endl;
  cin >> choice;
  
  return choice;
}

Fraction enterFraction()
{
  Fraction f;

  cout << "Please enter the numerator: ";
  cin >> f.m_a;
  
  do
  {
    cout << "Please enter the denominator: ";
    cin >> f.m_b;

    if(f.m_b == 0)
    {
      cout << "You can't have a denominator of zero!" << endl;
    }
  }while(f.m_b == 0);

  cout << endl;

  return f;
}

void displayFraction(Fraction fract)
{
  cout << fract.m_a << "/" << fract.m_b;
}

Fraction addFractions(Fraction fract1, Fraction fract2)
{
  Fraction f;
  
  f.m_a = (fract1.m_a * fract2.m_b) + (fract2.m_a * fract1.m_b);
  f.m_b = fract1.m_b * fract2.m_b;

  return f;
}

Fraction divideFractions(Fraction fract1, Fraction fract2)
{
  Fraction f;
  
  f.m_a = fract1.m_a * fract2.m_b;
  f.m_b = fract1.m_b * fract2.m_a;

  return f;
}

void simplifyFraction(Fraction& fract)
{
  int gcd = findGCD(fract.m_a, fract.m_b);

  fract.m_a /= gcd;
  fract.m_b /= gcd;
}

int findGCD(int a, int b)
{
  int big = a > b ? a : b, small = big == a ? b : a, answer;

  answer = big % small;

  while(answer != 0)
  {
    big = small;
    small = answer;
    answer = big % small;
  } 
  
  return small;
}

void displayError()
{
  cout << "You can't do that yet. Please enter fractions by choosing option 1\n"
       << endl;
}
