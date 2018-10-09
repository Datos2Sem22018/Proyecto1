//
// Created by zuckerberg on 23/09/18.
//

#include "RC.h"

void RC::addRef() {
    count++;
}

int RC::release() {
    return --count;
}