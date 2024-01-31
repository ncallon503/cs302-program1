#include "header.h"

int main() {

  string input = "-1";

  cout << "\nWelcome to the Winter Olympics! Which race would you like to spectate today?\n";
  
  while((input != "1") && (input != "2") && (input != "3") && (input != "0"))
  {
    cout << "Please enter one of the correct following options.\n\n";
    cout << "1. The Yearly Snowmobiler Distance Competition\n" << 
    "2. The Seasonal Snowboarder Showoff\n" << 
    "3. The exciting Skiier Race and Obstacle Course\n" <<
    "0. I'd rather relax in the cabins (Exit)\n\n";

    cin >> input;
  }

  while(input != "0") {

    switch(stoi(input)) {
      case 1: {

        MobileRace * theMobileRace = new MobileRace();
        theMobileRace->addSnowmobiler("Johnny Test");
        theMobileRace->addSnowmobiler("Bear Grylls");
        theMobileRace->addSnowmobiler("Gordon Ramsay");
        theMobileRace->addSnowmobiler("Billy Butcher");
        theMobileRace->addSnowmobiler("Mark Grayson");
        theMobileRace->addSnowmobiler("Nolan Grayson");
        theMobileRace->addSnowmobiler("Clark Kent");
        theMobileRace->addSnowmobiler("John Gillman");

        cout << "Welcome to the Yearly Snowmobiler Distance Competition! Our contestants are:\n";
        theMobileRace->display();
       
        //theMobileRace.startRace();

        delete theMobileRace;
        theMobileRace = nullptr;
      
        break;
      }

      case 2: {

        break;
      }

      case 3: {

        break;
      }

      case 0: {

        break;
      }

      default: {

        break;
      }

    }

    cout << "\nThank you for watching. Would you like to watch another event today?\n";
  
    input = "-1";
    while((input != "1") && (input != "2") && (input != "3") && (input != "0"))
    {
      cout << "Please enter one of the following options.\n\n";
      cout << "1. The Yearly Snowmobiler Distance Competition\n" << 
      "2. The Seasonal Snowboarder Showoff\n" << 
      "3. The exciting Skiier Race and Obstacle Course\n" <<
      "0. I'd rather relax in the cabins (Exit)\n\n";

      cin >> input;
    }

  }

  cout << "Thank you for attending our Winter Sporting Events!\n";

  Skiier testSkiier;
  Skiier testSkiier2 = testSkiier;

  Snowboarder testSnowboarder("testSnowboarder");
  Snowboarder testSnowboarder2 = testSnowboarder;

  cout << testSnowboarder2.getName() << "\n";
  
  Snowboarder aSnowboarer0("test");

  Snowmobiler aSnowmobiler("testtest\n");
  Snowmobiler Snowmobiler2 = aSnowmobiler;

  cout << "the name: " << aSnowmobiler.getName() << "\n\n\n\n";

  MobileRace aRace;

  aRace.addSnowmobiler("test 123");
  aRace.addSnowmobiler("a snowmobiler1");
  aRace.addSnowmobiler("a snowmobiler2");
  aRace.addSnowmobiler("a snowmobiler3");
  aRace.addSnowmobiler("a snowmobiler4");

  aRace.remove("bla");
  aRace.remove("a snowmobiler1");

  BoarderRace aBoard;
  
  SkiierRace aSki;

  Skiier *aSkiier = new Skiier("a name");

  aSki.addSkiier("a skiier");
  aSki.addSkiier("a skiier2");
  aSki.addSkiier("a skiier3");
  aSki.addSkiier("a skiier4");
  aSki.addSkiier("a skiier5");
  aSki.addSkiier("a skiier6");

  aBoard.addSnowboarder("a boarder");
  aBoard.addSnowboarder("a boarder1");
  aBoard.addSnowboarder("a boarder2");
  aBoard.addSnowboarder("a boarder3");
  aBoard.addSnowboarder("a boarder4");
  aBoard.addSnowboarder("a boarder5");

  aSki.remove("a skiier2");

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

