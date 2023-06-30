#include <fstream>
#include <iostream>
#pragma warning(disable : 4996)

class iPartition
{
  public:
	virtual bool checkPartition(int* array, int n) = 0;
};

class judge
{
  public:
	static void run(iPartition* solution);
};
