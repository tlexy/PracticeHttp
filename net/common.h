#ifndef ELIXIR_COMMON_H
#define ELIXIR_COMMON_H

#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>

namespace Elixir{

typedef boost::function<void()> Functor;
typedef Functor TimerFunctor;

#define SHAREDPTR(TYPE,PTR) typedef boost::shared_ptr<TYPE> PTR;

}

#endif
