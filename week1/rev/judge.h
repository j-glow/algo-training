class IREV {
public:
	virtual int bitReverse(int value) = 0;
};

class Judge {
public:
	static void run(IREV *solution);
};
