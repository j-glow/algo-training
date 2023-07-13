class IMSD {
public:
	virtual void init() = 0;
	virtual void makeDir(char *path, char *name) = 0;
	virtual void makeLink(char *pathSrc, char *pathDst) = 0;
	virtual void makeSystemFile(char *path) = 0;
	virtual void getMostSafeDir(char *result) = 0;
};

class Judge {
public:
	static void run(IMSD *solution);
};
