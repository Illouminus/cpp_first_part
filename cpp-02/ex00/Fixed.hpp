#pragma once // #include guard

class Fixed 
{
    private:
        int value;
        static const int fractionalBits = 8;

    public:
        Fixed(); // Default constructor
        Fixed(const Fixed &src); // Copy constructor
        ~Fixed(); // Destructor

        Fixed &operator=(const Fixed &src); // Assignation operator

        int getRawBits(void) const;
        void setRawBits(int const raw);
};