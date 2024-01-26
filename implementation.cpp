#include "header.h"

Person::Person() : name(nullptr)
{
  this->secretNumber = rand() % 1000 + 1;
  this->isFinished = false;
}

Person::Person(const char *aName)
{                                           // Constructor with arguments
  this->name = new char[strlen(aName) + 1]; // Allocate separate memory for Person's name
  strcpy(this->name, aName);                // Copy characters from other name to Person's name
  this->isFinished = false;
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

Race::Race()
{
  secretNumber = rand() % 1000 + 1; // Generates random number between 1 and 1000
  hasStarted = false;               // Sets race to not started
  isFinished = false;               // Sets race to not finished
}

Race::~Race()
{
}

Snowmobiler::Snowmobiler(): Person(), name(nullptr)
{
  gasLevel = 100;
  distanceTraveled = 0;
}

Snowmobiler::Snowmobiler(const Snowmobiler &aSnowmobiler): Person(aSnowmobiler), name(nullptr)
{
  if(aSnowmobiler.name == nullptr) this->name = nullptr;
  else {
    this->name = new char[strlen(aSnowmobiler.name) + 1];
    strcpy(this->name, aSnowmobiler.name);
  }

}

Snowmobiler::Snowmobiler(const char * aName) {
  this->name = new char[strlen(aName) + 1]; // Allocate separate memory for Person's name
  strcpy(this->name, aName);                // Copy characters from other name to Person's name
  this->isFinished = false;
}

Snowmobiler Snowmobiler::operator=(const Snowmobiler &aSnowmobiler)
{
  if (aSnowmobiler.name == nullptr)
    this->name = nullptr; // If other person does not have a name set name to null
  else
  {
    this->name = new char[strlen(aSnowmobiler.name) + 1];
    strcpy(this->name, aSnowmobiler.name); // Otherwise set it to their name
  }
  this->gasLevel = aSnowmobiler.gasLevel;
  this->secretNumber = aSnowmobiler.secretNumber;
  return *this;
}

Snowmobiler::~Snowmobiler()
{
  if(this->name != nullptr) {
    delete [] name;
  }
}

const char *Snowmobiler::getName() const
{
  if (name == nullptr)
    return ""; // Doesn't seem necessary but if you std::cout a nullptr, the output stream will be disabled.
  else
    return name; // If name set return their name
}

Snowboarder::Snowboarder()
{
  this->name = "";
  this->next = nullptr;
}

Snowboarder::Snowboarder(const string aName)
{
  this->name = aName;
  this->next = nullptr;
}

Snowboarder::Snowboarder(const Snowboarder &aSnowboarder)
{
  this->name = aSnowboarder.name;
  this->next = nullptr;
}

Snowboarder::~Snowboarder()
{
}

const string Snowboarder::getName() const
{
  return name;
}

Snowboarder *Snowboarder::getNext()
{
  if(this->next) return this->next;
  else return nullptr;
}

void Snowboarder::setNext(Snowboarder *aSnowboarder) {
  this->next = aSnowboarder;
}

Skiier::Skiier()
{
  this->name = "";
  this->next = nullptr;
  this->prev = nullptr;
}

Skiier::Skiier(const string aName)
{
  this->name = aName;
  this->next = nullptr;
  this->prev = nullptr;
}

Skiier::Skiier(const Skiier &aSkiier)
{
  this->name = aSkiier.name;
  this->next = nullptr;
  this->prev = nullptr;
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

Skiier * Skiier::getPrev() {
  return this->prev;
}

void Skiier::setNext(Skiier * aSkiier) {
  this->next = aSkiier;
}

void Skiier::setPrev(Skiier * aSkiier) {
  this->prev = aSkiier;
}

MobileRace::MobileRace() : Race()
{
}

MobileRace::~MobileRace()
{
}

void MobileRace::addRacer(const char * aName) {
  racers.insert(racers.begin(), Snowmobiler(aName));
}

BoarderRace::BoarderRace()
{
  this->head = nullptr;
}

BoarderRace::~BoarderRace()
{
  Snowboarder *traverser, *forward = nullptr;
  if(head) {
    traverser = this->head;
    forward = this->head->getNext();
    while (traverser != nullptr)
    {
      delete traverser;
      traverser = forward;
      if(forward) forward = forward->getNext();
    }
  }
}

void BoarderRace::addSnowboarder(const char * aName) {
  if(!head) {
    this->head = new Snowboarder(aName);
  } else {
    Snowboarder *traverser = head;
    while (traverser->getNext() != nullptr)
    traverser = traverser->getNext();
    traverser->setNext(new Snowboarder(aName));
  }
}

SkiierRace::SkiierRace()
{
  this->head = nullptr;
}

SkiierRace::~SkiierRace()
{
  if(head) {
  
    if(this->head->getNext() == this->head) { // If head is only node
      delete this->head;
      return;
    } else if (this->head->getNext()->getNext() == this->head) { // If only 2 nodes
      delete this->head->getNext();
      delete this->head;
    } else { // If  3 or more nodes
    
    Skiier *temp, *current;
    current = head->getNext();
    
    while(current != head) {
      temp = current->getNext();
      delete current;
      current = temp;
    }

    delete this->head;
    this->head = nullptr;

  }
}
}

void SkiierRace::addSkiier(const string aName) {
  Skiier *aSkiier = new Skiier(aName);
  if(!head) {
    this->head = aSkiier;
    this->head->setPrev(this->head); // Points to itself to make circular
    this->head->setNext(this->head); 
  } else if (this->head->getNext() == this->head) { // If only head exists
      this->head->setNext(aSkiier);
      this->head->setPrev(aSkiier);
      aSkiier->setNext(this->head);
      aSkiier->setPrev(this->head);
  } else { // 2 or more nodes, will insert in between head and head's node right after
      aSkiier->setNext(this->head->getNext());
      aSkiier->setPrev(this->head);
      this->head->getNext()->setPrev(aSkiier); 
      this->head->setNext(aSkiier);
  }
}
