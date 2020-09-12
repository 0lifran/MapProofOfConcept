class IdManager
{
public:
	static int _idCounter;
	IdManager();
	int GetNewId();
	void IncrementIdCounter();
};