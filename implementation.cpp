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
  this->secretNumber = rand() % 1000 + 1;
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

Race::Race()
{
  secretNumber = rand() % 1000 + 1; // Generates random number between 1 and 1000
  hasStarted = false;               // Sets race to not started
  isFinished = false;               // Sets race to not finished
}

Race::~Race()
{
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
}

Snowboarder::Snowboarder(const string aName): Person()
{
  this->name = aName;
  this->next = nullptr;
  this->score = 0;
}

Snowboarder::Snowboarder(const Snowboarder &aSnowboarder): Person(aSnowboarder)
{
  this->name = aSnowboarder.name;
  this->score = aSnowboarder.score;
  this->next = nullptr;
}

Snowboarder Snowboarder::operator=(const Snowboarder &aSnowboarder)
{
  if(this == &aSnowboarder) return *this;
  this->secretNumber = aSnowboarder.secretNumber;
  this->isFinished = aSnowboarder.isFinished;
  this->score = aSnowboarder.score;
  this->name = aSnowboarder.name;
  this->next = nullptr; //  Due to volatile activities we will set next pointer to null and manually assign it rather than having this "deep" copy point to another Snowboarder that might not know about it
  return *this;
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

Skiier::Skiier(): Person()
{
  this->name = "";
  this->next = nullptr;
}

Skiier::Skiier(const string aName): Person()
{
  this->name = aName;
  this->next = nullptr;
}

Skiier::Skiier(const Skiier &aSkiier): Person(aSkiier)
{
  this->name = aSkiier.name;
  this->next = nullptr;
}

Skiier Skiier::operator=(const Skiier &aSkiier)
{
  if(this == &aSkiier) return *this;
  this->secretNumber = aSkiier.secretNumber;
  this->isFinished = aSkiier.isFinished;
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

void Skiier::setNext(Skiier * aSkiier) {
  this->next = aSkiier;
}

MobileRace::MobileRace() : Race()
{
}

MobileRace::~MobileRace()
{
}

bool MobileRace::addSnowmobiler(const char * aName) {
  if(aName == nullptr || (strncmp(aName, "", 10) == 0)) {
    cout << "Snowmobiler must have a name that is not empty.\n";
    return false;
  }
  racers.insert(racers.begin(), Snowmobiler(aName));
  return true;
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

bool BoarderRace::addSnowboarder(const string aName) {
  if(aName == "") {
    cout << "Snowboarder must have a name that is not empty.\n";
    return false;
  }
  if(!head) {
    this->head = new Snowboarder(aName);
  } else {
    Snowboarder *traverser = head;
    while (traverser->getNext() != nullptr)
    traverser = traverser->getNext();
    traverser->setNext(new Snowboarder(aName));
  }
  return true;
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

bool SkiierRace::addSkiier(const string aName) {
  if(aName == "") {
    cout << "Skiier must have a name that is not empty.\n";
    return false;
  }
  Skiier *aSkiier = new Skiier(aName);
  if(!head) {
    this->head = aSkiier;
    this->head->setNext(this->head); 
  } else if (this->head->getNext() == this->head) { // If only head exists
      this->head->setNext(aSkiier);
      aSkiier->setNext(this->head);
  } else { // 2 or more nodes, will insert in between head and head's node right after
      aSkiier->setNext(this->head->getNext());
      this->head->setNext(aSkiier);
  }
  return true;
}
