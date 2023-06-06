#include "Stack.hpp"

template<typename T>
Stack<T>::Stack() {// constructor
		Node* newNode; //새로운 노드를 생성한다.
		newNode->next=NULL; //첫 next 포인터는 null값으로 초기화한다
		newNode->data=0; //데이터값 역시 0으로 초기화한다
		this->topNode=newNode; //topNode는 지금 생성한 노드로 초기화
}

template<typename T>
Stack<T>::~Stack() {// destructor
	clear();
}

template<typename T>
void Stack<T>::push(T data) { // push
	Node* newNode; //노드 생성
	
	newNode->data = data; //사용자의 입력을 해당 노드의 데이터변수에 할당한다
	newNode->next = this->topNode; //새로운 노드의 다음 노드를 현재 노드의 topNode로 설정
	this->topNode = newNode; //스택의 topNode를 새로운 노드로 설정
}

template<typename T> 
void Stack<T>::pop() { // pop
	Node* temp; //임시 노드

	if(isEmpty()){ //비어있는 경우
		printf("Stack is empty");
		exit(-1);
	}

	temp=this->topNode; //임시노드에 현재 최상단 노드를 할당
	this->topNode=this->topNode->next; //노드 루트 변경
	free(temp); //현재 값을 버림
}

template<typename T>
T Stack<T>::top() {// return top data
	if ( isEmpty() ) {
		printf("Stack is empty");
		exit(-1);
	}
	return this->topNode->data; //현재 topNode의 값을 반환
}

template<typename T>
bool Stack<T>::isEmpty() {// return 1 if empty
	return this->topNode == NULL; //topNode가 null이면 비어있는 것임
}

template<typename T>
int Stack<T>::size() {// return size of the stack
	Node* temp=this->topNode; //임시노드에 탑노드를 할당

	int count=0; 
	while(temp->next!=NULL){ //노드를 순회하면서 카운트를 증가시킴
		temp=temp->next;
		count++;
	}
	return count;
}

template<typename T>
void Stack<T>::clear() {// clear the stack
  while (size()!=0) { //stack size가 0이 될때 까지 
    pop(); //값을 꺼냄
  }
}

template<typename T>
void Stack<T>::printStack() {// print all elements in the stack
	Node* temp;
  if (isEmpty()) {
    cout << "Stack is Empty"<< endl;;
		exit(-1);
  }
  else { //값이 있는 경우
    temp = topNode; //탑노드값부터
    while (temp != NULL) { //topNode가 null이 될 때까지
			cout << temp->data; //데이터 출력
			temp = temp->next; //다음 노드로 이동
			if(temp != NULL)
			cout << " " << endl;;
      }
    }
}

