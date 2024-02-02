#include "Racers.h"

Person::Person() : name(nullptr)
{
  this->secretNumber = rand() % 100 + 1;
  this->isFinished = false;
}

Person::Person(const char *aName)
{                                           // Constructor with arguments
  this->name = new char[strlen(aName) + 1]; // Allocate separate memory for Person's name
  strcpy(this->name, aName);                // Copy characters from other name to Person's name
  this->isFinished = false;
  this->secretNumber = rand() % 100 + 1;
}

Person::Person(const Person &aPerson)
{ // Deep copy constructor
  if (aPerson.name == nullptr)
    this->name = nullptr; // If other person does not have a name set name to null
  else
  {
    this->name = new char[strlen(aPerson.name) + 1];
    strcpy(this->name, aPerson.name); // Otherwise set it to their name
  }
  this->isFinished = aPerson.isFinished;
  this->secretNumber = aPerson.secretNumber;
}

Person Person::operator=(const Person &aPerson)
{ // Equal overload
  if(this == &aPerson) return *this;
  if (aPerson.name == nullptr)
    this->name = nullptr; // If other person does not have a name set name to null
  else
  {
    delete [] this->name;
    this->name = new char[strlen(aPerson.name) + 1];
    strcpy(this->name, aPerson.name); // Otherwise set it to their name
  }
  this->isFinished = aPerson.isFinished;
  return *this;
}

Person::~Person()
{ // Destructor
  if (name) {
    delete [] name; // If memory allocated for name delete name
  name = nullptr;  // Remove pointer to memory
  }
}

const char *Person::getName() const
{ // Getter for Person's name
  if (name == nullptr)
    return ""; // Doesn't seem necessary but if you std::cout a nullptr, the output stream will be disabled.
  else
    return name; // If name set return their name
}

bool Person::setFinished()
{
  if(isFinished) {
    cout << this->name << " has already finished.\n";
    return false;
  } else {
    isFinished = true;
    return true;
  }
}

const bool Person::getFinished() const
{
  return isFinished;
}

Snowmobiler::Snowmobiler(): Person()
{
  this->name = nullptr;
  gasLevel = 100;
  distanceTraveled = 0;
}

Snowmobiler::Snowmobiler(const Snowmobiler &aSnowmobiler): Person(aSnowmobiler)
{
  if(aSnowmobiler.name == nullptr) this->name = nullptr;
  else {
    this->name = new char[strlen(aSnowmobiler.name) + 1];
    strcpy(this->name, aSnowmobiler.name);
  }
  gasLevel = aSnowmobiler.gasLevel;
  distanceTraveled = aSnowmobiler.distanceTraveled;
}

Snowmobiler::Snowmobiler(const char * aName): Person(aName)
{
  if (aName == nullptr)
    this->name = nullptr; // If other person does not have a name set name to null
  else
  {
    this->name = new char[strlen(aName) + 1];
    strcpy(this->name, aName); // Otherwise set it to their name
  }
  this->gasLevel = 100;
  this->distanceTraveled = 0;
}

Snowmobiler Snowmobiler::operator=(const Snowmobiler &aSnowmobiler)
{
  if (aSnowmobiler.name == nullptr)
    this->name = nullptr; // If other person does not have a name set name to null
  else
  {
    delete [] this->name;
    this->name = new char[strlen(aSnowmobiler.name) + 1];
    strcpy(this->name, aSnowmobiler.name); // Otherwise set it to their name
  }
  this->gasLevel = aSnowmobiler.gasLevel;
  this->secretNumber = aSnowmobiler.secretNumber;
  this->isFinished = aSnowmobiler.isFinished;
  return *this;
}

Snowmobiler::~Snowmobiler()
{
  if(this->name) { // Technically has a different name than Person()'s name because of Person's private scope, so we do still need to deallocate
    delete [] this->name;
    this->name = nullptr;
  }
}

int accelerate() {

  // If racer is out of gas
  if(outOfGas()) {
    cout << this->getName() << " is out of gas and has gone as far as they can.\n";
    return 0;
  }

  int randNumber = ((rand()  + secretNumber) % 500) + 1;

  // If racer's engine is stalled

  if(isEngineStalled()) {
    if(randNumber <= 250) {
    cout << this->getName() "'s engine is stalling and they are trying to fix it.\n";
    return 0;
    } else {
    this->setEngineStalled();
    cout << this->getName() << " has fixed their engine and is going again! Has traveled another " << randNumber / 2 << " meter.\n";
    distanceTraveled += randNumber / 2;
    return randNumber / 2;
    }
  }

  // Racer travelling at normal speeds

  if(randNumber <= 250) {
    cout << this->getName() << " is accelerating and just traveled " << randNumber << " meters!\n";
    distanceTraveled += randNumber;
    return randNumber;
  } else if (randNumber <= 430) { // Racer traveling extremely fast
    cout << this->getName() << " is traveling extremely fast and just went " << randNumber << " meters!\n";
    distanceTraveled += randNumber;
    return randNumber;
  } else if (randNumber <= 460) {
    cout << this->getName() << " is traveling so fast they've used their nitrous and gone 1.5x the distance at " << randNumber * 1.5 << " meters!\n";
    distanceTraveled += randNumber * 1.5;
    return randNumber * 1.5;
  } else {
    cout << this->getName() << " was going so fast that their nitrous and engine are now stalling.";
    setEngineStalled();
    return 0;
  }

}

const bool setEngineStalled() {
  if(this->engineStalled) {
    this->engineStalled = false;
    return false;
  }
  cout << this->getName() << "'s engine has stalled!\n";
  this->engineStalled = true;
  return true;
}

const bool isEngineStalled() {
  return engineStalled;
}

const bool outOfGas() {
  if(gasLevel <= 15) return true;
  else return false;
}

const char *Snowmobiler::getName() const
{
  if (name == nullptr)
    return ""; // Doesn't seem necessary but if you std::cout a nullptr, the output stream will be disabled.
  else
    return name; // If name set return their name
}

Snowboarder::Snowboarder(): Person()
{
  this->name = "";
  this->next = nullptr;
  this->score = 0;
  this->isDisqualified = false;
}

Snowboarder::Snowboarder(const string aName): Person()
{
  this->name = aName;
  this->next = nullptr;
  this->score = 0;
  this->isDisqualified = false;
}

Snowboarder::Snowboarder(const Snowboarder &aSnowboarder): Person(aSnowboarder)
{
  this->name = aSnowboarder.name;
  this->score = aSnowboarder.score;
  this->next = nullptr;
  this->isDisqualified = aSnowboarder.isDisqualified;
}

Snowboarder Snowboarder::operator=(const Snowboarder &aSnowboarder)
{
  if(this == &aSnowboarder) return *this;
  this->secretNumber = aSnowboarder.secretNumber;
  this->isFinished = aSnowboarder.isFinished;
  this->score = aSnowboarder.score;
  this->name = aSnowboarder.name;
  this->isDisqualified = aSnowboarder.isDisqualified;
  this->next = nullptr; //  Due to volatile activities we will set next pointer to null and manually assign it rather than having this "deep" copy point to another Snowboarder that might not know about it
  return *this;
}

Snowboarder::~Snowboarder()
{
}

int Snowboarder::performTrick() {
  if(this->isDisqualified) return 0;
  int randNumber = ((rand()  + secretNumber) % 100) + 1;
  if(randNumber <= 33)
    cout << this->getName() << " performed an Ollie for " << randNumber << " points!\n";
  else if (randNumber <= 67)
    cout << this->getName() << " performed a nose press for " << randNumber << " points!\n";
  else cout << this->getName() << " performed a tripod for " << randNumber << " points!\n";
  score += randNumber;
  return randNumber;
}

bool Snowboarder::attemptKnockover() {
  if(this->getNext() == nullptr) return false;
  if(this->getNext()->getDisqualified() == true) return false;
  int randNumber = ((rand() + secretNumber) % 100) + 1;
  if(randNumber <= 25) {
    this->getNext()->setDisqualified();
    cout << this->getName() << " has knocked down " << this->getNext()->getName() << " and disqualified them!\n";
    return true;
  } else {
    cout << this->getName() << " has attempted to knock down " << this->getNext()->getName() << " and failed!\n";
    return false;
  }
}

bool Snowboarder::setDisqualified() {
  if(this->isDisqualified == true) return false;
  this->isDisqualified = true;
  return true;
}

const bool Snowboarder::getDisqualified() {
  return this->isDisqualified;
}

const string Snowboarder::getName() const
{
  return name;
}

Snowboarder * Snowboarder::getNext()
{
  if(this->next) return this->next;
  else return nullptr;
}

bool Snowboarder::setNext(Snowboarder *aSnowboarder) {
  this->next = aSnowboarder;
  return true;
}

Skiier::Skiier(): Person()
{
  this->name = "";
  this->next = nullptr;
  this->timeCompleted = 0;
  this->isDisqualified = false;
}

Skiier::Skiier(const string aName): Person()
{
  this->name = aName;
  this->next = nullptr;
  this->timeCompleted = 0;
  this->isDisqualified = false;
}

Skiier::Skiier(const Skiier &aSkiier): Person(aSkiier)
{
  this->name = aSkiier.name;
  this->next = nullptr;
  this->timeCompleted = 0;
  this->isDisqualified = false;
}

Skiier Skiier::operator=(const Skiier &aSkiier)
{
  if(this == &aSkiier) return *this;
  this->secretNumber = aSkiier.secretNumber;
  this->isFinished = aSkiier.isFinished;
  this->timeCompleted = aSkiier.timeCompleted;
  this->isDisqualified = aSkiier.isDisqualified;
  this->name = aSkiier.name;
  this->next = nullptr; //  Due to volatile activities we will set next pointer to null and manually assign it rather than having this "deep" copy point to another Snowboarder that might not know about it
  return *this;
}


Skiier::~Skiier()
{
}

const string Skiier::getName() const
{
  return name;
}

Skiier * Skiier::getNext() {
  return this->next;
}

bool Skiier::setNext(Skiier * aSkiier) {
  this->next = aSkiier;
  return true;
}

const int Skiier::getTime() const {
  return timeCompleted;
}

bool Skiier::setDisqualified() {
  if(this->isDisqualified == true) return false;
  this->isDisqualified = true;
  return true;
}

const bool Skiier::getDisqualified() {
  return this->isDisqualified;
}


int Skiier::navigateTerrain(const string terrain) { // If the skiiers go too fast they crash, but are complimented if they make good time
  if(this->isDisqualified) return 0;
  int randNumber = ((rand()  + secretNumber) % 100) + 1;
  if(randNumber <= 13) {
    cout << this->getName() << " was going too fast and has crashed!\n";
    this->setDisqualified();
    return 0;
    }
  else if (randNumber <= 25) {
    cout << this->getName() << " has navigated the " << terrain << " in a whopping " << randNumber << " seconds!\n";
  } else {
    cout << this->getName() << " has navigated the " << terrain << " in " << randNumber << " seconds!\n";
  }
  this->timeCompleted += randNumber;
  return randNumber;
}

bool Skiier::attemptKnockover() {
  if(this->isDisqualified) return false;
  if(this->getNext() == this) {
    cout << "Can't knock over itself!\n";
    return false;
  }
  if(this->getNext() == nullptr) return false;
  if(this->getNext()->getDisqualified() == true) return false;
  int randNumber = ((rand() + secretNumber) % 100) + 1;
  if(randNumber <= 15) {
    this->getNext()->setDisqualified();
    cout << this->getName() << " has knocked down " << this->getNext()->getName() << " and disqualified them!\n";
    return true;
  } else {
    cout << this->getName() << " has attempted to knock down " << this->getNext()->getName() << " and failed!\n";
    return false;
  }

}
