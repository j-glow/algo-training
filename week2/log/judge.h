// #pragma warning(disable : 4996)

class iLOG
{
public:
	virtual int solve(int n, char logo[10][10], char stamps[][4][4]) = 0;
};

class judge
{
public:
	static void run(iLOG *solution);
};
