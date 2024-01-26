/* Nathan Callon, CS302, Karla Fant, 1/19/2024
In this program I'll be constructing races using 2 different parent classes and 3 different
child classes for each base class. The parent classes will not be instantiated in the main program
but the children will, and this will help reduce redundancy in the code. The races will be
separated into Snowmobilers, Snowboarders and Skiiers.*/

#ifndef _SNOW_
#define _SNOW_

#include <iostream>
#include <cstring>
#include <vector>
#include <stdlib.h>

using namespace std;

/* The Person class is the parent class for the
snowboarders, snowmobilers and skiiers, and it includes
functions that all of them will share and some of which may be overwritten. */
class Person
{ // Parent class for all types of participants
public:
  Person();                                // Base constructor
  Person(const char *aName);               // Constructor with arguments
  Person(const Person &aPerson);           // Deep copy constructor
  Person operator=(const Person &aPerson); // Copy aPerson into itself with new allocated memory
  ~Person();                               // Destructor

  const char *getName() const;    // Return name of participant
  bool setFinished();             // Declare that the racer has finished the race
  const bool getFinished() const; // Return whether or not the racer has finished the race
protected:
  int secretNumber; // Secret number to use RNG to determine how the racer acts
  bool isFinished;  // Keeps track of whether the racer has finished
private:
  char *name; // Stores name of participant
};

class Snowmobiler : public Person
{
public:
  Snowmobiler();
  Snowmobiler(const char *aName);
  Snowmobiler(const Snowmobiler &aSnowmobiler);
  Snowmobiler operator=(const Snowmobiler &aSnowmobiler);
  ~Snowmobiler();

  const char *getName() const;              // Return name of participant
  void changeSpeed(const int secretNumber); // Changes the speed of the snowmobile depending on the number passed in
protected:
private:
  int gasLevel;         // Keeps track of gas level of the snowmobile
  int distanceTraveled; // Keeps track of distance traveled of the snowmobile
  char *name;
};

class Snowboarder : public Person
{
public:
  Snowboarder();
  Snowboarder(const string aName);
  Snowboarder(const Snowboarder &aSnowboarder);
  Snowboarder operator=(const Snowboarder &aSnowboarder);
  ~Snowboarder();

  const string getName() const;
  Snowboarder *getNext();                   // Retrieves the next snowboarder as they are attached through a LLL
  void setNext(Snowboarder *aSnowboarder); // Sets the next snowboarder node
  int performTrick(int aNumber);            // Performs a trick returning a score based on the number passed in
protected:
private:
  Snowboarder *next; // Next node to attach nodes throughout LLL
  string name;
};

class Skiier : public Person
{
public:
  Skiier();
  Skiier(const string aName);
  Skiier(const Skiier &aSkiier);
  Skiier operator=(const Skiier &aSkiier);
  ~Skiier();

  const string getName() const;  // Return name of participant
  Skiier *getNext();             // Returns next Skiier from CLL
  void setNext(Skiier *aSkiier); // Sets next Skiier node attached to this node
  Skiier *getPrev();             // Returns previous Skiier from CLL
  void setPrev(Skiier *aSkiier); // Sets previous Skiier node attached to this node
protected:
  Skiier *next; // Next node to attach nodes through CLL
  Skiier *prev; // Previous node to attach nodes through CLL
private:
  string name;
};

/* Like the parent Person class not being instantiated, the same will
happen with this parent Race class which has three derived classes
for each type of race, each of which will be used in the program */
class Race
{
public:
  Race(); // Default constructor will construct a race that has no racers and has not started,
  // has not ended, and generates a random number to determine how the racers act
  ~Race();

protected:
  int secretNumber; // This secret number will determine how contestants interact in the event
  // When combined with their own secret numbers
  bool hasStarted; // This determines whether the race has begun or not
  bool isFinished; // This determines whether the race is finished or not
private:
};

class MobileRace : public Race
{
public:
  MobileRace();                                       // Default constructor will call parent constructor and initialize empty vector of racers
  ~MobileRace();

  void addRacer(const char * aName); // This is for adding snowmobilers to the race

  bool startRace();
  bool endRace();
  Person determineWinner(); // Determines the winner based on the furthest distance traveled
protected:
  vector<Snowmobiler> racers; // The snowmobile race will have the racers stored in a vector

private:
};

class BoarderRace : public Race
{
public:
  BoarderRace(); // Default constructor will call parent constructor and have an empty head pointer of LLL of racers
  ~BoarderRace(); // Dellocates the LLL of racers
 
  void addSnowboarder(const char *aName);

  bool startRace();
  bool endRace();
  Person determineWinner(); // Determines the winner based on the highest score from tricks
protected:
  Snowboarder *head; // Head pointer to linear linked list of snowboarders

private:
};

class SkiierRace : public Race
{
public:
  SkiierRace();                         // Default constructor will call parent constructor and have an empty head pointer of CLL of racers
  ~SkiierRace();

  void addSkiier(const string aName);

  bool startRace();
  bool endRace();
  Person determineWinner(); // Determines a winner based on who finished first
protected:
  Skiier *head; // Head pointer to circular linked list of skiiers

private:
};

#endif // _SNOW_
