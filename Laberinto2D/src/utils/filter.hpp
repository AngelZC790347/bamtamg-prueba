#include <vector>
#include <iostream>
#include <functional>

template <class Functor>
class Not
{
public:
    Not(Functor & f) : func(f) {}

    template <typename ArgType>
    bool operator()(ArgType & arg) {return !func(arg);}

private:
    Functor & func;
};
	
template<typename T, typename B>
T filter(T list, B pred) {
    T ret;
    std::remove_copy_if(
        list.begin(),
        list.end(),
        std::back_insert_iterator<T>(ret),
        Not<B>(pred)
    );

    return ret;
}

