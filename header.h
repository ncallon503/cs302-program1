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
  int secretNumber;
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
  int accelerate(); // Changes the speed of the snowmobile depending on the number passed in
  int nitroBoost(); // Does a nitrous boost for long distance but can fail and stall the engine, disqualifying the Snowmobiler
  const bool isEngineStalled() const; // Returns whether or not the engine is stalled (disqualifying the Snowmobiler)
  const bool outOfGas() const; // Returns whether or not the gas level is below 15 (which deems the Snowmobiler out of gas), doesn't disqualify just means they are done progressing
protected:
private:
  int gasLevel;         // Keeps track of gas level of the snowmobile
  int distanceTraveled; // Keeps track of distance traveled of the snowmobile
  bool engineStalled;
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
  Snowboarder * getNext();                   // Retrieves the next snowboarder as they are attached through a LLL
  bool setNext(Snowboarder *aSnowboarder); // Sets the next snowboarder node
  int performTrick(int aNumber);            // Performs a trick returning a score based on the number passed in
  bool attemptKnockover(); // Attempts to knock over next racer in LLL-fashion
  bool setDisqualified();
  const bool getDisqualified() const; // Returns whether the racer is disqualified or not
  const int getScore() const; // Shows the score of the snowboarder

protected:
private:
  Snowboarder *next; // Next node to attach nodes throughout LLL
  int score;
  bool isDisqualified; // If a snowboarder successfully knocks this one over then this one is disqualified
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
  Skiier * getNext();             // Returns next Skiier from CLL
  bool setNext(Skiier * aSkiier); // Sets next Skiier node attached to this node

  int navigateTerrain(); // Navigates the mountain based on the RNG of the race track and unlike snowboarders' action, the Skiier can crash and disqualify itself
  bool attemptKnockover(); // Attempts to knock over next racer in CLL-fashion
  bool setDisqualified();
  const bool getDisqualified() const; // Returns whether the racer is disqualified or not
  const int getTime() const; // Time in which racer completed the race
protected:
  Skiier *next; // Next node to attach nodes through CLL
private:
  int timeCompleted; // The time in which the racer completed the race
  bool isDisqualified; // If a skiier successfully knocks this one over then this one is disqualified
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

  bool addSnowmobiler(const char * aName); // This is for adding snowmobilers to the race
  bool remove(const char * aName);
  bool removeAll();
  bool display();

  bool startRace();
  bool endRace();
  Snowmobiler determineWinner(); // Determines the winner based on the furthest distance traveled
protected:

private:
  vector<Snowmobiler> racers; // The snowmobile race will have the racers stored in a vector
};

class BoarderRace : public Race
{
public:
  BoarderRace(); // Default constructor will call parent constructor and have an empty head pointer of LLL of racers
  BoarderRace(const BoarderRace& aRace);
  BoarderRace operator=(const BoarderRace& aRace);
  ~BoarderRace(); // Dellocates the LLL of racers
 
  bool addSnowboarder(const string aName);
  bool remove(const string aName);
  bool removeAll();
  bool display();

  bool startRace();
  bool endRace();
  bool displayWinner(); // Determines the winner based on the highest score from tricks
protected:
  bool remove(const string aName, Snowboarder *curr, Snowboarder *temp);
  bool removeAll(Snowboarder *curr);
  bool display(Snowboarder *curr);
  Snowboarder * displayWinner(Snowboarder *curr, Snowboarder *winner); // Determines the winner based on the highest score from tricks

private:
  Snowboarder *head; // Head pointer to linear linked list of snowboarders
};

class SkiierRace : public Race
{
public:
  SkiierRace();                         // Default constructor will call parent constructor and have an empty head pointer of CLL of racers
  SkiierRace(const SkiierRace& aRace);
  SkiierRace operator=(const SkiierRace& aRace);
  ~SkiierRace();

  bool addSkiier(const string aName);
  bool remove(const string aName);
  bool removeAll();
  bool display();

  bool startRace();
  bool endRace();
  bool displayWinner(); // Determines a winner based on who finished first
protected:
  bool remove(const string aName, Skiier *curr, Skiier *temp);
  bool removeAll(Skiier *head);
  bool display(Skiier *curr);
  Skiier * displayWinner(Skiier *curr, Skiier *winner); 

private:
  Skiier *head; // Head pointer to circular linked list of skiiers
};

#endif // _SNOW_
