#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <string>
#include "rwlock.h"
using namespace std;

rwlock global_lock;
string Str;
int Second;

const char *path = "results";

void reader(int Num)
{
	global_lock.reader_lock();
	
	cout << "---------------------------" << endl;
	cout << "I'm Reader " << Num << ".\n";
	for (int i = 0; i < 1; i++) {
		cout << "Reader" << Num << " sleep for " << Num << " seconds." << endl;
		std::this_thread::sleep_for(chrono::seconds(Num));
	}
	ifstream FileIn(path, ifstream::in);
	getline(FileIn, Str, '\0');
	cout << Str << endl;
	cout << "---------------------------" << endl;
	global_lock.reader_unlock();
}

void writer(int Num)
{
	global_lock.writer_lock();
	cout << "---------------------------" << endl;
	cout << "I'm Writer " << Num << ".\n";
	for (int i = 0; i < 1; i++) {
		cout << "Writer" << Num << " sleep for " << Num << " seconds." << endl;
		std::this_thread::sleep_for(chrono::seconds(Num));
	}
	ofstream FileOut(path, ofstream::out | ofstream::trunc);
	Second += Num;
	FileOut << Second;
	cout << "---------------------------" << endl;
	global_lock.writer_unlock();
}

int main()
{
	thread reader1;
	thread reader2;
	thread writer1;
	while (1) {
		reader1 = thread(reader, 3);
		reader2 = thread(writer, 4);
		writer1 = thread(writer, 2);
		reader1.join();
		reader2.join();
		writer1.join();
	}
	reader1.join();
	reader2.join();
	writer1.join();
	return 1;
}

