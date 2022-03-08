#pragma once

namespace ft
{
	template <class T, class A>
	void	vector<T,A>::push_back(const T& value)
	{
		if (this->_size == this->_capacity)
			this->reserve((this->_capacity + 1) * 2);
		this->_alloc.construct(this->_start + this->size++, value);
	}

	template <class T, class A>
	void	vector<T,A>::pop_back(void)
	{
		this->_alloc.destroy(this->_start + --this->size);
	}

	template <class T, class A>
	void	vector<T,A>::clear(void)
	{
		for (size_type i = 0; i < this->_size; i++)
			this->_alloc.destroy(this->_start + i);
		this->_size = 0;
	}
}