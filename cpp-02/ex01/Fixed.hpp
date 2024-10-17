#include <iostream>
#include <string>

class Fixed
{
  private:
	int value;
	const static int bits = 8;

  public:
	Fixed();
	Fixed(const Fixed &src);
	Fixed(const int value);
	Fixed(const float value);
	~Fixed();

	Fixed &operator=(const Fixed &src);

	int getRawBits() const;
	void setRawBits(int const raw);

    float toFloat(void) const;
	int toInt(void) const;
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);