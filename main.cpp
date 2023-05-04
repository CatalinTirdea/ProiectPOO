#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class customExceptionNegative : public exception{
 const char* negative = "Number cannot be nagative!";
 public:
  const char * what(){

   return negative;
 }

};
class customExceptionAge : public exception{
  const char* age = "The age should be over 18!";

  public:
   const char * what(){
    return age;
  }
};

class DriverChampionship{
 
 int points;
 
 public:
 
 DriverChampionship () : points(0) {}
  
  int getPoints (){
    return points;
  }
  
  DriverChampionship(int point){
    try{
    if(point < 0)
    throw customExceptionNegative();
    points = point;
    }
    catch(customExceptionNegative cen){
      cout<<cen.what()<<endl;
      cout<<"Points cannot be negative, setting them to 0. ";
      points = 0;

    }
    
  }
  
  void addPoints (int point){
    if (point < 0)
    throw customExceptionNegative();
    points += point;
  }
  void operator = (const DriverChampionship& dc)
  {
    points = dc.points;
  }
  friend ostream & operator << (ostream &out, const DriverChampionship &dc);
  friend istream & operator >> (istream &in,   DriverChampionship &dc);
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
  protected:
  int teamPoints;
  int penaltyPoints;
  int getTeamPoints(){
    return teamPoints;
  }
  public:
  
  ConstructorChampionship() : teamPoints(0),penaltyPoints(0) {}
  
   
  
  void setTeamPoints (int teamPoint){
    if (teamPoint < 0)
    throw customExceptionNegative();
    teamPoints = teamPoint;
  }
  
  void addTeamPoints (int teamPoint){
    if (teamPoint < 0)
    throw customExceptionNegative();
    teamPoints += teamPoint;
  }

  
 
  
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
   string compound;
  public:

   Tires () : compound("C5"){}

   string getCompound(){
    return compound;
   }

   void setCompound(string comp){
    compound = comp;
   }

   Tires(string comp) {
    compound = comp;
   }
   friend ostream & operator << (ostream &out, const Tires &tire);
  
    friend istream & operator >> (istream &in,   Tires &tire);
  
};

   ostream & operator << (ostream &out, const Tires &tire){
   out<<tire.compound;
    return out;
}

istream & operator >> (istream &in,   Tires &tire)
{   
      cout<<"Enter compound: ";
      in>>tire.compound;
    return in;
}

class Circuits
{ 
  string name;
  double length;
  int numberOfCorners;
  int numberOfDRSZones;
  public:
  Circuits () :  length(0.0), numberOfCorners(0),numberOfDRSZones(0){}

  Circuits (string nm, double lng, int nrcorners, int nrdrs){
    name = nm;
    length = lng;
    numberOfCorners = nrcorners;
    numberOfDRSZones = nrdrs;
  }
  
   bool checkIfEmpty(){
    if(numberOfCorners == 0){
      return true;
    }
    return false;
   }
    string getName(){
    return name;
   }
   double getLength(){
    return length;
   }
    int getnumberOfCorners(){
    return numberOfCorners;
   }
    int getnumberOfDRSZones(){
    return numberOfDRSZones;
   }
   void setName(string nm){
    name = nm;
   }
    void setLength(double ln){
    length = ln;
   }
    void setnumberOfCorners(int cn){
    numberOfCorners = cn;
   }
    void setnumberOfDRSZones(int dz){
    numberOfDRSZones = dz;
   }
};



class Races: public Circuits{
    string date;
    string circuitType;
    string fastestLap;
    Tires tire1;
    Tires tire2;
    Tires tire3;
   
  public: 
  Races (): date(" "), circuitType(" "), fastestLap(" "){}

  Races (string dateRace,string circType) {
   
       date = dateRace;
       circuitType = circType;

   
}

 Races (Tires t1,Tires t2,Tires t3){
  tire1 = t1;
  tire2 = t2;
  tire3 = t3;
 }

  void setFastestLap(string fl){
    fastestLap = fl;
  } 

 string getDate(){
    return date;
   }
    friend ostream & operator << (ostream &out,  Races &race);
  
    friend istream & operator >> (istream &in,   Races &race);
   
};

ostream & operator << (ostream &out,  Races &race)
{   out<<"The "<<race.getName()<<" circuit with a length of "<<race.getLength()<<"km has a number of "<<race.getnumberOfDRSZones()<<" DRS zones and "<<race.getnumberOfCorners()<<" corners";
    out<<". The date of the race is "<<race.date<<". The circuit type is "<<race.circuitType<<". The selected compounds are: "<<race.tire1<<", "<<race.tire2<<", "<<race.tire3<<".";
    if(race.fastestLap !="0"){
      out<<" The fastest lap set this season was: "<<race.fastestLap;
    }
    return out;
}


istream & operator >> (istream &in, Races &race)
{   
    cout<<"Date of the race: ";
    in>>race.date; 
    cout<<endl;
    cout<<"What was the fastest lap?(0 if the race didn't occur): ";
    in>>race.fastestLap;
    cout<<endl;
    cout<<"Enter the first chosen compound: ";
    in>>race.tire1;
    cout<<endl;
    cout<<"Enter the second chosen compound: ";
    in>>race.tire2;
    cout<<endl;
    cout<<"Enter the third chosen compound: ";
    in>>race.tire3;
    cout<<endl;
    cout<<"Enter circuit type: ";
    in>>race.circuitType;
    if(race.checkIfEmpty() == true){
      cout<<"Circuit name: ";
      string setname;
      double setlength;
      int setnrdrs;
      int setnrcorners;
      in>>setname;
      race.setName(setname);
      cout<<endl;
      cout<<"Circuit length(In kilometers): ";
      in>>setlength;
      race.setLength(setlength);
      cout<<endl;
      cout<<"Number of DRS Zones: ";
      in>>setnrdrs;
      race.setnumberOfDRSZones(setnrdrs);
      cout<<endl;
      cout<<"Number of Corners: ";
      in>>setnrcorners;
      race.setnumberOfCorners(setnrcorners);
    }

    return in;
 }



class EngineManufacturers
{
  string manufacturerName;
  double HP;
  int cc;
  public:
  EngineManufacturers () : HP(0.0), cc(0){}

  EngineManufacturers (string mnfname, double hp, int cylcap){
    manufacturerName = mnfname;
    HP = hp;
    cc = cylcap;
  }
  
};

class Driver{
 string name;
 int age;
 double weigth;
 double height;
 string nationality;
 DriverChampionship points;
 int driverPenaltyPoints;
 public:
 Driver() : age(0),weigth(0.0),height(0.0), driverPenaltyPoints(0){}
 
 Driver(string nm, int ag,double wei,double hei,string nat){
  name = nm;
  age = ag;
  weigth = wei;
  hei = height;
  nationality = nat;
 }
  void setDriverAge(int ag){
   try{
    if (ag < 18)
    throw customExceptionAge();
    else
    age = ag;
   }
   catch(customExceptionAge cea){
    if(ag < 0)
    {throw customExceptionNegative();}
    else{
    cout<<cea.what();
    }
  } 
  catch(customExceptionNegative cen){
    cout<<cen.what();
    
  }
  }
  Driver(DriverChampionship pnts){
    points = pnts;
  }
  
  Driver(int pnltypoints){
    driverPenaltyPoints = pnltypoints;
  }
 friend class Team;


};

class interfataCar{
 public:
 virtual bool checkLength(double length){
  if(length == 4.4){
    return true;
  }
  return false;
 }
 ~interfataCar(){
  cout<<"destructed"<<" ";
 }
 virtual bool checkCarName(string nm){
  if(nm !=" "){
    return true;
  }
  return false;
 }
};


class Car: public interfataCar {
    string name;
    double length;
    EngineManufacturers engine;
    string color;
    public:
    Car() :  length(0.0){}

    Car(string nm, double lngth, EngineManufacturers eng, string clr){
      if (checkCarName(nm) == true)
      name = nm;
      
      length = lngth;
      engine = eng;
      color = clr;
    } 
    Car(double ln){
      length = ln;
    }

    Car(EngineManufacturers eng){
      engine = eng;
    }
    bool checkLength()
    {
      if (length == 5.3){
        return true;
      }
      return false;
    }
    bool checkCarName(string nm){
      if (nm != ""){
        return true;
      }
      return false;

    }
  
  
};




class TeamPrincipal
{
  string name;
 
  protected:
   int age;
   double experience;
   TeamPrincipal (string nm, int ag,double exp){
    name = nm;
    experience = exp;
    age = ag;
  }
  
  public:
  TeamPrincipal() :name(" "),age(0),experience(0.0){}
 
  void setName(string nm){
    name = nm;
  }
  void setAge(int ag){
    age = ag;
  }
  void setExperience(double exp){
   experience = exp;
  }
  string getName(){
    return name;
  }
  int getAge(){
    return age;
  }
  double getExperience(){
    return experience;
  }
};

class interfaceSponsors
{
  public:
  virtual bool checkIfOk(string spns)
  {
    if(spns != " ")
    return true;
    return false;
  }
  virtual bool checkSize(int sz){
    if (sz !=0)
    return true;
    return false;
  }



  ~interfaceSponsors(){
    cout<<"destructed"<<" ";
  }
  
   
};


class Sponsors: public interfaceSponsors{
 vector<string> sponsors;
 
 public:
   bool checkIfOk(string spns)
  {
    if(spns != "")
    return true;
    return false;
  }
   virtual void addSponsors(string spns){
    if (checkIfOk(spns) == true)
    sponsors.push_back(spns);
   }
   
   void printSponsors(){
    for(int i  = 0 ;i < sponsors.size();i++){
      if (i != sponsors.size()-1)
      cout<<sponsors[i]<<", ";
      else cout<<sponsors[i];
    }
    cout<<endl;
   }
   bool checkSize(){
   if(sponsors.size() != 0)
    return true;
   return false;
   }
  void showSize(){
  
   cout<<sponsors.size();
  }
  
};


class Team: public TeamPrincipal, public ConstructorChampionship,public Sponsors
{ 
  string name;
  Driver driver1;
  Car    car1;
  Driver driver2;
  Car    car2;
  long int budget;



  public:
  Team () : budget(140000000){}

  Team(string nm, Driver d1, Car c1, Driver d2,Car c2,  string spns,long int bdg, int tmpnltypnts){
    name = nm;
    driver1 = d1;
    car1 = c1;
    driver2 = d2;
    car2 = c2;
    addSponsors(spns);
    budget = bdg;
    penaltyPoints = tmpnltypnts;
    
    

  }
  Team(string nam,int ag,int exp):TeamPrincipal(nam,ag,exp){
    
    
  }

  Team(Driver d2, Car c2)
  {
   if(driver1.age != 0){
   driver1 = driver2;
   car1 = car2;
   driver2 =d2;
   car2 =c2;
   }
   else{
    driver1 = d2;
    car1 = c2;
   }
     }
  

  Team(string spns){
    addSponsors(spns);
  }

  void addPenaltyPoints(int pnltypnts){
    penaltyPoints += pnltypnts;

  }

  void determineBudget(){
    int i;
    int penalty = 0;
    int penaltyPerPoint = 100000000;
    budget = 140000000;
    if(penaltyPoints >= 15)
  {
    penalty = penaltyPoints/15;
    penaltyPerPoint *= penalty;
  }
    
    budget -= penaltyPerPoint;
    }

   int getPoints(){
    return getTeamPoints();
   }
   
  friend class Driver;
};


 
int main()
{ 

  // Races race;
  // cin>>race;
  // cout<<race;
  // Team mercedes("Mihai",12,1);
  // mercedes.addSponsors("Pirelli");
  // mercedes.addSponsors("TeamViewer");
  // cout<<endl;
  // cout<<mercedes.getName()<<" "<<mercedes.getAge()<<" "<<mercedes.getExperience();
  // cout<<endl<<mercedes.getPoints();
  // cout<<endl;
  // mercedes.printSponsors();
  // cout<<endl;
  // Sponsors* spns = new Sponsors;
  // spns->addSponsors("asd");
  // spns->addSponsors("");
  // spns->printSponsors();
  // Car ferrari(5.3);
  // cout<<ferrari.checkLength();
  // cout<<endl;
  // interfataCar* interfata;
  // Car* haas = dynamic_cast<Car*>(interfata);
  Driver hamilton;
  hamilton.setDriverAge(-2);
  // DriverChampionship dc(-2);
    return 0;
}