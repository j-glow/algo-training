

class IContainer {
public:
	virtual void init(int size) = 0;
	virtual bool add(int a) = 0;
	virtual bool contains(int a) = 0;
	virtual bool remove(int a) = 0;
};

class Judge {
public:
	static void run(IContainer *k);
};
