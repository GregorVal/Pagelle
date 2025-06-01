#include "swapper.h"

swapper::swapper()
{

}

template<typename var>
void swapper::swap(var a, var b)
{
    var temp = a;
    a = b;
    b = temp;
}
