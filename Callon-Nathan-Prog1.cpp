#include "header.h"

int main() {
  
  Snowboarder aSnowboarer0("test");

  MobileRace aRace;

  Snowboarder aSnowboarder;

  Snowmobiler aSnowmobiler;

  Skiier aSkiier("test");

  Skiier aSkiier2(aSkiier);

  Skiier aSkiier3 = aSkiier2;

  cout << aSkiier2.getName() << "\n";

  cout << aSkiier3.getName() << "\n";

//  int test = rand() % 100 + 1;

  char *name = new char[5];
  strcpy(name, "test");

  Person aPerson(name);

  Person person2;

  delete [] name;

  return 0;
}

