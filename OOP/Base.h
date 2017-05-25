#include < iostream >
#include <string>

class Printable
{
public:
	virtual std::string Print() = 0;
};

class Named : public Printable
{

private:
	std::string m_name;

public:

	void Putname(std::string  const & name)
	{
		m_name = name;
	}

	std::string Getname() const
	{
		return m_name;
	}

};
