//###基于BlockingQueue的生产者消费者模型 ####BlockingQueue,
//在多线程编程中阻塞队列(Blocking Queue)是一种常用于实现生产者和消费者模型的数据结构。
//其与普通的队列区别在于，当队列为空时，从队列获取元素的操作将会 被阻塞，直到队列中被放入了元素；
//当队列满时，往队列里存放元素的操作也会被阻塞，直到有元素被从队列中取 出(以上的操作都是基于不同的线程来说的，
//线程在对阻塞队列进程操作时会被阻塞)

//C++ queue模拟阻塞队列的生产消费模型 代码：

#include<iostream>
#include<queue>
#include<stdlib.h>
#include<pthread.h>

#define MUM 8

class BlockQueue{
private:
	std::queue<int> q;
	int cap;
	pthread_mutex_t lock;
	pthread_cond_t full;
	pthread_cond_t empty;

	private:
		void LockQueue()
		{
			pthread_mutex_lock(&lock);
		}
		void UnLockQueue()
		{
			pthread_mutex_unlock(&lock);
		}

		void ProductWait()
		{
			pthread_cond_wait(&full, &lock);
		}
		void ConsumeWait()
		{
			pthread_cond_wait(&empty, &lock);
		}
		void NotifyProduct()
		{
			pthread_cond_signal(&full);
		}
		void NotifConsume()
		{
			pthread_cond_signal(&empty);
		}
		bool IsEmpty()
		{
			return (q.size() == 0 ? true : false);
		}
		bool IsFull()
		{
			return (q.size() == cap ? true : false);
		}
		
public:
	BlockQueue(int _cap = MUM) :cap(_cap)
	{
		pthread_mutex_init(&lock, NULL);
		pthread_cond_init(&full,NULL);
		pthread_cond_init(&empty, NULL);
	}
	 
	void PushData(const int &data)
	{
		LockQueue();
		while (IsFull())
		{
			NotifConsume();
			std::cout << "queue is full,notify consume data, product stop." << std::endl;
			ProductWait();
		}
		q.push(data);
		NotifConsume();
		UnLockQueue();
	}

	void PopData(int &data)
	{
		LockQueue();
		while (IsFull())
		{
			NotifyProduct();
			std::cout << "queue is empty, notify data , consue stop." << std::endl;
			ConsumeWait();
		}
		data = q.front();
		q.pop();
		NotifConsume();
		UnLockQueue();
	}

	~BlockQueue()
	{
		pthread_mutex_destroy(&lock);
		pthread_cond_destroy(&full);
		pthread_cond_destroy(&empty);
	}
};

void *consumer(void *arg)
{
	BlockQueue *bqp = (BlockQueue*)arg;
	int data;
	for (;;)
	{
		bqp->PopData(data);
		std::cout << "Consue data done :" << data << std::endl;
	}
}

void *producter(void *arg)
{
	BlockQueue *bqp = (BlockQueue*)arg;
	srand((unsigned long)time(NULL));
	for (;;)
	{
		int data = rand() % 1024;
		bqp->PushData(data);
		std::cout << "Prodoct data done :" << data << std::endl;
	}
}

int main()
{
	BlockQueue bq;
	pthread_t c, p;
	pthread_create(&c, NULL, consumer, (void*)&bq);
	pthread_create(&p, NULL, producter, (void*)&bq);

	pthread_join(c, NULL);
	pthread_join(p, NULL);
	return 0;

}