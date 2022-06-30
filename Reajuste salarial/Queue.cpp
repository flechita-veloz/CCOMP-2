#include <iostream>

using namespace std;

template<class T>
struct nodo
{
  T value;
  nodo<T> *next;
  nodo(T v, nodo<T>*n=NULL)
  {
    value = v;
    next = n;
  }
   ~nodo()
  {
    cout<<"Soy el nodo "<<value<<" adios mundo cruel"<<endl;
  }
};

template<class T>
struct Queue
{
  nodo<T>* rear;
  nodo<T>* front= rear;
  bool isEmpty();
  void enqueue(T v);
  void dequeue();
  void print();
  ~Queue();
};

template<class T>
bool Queue<T>::isEmpty()
{
  return !front;
}

template<class T>
void Queue<T>::enqueue(T V)
{	
	if(isEmpty())
	{
		rear= NULL;
		front= new nodo<T>(V,rear);
		rear= front;
	}
	else
	{
		rear->next= new nodo<T>(V,rear->next);
		rear= rear->next;
	}
  	cout << V << " encolado a la cola\n";
}

template<class T>
void Queue<T>::print()
{
  cout<<"FRONT->";
  for(nodo<T> *p=front;p;p=p->next)
    cout<<p->value<<"->";
  cout<<"REAR->NULL"<<endl;
}

template<class T>
void Queue<T>::dequeue()
{
  nodo<T>*tmp;
  if(!isEmpty())
  {
  	tmp= front;
  	front= front->next;
  	delete tmp;
  }
}

template<class T>
Queue<T>::~Queue()
{
  while(front)
    dequeue();

  /*while(front)
    {
      cout<<"Destruyendo "<<front->value<<endl;
      pop();
    }*/
}

int main() {
  Queue<int> fila;
  
  fila.print();
  fila.enqueue(8);
  fila.print();
  fila.dequeue();
  fila.dequeue();
  fila.print();
  fila.enqueue(29);
  fila.print();
  fila.enqueue(10);
  fila.print();
  fila.enqueue(93);
  fila.print();
  fila.enqueue(16);
  fila.print();
  fila.dequeue();
  fila.print();
  return 0;
}
