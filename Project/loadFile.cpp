#include "before.hpp"

vector<User> loadFile(FILE *fp) {
	// fp를 따라 파일을 켜서 객체화 시켜서 반환한다.
	int count = 0;
	char buf[1024];

	vector<User> userV;

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
			userV.push_back(User(name, password, money, record));
			break;
		}
		count++;
	}

	return userV;
}
