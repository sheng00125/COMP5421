#include "SlotMachine.hpp"

void SlotMachine::run(int initial_tokens)
{
  int current_tokens {initial_tokens};

  std::cout << "\nWelcome to 3-Reel Lucky Slot Machine Game!" << std::endl;
  std::cout << "Each reel will randomly display one of four shapes, each in 25 sizes. " << std::endl;
  std::cout << "To win 3 x bet, get 2 similar shapes AND 2 shapes with equal Scr Areas" << std::endl;
  std::cout << "To win 2 x bet, get 3 similar shapes" << std::endl;
  std::cout << "To win 1 x bet, get (Middle) Scr Area > ( Left + Right ) Scr Areas" << std::endl;
  std::cout << "To win or lose  nothing, get same Left and Right shapes" << std::endl;
  std::cout << "Otherwise, you lose your bet." << std::endl;
  std::cout << "You start with " << current_tokens << " free slot tokens !" << std::endl;

  
  while ( current_tokens > 0 )
    {
      std::string bad_data;

      int bet {0};
      std::cout << "\nHow much would you like to bet (enter 0 to quit)? ";
      std::cin >> bet;

      if ( bet > current_tokens ) {
	std::cout << "You can't bet more than " << current_tokens  << ", try again!" << std::endl;
	std::cin.setstate(std::ios_base::failbit);
      }

      while(! std::cin || bet > current_tokens) {
	std::cin.clear();
	std::getline(std::cin, bad_data);
	std::cout << "\nHow much would you like to bet (enter 0 to quit)? ";
	std::cin >> bet;

	if ( bet > current_tokens )
	    std::cout << "You can't bet more than " << current_tokens  << ", try again!" << std::endl;
      }
      
      std::getline(std::cin, bad_data);

      if (bet == 0)
	return ; // exit the program.

      make_shapes();
  
      Grid box_0 = reel[0]->draw();
      Grid box_1 = reel[1]->draw();
      Grid box_2 = reel[2]->draw();

      // begin printing the shapes *********************************************
      std::cout << "+-" << std::string(box_0.front().size(), '-') << "-+-" << std::string(box_1.front().size(), '-') << "-+-" << std::string(box_2.front().size(), '-') << + "-+\n" ;

      for (int i = 0 ; i < std::max( {box_0.size(), box_1.size(), box_2.size()} ); ++i) {

	std::cout << "| ";
	
	for ( const Grid& box : { box_0, box_1, box_2 } ) {
	  
	  if ( i >= box.size() )
	    {
	      std::cout << std::string(box.front().size(), ' ') << " | " ;
	      continue;
	    }
	  
	  for ( auto ite = box[i].begin() ; ite != box[i].end() ; ++ite)
	    {
	      std::cout << *ite ;
	    }
	  
	  std::cout << " | ";
	  
	}
      
	std::cout << std::endl; 
      
      }

      std::cout << "+-" << std::string(box_0.front().size(), '-') << "-+-" << std::string(box_1.front().size(), '-') << "-+-" << std::string(box_2.front().size(), '-') << + "-+\n" ;
      // finish printing the shapes *************************************************
      
      for ( auto const& shape: reel )
	std::cout << "(" << (*shape).getName() << ", " << (*shape).getBoundingBoxWidth() << ", " << (*shape).getBoundingBoxHeight() << ") "; std::cout << std::endl;

      // build a hashtable to serve as counter.
      std::map<std::string, int> namecount;
      std::map<int, int> sizecount;
      for (auto const& shape : reel) {
	namecount[(*shape).getName()] = namecount.count((*shape).getName()) == 1 ? namecount[(*shape).getName()] + 1 : 1;
	sizecount[(*shape).computeScreenArea()] = sizecount.count((*shape).computeScreenArea()) == 1 ? sizecount[(*shape).computeScreenArea()] + 1 : 1;
      }

      bool won = false;
      //case1
      if ( won ) continue;
      for (auto const& name: namecount ) {
	if ( name.second == 2) {
	  for (auto const& size : sizecount ) {
	    if ( size.second == 2 ) {
	      won = true;
	      current_tokens += bet * 3;
	      std::cout << "Jackpot! 2 Similar Shapes AND 2 Equal Screen Areas!" <<std::endl;
	      std::cout << "Congratulations! you win 3 times your bet: " <<  bet * 3 << std::endl;
	      std::cout << "You now have " << current_tokens << " tokens." << std::endl;
	    }
	  }
	} 
      }

      //case 2
      if ( won ) continue;
      for ( auto const& name: namecount ) {
	if ( name.second == 3 ) {
	  won = true;
	  current_tokens += bet * 2;
	  std::cout << "Three similar shapes" <<std::endl;
	  std::cout << "Congratulations! you win 2 times your bet: " <<  bet * 2 << std::endl;
	  std::cout << "You now have " << current_tokens << " tokens."  << std::endl;
	}
      }
      
      // case 3
      if ( won ) continue;
      if ( reel[1]->computeScreenArea() > ( reel[0]->computeScreenArea() + reel[2]->computeScreenArea() ) ) {
	won = true;
	current_tokens += bet * 1;
	std::cout << "Middle > Left + Right, in Screen Areas" <<std::endl;
	std::cout << "Congratulations! you win your bet: " << bet << std::endl;
	std::cout << "You now have " << current_tokens << " tokens." << std::endl;
      }

      // case 4
      if ( won ) continue;
      if ( reel[0]->getName() == reel[2]->getName() ) {
	won = true;
	std::cout << "Lucky this time! " <<std::endl;
	std::cout << "You don't win, you don't lose, your safe!" << std::endl;
	std::cout << "You now have " << current_tokens << " tokens." << std::endl;
      }

      if ( won ) continue;
      current_tokens -= bet;
      std::cout << "Oh No!" << std::endl;
      std::cout << "You lose your bet" << std::endl;
      std::cout << "You now have " << current_tokens << " tokens." << std::endl;

      if ( current_tokens == 0 )  {
	std::cout << "You just ran out of tokens. Better luck next time!" << std::endl;
	std::cout << "Game Over.\n";
      }
      
    }
  
}

void SlotMachine::make_shapes()
{
  for (int k = 0; k < 3; ++k)
    make_shape(k);
}

void SlotMachine::make_shape(int k)
{
  int n { rand() % 4 };
  int w { rand() % 26 + 1 };
  
  if ( n == 0)
    reel[k].reset(new Rhombus( w ));
  else if ( n == 1 )
    reel[k].reset(new AcuteTriangle( w ));
  else if ( n == 2 )
    reel[k].reset(new RightTriangle( w ));
  else {
    int h { rand() % 26 + 1 };
    reel[k].reset(new Rectangle( w , h ));
  }
  
}

void SlotMachine::display()
{
  
}
