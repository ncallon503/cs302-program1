#include "header.h"

Person::Person(): name(nullptr) {
  this->secretNumber = rand() % 1000 + 1;
  this->isFinished = false;
}

Person::Person(const char *aName) { // Constructor with arguments
  this->name = new char[strlen(aName)+1]; //Allocate separate memory for Person's name
  strcpy(this->name, aName); //Copy characters from other name to Person's name
  this->isFinished = false;
}

Person::Person(const Person& aPerson) { // Deep copy constructor
  if(aPerson.name == nullptr) this->name = nullptr; // If other person does not have a name set name to null
  else 
  {
    this->name = new char[strlen(aPerson.name)+1];
    strcpy(this->name, aPerson.name); // Otherwise set it to their name
  }
  this->isFinished = aPerson.isFinished;
}

Person Person::operator=(const Person& aPerson) { // Equal overload
  if(aPerson.name == nullptr) this->name = nullptr; // If other person does not have a name set name to null
  else 
  {
    this->name = new char[strlen(aPerson.name)+1];
    strcpy(this->name, aPerson.name); // Otherwise set it to their name
  }
  this->isFinished = aPerson.isFinished;
  return *this;
}

Person::~Person() { // Destructor
  if(name) delete [] name; // If memory allocated for name delete name
  name = nullptr; // Remove pointer to memory
}

const char * Person::getName() const { // Getter for Person's name
  if(name == nullptr) return ""; // Doesn't seem necessary but if you std::cout a nullptr, the output stream will be disabled.
  else return name; // If name set return their name
}

void Person::setFinished() {
  isFinished = true;
}

const bool Person::getFinished() const {
  return isFinished;
}

Race::Race() {
  secretNumber = rand() % 1000 + 1; // Generates random number between 1 and 1000
  hasStarted = false; // Sets race to not started
  isFinished = false; // Sets race to not finished
}

Race::~Race() {
}

Snowmobiler::Snowmobiler(): Person() {
  gasLevel = 100;
  distanceTraveled = 0;
}

Snowmobiler::Snowmobiler(const Snowmobiler& aSnowmobiler): Person(aSnowmobiler) {
}

Snowmobiler Snowmobiler::operator=(const Snowmobiler& aSnowmobiler) {
  if(aSnowmobiler.name == nullptr) this->name = nullptr; // If other person does not have a name set name to null
  else 
  {
    this->name = new char[strlen(aSnowmobiler.name)+1];
    strcpy(this->name, aSnowmobiler.name); // Otherwise set it to their name
  }
  this->gasLevel = aSnowmobiler.gasLevel;
  this->secretNumber = aSnowmobiler.secretNumber;
  return *this;
}

Snowmobiler::~Snowmobiler() {
}

Snowboarder::Snowboarder(): {
  this->name = "";
  this->next = nullptr;
}

Snowboarder::Snowboarder(const char* aName): Person(aName) {
  this->name = aName;
  this->next = nullptr;
}

Snowboarder::Snowboarder(const Snowboarder& aSnowboarder): Person(aSnowboarder) {
  this->name = aSnowboarder.name;
  this->next= nullptr;
}

Snowboarder::~Snowboarder() {

}

const string Snowboarder::getName() {
  return name;
}

Snowboarder * Snowboarder::getNext() {
  return this->next;
}

Skiier::Skiier(): {
  this->name = "";
  this->next = nullptr;
  this->prev = nullptr;
}

Skiier::Skiier(const string aName): {
  this->name = aName;
  this->next = nullptr;
  this->prev = nullptr;
}

Skiier::Skiier(const Skiier& aSkiier): {
  this->name = aSkiier.name;
  this->next = nullptr;
  this->prev = nullptr;
}

Skiier::~Skiier() {

}

const string Skiier::getName() {
  return name;
}

MobileRace::MobileRace(): Race() {
}

MobileRace::MobileRace(const vector<Snowmobiler> snowmobilers): Race() {
  for(long unsigned int i = 0; i < snowmobilers.size(); i++)
    racers.insert(racers.begin(), snowmobilers[i]);
}

MobileRace::~MobileRace() {

}

BoarderRace::BoarderRace() {

}

BoarderRace::~BoarderRace() {
  Snowboarder *traverser, *forward = nullptr;
  traverser = this->head;
  forward = this->head->getNext();
  while(traverser != nullptr) {
    delete traverser;
    traverser = forward;
    forward = forward->getNext();
  }
}


