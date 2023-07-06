class ITUR {
public:
	virtual int getBestResult(int *board, int size) = 0;
};

class Judge
{
public:
	static void run(ITUR *solution);
};

