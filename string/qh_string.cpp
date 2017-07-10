#include "qh_string.h"

#include <string.h>

namespace qh
{

    string::string()
    : data_(NULL), len_(0)
    {
    }

    string::string(const char* s)
    {
        if (s == NULL)
        {
            data_ = new char[1];
            *data_ = '\0';
            len_ = 0;
        }
        else {
            len_ = strlen(s);
            data_ = new char[len_+1];
            strcpy(data_, s);
        }
    }

    string::string(const char* s, size_t len)
    {
        if (s == NULL || len == 0)
        {
            data_ = new char[1];
            *data_ = '\0';
            len_ = 0;
        }
        else {
            len_ = len;
            data_ = new char[len_ + 1];
            memcpy(data_, s, len);
            data_[len_] = '\0';
        }
    }

    string::string(const string& rhs)
    {
        len_ = strlen(rhs.data_);
        data_ = new char[len_ + 1];
        strcpy(data_, rhs.data_);
    }

    string& string::operator=(const string& rhs)
    {
        if (this != &rhs)
        {
            delete[] data_;
            if (!rhs.data_)
            {
                data_ = new char[1];
                *data_ = '\0';
                len_ = 0;
            }
            else
            {
                len_ = strlen(rhs.data_);
                data_ = new char[len_ + 1];
                strcpy(data_, rhs.data_);
            }
        }
        return *this;
    }

    string::~string()
    {
        delete[] data_;
        len_ = 0;
    }

    size_t string::size() const
    {
        return len_;
    }

    const char* string::data() const
    {
        if (len_ == 0) {
            return "";
        }
        return data_;
    }

    const char* string::c_str() const
    {
        char *s = new char[len_ + 1];
        strcpy(s, data_);
        s[len_] = '\0';
        return s;
    }

    char* string::operator[](size_t index)
    {
        char* s = new char[2];
        if (index >= 0 && index <= len_)
        {
            s[0] = data_[index];
        }
        s[1] = '\0';
        return s;
    }
}

