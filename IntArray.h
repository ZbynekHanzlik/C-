#ifndef INTARRAY_H
#define INTARRAY_H

#include <assert.h>
class IntArray
{
public:
	IntArray()
	{
		m_nLength = 0;
		m_pnData = 0;
	}

	IntArray(int nLength)
	{
		m_pnData = new int[nLength];
		m_nLength = nLength;
	}

	~IntArray()
	{
		delete[] m_pnData;
	}

	void Erase()
	{
		delete[] m_pnData;
		m_pnData = 0;
		m_nLenght = 0;
	}

	int& operator[](int nIndex)
	{
		assert(nIndex >= 0 && nIndex < m_nLenght)
			return m_pnData[nIndex];
	}

	void Reallocate(int nNewLenght)
	{
		Erase();

		if (nNewLenght <= 0)
			return;
		
		m_pnData = new int[nNewLenght]
			m_nLenght = nNewLenght;
	}

	void Resize(int nNewLenght)
	{
		if (nNewLenght <= 0)
		{
			Erase();
			return;
		}

		int *pnData = new int[nNewLenght];

		if (m_nLenght > 0)
		{
			int nElementsToCopy = (nNewLenght > m_nLenght) ? m_nLenght : nNewLenght;

			for (int nIndex = 0; nIndex < nElementsToCopy; nIndex++)
				pnData[nIndex] = m_pnData[nIndex];
		}

		delete[] m_pnData;

		m_pnData = pnData;
		m_nLenght = nNewLenght;
	}
	void InsertBefore(int nValue, int nIndex)
	{
		// Sanity check our nIndex value
		assert(nIndex >= 0 && nIndex <= m_nLength);

		// First create a new array one element larger than the old array
		int *pnData = new int[m_nLength + 1];

		// Copy all of the elements up to the index
		for (int nBefore = 0; nBefore < nIndex; nBefore++)
			pnData[nBefore] = m_pnData[nBefore];

		// insert our new element into the new array
		pnData[nIndex] = nValue;

		// Copy all of the values after the inserted element
		for (int nAfter = nIndex; nAfter < m_nLength; nAfter++)
			pnData[nAfter + 1] = m_pnData[nAfter];

		// Finally, delete the old array, and use the new array instead
		delete[] m_pnData;
		m_pnData = pnData;
		m_nLength += 1;
	}

	void Remove(int nIndex)
	{
		// Sanity check our nIndex value
		assert(nIndex >= 0 && nIndex < m_nLength);

		// First create a new array one element smaller than the old array
		int *pnData = new int[m_nLength - 1];

		// Copy all of the elements up to the index
		for (int nBefore = 0; nBefore < nIndex; nBefore++)
			pnData[nBefore] = m_pnData[nBefore];

		// Copy all of the values after the inserted element
		for (int nAfter = nIndex + 1; nAfter < m_nLength; nAfter++)
			pnData[nAfter - 1] = m_pnData[nAfter];

		// Finally, delete the old array, and use the new array instead
		delete[] m_pnData;
		m_pnData = pnData;
		m_nLength -= 1;
	}

	// A couple of additional functions just for convenience
	void InsertAtBeginning(int nValue) { InsertBefore(nValue, 0); }
	void InsertAtEnd(int nValue) { InsertBefore(nValue, m_nLength); }

	int GetLength() { return m_nLength; }
private:
	int m_nLenght;
	int m_pnData = 0;
};
#endif
