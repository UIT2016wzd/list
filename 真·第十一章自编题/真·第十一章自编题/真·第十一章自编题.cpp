#include"iostream"
#include"string"
using namespace std;
class person
{
public:
	person();
	person(string nam, int ag, char se) :person(nam,ag,se)
	{
		name = nam;
		age = ag;
		sex = se;
	}
	string name;
	int age;
	~person(){}
	void display()
	{
		cout << "首先这是一个名为" << name << "的" << age << "岁" << sex << "性人类" << endl;
	}
protected:
	char sex;
};

class student :public person
{
public:
	student(int n, string nam, int ag, char se, string sch) :student(n,sch)
	{
		num = n;
		school = sch;
	}
	~student(){}
	void display()
	{
		cout << "然后这是一个名为" << name << "的在" << school << "学校的" << age << "岁" << sex << "学号为"<<num<<"的学生" << endl;
	}
private:
	int num;
	string school;
};

int main()
{
	person S("WZD", 20, "N");
	S.display();
	student T(5, "BOB", 20, "N", "DLCY");
	T.display();

}