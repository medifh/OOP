#include < iostream >
#include <string>

class Printable
{
public:
	virtual std::string Print(void) = 0;
};

class Named : public Printable
{

private:
	std::string m_name;

public:

	void Putname(std::string name)
	{
		m_name = name;
	}

	std::string Getname()
	{
		return m_name;
	}

};
