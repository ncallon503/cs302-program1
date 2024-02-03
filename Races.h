/* For the Race class, all the races are handled very differently but do share the similar booleans of
hasStarted and isFinished which they inherit from the parent class. The MobileRace represents the Snowmobiler
race and contains a vector of Snowmobilers it manages, the BoarderRace represents the Snowboarder race and 
contains a LLL of Snowboarders, and the SkiierRace contains a CLL of Skiiers. */

#ifndef _RACES_
#define _RACES_

#include "Racers.h"

using namespace std;

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
  bool displayWinner(); // Determines the winner based on the furthest distance traveled
protected:
  const int accelerate();


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
  bool displayWinner(); // Determines the winner based on the highest score from tricks
protected:
  bool remove(const string aName, Snowboarder *curr, Snowboarder *temp);
  bool removeAll(Snowboarder *curr);
  bool display(Snowboarder *curr);
  int performTrick(Snowboarder *curr); // Makes all snowboarders perform a trick and returns total score of all added up
  bool attemptKnockover(Snowboarder *curr); // Makes all snowboarders attempt to knock down the one in front of them (brutal I know) and returns true or false if someone was knocked over
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
  bool displayWinner(); // Determines a winner based on who finished first
protected:
  bool remove(const string aName, Skiier *curr, Skiier *temp);
  bool removeAll(Skiier *head);
  bool display(Skiier *curr);
  int navigateTerrain(Skiier *curr, const string terrain);
  bool attemptKnockover(Skiier *curr);
  Skiier * displayWinner(Skiier *curr, Skiier *winner); 
  Skiier * firstNonDisqualified(Skiier *curr);

private:
  Skiier *head; // Head pointer to circular linked list of skiiers
};

#endif // _RACES_
