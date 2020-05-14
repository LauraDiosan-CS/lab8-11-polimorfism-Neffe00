//#include"UI.h"
//
//#include<string>
//#include<map>
//
//#include<iostream>
//using namespace std;
//
//UI::UI()
//{}
//UI::UI(Service& service)
//{
//	this->service = service;
//}
//UI::~UI()
//{}
//
//void UI::displayMenu()
//{
//	cout << "ADD medicine: 'add' + id + name + needRec + stockQ + producer" << endl;
//	cout << "SHOW medicine: 'show_m' + partName"<<endl;
//	cout << "SHOW medicines: 'show_m' " << endl;
//	cout << "SHOW employees: 'show_e' " << endl;
//	cout << "DELETE medicine: 'delete' + id" << endl;;
//	cout << "EXIT: 'exit'" << endl;
//	cout << endl << endl;
//}
//
//void UI::UIaddMedicine(string  cmd)
//{
//	//add
//	string sep = " ";
//	size_t pos = cmd.find(sep);
//	cmd.erase(0, pos + 1);
//
//	//id
//	pos = cmd.find(sep);
//	string token = cmd.substr(0, pos);
//	int id = stoi(token);
//	cmd.erase(0, pos + 1);
//
//	//name
//	pos = cmd.find(sep);
//	string name = cmd.substr(0, pos);
//	cmd.erase(0, pos + 1);
//
//	//needRecepie
//	pos = cmd.find(sep);
//	token = cmd.substr(0, pos);
//	int needRecepie = stoi(token);
//	cmd.erase(0, pos + 1);
//	
//	//stockQuantity
//	pos = cmd.find(sep);
//	token = cmd.substr(0, pos);
//	int stockQuantity= stoi(token);
//	cmd.erase(0, pos + 1);
//
//	//porducer
//	string producer = cmd;
//
//	this->service.addMedicine(id, name, needRecepie, stockQuantity, producer);
//}
//
//void UI::UIshowMedicine(string cmd)
//{
//	//numaram cuvintele
//	int wordCount = 1;
//	string sep = " ";
//	string cmdCopy = cmd;
//
//	while (cmdCopy.find(sep) != string::npos)
//	{
//		size_t pos = cmdCopy.find(sep);
//		cmdCopy.erase(0, pos + 1);
//		wordCount++;
//	}
//
//	//eliminam cuvantul show
//	size_t pos = cmd.find(sep);
//	cmd.erase(0, pos + 1);
//
//	if (wordCount == 1)
//	{
//		//afisam toate cheltuielile
//		vector<Medicine> Medicines = this->service.getMedicines();
//		vector<Medicine> ::iterator it;
//		for (it = Medicines.begin(); it != Medicines.end(); it++)
//			cout << *it << endl;
//	}
//	else if (wordCount == 2)
//	{
//		//aflam partea din nume
//		string namePart = cmd;
//
//		vector<Medicine> Medicines = this->service.getMedicines();
//		vector<Medicine> ::iterator it;
//		for (it = Medicines.begin(); it != Medicines.end(); it++)
//			if (it->getName().find(namePart)!=string::npos)
//				cout << *it << endl;
//	}
//}
//
//void UI::UIshowEmployee(string cmd)
//{
//	vector<Employee> Employees = this->service.getEmployees();
//	vector<Employee> ::iterator it;
//	for (it = Employees.begin(); it != Employees.end(); it++)
//		cout << *it << endl;
//}
//
//
//void UI::UIupdateMedicine(string cmd)
//{
//
//}
//
//void UI::UIdeleteMedicine(string cmd)
//{
//	//eliminam cuvantul delete
//	size_t pos = cmd.find(" ");
//	cmd.erase(0, pos + 1);
//
//	string token = cmd;
//	int id = stoi(token);
//
//	vector<Medicine> Medicines = this->service.getMedicines();
//	vector<Medicine> ::iterator it;
//	for (it = Medicines.begin(); it != Medicines.end(); it++)
//		if (it->getId()==id)
//			this->service.deleteMedicine((*it).getId());
//}
//
///*
//class Login
//{
//public:
//	string user;
//	string pass;
//
//	Login(string user, string pass)
//	{
//		this->user = user;
//		this->pass = pass;
//	}
//
//	Login(const Login& l)
//	{
//		this->user = l .user;
//		this->pass = l.pass;
//	}
//
//	~Login() {}
//
//};
//
//void UI::validateLogin(const Login& l)
//{
//	string mess = "";
//
//	vector<Employee> Employees = service.
//		vector<Employee> ::iterator it;
//	for (it = Employees.begin(); it != Employees.end(); it++)
//
//
//		if (mess != "") {
//
//			throw exception(mess.c_str());
//		}
//}
//*/
//
//void UI::runUI()
//{
//	/*string user, pass;
//	cout << "Login" << endl;
//	
//	cout << "user: ";
//	cin >> user;
//
//	cout << "pass: ";
//	cin >> pass;
//
//	Login l(user, pass);*/
//
//	this->displayMenu();
//
//	bool shouldRun = true;
//	string cmd;
//
//	while (shouldRun)
//	{
//		getline(cin, cmd);
//
//		if (cmd.find("add") != string::npos)
//			this->UIaddMedicine(cmd);
//		
//		else if (cmd.find("show_m") != string::npos)
//			this->UIshowMedicine(cmd);
//		
//		else if (cmd.find("show_e") != string::npos)
//			this->UIshowEmployee(cmd);
//
//		else if (cmd.find("del") != string::npos)
//			this->UIdeleteMedicine(cmd);
//
//		
//
//		else if (cmd.find("exit") != string::npos)
//			shouldRun = false;
//	}
//}