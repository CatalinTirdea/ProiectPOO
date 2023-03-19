#include <iostream>

using namespace std;


class String{
  
  char *sir1;
  
  public:
  String () {
     sir1 = NULL;
  }
    
  
  String (const char sir3[])
  {  
     int lungime =  strlen(sir3);
     sir1 = new char[lungime + 1];
    // strcopy
     strcpy(sir1,sir3);
  }

  String::~String()
  {
    delete[] sir1; 
  }

  
};

class TeamPrincipal
{
  String name;
  int age;
  double height;
  int experience;

};

class DriverChampionship{
 int points;
};

class ConstructorChampionship{
  int teamPoints;
};

class Tires{
   String compound;
};

class Races{
    String date;
    String circuiteType;
    String fastestLap;
    Tires tire1;
    Tires tire2;
    Tires tire3;
    Circuits circuit;

};

class Circuits
{ 
  String name;
  double length;
  int numberOfCorners;
  int numberOfDRSZones;
  

};

class EngineManufacturers
{
  String name;
  double HP;
  int cc;
 
};

class Driver{
 String name;
 int age;
 double weigth;
 double height;
 String nationality;
 DriverChampionship points;
};


class Car
{
    String name;
    double length;
    EngineManufacturers engine;
    String color;

};

class Team
{ 
  TeamPrincipal teamPrincipal;
  Driver driver1;
  Car    car1;
  Driver driver2;
  Car    car2;
  ConstructorChampionship teamPoints;
  String Sponsors;
  int budget;
  
};

int main()
{



    return 0;
}