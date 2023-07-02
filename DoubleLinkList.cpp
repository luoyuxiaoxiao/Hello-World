#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

class DataNode//节点类，存放姓名，电话号码，性别，年龄
{
public:
	string name;
	long long int number;
	string sex;
	int age;
	DataNode* Previous;//前指针
	DataNode* Next;//后指针
	DataNode() {
		name = "0";
		number = 0;
		sex = "0";
		age = 0;
		Previous = nullptr;
		Next = nullptr;
	}
};


class DoubleLinkList
{
private:
	DataNode* FirstNode;
	DataNode* EndNode;
public:
	DoubleLinkList() { FirstNode = nullptr; EndNode = nullptr; }
	void CreatNode();//创造双链表节点
	void AppendNode();//增加双链表节点
	bool search(string Name);//按名称查询节点数据
	DataNode* search1(string Name);//按名称查询节点数据，并返回其位置
	DataNode* search2(string Name);//用于模糊查找
	bool del_node(string Name);//按名称删除节点
	void change_node(string Name);//按名称修改节点数值
	bool show_node1();//正序输出
	bool show_node2();//逆序输出
	bool blank_node();//判断是否为空链表
};

void DoubleLinkList::CreatNode()
{
	DataNode* p1 = new DataNode, * p2 = p1, * p3 = p1;
	FirstNode = p1;
	cout << "按下数字‘0’退出。" << endl;
	while (1) {
		cout << "请输入姓名：" << endl;
		cin >> p1->name;
		if (p1->name == " ") break;
		if (p1->name == "0") break;
		cout << "请输入电话号码：" << endl;
		cin >> p1->number;
		if (p1->number == 0) break;
		cout << "请输入性别：" << endl;
		cin >> p1->sex;
		if (p1->sex == " ") break;
		if (p1->sex == "0") break;
		cout << "请输入年龄：" << endl;
		cin >> p1->age;
		if (p1->age == 0) break;
		EndNode = p1;
		p1 = new DataNode;
		p3 = p1;
		p3->Previous = p2;//连接前指针
		p2->Next = p3;//连接后指针
		p2 = p1;
	}
	p2 = p2->Previous;
	if (p2 == nullptr) { FirstNode = nullptr; EndNode = nullptr; delete p1; }
	else {
		p2->Next = nullptr;
		p2 = p1;
		delete p1;
	}//释放多余的内存，并保证最后的next指针指向nullptr，防止next成为野指针
}

void DoubleLinkList::AppendNode()
{
	DataNode* p1 = new DataNode, * p2 = p1, * p3 = p1;
	DataNode* Temp_p = p1;
	cout << "按下数字‘0’退出。" << endl;
	while (1) {
		cout << "请输入姓名：" << endl;
		cin >> p1->name;
		if (p1->name == " ") break;
		if (p1->name == "0") break;
		cout << "请输入电话号码：" << endl;
		cin >> p1->number;
		if (p1->number == 0) break;
		cout << "请输入性别：" << endl;
		cin >> p1->sex;
		if (p1->sex == " ") break;
		if (p1->sex == "0") break;
		cout << "请输入年龄：" << endl;
		cin >> p1->age;
		if (p1->age == 0) break;
		p1 = new DataNode;
		p3 = p1;
		p3->Previous = p2;//连接前指针
		p2->Next = p3;//连接后指针
		p2 = p1;
	}
	p2 = p2->Previous;
	if (FirstNode == nullptr) { EndNode = p2; FirstNode = Temp_p; delete p1; p2->Next = nullptr; }//判断是否在创造链表后又删除了对象
	else {
		if (p2 == nullptr) {  delete p1;  }//说明只有一个结点
		else {
			p2->Previous = EndNode;//连接新节点的前结点
			EndNode->Next = p2;
			EndNode = p2;//将尾节点移动到新链表的最后一个位置
			p2->Next = nullptr;
			Temp_p = p1;//一起删除
			delete p1;
			/*p2->Next = FirstNode;连接新节点的后节点
			FirstNode->Previous = p2;连接新节点的前节点
			FirstNode = Temp_p;将首节点移动到新链表的第一个位置
			EndNode = p2->Next;将尾节点移动到新链表的最后一个位置
			Temp_p = p1;把Temp_p一并删除
			delete p1;*/
		}
	}//释放多余的内存，并保证最后的next指针指向nullptr，防止next成为野指针
}

bool DoubleLinkList::search(string Name)
{
	DataNode* p = DoubleLinkList::search2(Name);
	if (p == nullptr) { cout << "未查询到相关人员信息，请重试。" << endl; return false; }
	else
	{
		//while (p != nullptr)输出所有相关姓名
		cout << "姓名为：" << p->name << endl << "电话号码为：" << p->number << endl << "性别为：" << p->sex << endl << "年龄为：" << p->age << endl; 
		return true;
	}
	//if (p == nullptr) { cout << "未查询到相关人员信息。" << endl; return false; } //空链表
	//else {
	//	while (p != nullptr)
	//	{
	//		if (p->name==Name) { cout << "姓名为：" << p->name << endl << "电话号码为：" << p->number << endl << "性别为：" << p->sex << endl << "年龄为：" << p->age << endl; return true; }
	//		p = p->Next;
	//	}
	//	if (p == nullptr) cout << "未查询到相关人员信息。" << endl; return false;
	//}
}

DataNode* DoubleLinkList::search1(string Name)
{
	DataNode* p = FirstNode;
	if (p == nullptr) { return p; }// 空链表
	else {
		while (p != nullptr)
		{
			if (p->name == Name) break;
			p = p->Next;
		}
		//if (p == nullptr) {  return p; }
		return p;
	}
}//返回查询用户的位置

DataNode* DoubleLinkList::search2(string Name)
{
	DataNode* p = FirstNode;
	int i = 0;
	auto Begin = Name.begin();//要查找的姓名的第一个字
	if (p == nullptr) {
		return p;//若为空链表
	}
	else{
	do {
		if (p->name[i]!='0' && p->name[i] == Name[i]) {
			i++;
			Begin++;
		}//比较链表里的名字是否包含要查找的名字
		else
		{
			Begin = Name.begin();
			i = 0;
			if (p != nullptr) 
			{
				p = p->Next;
			}
			continue;
		}//不包含，查找下一个结点
	} while (p!=nullptr&&Begin != Name.end());
	return p;}
}

bool DoubleLinkList::del_node(string Name)
{
	DataNode* del_p = search1(Name);
	DataNode* temp_p = del_p;
	if (del_p == nullptr) { cout << "未找到要删除的对象：" << endl; return false; }
	else if (del_p->Next == nullptr && del_p->Previous == nullptr) //节点数为一个
	{
		FirstNode = nullptr;
		EndNode = nullptr;
		delete temp_p;
		cout << "已成功删除。" << endl;
	}
	else if (del_p->Next == nullptr || del_p->Previous == nullptr) //如果要删除的节点位于第一个或最后一个,而且节点数大于等于2
	{
		if (del_p->Next == nullptr) {
			del_p = del_p->Previous;
			del_p->Next = nullptr;
			EndNode = del_p;
		}//删除最后一个节点，并把尾指针向前移
		else if (del_p->Previous == nullptr){
			del_p = del_p->Next;
			FirstNode = del_p;
			del_p->Previous = nullptr;
		}//删除第一个节点，并把头指针向后移
		delete temp_p; 
		cout << "已成功删除。" << endl; 
		return true;
	}
	else //要删除的节点位于中间位置
	{
		del_p = del_p->Previous;//退一步
		del_p->Next = del_p->Next->Next;
		del_p = del_p->Next->Next;
		del_p->Previous = del_p->Previous->Previous;
		free(temp_p);
		cout << "已成功删除。" << endl;
		return true;
	}
}

void DoubleLinkList::change_node(string Name)
{
	DataNode* change_p = search1(Name);
	if (change_p == nullptr) { cout << "未找到要修改的对象：" << endl; }
	else
	{
		int i;
		string new_name;
		long long int new_number;
		int new_age;
		string new_sex;
		cout << endl
			<< "按下数字‘1’开始修改用户姓名。" << endl
			<< "按下数字‘2’开始修改用户电话号码。" << endl
			<< "按下数字‘3’开始修改用户性别。" << endl
			<< "按下数字‘4’开始修改用户年龄。" << endl
			<< "按下数字'0'或‘5’结束修改。" << endl;
		cin >> i;
		while (i % 5) {
			switch (i % 5)
			{
			case 1:
				cout << "请输入要修改成的姓名：" << endl;
				cin >> new_name;
				change_p->name = new_name; break;
			case 2:
				cout << "请输入要修改成的电话号码：" << endl;
				cin >> new_number;
				change_p->number = new_number; break;
			case 3:
				cout << "请输入要修改成的性别：" << endl;
				cin >> new_sex;
				change_p->sex = new_sex; break;
			case 4:
				cout << "请输入要修改成的年龄：" << endl;
				cin >> new_age;
				change_p->age = new_age; break;
			default:
				break;
			}
			cout << endl
				<< "按下数字‘1’开始修改用户姓名。" << endl
				<< "按下数字‘2’开始修改用户电话号码。" << endl
				<< "按下数字‘3’开始修改用户性别。" << endl
				<< "按下数字‘4’开始修改用户年龄。" << endl
				<< "按下数字‘5’结束修改。" << endl;
			cin >> i;
		}
	}
}

bool DoubleLinkList::show_node1()
{
	DataNode* t_p = FirstNode;
	if (t_p == nullptr) { cout << "目前没有任何用户信息，请添加后再试！" << endl; return false; }//防止空链表出现
	else {
		while (t_p!= nullptr)//不是空链表的时候
		{
			cout << "姓名为：" << setiosflags(ios::left) << setw(20) << t_p->name
				<< "电话号码为：" << setiosflags(ios::left) << setw(20) << t_p->number
				<< "性别为：" << setiosflags(ios::left) << setw(20) << t_p->sex
				<< "年龄为：" << setiosflags(ios::left) << setw(20) << t_p->age << endl;
			t_p = t_p->Next;
		}
	}
	t_p = FirstNode; return true;
}

bool DoubleLinkList::show_node2()
{
	DataNode* t1_p = EndNode;
	if (t1_p == nullptr) { cout << "目前没有任何用户信息，请添加后再试！" << endl; return false; }
	else {
		while (t1_p != nullptr)
		{
			cout  << "姓名为：" << setiosflags(ios::left) << setw(20) << t1_p->name
				 << "电话号码为：" << setiosflags(ios::left) << setw(20) << t1_p->number 
				 << "性别为：" << setiosflags(ios::left) << setw(20) << t1_p->sex 
				 << "年龄为：" << setiosflags(ios::left) << setw(20) << t1_p->age << endl;
			t1_p = t1_p->Previous;
		}
	}
	t1_p = EndNode; return true;
}

bool DoubleLinkList::blank_node()
{
	DataNode* temp = FirstNode;
	if (temp == nullptr) { return false; }
	else 
		return true;
}

int main()
{
	int i,t;
	int count = 0;//用来判断是否为第一次生成双链表
	string Name;
	cout << "开始" << endl
		<< "按下数字‘1’开始增加用户相关信息。" << endl
		<< "按下数字‘2’开始删除用户相关信息。" << endl
		<< "按下数字‘3’开始修改用户相关信息。" << endl
		<< "按下数字‘4’开始查询用户相关信息。" << endl
		<< "按下数字‘5’显示目前所以用户的相关信息。" << endl
		<< "按下数字‘6’退出程序。" << endl;
	cout << endl;
	cin >> i;
	DoubleLinkList new_user;
	while (i % 6) {
		switch (i % 7)
		{
		case 1:
			count = new_user.blank_node();
			if (count == 0) {
				new_user.CreatNode();
				cout << endl; count++; break;
			}
			else {
				new_user.AppendNode();
				cout << endl; break;
			}
		case 2:
			cout << " 请输入要删除用户的姓名：" << endl;
			cin >> Name;
			new_user.del_node(Name);
			cout << endl;
			break;
		case 3:
			cout << " 请输入要修改用户的姓名：" << endl;
			cin >> Name;
			new_user.change_node(Name);
			cout << endl;
			break;
		case 4:
			cout << " 请输入要查询用户的姓名：" << endl;
			cin >> Name;
			new_user.search(Name);
			cout << endl;
			break;
		case 5:
			cout << "输入‘1’正序输出所有用户信息：" << endl;
			cout << "输入‘2’逆序输出所有用户信息：" << endl;
			cin >> t;
			if (t == 1) {
				new_user.show_node1();
				cout << endl;
			}
			else if (t == 2) {
				new_user.show_node2();
				cout << endl;
			}
			break;
		default:
			break;
		}
		cout << "开始" << endl
			<< "按下数字‘1’开始增加用户相关信息。" << endl
			<< "按下数字‘2’开始删除用户相关信息。" << endl
			<< "按下数字‘3’开始修改用户相关信息。" << endl
			<< "按下数字‘4’开始查询用户相关信息。" << endl
			<< "按下数字‘5’显示目前所以用户的相关信息。" << endl
			<< "按下数字‘6’退出程序。" << endl;
		cout << endl;
		cin >> i;
	}
}