class Snail
{
public:
	Snail() {};
	~Snail() {};

	int weight;					// ������ ����
	int age;					// ������ ����
	int minSpeed, maxSpeed;		// �⺻ �ӵ� ����
	int character;				// ����
								/*
								1) ������
									- �ʱ� �ӵ��� ��� ��.
								2) ����������
									- �ӵ� ���� ����(2��)
								3) ������
									- ó���� ������.
									- �ʹ� ������� �ӵ� ������ �ִ밪�� ����
								4) �ܷο�
									- �� ���̵忡�� �� ��, �ӵ� x 1.1
								5) �ºλ�
									- �߰��� ������ ��, �ӵ� ����.
								*/

	Snail(int weight, int age, int minSpeed, int maxSpeed, int character)
		: weight(weight), age(age), minSpeed(minSpeed), maxSpeed(maxSpeed), character(character)
	{}

};

