/* my own simple reader/writer lock, to be implemented */
#include "rwlock.h"

void rwlock::writer_lock()
{
	wlock.lock();
}

void rwlock::writer_unlock()
{
	wlock.unlock();
}


void rwlock::reader_lock()
{
	rlock.lock();
	Count++;
	if (Count == 1)
		wlock.lock();
	rlock.unlock();
}

void rwlock::reader_unlock()
{
	rlock.lock();
	Count--;
	if (Count == 0)
		wlock.unlock();
	rlock.unlock();
}

