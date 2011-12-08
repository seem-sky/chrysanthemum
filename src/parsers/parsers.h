// ======================================================================================
// File         : parsers.h
// Author       : Gao Lei 
// Last Change  : 12/01/2011 | 01:43:39 AM | Thursday,December
// Description  : 
// ======================================================================================
#ifndef __PARSERS_H__
#define __PARSERS_H__

#include <cctype>
#include "../utility/data_holder.h"

class alpha_parser:public data_holder<char>
{
public:
    alpha_parser() {}
    ~alpha_parser() {}
public:
    template <typename Iterator>
    bool operator()(Iterator& first,Iterator last)
    {
        if(first==last)
            return false;
        if(!std::isalpha(*first))
            return false;
        return set_data_and_call_back(*first++);
    }  

};

#define CHAR_TO_NUM(X) ((X)-'0')

class digit_parser:public data_holder<char>
{
public:
    digit_parser() {}
    ~digit_parser() {}
public:
    template <typename Iterator>
    bool operator()(Iterator& first,Iterator last)
    {
        if(first == last)
            return false;
        if(!std::isdigit(*first))
            return false;
        return set_data_and_call_back(*first++);
    }
 

};


class cntrl_parser:public data_holder<char>
{
public:
    cntrl_parser() {}
    ~cntrl_parser() {}
public:
    template <typename Iterator>
    bool operator()(Iterator& first,Iterator last)
    {
        if(first == last)
            return false;
        if(!std::iscntrl(*first))
            return false;
        return set_data_and_call_back(*first++);
    }
    
};

class space_parser:public data_holder<char>
{
public:
    space_parser() {}
    ~space_parser() {}
public:
    template <typename Iterator>
    bool operator()(Iterator& first,Iterator last)
    {
        if(first == last)
            return false;
        if(!std::isspace(*first))
            return false;
        return set_data_and_call_back(*first++);
    }
 };

class oct_parser:public data_holder<char>
{
public:
    oct_parser() {}
    ~oct_parser() {}
public:
    template <typename Iterator>
    bool operator()(Iterator& first,Iterator last)
    {
        if(first == last)
            return false;
        return set_data_and_call_back(*first++);
    }
 };


typedef alpha_parser _alpha;
typedef digit_parser _digit;
typedef space_parser _space;
typedef cntrl_parser _cntrl;
typedef oct_parser _oct;


#endif
