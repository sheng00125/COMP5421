#include "SlotMachine.hpp"

SlotMachine::SlotMachine()
{
  
}

void SlotMachine::run()
{
  int current_tokens {10};
  
  while ( current_tokens > 0 )
    {
      std::cout << "How much would you like to bet (enter 0 to quit)? ";

      for (int k = 0; k < 3; ++k) {
	int n { rand() % 4 };
	int w { rand() % 26 + 1 };

	if ( n == 0)
	  reel[k].reset(new Rhombus( w ));
	else if ( n == 1)
	  reel[k].reset(new AcuteTriangle( w ));
	else if ( n == 2)
	  reel[k].reset(new RightTriangle( w ));
	else {
	  int h { rand() % 26 + 1 };
	  reel[k].reset(new Rectangle( w , k ));
	}
	
      }

      Grid box_0 = reel[0]->draw();
      Grid box_1 = reel[0]->draw();
      Grid box_2 = reel[0]->draw();
      
    }
}
