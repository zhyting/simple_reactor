#include <memory>
#include <stdio.h>
#include <iostream>
#include <time.h>

class node{
public: 
	/*
	node(int num) : val(num) {}
	int val;
	*/
	node(int delay_seconds) {
		expire = time(NULL) + delay_seconds;
	}
	time_t expire;
	void (*cb_func)(void);

};

class heap{
public:
	heap(int cap) : capacity(cap) {
		cur = 0;
		arr = new node* [capacity];
		for(int i = 0; i < capacity; ++i)
		{
			arr[i] = NULL;
		}
	}
	~heap()
	{
		//for(int i = 0;i < )
	}
	//void MinHeapAddNumber(node &arr,int insert_loc,int insert_val);
	//void MinHeapDeleteNumber(node arr[],int cur_length);

	void dbg_print(void)
	{
		for(int j = 0; j < cur; ++j)
			std::cout << arr[j]->expire << "	";
		printf("\n");
	}

	void MinHeapAddNumber(node* insert_val)
	{
		int insert_loc = cur;
		arr[cur++] = insert_val;
		MinHeapFixup(insert_loc);
	}
	void MinHeapDeleteNumber(void)
	{
		int cur_length;

		arr[0] = arr[cur-1];
		cur --;
		cur_length = cur;
		MinHeapFixdown(0,cur_length);
	}

	bool empty() const { return cur == 0; }

	node* top() const 
	{
		if(empty())
		{
			return NULL;
		}
		return arr[0];
	}

	void tick()
	{
		node* expire_node = arr[0];
		time_t cur_time = time(NULL);
		while(!empty())
		{
			if(!expire_node)
			{
				break;
			}
			if(expire_node->expire > cur_time)
			{
				break;
			}
			if(arr[0]->cb_func)
				arr[0]->cb_func();
			MinHeapDeleteNumber();
			expire_node = NULL;
		}
	}
private:
	//void MinHeapFixup(node &arr,int insert_loc);
	//void MinHeapFIxdown(node &arr,int i,int cur_length);

	void MinHeapFixup(int insert_loc)
	{
		int j;
		node *temp;

		temp = arr[insert_loc];
		j = (insert_loc - 1)/2;

		while(j>=0 && insert_loc!=0)
		{
			if(arr[j]->expire <temp->expire)
				break;
			arr[insert_loc] = arr[j];
			insert_loc = j;
			j = (insert_loc-1)/2;
		}
		arr[insert_loc] = temp;

	}
	void MinHeapFixdown(int i,int cur_length)
	{
		int j;
		node* temp;

		temp = arr[i];

		j = 2*i +1;
		while(j < cur_length)
		{
			if(j+1<cur_length && arr[j+1]->expire <arr[j]->expire)
				j++;
			if(arr[j]->expire >= temp->expire)
				break;
			arr[i] = arr[j];
			i = j;
			j = 2*i +1;
		}
		arr[i] = temp;
	}

	int cur;
	int capacity; 
	node **arr;

};