#include < stdio.h >

template < typename T >

class Conteiner
{
private:
	struct Element
	{
		T m_value;
		Element * m_next;
		Element * m_previous;
		int tag;
	};

	Element * m_head;
	Element * m_tail;
	int m_quanity;

public:

	Conteiner()
	{
		m_head = NULL;
		m_tail = NULL;
		m_quanity = 0;
	};

	~Conteiner()
	{
		Element * current = m_head;
		Element * current2 = m_head;
		while (current != NULL)
		{
			current2 = (current->m_previous);
			delete current;
			current = current2;
		}
	};

	Conteiner(const Conteiner & orig)
	{
		this->m_head = orig.m_head;
		this->m_tail = orig.m_tail;
	}

	void DelTail()
	{
		if (m_tail != NULL)
		{
			Element* current = m_tail->m_next;
			if (m_quanity == 1) m_head = NULL;
			m_tail = NULL;
			m_tail = current;
			m_quanity--;
		}
	}

	void DelHead()
	{
		if (m_head != NULL)
		{
			Element * current = m_head->m_previous;
			m_head = NULL;
			m_head = current;
			if (m_quanity == 1) m_tail = NULL;
			m_quanity--;
		}

	}

	T GetHead() //get from conteiner first element
	{
		return m_head->m_value;
	}

	T GetTail() //get from conteiner last element
	{
		return m_tail->m_value;
	}

	T GetElement(int numb) //get from conteiner element with number "numb"
	{
		int i = 0;
		Element * current = m_tail;
		while ((current != NULL) && (i < numb))
		{
			current = current->m_next;
			i++;
		}
		return current->m_value;
	}

	void PutHead(T newval) //put in conteiner new first element
	{
		Element * newhead = new Element;
		newhead->m_next = NULL;
		newhead->m_previous = m_head;
		newhead->m_value = newval;
		if (m_head != NULL) m_head->m_next = newhead;
		m_head = newhead;
		if (m_tail == NULL) m_tail = m_head;
		if (m_quanity == 1) m_tail->m_next = m_head;
		m_quanity++;
	}

	void PutTail(T newval) // put in conteiner new last element
	{
		Element * newtail = new Element;
		newtail->m_next = m_tail;
		newtail->m_previous = NULL;
		newtail->m_value = newval;
		if (m_tail != NULL) m_tail->m_previous = newtail;
		m_tail = newtail;
		if (m_head == NULL) m_head = m_tail;
		if (m_quanity == 1) m_head->m_previous = m_tail;
		m_quanity++;
	}

	bool IsEmpty()
	{
		return (m_head == NULL);
	}

	void Clearn()
	{
		Element * current = m_head;
		Element * current2 = m_head;
		while (current != NULL)
		{
			current2 = (current->m_previous);
			delete current;
			current = current2;
		}
		m_head = NULL;
		m_tail = NULL;
		m_quanity = 0;
	}

	int GetQuanity()
	{
		return m_quanity;
	}
};