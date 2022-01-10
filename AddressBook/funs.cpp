#include "funs.h"

extern AddressBook adds[LEN+1];
extern unordered_map<string,UINT> names;

int judgeTelepone(string teleponeNumber) {

}
void input(AddressBook *oneAddress) {
	UINT sex;
	string teleponeNumber;
	cout << "请输入姓名：" << endl;
	cin >> oneAddress->name;
	SEXRE:
	cout << "请输入性别：\n0-女\n1-男" << endl;
	cin >> sex;
	if (sex==1 || sex==0) {
		oneAddress->sex = sex;
	}
	else
	{
		cout << "请输入正确的性别编码" << endl;
		goto SEXRE;
	}
	cout << "请输入年龄：" << endl;
	cin >> oneAddress->age;
	cout << "请输入联系电话：" << endl;
	cin >> teleponeNumber;//注意长度

	cout << "请输入住址" << endl;
	cin >> oneAddress->address;
}
void addContacts(UINT *addc,AddressBook oneAddress) {
	if (*addc == LEN + 1) {
		cout << "通讯录已满" << endl;
		return ;
	}
	else
	{
		adds[*addc] = oneAddress;
		names[oneAddress.name] = *addc;
		(*addc)++;
	}
}

void showContacts(UINT addc) {

	cout << "name" << "\t"
		<< "sex" << "\t"
		<< "age" << "\t"
		<< "teleponeNumber" << "\t"
		<< "address" << endl;
	for (int i = 1;i < addc;i++) {
		cout << adds[i].name << "\t"
			<< (adds[i].sex == 1 ? "男" : "女") << "\t"
			<< adds[i].age << "\t"
			<< adds[i].teleponeNumber << "\t\t"
			<< adds[i].address << endl;
	}
}

void deleteContacts(string name,UINT *addc) {
	UINT m = names[name];
	cout << m << endl;
	if (m == NULL) {
		cout << "查无此人" << endl;//写的太耦合了
	}
	else {//难点，从数组中删去一个元素,因为数组的连续性，不能直接释放该处空间
		//解法一，遍历，到寻找处时，将之后的元素向前移动覆盖 o(N^2),o(1)
		for (int i = m;i <= *addc;i++) {
			if (i == *addc) {
				adds[i] = adds[0];
			}
			else {
				adds[i] = adds[i + 1];
			}
		}
		(*addc)--;
		names.erase(name);
		cout << "已经删除-" << name << endl;
	}
}

void findContacts(string name) {
	UINT m = names[name];
	if (m == NULL) {
		cout << "查无此人" << endl;
	}
	else {
		cout << adds[m].name << "\t"
			<< adds[m].sex << "\t"
			<< adds[m].age << "\t"
			<< adds[m].teleponeNumber << "\t"
			<< adds[m].address << endl;
	}
}

void modifyContacts(string name) {//在于如果针对姓名进行修改时，直接新建一个，且删除替换旧的
	UINT m = names[name];
	AddressBook oneAddresss;
	if (m==NULL) {
		cout << "查无此人" << endl;
	}
	else {
		input(&oneAddresss);
		addContacts(&m, oneAddresss);
	}
}

void clearContacts(UINT *addc) {
	memset(adds, NULL, sizeof(adds));
	names.clear();
	*addc=1;
}

void testAdd(UINT *addc) {
	AddressBook testContacts[5] = {
		{"张三",1,23,123456,"西伯利亚"},
		{"李是",0,23,234567,"天津"},
		{"王五",1,56,543777,"北京朝阳区"},
		{"赵四",0,75,753159,"西藏拉萨"},
		{"老八",0,45,154678,"卡德山"},
	};
	for (auto e : testContacts) {
		addContacts(addc,e);
	}
}

void show(UINT *addc) {
	cout << "********************" << "\n"
		<< "*** 1-添加联系人 ***" << "\n"
		<< "*** 2-显示联系人 ***" << "\n"
		<< "*** 3-删除联系人 ***" << "\n"
		<< "*** 4-查找联系人 ***" << "\n"
		<< "*** 5-修改联系人 ***" << "\n"
		<< "*** 6-清空联系人 ***" << "\n"
		<< "*** 7-退出通讯录 ***" << "\n"
		<< "********************" << endl;
	UINT operation = 0;
	string name;
	AddressBook oneAddress;
	try
	{
		while (1) {//存在一个问题，弱输入的类型和设定的类型不同，会陷入无限循环中
			cout << "你要进行的操作:" << endl;
			cin >> operation;
			switch (operation) {
			case 1:
				input(&oneAddress);
				addContacts(addc,oneAddress);
				operation = 0;
				break;

			case 2:
				showContacts(*addc);
				break;
			case 3:
				cout << "请输入要删除的联系人的名字：" << endl;
				cin >> name;
				deleteContacts(name, addc);
				operation = 0;
				break;
			case 4:
				cout << "请输入要查找的联系人的名字：" << endl;
				cin >> name;
				findContacts(name);
				operation = 0;
				break;
			case 5:
				cout << "请输入要修改的联系人的名字：" << endl;
				cin >> name;
				modifyContacts(name);
				operation = 0;
				break;
			case 6:
				clearContacts(addc);
				operation = 0;
				break;
			case 7:
				return;
				break;
			case 8:
				testAdd(addc);
				break;
			default:
				operation = 0;
				break;
			}
		}
	}
	catch (const std::exception&)
	{
		cout << "请不要进行错误操作" << endl;
		exit(0);
	}
}
