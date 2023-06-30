// #pragma warning(disable : 4996)

class iFriends
{
public:
	virtual void addFriend(int a, int b) = 0;
	virtual bool haveCommonFriend(int a, int b) = 0;
};

class judge
{
public:
	static void run(iFriends *solution);
};