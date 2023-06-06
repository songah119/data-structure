#include "PQueue.hpp"
#include "PQueue.cpp"

int main() {
	PQueue pqueue(20);
	pqueue.insert(45);
	pqueue.insert(20);
	pqueue.insert(14);
	pqueue.insert(12);
	pqueue.insert(31);
	pqueue.insert(7);
	pqueue.insert(11);
	pqueue.insert(13);
	pqueue.insert(7);
	pqueue.display(); // for i<size 인 값을 모두 출력
	pqueue.removeData(45); //해당 값을 삭제
	pqueue.display(); //값 다 뽑아내는 거
	cout << pqueue.find(12) << endl; //몇번 인덱스인지 반환
	pqueue.heapSort(); // min heap으로 sorting
	pqueue.display(); // min heap

	return 0;
}
