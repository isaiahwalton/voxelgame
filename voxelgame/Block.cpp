#include "Block.h"


Block::Block()
{
	m_type = types::air;
}


void Block::SetType(int val)
{
	m_type = val;
}

int Block::GetType()
{
	return m_type;
}
