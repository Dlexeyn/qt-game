#include "Reader.h"

void Reader::setData(std::map<int, Commands> *data){
    this->data = data;
    this->data->clear();
}
