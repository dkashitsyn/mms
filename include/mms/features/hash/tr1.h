#pragma once

#ifndef MMS_USE_TR1
#    error should be used only with MMS_USE_TR1 enabled
#endif

#include <cstddef>

#include <tr1/functional>

namespace mms {

namespace impl {

template<class T>
inline size_t hash_combine(size_t hash, const T& t)
{
	return hash ^ (std::tr1::hash<T>()(t) + 0x9e3779b9 + (hash << 6) + (hash >> 2)); // stolen from boost
}

template<class Iter>
inline size_t hash_range(Iter begin, Iter end)
{
	size_t h = 0;
	for (; begin != end; ++begin)
		h = hash_combine(h, *begin);
	return h;
}

}

}
