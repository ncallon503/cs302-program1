#include "header.h"

int main() {
  
  Snowboarder aSnowboarer0("test");

  Snowmobiler aSnowmobiler("testtest\n");

  cout << "the name: " << aSnowmobiler.getName() << "\n\n\n\n";

  MobileRace aRace;

  aRace.addRacer("test 123");

  BoarderRace aBoard;
  
  SkiierRace aSki;

  Skiier *aSkiier = new Skiier("a name");

  aSki.addSkiier("a skiier");
  aSki.addSkiier("a skiier2");
  aSki.addSkiier("a skiier3");

  //aSki.addSkiier("skiier1");

  Snowboarder aSnowboarder;


  // Skiier aSkiier("test");

  Skiier aSkiier2(*aSkiier);

  Skiier aSkiier3 = aSkiier2;

  cout << aSkiier2.getName() << "\n";

  cout << aSkiier3.getName() << "\n";

//  int test = rand() % 100 + 1;

  char *name = new char[5];
  strcpy(name, "test");

  Person aPerson(name);

  Person person2;

  delete [] name;

  delete aSkiier;

  return 0;
}

