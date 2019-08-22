#pragma once


template <class T>

class Singleton
{
private:
	static T* _instance;
public:
	static T * GetInstance()
	{
		if (_instance == nullptr)
			_instance = new T();
		return _instance;
	}
};

template<class T> T* Singleton<T>::_instance = nullptr;


class Time
{
public:
	static float deltaTime;
	static float timeScale;
};