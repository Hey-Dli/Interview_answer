#ifndef QIHOO_VECTOR_H_
#define QIHOO_VECTOR_H_

#include <stdlib.h>

namespace qh
{
    template<class T>
    class vector {
    public:
        //ctor
        vector()
        : data_(NULL), size_(0)
        {
        }

        explicit vector( size_t n, const T& value = T())
        {
            data_ = new T[n];
            for (size_t i = 0; i < n; i++)
            {
                data_[0] = value;
            }
        }

        vector<T>& operator=(const vector<T>& rhs)
        {
            data_ = rhs.data_;
            size_ = rhs.size_;
        }

        //dtor
        ~vector()
        {
            if (data_)
            {
                delete data_;
            }
        }

        //get
        size_t size() const
        {
            return size_;
        }

        // set & get
        T& operator[](size_t index)
        {
            return data_[index];
        }

        // set
        void push_back(const T& element)
        {
            if (size_ == 0)
            {
                data_ = new T[1];
                data_[0] = element;
                size_++;
            }
            else
                data_[size_++] = element;
        }

        void pop_back()
        {
            --size_;
        }

        void resize(size_t size)
        {
            if (size <= size_) {
                size_ = size;
            }
            else
            {
                while (size_ < size) {
                    push_back(0);
                }
            }
        }

        void reserve(size_t size)
        {
            if (size < size_)
            return;
            T* tmp = new T[size];
            for (int i = 0; i < size_; ++i) {
                tmp[i] = data_[i];
            }
            data_ = tmp;
        }

        void clear()
        {
            size_ = 0;
        }

        bool empty()
        {
            return size_==0 ? true : false;
        }

    private:
        T*      data_;
        size_t  size_;
    };
}

#endif
