#include "before.hpp"
#include <time.h>
#include <stdlib.h>

void race_start()
{
	//show snail data
	srand(time(NULL));

	int charNum[5] = {0, };
	bool checkExist[5] = {false, };
	
	for (int i = 0; i < 5; )
	{
		/* Make Snail Info */
		int character = (rand() % 5);

		if(checkExist[character] == false ){
			checkExist[character] = true;
			charNum[i] = character;
			++i;
		}

		Snail* babySnail = new Snail(character);
	}

	// //bet
	// for (int i = 0; i < snail.size(); i++) {
	// 	cout << i + 1 << "�� ������" << endl;
	// 	cout << "���� : " << snail[i]->age << endl;
	// 	cout << "Ư�� : " << snail[i]->character << endl;
	// }
	// //run
	
	
	// // Do Fork to Make 5 Snails.
	//  int snail_index = 0;
	//  for(snail_index = 0; snail_index<5; snail_index++)
	//   if(fork() <= 0)
	//       break;



	// // /* In a Race */
	// // //

	//  /* Delete Snail Info */
	//  for(int i=0; i<5; i++)
	//   delete snail[i];
	//  return;
}

