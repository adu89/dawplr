#pragma once

#include <vector>
#include <functional>
#include <algorithm>

template<class T>
class Listeners {
private:
	std::vector<T*> listeners;
public:
	void AddListener(T* l) { 
		auto e = std::find(listeners.begin(), listeners.end(), l);
		if(e == listeners.end())
			listeners.push_back(l);
	}

	void RemoveListener(T* l) {
		auto e = std::find(listeners.begin(), listeners.end(), l);
		if (e != listeners.end())
			std::remove(listeners.begin(), listeners.end(), l);
	}

	void Call(std::function<void(T*)> func)
	{
		std::for_each(listeners.begin(), listeners.end(), [&](T* t) { func(t); });
	}
};