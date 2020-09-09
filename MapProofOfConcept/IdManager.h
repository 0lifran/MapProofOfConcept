namespace IdManager
{
	int idCounter = 0;
	int GetNewId()
	{
		idCounter++;
		return idCounter;
	}
}