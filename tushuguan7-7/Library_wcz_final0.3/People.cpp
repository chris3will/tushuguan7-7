#include"People.h"
#include"Book.h"
#include"Library.h"
#include<string>
#include<sstream>
class Book;
void People::input()
{
	cout << "***Please enter people's ID(no space)***:";
	cin >> s_id;
	cout << endl;
	cout << "***Please enter people's password(no space)***:";
	cin >> s_password;
	cout << endl;
	cout << "***Please enter book_num if he has borrowed some(no more than 30)(int please)***:";
	cin >> i_the_book;
	cout << endl;
	while (i_the_book > 30)
	{
		cout <<"please re-enter the num of book!" << endl;
		cin >> i_the_book;
	}
	string name_temp;
	int i_all = 0;
	int k = i_the_book;
	//One can't borrow more than 
	while(k > 0)
	{
		cout << "***Please enter book's name(no space)***:";
		cout << "attention: " << k << " left to write!" << endl;
		cin >> name_temp;
		v_Bbook.push_back(name_temp);
		k--;
		cout << endl;
	}
	//we can know the state of a book's loan?.
	return;
}
void People::ReadFile(string &temp) 
{
	int identi;
	string s_temp(temp);
	int j = 0;
	int i = 0;
	int flag = 1;
	string s_out_temp;
	int i_len = s_temp.size();
	while (i < i_len)
	{
		j = i;
		while (s_temp[j] != ','&&j < i_len)
		{
			j++;//to store every son string's length j-i is just the length.
		}
		s_out_temp.assign(s_temp, i, j - i);
		identi = s_out_temp.size();
		//cout << s_out_temp << endl;
		stringstream ss;
		ss.clear();
		ss << s_out_temp;
		string tempp;
		switch (flag)
		{
		case 1:ss >> s_id; break;
		case 2:ss >> s_password; break;
		case 3:ss >> i_the_book; break;
		default:break;
		}
		if (flag <= 3)
		{
			//if (flag == 3)
			//{
			//	cout << i_the_book << endl;
			//}
			flag++;
			i = j + 1;	
		}
		else
		{
			if (i_the_book > 0)
			{
				flag++;
				i = j + 1;
				//cout << s_out_temp;
				//system("pause");
				v_Bbook.push_back(s_out_temp);
				//i_the_book--;
			}
			else
			{
				i = j + 1;
				break;
			}
		}
	}
	//begin to read the book if he borrowed something.
	
}
void People::FindBook()
{
	int i_flag = s_id.size();
	Library test;
	test.Lib_init();
	
	test.Findacurate(i_flag,this);
	test.Save();
}
void People::ReturnBook()
{
	Library test;
	test.Lib_init();
	cout << "Hello, my friend,please tell us the book you want to return.(The name of the book is ok!)" << endl;
	string s_temp;
	cin >> s_temp;
	test.Returnbook(this, s_temp);
	test.Save();
	//first find the node that has this string,then use the special function
}

