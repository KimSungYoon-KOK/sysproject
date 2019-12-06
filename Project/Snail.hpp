class Snail
{
public:
	Snail() {};
	~Snail() {};

	int weight;						//��� ��					
	int age;							//��� ��
	int minSpeed, maxSpeed;		//�� �� ��
	int character;			
	
	bool sincerity_flag = false;
	bool shy_flag = false;
	bool lonely_flag = false;
	bool adventure_flag = false;

	Snail(int character)
		:character(character)
	{
		srand(time(NULL));		
		weight = (rand() % 20) + 1;		//1kg ~ 20kg
		age = (rand() % 5) + 1;				//1years ~ 5years
		minSpeed = 50-(weight*age/4);		// default : 50 -> 25~50
		maxSpeed = 100-(weight*age/4);	//default : 100 -> 75~100

		switch(character){
			case 0:
				//sincerity
				sincerity_flag = true;
				break;
			case 1:
				//moodiness
				minSpeed /= 2;
				maxSpeed *= 2;
				break;
			case 2:
				//shyness
				shy_flag = true;
				break;
			case 3:
				//loneliness
				lonely_flag = true;
				break;
			case 4:
				//adventurer
				adventure_flag = true;
				break;
		}
		cout<< "character : "<< character <<endl;
	}
};
