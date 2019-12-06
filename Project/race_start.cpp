#include "before.hpp"
#include <time.h>
#include <stdlib.h>

void race_start()
{
	//show snail data
	srand(time(0));
	for (int i = 0; i < 5; i++)
	{
		/* Make Snail Info */

		int weight = (rand() % 20) + 1; // 1kg ~ 20kg
		int age = (rand() % 5) + 1; // 1years  ~ 5 years
		int minSpeed = (rand() % 100) + 1; // 1 ~ 100
		int maxSpeed = (rand() % (100 - minSpeed)) + minSpeed; // minSpeed ~ 100
		int character = (rand() % 5) + 1;   // 1 ~ 5
		Snail* babySnail = new Snail(weight, age, minSpeed, maxSpeed, character);
		snail.push_back(babySnail);
	}

	//bet
	for (int i = 0; i < snail.size(); i++) {
		cout << i + 1 << "번 달팽이" << endl;
		cout << "나이 : " << snail[i]->age << endl;
		cout << "특성 : " << snail[i]->character << endl;
	}
	//run
	
	
	// Do Fork to Make 5 Snails.
	 int snail_index = 0;
	 for(snail_index = 0; snail_index<5; snail_index++)
	  if(fork() <= 0)
	      break;



	// /* In a Race */
	// //

	 /* Delete Snail Info */
	 for(int i=0; i<5; i++)
	  delete snail[i];
	 return;
}

