#include "Racers.h"
#include "Races.h"

int main() {

  srand(time(0)); // Seeds the random number generator

  string input = "-1";
  bool raceWatched = false;

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

  MobileRace * theMobileRace = nullptr;
  BoarderRace * theBoarderRace = nullptr;
  SkiierRace * theSkiierRace = nullptr;

  while(input != "0") {

    switch(stoi(input)) {
      case 1: {

        theMobileRace = new MobileRace();
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
       
        theMobileRace->startRace();

        delete theMobileRace;
        theMobileRace = nullptr;

        raceWatched = true;
      
        break;
      }

      case 2: {

        theBoarderRace = new BoarderRace();
        theBoarderRace->addSnowboarder("Mark Cuban");
        theBoarderRace->addSnowboarder("LeBron James");
        theBoarderRace->addSnowboarder("Kevin Durant");
        theBoarderRace->addSnowboarder("Steph Curry");
        theBoarderRace->addSnowboarder("Kobe Bryant");
        theBoarderRace->addSnowboarder("Robin");
        theBoarderRace->addSnowboarder("Batman");
        theBoarderRace->addSnowboarder("Raven");

        cout << "Welcome to the Seasonal Snowboarder Showoff! Our contestants are:\n";
        theBoarderRace->display(); 
       
        theBoarderRace->startRace();

        delete theBoarderRace;
        theBoarderRace = nullptr;

        raceWatched = true;

        break;
      }

      case 3: {

        theSkiierRace = new SkiierRace();
        theSkiierRace->addSkiier("Harley Quinn");
        theSkiierRace->addSkiier("Joker");
        theSkiierRace->addSkiier("Pikachu");
        theSkiierRace->addSkiier("Mario");
        theSkiierRace->addSkiier("Pac-Man");
        theSkiierRace->addSkiier("Sonic");
        theSkiierRace->addSkiier("Bowser");
        theSkiierRace->addSkiier("Luigi");

        cout << "Welcome to the Skiier Race and Obstacle Course! Our contestants are:\n";
        theSkiierRace->display();
       
        theSkiierRace->startRace();

        delete theSkiierRace;
        theSkiierRace = nullptr;

        raceWatched = true;

        break;
      }

      case 0: {

        if(!raceWatched) cout << "Leaving that soon? Well, see you next time!\n";
        else cout << "Hope you enjoyed and come back next year!";

        break;
      }

      default: {

        cout << "Input not recognized.\n";

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

  return 0;

}

