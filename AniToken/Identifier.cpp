
#include "Identifier.h"

bool Identifiers::is_open_bracket(const char ch)
{
	switch (ch)
	{
	case '[':
	case '(':
		return true;
	default:
		return false;
	}
}

bool Identifiers::is_close_bracket(const char ch)
{
	switch (ch)
	{
	case ']':
	case ')':
		return true;
	default:
		return false;
	}
}


bool Identifiers::is_separator(const char ch)
{
	switch (ch)
	{
	case ' ':
	case '_':
		return true;
	default:
		return false;
	}
}
