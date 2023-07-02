#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

class DataNode//�ڵ��࣬����������绰���룬�Ա�����
{
public:
	string name;
	long long int number;
	string sex;
	int age;
	DataNode* Previous;//ǰָ��
	DataNode* Next;//��ָ��
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
	void CreatNode();//����˫����ڵ�
	void AppendNode();//����˫����ڵ�
	bool search(string Name);//�����Ʋ�ѯ�ڵ�����
	DataNode* search1(string Name);//�����Ʋ�ѯ�ڵ����ݣ���������λ��
	DataNode* search2(string Name);//����ģ������
	bool del_node(string Name);//������ɾ���ڵ�
	void change_node(string Name);//�������޸Ľڵ���ֵ
	bool show_node1();//�������
	bool show_node2();//�������
	bool blank_node();//�ж��Ƿ�Ϊ������
};

void DoubleLinkList::CreatNode()
{
	DataNode* p1 = new DataNode, * p2 = p1, * p3 = p1;
	FirstNode = p1;
	cout << "�������֡�0���˳���" << endl;
	while (1) {
		cout << "������������" << endl;
		cin >> p1->name;
		if (p1->name == " ") break;
		if (p1->name == "0") break;
		cout << "������绰���룺" << endl;
		cin >> p1->number;
		if (p1->number == 0) break;
		cout << "�������Ա�" << endl;
		cin >> p1->sex;
		if (p1->sex == " ") break;
		if (p1->sex == "0") break;
		cout << "���������䣺" << endl;
		cin >> p1->age;
		if (p1->age == 0) break;
		EndNode = p1;
		p1 = new DataNode;
		p3 = p1;
		p3->Previous = p2;//����ǰָ��
		p2->Next = p3;//���Ӻ�ָ��
		p2 = p1;
	}
	p2 = p2->Previous;
	if (p2 == nullptr) { FirstNode = nullptr; EndNode = nullptr; delete p1; }
	else {
		p2->Next = nullptr;
		p2 = p1;
		delete p1;
	}//�ͷŶ�����ڴ棬����֤����nextָ��ָ��nullptr����ֹnext��ΪҰָ��
}

void DoubleLinkList::AppendNode()
{
	DataNode* p1 = new DataNode, * p2 = p1, * p3 = p1;
	DataNode* Temp_p = p1;
	cout << "�������֡�0���˳���" << endl;
	while (1) {
		cout << "������������" << endl;
		cin >> p1->name;
		if (p1->name == " ") break;
		if (p1->name == "0") break;
		cout << "������绰���룺" << endl;
		cin >> p1->number;
		if (p1->number == 0) break;
		cout << "�������Ա�" << endl;
		cin >> p1->sex;
		if (p1->sex == " ") break;
		if (p1->sex == "0") break;
		cout << "���������䣺" << endl;
		cin >> p1->age;
		if (p1->age == 0) break;
		p1 = new DataNode;
		p3 = p1;
		p3->Previous = p2;//����ǰָ��
		p2->Next = p3;//���Ӻ�ָ��
		p2 = p1;
	}
	p2 = p2->Previous;
	if (FirstNode == nullptr) { EndNode = p2; FirstNode = Temp_p; delete p1; p2->Next = nullptr; }//�ж��Ƿ��ڴ����������ɾ���˶���
	else {
		if (p2 == nullptr) {  delete p1;  }//˵��ֻ��һ�����
		else {
			p2->Previous = EndNode;//�����½ڵ��ǰ���
			EndNode->Next = p2;
			EndNode = p2;//��β�ڵ��ƶ�������������һ��λ��
			p2->Next = nullptr;
			Temp_p = p1;//һ��ɾ��
			delete p1;
			/*p2->Next = FirstNode;�����½ڵ�ĺ�ڵ�
			FirstNode->Previous = p2;�����½ڵ��ǰ�ڵ�
			FirstNode = Temp_p;���׽ڵ��ƶ���������ĵ�һ��λ��
			EndNode = p2->Next;��β�ڵ��ƶ�������������һ��λ��
			Temp_p = p1;��Temp_pһ��ɾ��
			delete p1;*/
		}
	}//�ͷŶ�����ڴ棬����֤����nextָ��ָ��nullptr����ֹnext��ΪҰָ��
}

bool DoubleLinkList::search(string Name)
{
	DataNode* p = DoubleLinkList::search2(Name);
	if (p == nullptr) { cout << "δ��ѯ�������Ա��Ϣ�������ԡ�" << endl; return false; }
	else
	{
		//while (p != nullptr)��������������
		cout << "����Ϊ��" << p->name << endl << "�绰����Ϊ��" << p->number << endl << "�Ա�Ϊ��" << p->sex << endl << "����Ϊ��" << p->age << endl; 
		return true;
	}
	//if (p == nullptr) { cout << "δ��ѯ�������Ա��Ϣ��" << endl; return false; } //������
	//else {
	//	while (p != nullptr)
	//	{
	//		if (p->name==Name) { cout << "����Ϊ��" << p->name << endl << "�绰����Ϊ��" << p->number << endl << "�Ա�Ϊ��" << p->sex << endl << "����Ϊ��" << p->age << endl; return true; }
	//		p = p->Next;
	//	}
	//	if (p == nullptr) cout << "δ��ѯ�������Ա��Ϣ��" << endl; return false;
	//}
}

DataNode* DoubleLinkList::search1(string Name)
{
	DataNode* p = FirstNode;
	if (p == nullptr) { return p; }// ������
	else {
		while (p != nullptr)
		{
			if (p->name == Name) break;
			p = p->Next;
		}
		//if (p == nullptr) {  return p; }
		return p;
	}
}//���ز�ѯ�û���λ��

DataNode* DoubleLinkList::search2(string Name)
{
	DataNode* p = FirstNode;
	int i = 0;
	auto Begin = Name.begin();//Ҫ���ҵ������ĵ�һ����
	if (p == nullptr) {
		return p;//��Ϊ������
	}
	else{
	do {
		if (p->name[i]!='0' && p->name[i] == Name[i]) {
			i++;
			Begin++;
		}//�Ƚ�������������Ƿ����Ҫ���ҵ�����
		else
		{
			Begin = Name.begin();
			i = 0;
			if (p != nullptr) 
			{
				p = p->Next;
			}
			continue;
		}//��������������һ�����
	} while (p!=nullptr&&Begin != Name.end());
	return p;}
}

bool DoubleLinkList::del_node(string Name)
{
	DataNode* del_p = search1(Name);
	DataNode* temp_p = del_p;
	if (del_p == nullptr) { cout << "δ�ҵ�Ҫɾ���Ķ���" << endl; return false; }
	else if (del_p->Next == nullptr && del_p->Previous == nullptr) //�ڵ���Ϊһ��
	{
		FirstNode = nullptr;
		EndNode = nullptr;
		delete temp_p;
		cout << "�ѳɹ�ɾ����" << endl;
	}
	else if (del_p->Next == nullptr || del_p->Previous == nullptr) //���Ҫɾ���Ľڵ�λ�ڵ�һ�������һ��,���ҽڵ������ڵ���2
	{
		if (del_p->Next == nullptr) {
			del_p = del_p->Previous;
			del_p->Next = nullptr;
			EndNode = del_p;
		}//ɾ�����һ���ڵ㣬����βָ����ǰ��
		else if (del_p->Previous == nullptr){
			del_p = del_p->Next;
			FirstNode = del_p;
			del_p->Previous = nullptr;
		}//ɾ����һ���ڵ㣬����ͷָ�������
		delete temp_p; 
		cout << "�ѳɹ�ɾ����" << endl; 
		return true;
	}
	else //Ҫɾ���Ľڵ�λ���м�λ��
	{
		del_p = del_p->Previous;//��һ��
		del_p->Next = del_p->Next->Next;
		del_p = del_p->Next->Next;
		del_p->Previous = del_p->Previous->Previous;
		free(temp_p);
		cout << "�ѳɹ�ɾ����" << endl;
		return true;
	}
}

void DoubleLinkList::change_node(string Name)
{
	DataNode* change_p = search1(Name);
	if (change_p == nullptr) { cout << "δ�ҵ�Ҫ�޸ĵĶ���" << endl; }
	else
	{
		int i;
		string new_name;
		long long int new_number;
		int new_age;
		string new_sex;
		cout << endl
			<< "�������֡�1����ʼ�޸��û�������" << endl
			<< "�������֡�2����ʼ�޸��û��绰���롣" << endl
			<< "�������֡�3����ʼ�޸��û��Ա�" << endl
			<< "�������֡�4����ʼ�޸��û����䡣" << endl
			<< "��������'0'��5�������޸ġ�" << endl;
		cin >> i;
		while (i % 5) {
			switch (i % 5)
			{
			case 1:
				cout << "������Ҫ�޸ĳɵ�������" << endl;
				cin >> new_name;
				change_p->name = new_name; break;
			case 2:
				cout << "������Ҫ�޸ĳɵĵ绰���룺" << endl;
				cin >> new_number;
				change_p->number = new_number; break;
			case 3:
				cout << "������Ҫ�޸ĳɵ��Ա�" << endl;
				cin >> new_sex;
				change_p->sex = new_sex; break;
			case 4:
				cout << "������Ҫ�޸ĳɵ����䣺" << endl;
				cin >> new_age;
				change_p->age = new_age; break;
			default:
				break;
			}
			cout << endl
				<< "�������֡�1����ʼ�޸��û�������" << endl
				<< "�������֡�2����ʼ�޸��û��绰���롣" << endl
				<< "�������֡�3����ʼ�޸��û��Ա�" << endl
				<< "�������֡�4����ʼ�޸��û����䡣" << endl
				<< "�������֡�5�������޸ġ�" << endl;
			cin >> i;
		}
	}
}

bool DoubleLinkList::show_node1()
{
	DataNode* t_p = FirstNode;
	if (t_p == nullptr) { cout << "Ŀǰû���κ��û���Ϣ������Ӻ����ԣ�" << endl; return false; }//��ֹ���������
	else {
		while (t_p!= nullptr)//���ǿ������ʱ��
		{
			cout << "����Ϊ��" << setiosflags(ios::left) << setw(20) << t_p->name
				<< "�绰����Ϊ��" << setiosflags(ios::left) << setw(20) << t_p->number
				<< "�Ա�Ϊ��" << setiosflags(ios::left) << setw(20) << t_p->sex
				<< "����Ϊ��" << setiosflags(ios::left) << setw(20) << t_p->age << endl;
			t_p = t_p->Next;
		}
	}
	t_p = FirstNode; return true;
}

bool DoubleLinkList::show_node2()
{
	DataNode* t1_p = EndNode;
	if (t1_p == nullptr) { cout << "Ŀǰû���κ��û���Ϣ������Ӻ����ԣ�" << endl; return false; }
	else {
		while (t1_p != nullptr)
		{
			cout  << "����Ϊ��" << setiosflags(ios::left) << setw(20) << t1_p->name
				 << "�绰����Ϊ��" << setiosflags(ios::left) << setw(20) << t1_p->number 
				 << "�Ա�Ϊ��" << setiosflags(ios::left) << setw(20) << t1_p->sex 
				 << "����Ϊ��" << setiosflags(ios::left) << setw(20) << t1_p->age << endl;
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
	int count = 0;//�����ж��Ƿ�Ϊ��һ������˫����
	string Name;
	cout << "��ʼ" << endl
		<< "�������֡�1����ʼ�����û������Ϣ��" << endl
		<< "�������֡�2����ʼɾ���û������Ϣ��" << endl
		<< "�������֡�3����ʼ�޸��û������Ϣ��" << endl
		<< "�������֡�4����ʼ��ѯ�û������Ϣ��" << endl
		<< "�������֡�5����ʾĿǰ�����û��������Ϣ��" << endl
		<< "�������֡�6���˳�����" << endl;
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
			cout << " ������Ҫɾ���û���������" << endl;
			cin >> Name;
			new_user.del_node(Name);
			cout << endl;
			break;
		case 3:
			cout << " ������Ҫ�޸��û���������" << endl;
			cin >> Name;
			new_user.change_node(Name);
			cout << endl;
			break;
		case 4:
			cout << " ������Ҫ��ѯ�û���������" << endl;
			cin >> Name;
			new_user.search(Name);
			cout << endl;
			break;
		case 5:
			cout << "���롮1��������������û���Ϣ��" << endl;
			cout << "���롮2��������������û���Ϣ��" << endl;
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
		cout << "��ʼ" << endl
			<< "�������֡�1����ʼ�����û������Ϣ��" << endl
			<< "�������֡�2����ʼɾ���û������Ϣ��" << endl
			<< "�������֡�3����ʼ�޸��û������Ϣ��" << endl
			<< "�������֡�4����ʼ��ѯ�û������Ϣ��" << endl
			<< "�������֡�5����ʾĿǰ�����û��������Ϣ��" << endl
			<< "�������֡�6���˳�����" << endl;
		cout << endl;
		cin >> i;
	}
}