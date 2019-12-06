#include "before.hpp"
#include <time.h>
#include <stdlib.h>
#include <sys/wait.h>

pid_t r_wait(int *stat_loc) {
   int retval;
   while (((retval = wait(stat_loc)) == -1) && (errno == EINTR)) ;
       return retval;
}


void gotoxy(int x, int y)
{
	printf("\033[%d;%df", y, x);
	fflush(stdout);
}

void race_start()
{
	int signal[5];
	//show snail data
	srand((unsigned int)time(NULL));

	int charNum[5] = {
		0,
	};
	bool checkExist[5] = {
		false,
	};

	for (int i = 0; i < 5;)
	{
		/* Make Snail Info */
		int character = (rand() % 5);

		if (checkExist[character] == false)
		{
			checkExist[character] = true;
			charNum[i] = character;
			
			Snail *babySnail = new Snail(character);
			snail[i] = babySnail;
			++i;
		}
	}

	//bet


	for (int i = 0; i < snail.size(); i++)
	{
		cout << "["<<i + 1 << " 번 달팽이]" << endl;
		cout << "무게 : " << snail[i]->weight <<endl;
		cout << "나이 : " << snail[i]->age << endl;
		string tempchar;
		switch (snail[i]->character)
		{
		case 0:
			tempchar = "성실함"; break;
		case 1:
			tempchar = "변덕스러움"; break;
		case 2:
			tempchar = "수줍음"; break;
		case 3:
			tempchar = "외로움"; break;
		case 4:
			tempchar = "승부사"; break;
		default:
			break;
		}
		cout << "특성 : " << tempchar << endl;
		cout << "기본 속도 범위 : " << snail[i]->minSpeed << " ~ "<< snail[i]->maxSpeed << endl << endl;
	}

	string goal;
	cout << " 1등 달팽이는 누구? " << endl;
	cin >> goal;
	cout << "내가 고른 1등은 " << goal << endl;

	//Clear Screen
	system("clear");
	// Do Fork to Make 5 Snails.
	int snail_index = 0;
	int pid = -1;
	for (snail_index = 0; snail_index < 5; snail_index++)
	{
		pid = fork();
		if (pid <= 0)
			break;
	}
	//내가 몇번 달팽이인지 알아야해
	if (pid == 0)
	{
		Snail *s = snail[snail_index];
		// /* In a Race */
		int distance = 3000;
		int now = 1;
		int phase = 1;
		int show = 0;
		while (now < distance)
		{
			int tempSpeed = (rand() % (s->maxSpeed - s->minSpeed + 1)) + s->minSpeed;
			now += tempSpeed; //tempSpeed 나이랑 성격 무게 계수를 곱해줘야하니까
			//달팽이출력
			show = (int)(now / 100);
			gotoxy(0, snail_index + 2);
			for (int i = 0; i < show; i++)
			{
				//cout << "■";
				cout << "~";
			}
			cout << "@_v" << endl;
			sleep(1);
			phase++;
		}
		exit(snail_index);
	}
	else
	{
		//벡터로 해서 1등 알아야됨
		for(int i=0; i<5; i++)
			r_wait(&signal[i]);

		vector<int> rank;
		for(int i=0; i<5; i++)
			rank.push_back(WEXITSTATUS(signal[i]));
		
		/* Temporary Print */
		for(int e : rank)
			cout << e << " " << endl;
	}

	//  /* Delete Snail Info */
	 for(int i=0; i<5; i++)
	  delete snail[i];
	return;
}
