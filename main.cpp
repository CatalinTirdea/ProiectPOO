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



class DriverChampionship{
 int points;
};

class ConstructorChampionship{
  int teampoints;
};

class Tires{
   String compound;
};

class Races{
    String date;
    String circuiteType;
    

};

class Circuits
{

};

class EngineManufacturers
{
 
};

class Driver{

};


class Car
{
    
};

class Team
{
  
};

int main()
{



    return 0;
}