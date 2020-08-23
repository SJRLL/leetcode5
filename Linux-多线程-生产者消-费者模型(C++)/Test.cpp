//###����BlockingQueue��������������ģ�� ####BlockingQueue,
//�ڶ��̱߳������������(Blocking Queue)��һ�ֳ�����ʵ�������ߺ�������ģ�͵����ݽṹ��
//������ͨ�Ķ����������ڣ�������Ϊ��ʱ���Ӷ��л�ȡԪ�صĲ������� ��������ֱ�������б�������Ԫ�أ�
//��������ʱ������������Ԫ�صĲ���Ҳ�ᱻ������ֱ����Ԫ�ر��Ӷ�����ȡ ��(���ϵĲ������ǻ��ڲ�ͬ���߳���˵�ģ�
//�߳��ڶ��������н��̲���ʱ�ᱻ����)

//C++ queueģ���������е���������ģ�� ���룺

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