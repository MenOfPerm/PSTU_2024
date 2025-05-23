#pragma once
#include <string>
#include <iostream>

using namespace std;

class Error 
{
public:
    virtual void what() = 0;
    virtual ~Error() = default;
};

class IndexError : public Error 
{
protected:
    string msg;
public:
    IndexError();
    void what() override;
};

class SizeError : public Error 
{
protected:
    string msg;
public:
    SizeError();
    void what() override;
};

class MaxSizeError : public SizeError 
{
protected:
    string _msg;
public:
    MaxSizeError();
    void what() override;
};

class EmptyError : public Error 
{
protected:
    string msg;
public:
    EmptyError();
    void what() override;
};

class DifferentSizeError : public SizeError 
{
protected:
    string _msg;
public:
    DifferentSizeError();
    void what() override;
};