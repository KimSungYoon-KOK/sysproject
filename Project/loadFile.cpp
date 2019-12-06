#include "before.hpp"
void loadFile(FILE *fp) {
	// fp�� ���� ������ �Ѽ� ��üȭ ���Ѽ� ��ȯ�Ѵ�.
	int count = 0;
	char buf[1024];

	string name = "";
	string password = "";
	int money = 0;
	string record = "";

	while (0 < fscanf(fp, "%s", buf)) {
		switch (count)
		{
		case 0:
			/* code */
			name = buf;
			break;
		case 1:
			/* code */
			password = buf;
			break;
		case 2:
			/* code */
			money = atoi(buf);
			break;
		case 3:
			/* code */
			record = buf;
			break;
		case 4:
			count = -1;
			users.push_back(User(name, password, money, record));
			break;
		}
		count++;
	}
}
