//
// Created by zuckerberg on 23/09/18.
//

#ifndef PROYECTO1_RC_H
#define PROYECTO1_RC_H


class RC {
private:
    int count;
public:
    RC() = default;
    ~RC() = default;
    void addRef();
    int release();
};

#endif //PROYECTO1_RC_H
