// #pragma warning(disable : 4996)

class iBFS
{
public:
	virtual int solve(int n, int m, const char* start, const char* end, const char** a, const char** b) = 0;
};

class judge
{
public:
	static void run(iBFS *solution);
};