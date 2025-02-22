#ifndef INT24_H
#define INT24_H

#include <QObject>

#define INT24_MAX 8388607
#define UINT24_MAX 16777215


class Int24
{
protected:
	unsigned char m_Internal[3];
public:
	Int24()
	{
	}

	Int24 (unsigned char v1, unsigned char v2, unsigned char v3)
	{
		m_Internal[0] = v1;// ((unsigned char*)&input)[0];
		m_Internal[1] = v2;// ((unsigned char*)&input)[1];
		m_Internal[2] = v3;// ((unsigned char*)&input)[2];
	}

	Int24(const int val)
	{
		*this = val;
	}

	Int24(const Int24& val)
	{
		*this = val;
	}

	operator int() const
	{
		if (m_Internal[2] & 0x80) // Is this a negative?  Then we need to siingn extend.
		{
			return (0xff << 24) | (m_Internal[2] << 16) | (m_Internal[1] << 8) | (m_Internal[0] << 0);
		}
		else
		{
			return (m_Internal[2] << 16) | (m_Internal[1] << 8) | (m_Internal[0] << 0);
		}
	}

	operator float() const
	{
		return (float)this->operator int();
	}

	Int24& operator =(const Int24& input)
	{
		m_Internal[0] = input.m_Internal[0];
		m_Internal[1] = input.m_Internal[1];
		m_Internal[2] = input.m_Internal[2];

		return *this;
	}

	Int24& operator =(const int input)
	{
		m_Internal[0] = ((unsigned char*)&input)[0];
		m_Internal[1] = ((unsigned char*)&input)[1];
		m_Internal[2] = ((unsigned char*)&input)[2];

		return *this;
	}



	/***********************************************/

	Int24 operator +(const Int24& val) const
	{
		return Int24((int)*this + (int)val);
	}

	Int24 operator -(const Int24& val) const
	{
		return Int24((int)*this - (int)val);
	}

	Int24 operator *(const Int24& val) const
	{
		return Int24((int)*this * (int)val);
	}

	Int24 operator /(const Int24& val) const
	{
		return Int24((int)*this / (int)val);
	}

	/***********************************************/

	Int24 operator +(const int val) const
	{
		return Int24((int)*this + val);
	}

	Int24 operator -(const int val) const
	{
		return Int24((int)*this - val);
	}

	Int24 operator *(const int val) const
	{
		return Int24((int)*this * val);
	}

	Int24 operator /(const int val) const
	{
		return Int24((int)*this / val);
	}

	/***********************************************/
	/***********************************************/


	Int24& operator +=(const Int24& val)
	{
		*this = *this + val;
		return *this;
	}

	Int24& operator -=(const Int24& val)
	{
		*this = *this - val;
		return *this;
	}

	Int24& operator *=(const Int24& val)
	{
		*this = *this * val;
		return *this;
	}

	Int24& operator /=(const Int24& val)
	{
		*this = *this / val;
		return *this;
	}

	/***********************************************/

	Int24& operator +=(const int val)
	{
		*this = *this + val;
		return *this;
	}

	Int24& operator -=(const int val)
	{
		*this = *this - val;
		return *this;
	}

	Int24& operator *=(const int val)
	{
		*this = *this * val;
		return *this;
	}

	Int24& operator /=(const int val)
	{
		*this = *this / val;
		return *this;
	}

	/***********************************************/
	/***********************************************/

	Int24 operator >>(const int val) const
	{
		return Int24((int)*this >> val);
	}

	Int24 operator <<(const int val) const
	{
		return Int24((int)*this << val);
	}

	/***********************************************/

	Int24& operator >>=(const int val)
	{
		*this = *this >> val;
		return *this;
	}

	Int24& operator <<=(const int val)
	{
		*this = *this << val;
		return *this;
	}

	/***********************************************/
	/***********************************************/

	operator bool() const
	{
		return (int)*this != 0;
	}

	bool operator !() const
	{
		return !((int)*this);
	}

	Int24 operator -()
	{
		return Int24(-(int)*this);
	}

	/***********************************************/
	/***********************************************/

	bool operator ==(const Int24& val) const
	{
		return (int)*this == (int)val;
	}

	bool operator !=(const Int24& val) const
	{
		return (int)*this != (int)val;
	}

	bool operator >=(const Int24& val) const
	{
		return (int)*this >= (int)val;
	}

	bool operator <=(const Int24& val) const
	{
		return (int)*this <= (int)val;
	}

	bool operator >(const Int24& val) const
	{
		return (int)*this > (int)val;
	}

	bool operator <(const Int24& val) const
	{
		return (int)*this < (int)val;
	}

	/***********************************************/

	bool operator ==(const int val) const
	{
		return (int)*this == val;
	}

	bool operator !=(const int val) const
	{
		return (int)*this != val;
	}

	bool operator >=(const int val) const
	{
		return (int)*this >= val;
	}

	bool operator <=(const int val) const
	{
		return (int)*this <= val;
	}

	bool operator >(const int val) const
	{
		return ((int)*this) > val;
	}

	bool operator <(const int val) const
	{
		return (int)*this < val;
	}

	/***********************************************/
	/***********************************************/
};

class Uint24
{
public:
	unsigned char bits[3]; // assuming char is 8 bits
	Uint24()
		: bits()
	{}

	Uint24(unsigned val)
	{
		*this = val;
	}

	Uint24& operator=(unsigned val)
	{
		// store as little-endian
		bits[2] = val >> 16 & 0xff;
		bits[1] = val >> 8 & 0xff;
		bits[0] = val & 0xff;
		return *this;
	}

	quint32  as_unsigned() const {

		//return (bits[2] << 16) | (bits[1] << 8) | (bits[0] << 0);
		return bits[0] | bits[1] << 8 | bits[2] << 16;
	}
};

#endif
