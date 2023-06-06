#include "PQueue.hpp"

void swap(int* val1, int* val2) { // 스왑 함수
    int tmp = *val1;
    *val1 = *val2;
    *val2 = tmp;
}

PQueue::PQueue(int cap) {
  heap = new int[cap+1];
  capacity=cap;
  size=0;
}

PQueue::~PQueue() {
  delete heap;
}

void PQueue::insert(int data) {
	heap[++size] = data;
	int child = size;
	int parent = child / 2;

	while (child > 1 && heap[parent] < heap[child]) {
		swap(&heap[parent], &heap[child]);
		child = parent;
		parent = child / 2;
	}
}

void heapify(int* heap,int cur,int N){
    int cur_idx=cur;
    int l_child=cur*2;
    int r_child=cur*2+1;

    if ((l_child <= N) && (heap[l_child] > heap[cur_idx])) cur_idx=l_child;
    if ((r_child <= N) && (heap[r_child] > heap[cur_idx])) cur_idx=r_child;

    if (cur_idx != cur){
      swap(&heap[cur_idx],&heap[cur]);
      heapify(heap,cur_idx,N); // 재귀호출
    }
}

void PQueue::removeData(int data) {
  for(int i=1; i<size+1; i++){
    if(heap[i]==data){
      heap[i]=heap[size]; // 마지막 데이터와 스왑
      size--; // 배열 size 하나 줄임
      heapify(heap,i,size);
      break;
    }
  }
}

int PQueue::find(int data) {
  for(int i=1; i<size+1; i++){
    if(heap[i]==data){
      return i-1;
    }
  }
  return 0;
}

void PQueue::display() {
  for (int i=1; i<size+1; i++) {
    cout << heap[i] << " ";
  }
  cout << endl;
}

void PQueue::heapSort() {
  for (int i=size; i >= 2; i--){
    swap(&heap[i], &heap[1]);    // Root와 정렬이 안된 마지막 Node 교환.
    heapify(heap,1,i-1);       // 제자리 찾아가기!  
  }
}