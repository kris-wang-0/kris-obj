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
		cout << "���޴���" << endl;//д��̫�����
	}
	else {//�ѵ㣬��������ɾȥһ��Ԫ��,��Ϊ����������ԣ�����ֱ���ͷŸô��ռ�
		//�ⷨһ����������Ѱ�Ҵ�ʱ����֮���Ԫ����ǰ�ƶ����� o(N^2),o(1)
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
		cout << "�Ѿ�ɾ��-" << name << endl;
	}
}

void findContacts(string name) {
	UINT m = names[name];
	if (m == NULL) {
		cout << "���޴���" << endl;
	}
	else {
		cout << adds[m].name << "\t"
			<< adds[m].sex << "\t"
			<< adds[m].age << "\t"
			<< adds[m].teleponeNumber << "\t"
			<< adds[m].address << endl;
	}
}

void modifyContacts(string name) {//�������������������޸�ʱ��ֱ���½�һ������ɾ���滻�ɵ�
	UINT m = names[name];
	if (m==NULL) {
		cout << "���޴���" << endl;
	}
	else {
		cout << "������������" << endl;
		cin >> adds[m].name;
		cout << "�������Ա�\n0-Ů\n1-��" << endl;
		cin >> adds[m].sex;
		cout << "���������䣺" << endl;
		cin >> adds[m].age;
		cout << "��������ϵ�绰��" << endl;
		cin >> adds[m].teleponeNumber;//ע�ⳤ��
		cout << "������סַ" << endl;
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
		{"����",1,23,123456,"��������"},
		{"����",0,23,234567,"���"},
		{"����",1,56,543777,"����������"},
		{"����",0,75,753159,"��������"},
		{"�ϰ�",0,45,154678,"����ɽ"},
	};
	for (auto e : testContacts) {
		addContacts(addc, e);
	}
}