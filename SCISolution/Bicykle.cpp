#include "Bicykle.h"

namespace world
{
	//ctor
	Bicykle::Bicykle():
		m_weight{ 123.543f },
		m_tire{ 29.0f }
	{
	}

	//dtor
	Bicykle::~Bicykle()
	{
		m_weight = 0;
		m_tire = 0;
	}
}