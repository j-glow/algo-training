// #pragma warning(disable : 4996)

class iShops
{
public:
	virtual int getDistance(char data[256][256]) = 0;
};

class judge
{
public:
	static void run(iShops *solution);
};