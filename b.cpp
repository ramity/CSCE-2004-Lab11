#include <iostream>
using namespace std;

// Interface for Temperature class
//--------------------------------
class Temperature
{
public:
   Temperature();
   Temperature(const Temperature & temp);
   ~Temperature();

   double getCelsius() const;
   double getFahrenheit() const;
   void setCelsius(double temp);
   void setFahrenheit(double temp);

private:
   static const double ABSOLUTE_ZERO = -273.15;
   static const double SUN_CORE_TEMP = 15710000;
   double celsiusTemperature;
};

// Implementation of Temperature class
//-----------------------------------
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
   if (celsiusTemperature > SUN_CORE_TEMP)
      celsiusTemperature = SUN_CORE_TEMP;
}

void Temperature::setFahrenheit(double temp)
{
   celsiusTemperature = (temp - 32.0) * 5.0 / 9.0 ;
   if (celsiusTemperature < ABSOLUTE_ZERO)
      celsiusTemperature = ABSOLUTE_ZERO;
   if (celsiusTemperature > SUN_CORE_TEMP)
      celsiusTemperature = SUN_CORE_TEMP;
}


// Program to demonstrate Temperature class
//-----------------------------------------
int main()
{
   Temperature freezing;
   Temperature boiling;
   Temperature coldcold;
   Temperature hothot;

   freezing.setCelsius(0);
   boiling.setCelsius(100);
   coldcold.setCelsius(-500);
   hothot.setCelsius(20000000);

   cout << "freezing: " << freezing.getFahrenheit() << "F\n";
   cout << "boiling: " << boiling.getFahrenheit() << "F\n";
   cout << "coldcold: " << coldcold.getFahrenheit() << "F\n";
   cout << "hothot: " << hothot.getFahrenheit() << "F\n";
   return 0;
}
