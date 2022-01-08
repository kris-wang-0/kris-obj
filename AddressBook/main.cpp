#include<math.h>
#include "funs.h"

AddressBook adds[LEN];
//��Ҫһ����ϣ�� ��name-index��ʡ��ѯʱ��
unordered_map<string,UINT> names;
UINT addc = 1;
int main() {
    cout << "********************" << "\n"
         << "*** 1-�����ϵ�� ***" << "\n"
         << "*** 2-��ʾ��ϵ�� ***" << "\n"
         << "*** 3-ɾ����ϵ�� ***" << "\n"
         << "*** 4-������ϵ�� ***" << "\n"
         << "*** 5-�޸���ϵ�� ***" << "\n"
         << "*** 6-�����ϵ�� ***" << "\n"
         << "*** 7-�˳�ͨѶ¼ ***" << "\n"
         << "********************" << endl;
    UINT operation = 0;
    string name;
    AddressBook oneAdd;
    try
    {
        while (1) {//����һ�����⣬����������ͺ��趨�����Ͳ�ͬ������������ѭ����
            cout << "��Ҫ���еĲ���:" << endl;
            cin >> operation;
            switch (operation) {
            case 1:
                cout << "������������" << endl;
                cin >> oneAdd.name;
                cout << "�������Ա�\n0-Ů\n1-��" << endl;
                cin >> oneAdd.sex;
                cout << "���������䣺" << endl;
                cin >> oneAdd.age;
                cout << "��������ϵ�绰��" << endl;
                cin >> oneAdd.teleponeNumber;//ע�ⳤ��
                cout << "������סַ" << endl;
                cin >> oneAdd.address;
                addContacts(&addc, oneAdd);
                operation = 0;
                break;
            case 2:
                showContacts(addc);
                break;
            case 3:
                cout << "������Ҫɾ������ϵ�˵����֣�" << endl;
                cin >> name;
                deleteContacts(name,&addc);
                operation = 0;
                break;
            case 4:
                cout << "������Ҫ���ҵ���ϵ�˵����֣�" << endl;
                cin >> name;
                findContacts(name);
                operation = 0;
                break;
            case 5:
                cout << "������Ҫ�޸ĵ���ϵ�˵����֣�" << endl;
                cin >> name;
                modifyContacts(name);
                operation = 0;
                break;
            case 6:
                clearContacts(&addc);
                operation = 0;
                break;
            case 7:
                exit(0);
                break;
            case 8:
                testAdd(&addc);
                break;
            default:
                operation = 0;
                break;
            }
        }
    }
    catch (const std::exception&)
    {
        cout << "�벻Ҫ���д������" << endl;
        exit(0);
    }
    

}