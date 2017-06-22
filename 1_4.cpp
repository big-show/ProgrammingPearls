#include<iostream>
#include<random>
#include<fstream>
#include<time.h>
#include<set>
#include<string>
using namespace std;
#define Count 100000
#define MaxNumber 99999
#define MinNumber 0
#define TempCount 2500
#define SecondGroupCount 50000
#define BitsPerWord 32
#define Move 5
int ArraySaveNum[1 + Count / BitsPerWord];
int data_to_save_to_txt[MaxNumber];
int temp_array[TempCount];
int genOneBigRandomNumber()
{
	return rand()*RAND_MAX + rand();
}
int genOneRandomNumberBetMinAndMax()
{
	return MinNumber+genOneBigRandomNumber()%MaxNumber;
}
void printMessage(int array[],int count)
{
	for (int i = 0; i < count; i++)
		cout << array[i] << " ";
	cout << endl;
}
void genDiffRandomNumberBetweenMinAndMax(int *temp)
{
	for (int i = 0; i <= MaxNumber; i++)
	{
		temp[i] = i+1;
	}
	for (int j = 0; j < Count; j++)
	{
		int t = genOneRandomNumberBetMinAndMax() % MaxNumber;
		swap(temp[j], temp[t]);
	}
	//printMessage(temp, Count);
}
void writeTofileTxt(int *data)
{
	ofstream fout;
	fout.open("data.txt");
	for (int i = 0; i < Count; i++)
	{
		fout << data[i] << endl;
	}
	fout << flush;
	fout.close();
}
bool isInRange(int range_rate, int number)
{
	int min_range = range_rate*TempCount;
	int max_range = (range_rate + 1)*TempCount;
	if (min_range <= number && max_range >= number)
		return true;
	return false;
}
bool isInRange(int range_rate, int number,int content_count)
{
	int min_range = range_rate*content_count;
	int max_range = (range_rate + 1)*content_count;
	if (min_range <= number && max_range >= number)
		return true;
	return false;
}
void writeTempDataToFile(std::set<double> s)
{
	ofstream fout;
	fout.open("method_1_result.txt",ios::app|ios::out);
	std::set<double>::iterator ite;
	for (ite = s.begin(); ite != s.end();ite++)
	{
		fout << *ite<<endl;
	}
	fout << flush;
	fout.close();
}
//void writeTempDataToFile(int start,int end,string name)
//{
//	ofstream fout;
//	fout.open(name, ios::app | ios::out);
//	for (int i = start; i <= end;i++)
//	{
//		fout << *ite << endl;
//	}
//	fout << flush;
//	fout.close();
//}
void tradiMethodToSort()
{
	std::set<double>s;
	string temp_string;
	int count = 0;
	ifstream fin;
	if (fin.fail())
	{
		cout << "open failed" << endl;
		return;
	}
	for (int i = 0; i < Count / TempCount; i++)
	{
		fin.open("C:\\Users\\small\\Documents\\Visual Studio 2013\\Projects\\ProgramingPearl\\ProgramingPearl\\data.txt");
		while (!fin.eof())
		{
			getline(fin, temp_string);
			double temp_num = atof(temp_string.c_str());
			if (isInRange(i, temp_num))
			{
				s.insert(temp_num);
			}
		}
		writeTempDataToFile(s);
		s.clear();
		fin.close();
	}
}
void setMark(int i)
{
	ArraySaveNum[i >> Move] |= 1 << (i & 0x1F);
}
void clrMark(int i)
{
	ArraySaveNum[i >> Move] &= ~(1 << (i & 0x1F));
}
int test(int i)
{
	return ArraySaveNum[i >> Move] & i << (i & 0x1F);
}
void newMethodToSort()
{
	ifstream fin;
	fin.open("data.txt");
	string temp_s;
	if (fin.fail())
	{
		cout << "open failed" << endl;
	}
	while (!fin.eof())
	{
		getline(fin, temp_s);
		int temp_value = (int)atof(temp_s.c_str());
		setMark(temp_value);
	}
	ofstream fout;
	fout.open("method_2_result.txt", ios::app | ios::out);
	for (int i = 0; i <= MaxNumber; i++)
	{
		if (test(i))
			fout << i << endl;
	}
	fout << flush;
	fout.close();
}
void method_1_5_result()
{
	ifstream fin;
	for (int i = 0; i < 2; i++)
	{
		fin.open("data.txt");
		while (!fin.eof())
		{
			string s;
			getline(fin, s);
			int temp_value = (int)atof(s.c_str());
			if (isInRange(i, temp_value, SecondGroupCount))
				setMark(temp_value);
		}
		fin.close();
		ofstream fout;
		fout.open("method_1_5_result.txt", ios::app | ios::out);
		if (i == 0){
			for (int i = 0; i <= SecondGroupCount; i++)
			{
				if (test(i))
					fout << i << endl;
			}
			fout << flush;
			fout.close();
		}
		if (i==1)
		{
			for (int i = SecondGroupCount+1; i <= MaxNumber; i++)
			{
				if (test(i))
					fout << i << endl;
			}
			fout << flush;
			fout.close();
		}

	}
	}
void main()
{
	clock_t start, end;
	start = clock();
	//genDiffRandomNumberBetweenMinAndMax(data_to_save_to_txt);
	//writeTofileTxt(data_to_save_to_txt); 
	//tradiMethodToSort();
	//newMethodToSort();
	method_1_5_result();
	end = clock();
	double total = (double)(end - start);
	cout << total << endl;
	getchar();
}