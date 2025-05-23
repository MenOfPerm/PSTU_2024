#pragma once

#include "Money.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int make_file(const char* filename);
int print_file(const char* filename);
int delete_by_value(const char* filename, const Money& value);
int increase_by_value(const char* filename, const Money& value);
int add_file(const char* filename, int k, int n);