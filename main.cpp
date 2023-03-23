#include <iostream>
#include <string.h>
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

  ~String() 
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
 DriverChampionship () : points(0) {}
  
  int getPoints (){
    return points;
  }
  
  DriverChampionship(int point){
    points = point;
  }
  
  void addPoints (int point){
    points += point;
  }
  friend class Driver;
};

class ConstructorChampionship{
  int teamPoints;
   ConstructorChampionship() : teamPoints(0) {}
  
  int getTeamPoints(){
    return teamPoints;
  }
  
  void setTeamPoints (int teamPoint){
    teamPoints = teamPoint;
  }
  
  void addTeamPoints (int teamPoint){
    teamPoints += teamPoint;
  }
  friend class Team;
};

class Tires{
   String compound;

   Tires () : compound("C5"){}

   String getCompound(){
    return compound;
   }

   void setCompound(String comp){
    compound = comp;
   }

   Tires(String comp) {
    compound= comp;
   }

  friend class Races;
};

class Circuits
{ 
  String name;
  double length;
  int numberOfCorners;
  int numberOfDRSZones;
 
  Circuits () :  length(0.0), numberOfCorners(0),numberOfDRSZones(0){}

  Circuits (String nm, double lng, int nrcorners, int nrdrs){
    name = nm;
    length = lng;
    numberOfCorners = nrcorners;
    numberOfDRSZones = nrdrs;
  }

  friend class Races;

};

class Races{
    String date;
    String circuitType;
    String fastestLap;
    Tires tire1;
    Tires tire2;
    Tires tire3;
    Circuits circuit;
    
  Races (String dateRace,String circType,Circuits circ) {
   
       date = dateRace;
       circuitType = circType;
       circuit = circ;

   
   
}

 Races (Tires t1,Tires t2,Tires t3){
  tire1 = t1;
  tire2 = t2;
  tire3 = t3;
 }

 Races(String fl){
  fastestLap = fl;
 }
};



class EngineManufacturers
{
  String manufacturerName;
  double HP;
  int cc;
  EngineManufacturers () : HP(0.0), cc(0){}

  EngineManufacturers (String mnfname, double hp, int cylcap){
    manufacturerName = mnfname;
    HP = hp;
    cc = cylcap;
  }
  friend class Car;
};

class Driver{
 String name;
 int age;
 double weigth;
 double height;
 String nationality;
 DriverChampionship points;
 int driverPenaltyPoints;
 
 Driver() : age(0),weigth(0.0),height(0.0), driverPenaltyPoints(0){}
 
 Driver(String nm, int ag,double wei,double hei,String nat){
  name = nm;
  age = ag;
  weigth = wei;
  hei = height;
  nationality = nat;
 }
  
  Driver(DriverChampionship pnts){
    points = pnts;
  }
  
  Driver(int pnltypoints){
    driverPenaltyPoints = pnltypoints;
  }
  friend class Team;
};


class Car
{
    String name;
    double length;
    EngineManufacturers engine;
    String color;
    
    Car() :  length(0.0){}

    Car(String nm, double lngth, EngineManufacturers eng, String clr){
      name = nm;
      length = lngth;
      engine = eng;
      color = clr;
    } 

    Car(EngineManufacturers eng){
      engine = eng;
    }

    friend class Team;
};

class Team
{ 
  String name;
  TeamPrincipal teamPrincipal;
  Driver driver1;
  Car    car1;
  Driver driver2;
  Car    car2;
  ConstructorChampionship teamPoints;
  String Sponsors;
  long int budget;
  int teamPenaltyPoints;

  Team () : budget(140000000), teamPenaltyPoints(0){}

  Team(String nm, TeamPrincipal tp, Driver d1, Car c1, Driver d2,Car c2, ConstructorChampionship teamp, String spns,long int bdg, int tmpnltypnts){
    name = nm;
    teamPrincipal = tp;
    driver1 = d1;
    car1 = c1;
    driver2 = d2;
    car2 = c2;
    teamPoints = teamp;
    Sponsors = spns;
    budget = bdg;
    teamPenaltyPoints = tmpnltypnts;

  }

  Team(Driver d2, Car c2)
  {
   driver1 = driver2;
   car1 = car2;
   driver2 =d2;
   car2 =c2;
     }
  
  Team(TeamPrincipal tp){
    teamPrincipal = tp;
  }
  Team(String spns){
    Sponsors = spns;
  }
};

int main()
{



    return 0;
}