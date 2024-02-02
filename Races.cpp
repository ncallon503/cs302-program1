#include "Races.h"

Race::Race()
{
  hasStarted = false;               // Sets race to not started
  isFinished = false;               // Sets race to not finished
}

Race::~Race()
{
}

MobileRace::MobileRace() : Race()
{
}

MobileRace::~MobileRace()
{
  removeAll();
}

bool MobileRace::addSnowmobiler(const char * aName) {
  if(aName == nullptr || (strncmp(aName, "", 10) == 0)) {
    cout << "Snowmobiler must have a name that is not empty.\n";
    return false;
  }
  racers.insert(racers.begin(), Snowmobiler(aName));
  return true;
}


bool MobileRace::remove(const char * aName) {
  int indexToRemove = -1;
  for(long unsigned int i = 0; i < racers.size(); i++) {
    if(strcmp(racers[i].getName(), aName) == 0) indexToRemove = i;
  }
  if(indexToRemove == -1) {
    cout << "Snowboarder not found to remove.\n";
    return false;
  }
  racers.erase(racers.begin() + indexToRemove);
  return true;
}

bool MobileRace::removeAll() {
  if(racers.size() == 0) return false;
  racers.clear();
  return true;
}

bool MobileRace::display() {
  if(racers.size() == 0) return false;
  for(long unsigned int i = 0; i < racers.size(); i++)
    cout << "Welcome Snowmobiler " << racers[i].getName() << "!\n";
  return true;
}


BoarderRace::BoarderRace()
{
  this->head = nullptr;
}

BoarderRace::~BoarderRace()
{
  removeAll();
}

bool BoarderRace::startRace() {
  if (hasStarted) {
    cout << "Race has already started.\n";
    return false;
  }
  if(!head) {
    cout << "No racers to start with.\n";
    return false;
  }

  hasStarted = true;
  
  cout << "The race has begun!" << "\n";
  cout << "\n";

  // First phase

  this->performTrick(head);
  cout << "\n";

  // Second phase

  this->attemptKnockover(head);
  cout << "\n";

  // Third phase

  this->performTrick(head);
  cout << "\n";

  // Fourth phase

  this->attemptKnockover(head);
  cout << "\n";

  // Fifth phase

  this->performTrick(head);
  cout << "\n";

  this->displayWinner();
  cout << "\n";

  isFinished = true;

  return true;
}

int BoarderRace::performTrick(Snowboarder *curr) {
  if(!head || !curr) return 0;
  return curr->performTrick() + this->performTrick(curr->getNext());
}

bool BoarderRace::attemptKnockover(Snowboarder *curr) {
  if(!curr) return true;
  curr->attemptKnockover();
  return this->attemptKnockover(curr->getNext());
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

bool BoarderRace::remove(const string aName) {
  return remove(aName, this->head, this->head->getNext());
}

bool BoarderRace::remove(const string aName, Snowboarder *curr, Snowboarder *temp) {
  if(!head) return false; // No head node
  if(temp == head) {
    if(curr->getName() == aName) { // Head is only node
      delete head;
      head = nullptr;
      return true;
    } else return false;
  }
if(temp->getName() == aName)
  {
    curr->setNext(temp->getNext());
    delete temp;
    return true;
  }
  return remove(aName, curr->getNext(), temp->getNext());
}

bool BoarderRace::removeAll() {
  return removeAll(head);
}

bool BoarderRace::removeAll(Snowboarder *curr) {
  if(!head) return true;
  if(!curr) return true;
  Snowboarder *tmp = curr;
  curr = curr->getNext();
  delete tmp;
  return removeAll(curr);
}

bool BoarderRace::display() {
  return display(head);
}

bool BoarderRace::display(Snowboarder *head) {
  if(!head) return true;
  cout << "Welcome Snowboarder " << head->getName() << "!\n";
  return display(head->getNext());
}

bool BoarderRace::displayWinner() {
  if(!head) return false;
  Snowboarder *winner = displayWinner(head, head);
  cout << "\nThe winner of the Snowboarder Competition is " << winner->getName() << " with a score " <<
  "of " << winner->getScore() << "!\n";
  return true;
}

Snowboarder * BoarderRace::displayWinner(Snowboarder *curr, Snowboarder *winner) {
  if(!curr) return winner;
  if(curr->getScore() >= winner->getScore() && !curr->getDisqualified()) winner = curr;
  return displayWinner(curr->getNext(), winner);
}

const int Snowboarder::getScore() const {
  return score;
}

SkiierRace::SkiierRace()
{
  this->head = nullptr;
}

SkiierRace::~SkiierRace()
{
  this->removeAll();
}

bool SkiierRace::startRace() {
  if (hasStarted) {
    cout << "Race has already started.\n";
    return false;
  }
  if(!head) {
    cout << "No racers to start with.\n";
    return false;
  }

  hasStarted = true;
  
  cout << "The race has begun!" << "\n";
  cout << "\n";

  // First phase

  this->navigateTerrain(head->getNext(), "snowy hillside");
  cout << "\n";

  // Second phase

  this->attemptKnockover(head->getNext());
  cout << "\n";

  // Third phase

  this->navigateTerrain(head->getNext(), "winding alpines");
  cout << "\n";

  // Fourth phase

  this->attemptKnockover(head->getNext());
  cout << "\n";

  // Fifth phase

  this->navigateTerrain(head->getNext(), "rocky finish line");
  cout << "\n";

  this->displayWinner();
  cout << "\n";

  isFinished = true;

  return true;
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

bool SkiierRace::remove(const string aName) {
  return remove(aName, this->head, this->head->getNext());
}

bool SkiierRace::remove(const string aName, Skiier *curr, Skiier *temp) {
  if(!head) return false; // No head node
  if(temp == head) {
    if(curr->getName() == aName) { // Head is only node
      delete head;
      head = nullptr;
      return true;
    } else return false;
  }
  if(temp->getName() == aName)
    {
      curr->setNext(temp->getNext());
      delete temp;
      return true;
    }
  return remove(aName, curr->getNext(), temp->getNext());
}

bool SkiierRace::removeAll() {
  removeAll(head);
  head = nullptr;
  return true;
}

bool SkiierRace::removeAll(Skiier *head) {
  if(!head) return true; // no head
  if(head->getNext() == head) { // head points to itself
    delete head;
    head = nullptr;
    return true;
  }
  Skiier *curr = head->getNext(); // Set to next of head, not head if 2 nodes, to not delete the tail (itself)
  head->setNext(head->getNext()->getNext());
  delete curr;
  return removeAll(head);
}

bool SkiierRace::display() {
  if(!head) return false;
  return display(head);
}

bool SkiierRace::display(Skiier *curr) {
  if(!head) return false; // base case 1
  if(curr->getNext() == head) { //base case 2
    cout << "Welcome Skiier " << curr->getName() << "!\n";
    return true;
  }
  cout << "Welcome Skiier " << curr->getName() << "!\n";
  return display(curr->getNext());
}

bool SkiierRace::displayWinner() {
  if(!head) return false;
  Skiier *firstNon =  firstNonDisqualified(head->getNext());
  Skiier *winner = displayWinner(head->getNext(), firstNon);
  cout << "\nThe winner of the Skiier Race and Obstacle Course is " << winner->getName() << winner->getDisqualified() << " with a time finished of " <<
  "of " << winner->getTime() << " seconds!\n";
  return true;

}

Skiier *SkiierRace::displayWinner(Skiier *curr, Skiier *winner) {
  if(curr == head) { // final case to end
    if((curr->getTime() <= winner->getTime()) && (curr->getDisqualified() == false)) 
      curr = winner;
    return winner;
  }
  if(curr->getDisqualified()) return displayWinner(curr->getNext(), winner);
  if((curr->getTime() <= winner->getTime()) && (curr->getDisqualified() == false)) winner = curr;
  return displayWinner(curr->getNext(), winner);
}

int SkiierRace::navigateTerrain(Skiier *curr, const string terrain) { // Returns the accumulated amount of seconds from all racers
  if(!head || !curr) return 0;
  if(curr == head) return curr->navigateTerrain(terrain); // Base case
  return curr->navigateTerrain(terrain) + this->navigateTerrain(curr->getNext(), terrain);
}

bool SkiierRace::attemptKnockover(Skiier *curr) {
  if(!head) return false;
  curr->attemptKnockover(); // Circular linked list will attempt regardless
  if(curr == head) return true; // Returns after, so head gets a turn
  return this->attemptKnockover(curr->getNext());
}

Skiier * SkiierRace::firstNonDisqualified(Skiier *curr) { // Needed so the race doesn't bug due to CLL and set head->getNext() as default winner despite them being disqualified
  if(curr->getDisqualified()) return firstNonDisqualified(curr->getNext());
  else return curr;
}
