#pragma warning(disable : 4996)

class iwater
{
public:
	virtual int minMoves(int n, int o[4], int w[4]) = 0;
};

class judge
{
public:
	static void run(iwater *);
};