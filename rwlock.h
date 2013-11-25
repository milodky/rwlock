#ifndef RWLOCK_H_
#define RWLOCK_H_
#include <mutex>
#include <iostream>
using std::mutex;
using std::cout;
using std::endl;
class rwlock {
public:
	rwlock() : Count(0) {}
	void writer_lock(void);
	void writer_unlock(void);

	void reader_lock(void);
	void reader_unlock(void);
	~rwlock(){}
private:
	mutex rlock;
	mutex wlock;
	int Count;
};


#endif
