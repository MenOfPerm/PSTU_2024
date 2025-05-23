#include "Error.h"

IndexError::IndexError() { msg = "Index Error"; }
void IndexError::what() { cout << msg; }

SizeError::SizeError() { msg = "Size Error"; }
void SizeError::what() { cout << msg; }

MaxSizeError::MaxSizeError() { _msg = "Size > MAX_SIZE"; }
void MaxSizeError::what() { cout << msg << " : " << _msg; }

EmptyError::EmptyError() { msg = "Vector is empty"; }
void EmptyError::what() { cout << msg; }

DifferentSizeError::DifferentSizeError() { _msg = "Vectors have different sizes"; }
void DifferentSizeError::what() { cout << msg << " : " << _msg; }