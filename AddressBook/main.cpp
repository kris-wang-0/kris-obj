#include<math.h>
#include "funs.h"

AddressBook adds[LEN];
//需要一个哈希表 、name-index节省查询时间
unordered_map<string,UINT> names;
UINT addc = 1;
int main() {
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
    AddressBook oneAdd;
    try
    {
        while (1) {//存在一个问题，弱输入的类型和设定的类型不同，会陷入无限循环中
            cout << "你要进行的操作:" << endl;
            cin >> operation;
            switch (operation) {
            case 1:
                cout << "请输入姓名：" << endl;
                cin >> oneAdd.name;
                cout << "请输入性别：\n0-女\n1-男" << endl;
                cin >> oneAdd.sex;
                cout << "请输入年龄：" << endl;
                cin >> oneAdd.age;
                cout << "请输入联系电话：" << endl;
                cin >> oneAdd.teleponeNumber;//注意长度
                cout << "请输入住址" << endl;
                cin >> oneAdd.address;
                addContacts(&addc, oneAdd);
                operation = 0;
                break;
            case 2:
                showContacts(addc);
                break;
            case 3:
                cout << "请输入要删除的联系人的名字：" << endl;
                cin >> name;
                deleteContacts(name,&addc);
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
        cout << "请不要进行错误操作" << endl;
        exit(0);
    }
    

}