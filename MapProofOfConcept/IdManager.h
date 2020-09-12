class IdManager
{
public:
	IdManager();
	int GetNewId();
private:
	static int IdCounter;
	void IncrementIdCounter();
};