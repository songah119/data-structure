#include "Queue.hpp"

template<typename T>
Queue<T>::Queue(int size) {// constructor
		this->queue = new char[size]; //char타입의 배열 생성
		front_p = rear_p = -1; //front와 rear 를 같은 -1 인덱스로 초기화
		this->queue_size = size; //사이즈 멤버변수에 초기값 할당
}

template<typename T>
Queue<T>::~Queue() {// destructor
	clear(); //clear함수 호출
}

template<typename T>
void Queue<T>::enqueue(T data) {// enqueue
	if ((rear_p + 1)%queue_size == front_p){ //원형큐가 모두 차있는 경우
    cout<<"Queue is full\n" << endl;
		exit(-1);
	}
	else{
  	if( front_p == -1) //첫번째 원소 삽입
		front_p = 0; //인덱스 증가시킴
		rear_p = (rear_p+1)%queue_size; //rear은 rear+1을 큐 사이즈로 나눔 -> 원형큐이기 때문
		queue[rear_p] = data; //해당 인덱스에 데이터 할당
	}
}

template<typename T>
void Queue<T>::dequeue() {// dequeue
	if( isEmpty() ) //큐가 비어있는 경우
  cout<<"Queue is empty\n" << endl;
	else 
	if( front_p == rear_p )
	front_p = rear_p = -1; //오직 하나의 원소
	else
  front_p = (front_p + 1) % queue_size; //front 인덱스를 한칸 옮김
}

template<typename T>
T Queue<T>::front() { // return front data
	if (isEmpty()) { 
		cout << "Queue is empty\n" << endl;
		exit(-1);
	}
	else return queue[front_p]; //front가 가리키는 값을 반환함
}

template<typename T>
bool Queue<T>::isEmpty() { // return 1 if empty
if(front_p == -1 && rear_p == -1) //인덱스가 모두 -1인 경우 비어있음
return true;
else
return false;
}

template<typename T>
bool Queue<T>::isFull() {// return 1 if full
	if (front_p == 0 && rear_p == queue_size - 1) { //front=0 이고 rear=큐 사이즈-1 이거나
      return true;
    }
    if (front_p == rear_p + 1) { //front가 rear+1과 같으면 모두 찬것이다
      return true;
    }
    return false;
}

template<typename T>
int Queue<T>::size() {// return size of the queue
return (queue_size + rear_p - front_p + 1) % queue_size; //큐에 들어있는 원소들의 수는 큐사이즈+rear포인터-front포인터+1 을 큐 사이즈로 나눈 값이다.
}

template<typename T>
void Queue<T>::clear() {// clear the queue
	while(size()!=0){ //사이즈가 0이 될때까지 디큐를 실행
		dequeue();
	}
}

template<typename T>
void Queue<T>::printQueue() {// print all elements in the queue
	for (auto i = front_p; true; i = (i + 1) % queue_size) { //i값을 front 인덱스부터 하나씩 증가시키면서 배열의 끝값까지 출력
		cout << queue[i] << " ";
		if (i == rear_p) {
			break;
		}
	}
	cout << endl;
	cout << "Queue is empty\n" << endl;
}