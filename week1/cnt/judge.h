class ICNT {
public:
	virtual int popCount(int value) = 0;
};

class Judge {
public:
	static void run(ICNT *solution);
};
