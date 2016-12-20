#include <iostream>
using namespace std;

// Interface for Temperature class
class Temperature
{
public:
   Temperature();
   Temperature(const Temperature & Temp);
   ~Temperature();

   double getCelsius() const;
   double getFahrenheit() const;
   void setCelsius(double Temp);
   void setFahrenheit(double Temp);

   //user created
   void print();
   void read();


private:
   static const double ABSOLUTE_ZERO = -273.15;
   double celsiusTemperature;
};

// Implementation of Temperature class
Temperature::Temperature()
{
   celsiusTemperature = 0;
}

Temperature::Temperature(const Temperature & temp)
{
   celsiusTemperature = temp.celsiusTemperature;
}

Temperature::~Temperature()
{
}

double Temperature::getCelsius() const
{
   return celsiusTemperature;
}

double Temperature::getFahrenheit() const
{
   return 9.0 * celsiusTemperature / 5.0 + 32.0;
}

void Temperature::setCelsius(double temp)
{
   celsiusTemperature = temp;
   if (celsiusTemperature < ABSOLUTE_ZERO)
      celsiusTemperature = ABSOLUTE_ZERO;
}

void Temperature::setFahrenheit(double temp)
{
   celsiusTemperature = (temp - 32.0) * 5.0 / 9.0 ;
   if (celsiusTemperature < ABSOLUTE_ZERO)
      celsiusTemperature = ABSOLUTE_ZERO;
}

void Temperature::print()
{
   cout << this->getFahrenheit() << "F = " << this->getCelsius() << "C\n";
}

void Temperature::read()
{
   double value;
   char character;

   cout << "Enter a temp value followed by a space and a temperature unit (F/C)" << endl;
   cin >> value;
   cin >> character;

   if(character == 'c' || character == 'C')
   {
      this->setCelsius(value);
   }
   if(character == 'f' || character == 'F')
   {
      this->setFahrenheit(value);
   }
}

// Program to test Temperature class
int main()
{
   Temperature Start;
   Temperature End;

   Start.read();
   End.read();

   cout.precision(3);
   for (double F = Start.getFahrenheit(); F <= End.getFahrenheit(); F++)
   {
      Temperature temp;
      temp.setFahrenheit(F);
      temp.print();
   }
   return 0;
}
