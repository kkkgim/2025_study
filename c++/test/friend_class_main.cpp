#include <iostream>
#include "FriendExample.h"

int main() {
    FriendExample x(3);
    OtherClass y;

    x.showValue();
    accessSecret(x);
    y.showSecret(x);
    return 0;
}