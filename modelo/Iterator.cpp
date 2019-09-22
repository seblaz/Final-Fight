//
// Created by sebas on 31/8/19.
// TODO: Obtenido de https://stackoverflow.com/questions/23400693/is-iterable-like-behavior-in-c-attainable,
// TODO: consultar si se puede usar.
//

#ifndef FINAL_FIGHT_ITERATOR_H
#define FINAL_FIGHT_ITERATOR_H

template<class T, class U>
struct Iterable
{
    T _begin;
    U _end;

    Iterable(T begin, U end)
    : _begin(begin), _end(end)
    {}

    T begin()
    {
        return _begin;
    }

    U end()
    {
        return _end;
    }
};

template<class T, class U>
Iterable<T,U> make_iterable(T t, U u)
{
    return Iterable<T,U>(t, u);
}

#endif //FINAL_FIGHT_ITERATOR_H