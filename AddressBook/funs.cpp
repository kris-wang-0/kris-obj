#include "funs.h"

extern AddressBook adds[LEN+1];
extern unordered_map<string,UINT> names;


void addContacts(UINT *addc,AddressBook oneAdd) {
	adds[*addc] = oneAdd;
	names[oneAdd.name] = *addc;
	(*addc)++;

}

void showContacts(UINT addc) {
	cout << "name" << "\t"
		<< "sex" << "\t"
		<< "age" << "\t"
		<< "teleponeNumber" << "\t"
		<< "address" << endl;
	for (int i = 1;i < addc;i++) {
		cout << adds[i].name << "\t"
			<< adds[i].sex << "\t"
			<< adds[i].age << "\t"
			<< adds[i].teleponeNumber << "\t"
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
	if (m==NULL) {
		cout << "查无此人" << endl;
	}
	else {
		cout << "请输入姓名：" << endl;
		cin >> adds[m].name;
		cout << "请输入性别：\n0-女\n1-男" << endl;
		cin >> adds[m].sex;
		cout << "请输入年龄：" << endl;
		cin >> adds[m].age;
		cout << "请输入联系电话：" << endl;
		cin >> adds[m].teleponeNumber;//注意长度
		cout << "请输入住址" << endl;
		cin >> adds[m].address;
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
		addContacts(addc, e);
	}
}