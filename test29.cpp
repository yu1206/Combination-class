
#include <fstream>
#include <iostream>
#include <string>
#include <sstream> 
#include "opencv\cv.h"
#include "opencv\highgui.h"
using namespace cv;
using namespace std;

// 两个车牌分层三类。1，2，3，5，7；1类。4,9;2类。6，8；3类。

int test29(int argc, char *argv[])
{

	int classlabel[10] = {0,1,1,1,2,1,3,1,3,2};
	string  labelpath = "I:/双个车牌放在一起/0_one.txt";
	string  labelpathone = "I:/双个车牌放在一起/0_label.txt";


	fstream finRead;
	finRead.open(labelpath, ios::in);
	if (!finRead.is_open())
	{
		cout << "finRead 文件数据打开错误！" << endl;
		system("pause");
		return false;
	}

	fstream finWrite;
	finWrite.open(labelpathone, ios::out);
	if (!finWrite.is_open())
	{
		cout << "finRead 文件数据打开错误！" << endl;
		system("pause");
		return false;
	}

	string line;
	while (getline(finRead, line))
	{
		if (line.empty())
		{
			break;
		}
		
		
		cout << line.c_str() << endl;
		
		string ntxt; int label = 0;
		int x1= 0; int y1 =  0 ; int x2 =  0 ; int y2 =  0 ;
		
			stringstream str_s(line);
			str_s >> ntxt >> label >> x1 >> y1 >> x2 >> y2;
			
			finWrite << ntxt << " " << classlabel[label] << " " << x1<< " " << y1<< " " << x2 << " " << y2 << endl;

		
	}
	finRead.close();
	finWrite.close();
	return 0;
}