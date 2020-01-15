#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#include "heap.h"



void print_hello()
{
	printf("hello world\n");
}

int main()
{
	/*
	heap *hp = new heap;
	node *nd1 = new node;
	node *nd2 = new node
	*/

	heap hp(10);
	node nd1(5);
	nd1.cb_func = print_hello;

	node nd2(10);
	nd2.cb_func = print_hello;

	node nd3(15);
	nd3.cb_func = print_hello;

	node nd4(20);
	nd4.cb_func = print_hello;

	node nd5(25);
	nd5.cb_func = print_hello;
	
	node nd6(30);
	nd6.cb_func = print_hello;

	hp.MinHeapAddNumber(&nd1);
	hp.MinHeapAddNumber(&nd2);
	hp.MinHeapAddNumber(&nd3);
	hp.MinHeapAddNumber(&nd4);
	hp.MinHeapAddNumber(&nd5);
	hp.MinHeapAddNumber(&nd6);

	while(1)
	{
		int timeout;
		struct timeval tv;
		if(hp.top() == NULL)
		{
			timeout = 0;
		}
		else 
		{
			timeout = hp.top()->expire - time(NULL);
		}
		tv.tv_sec = timeout;
		tv.tv_usec = 0;
		select(0,NULL,NULL,NULL,&tv);
		hp.tick();
	}

	return 0;
}



























