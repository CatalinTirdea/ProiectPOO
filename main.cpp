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

  void operator = (const String& sir){
   sir1 = sir.sir1;
}
   friend ostream & operator << (ostream &out, const String &strin);

};

ostream & operator << (ostream &out, const String &strin)
{
   out<<strin.sir1;
    return out;
}

class TeamPrincipal
{
  String name;
  int age;
  double height;
  int experience;

};




class DriverChampionship{
 
 int points;
 
 public:
 
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
  void operator = (const DriverChampionship& dc)
  {
    points = dc.points;
  }
  friend ostream & operator << (ostream &out, const DriverChampionship &dc);
  friend istream & operator >> (istream &in,   DriverChampionship &dc);
  friend class Driver;
};


ostream & operator << (ostream &out, const DriverChampionship &dc)
{
   out<<"Current Driver Chapmionship points are: "<<dc.points;
    return out;
}


istream & operator >> (istream &in, DriverChampionship &dc)
{   
      in>>dc.points;
    
    return in;
}



class ConstructorChampionship{
  int teamPoints;
  
  public:
  
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
  
  friend ostream & operator << (ostream &out, const ConstructorChampionship &cc);
  
  friend istream & operator >> (istream &in,   ConstructorChampionship &cc);
};

ostream & operator << (ostream &out, const ConstructorChampionship &cc)
{
   out<<"Current Constructor Chapmionship points are: "<<cc.teamPoints;
    return out;
}

istream & operator >> (istream &in, ConstructorChampionship &cc)
{   
      in>>cc.teamPoints;
    
    return in;
}



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

  void setFastestLap(String fl){
    fastestLap = fl;
  } 

 String getDate(){
    return date;
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
  String sponsors;
  long int budget;
  int teamPenaltyPoints;


  public:
  Team () : budget(140000000), teamPenaltyPoints(0){}

  Team(String nm, TeamPrincipal tp, Driver d1, Car c1, Driver d2,Car c2, ConstructorChampionship teamp, String spns,long int bdg, int tmpnltypnts){
    name = nm;
    teamPrincipal = tp;
    driver1 = d1;
    car1 = c1;
    driver2 = d2;
    car2 = c2;
    teamPoints = teamp;
    sponsors = spns;
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
    sponsors = spns;
  }

  void addPenaltyPoints(int pnltypnts){
    teamPenaltyPoints += pnltypnts;

  }

  void determineBudget(){
    int i;
    int penalty = 0;
    int penaltyPerPoint = 100000000;
    budget = 140000000;
    if(teamPenaltyPoints >= 15)
  {
    penalty = teamPenaltyPoints/15;
    penaltyPerPoint *= penalty;
  }
    
    budget -= penaltyPerPoint;
    }
  

};


 
int main()
{
ConstructorChampionship points1;
 ConstructorChampionship points2;
 DriverChampionship points3;
 cin>>points1;
 cout<<points1<<endl;
 cin>>points3;
 cout<<points3<<endl;
 String sir("abc");
 String sir2;
 sir2 = sir;
 cout<<sir2<<endl;
 points2 = points1;
 cout<<points2<<endl;
 points1.setTeamPoints(100);
 cout<<points1<<endl;
 points2.getTeamPoints();
 
    return 0;
}