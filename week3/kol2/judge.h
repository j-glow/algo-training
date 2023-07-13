class IKOL2 {
public:
	virtual bool isGraph2Colorable(int vertexCount, int edgeCount, int *edge1, int *edge2) = 0;
};

class Judge
{
public:
	static void run(IKOL2 *solution);
};

