#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>

template <typename T> class Array
{
  private:
	T *_elements;
	unsigned int _size;

  public:
	// Constructeur par défaut (tableau vide)
	Array() : _elements(NULL), _size(0)
	{
	}

	// Constructeur avec taille
	Array(unsigned int n) : _elements(new T[n]), _size(n)
	{
	}

	// Constructeur par copie
	Array(const Array &other) : _elements(NULL), _size(0)
	{
		*this = other;
	}

	// Opérateur d'affectation
	Array &operator=(const Array &other)
	{
		if (this != &other)
		{
			delete[] _elements;
			_size = other._size;
			_elements = new T[_size];
			for (unsigned int i = 0; i < _size; ++i)
			{
				_elements[i] = other._elements[i];
			}
		}
		return (*this);
	}

	// Destructeur
	~Array()
	{
		delete[] _elements;
	}

	// Opérateur d'accès
	T &operator[](unsigned int index)
	{
		if (index >= _size)
		{
			throw std::out_of_range("Index out of bounds");
		}
		return (_elements[index]);
	}

	// Version const de l'opérateur d'accès
	const T &operator[](unsigned int index) const
	{
		if (index >= _size)
		{
			throw std::out_of_range("Index out of bounds");
		}
		return (_elements[index]);
	}

	// Fonction size()
	unsigned int size() const
	{
		return (_size);
	}
};

#endif
