class Snail
{
public:
	Snail() {};
	~Snail() {};

	int weight;					// 껍데기 무게
	int age;					// 달팽이 나이
	int minSpeed, maxSpeed;		// 기본 속도 범위
	int character;				// 성격
								/*
								1) 성실함
									- 초기 속도로 계쏙 뜀.
								2) 변덕스러움
									- 속도 범위 증가(2배)
								3) 수줍음
									- 처음엔 느리다.
									- 초반 페이즈에서 속도 범위값 최대값을 감소
								4) 외로움
									- 양 사이드에서 뛸 때, 속도 x 1.1
								5) 승부사
									- 중간에 끼었을 때, 속도 증가.
								*/

	Snail(int weight, int age, int minSpeed, int maxSpeed, int character)
		: weight(weight), age(age), minSpeed(minSpeed), maxSpeed(maxSpeed), character(character)
	{}

};

