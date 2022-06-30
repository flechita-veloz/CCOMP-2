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
struct Stack
{
  nodo<T>* top= NULL;
  bool isEmpty();
  void push(T v);
  void pop();
  void print();
  ~Stack();
};

template<class T>
bool Stack<T>::isEmpty()
{
  return !top;
}

template<class T>
void Stack<T>::push(T V)
{
  top= new nodo<T> (V,top);
  cout << V << " pusheado a la pila\n";
}

template<class T>
void Stack<T>::print()
{
  cout<<"TOP->";
  for(nodo<T> *p=top;p;p=p->next)
    cout<<p->value<<"->";
  cout<<"NULL"<<endl;
}

template<class T>
void Stack<T>::pop()
{
  nodo<T>*tmp;
  if(!isEmpty())
  {
  	tmp= top;
  	top= top->next; 
    delete tmp;
  }
}

template<class T>
Stack<T>::~Stack()
{
  while(top)
    pop();

  /*while(top)
    {
      cout<<"Destruyendo "<<top->value<<endl;
      pop();
    }*/
}

int main() {
  Stack<int> pila;

  pila.print();
  pila.push(2);
  pila.print();
  pila.push(4);
  pila.print();
  pila.push(10);
  pila.print();
  pila.push(1);
  pila.push(9);
  pila.print();
  pila.pop();
  pila.print();
  pila.pop();
  pila.pop();
  pila.print();
  pila.push(100);
  pila.print();
  pila.pop();
  pila.print();
  pila.pop();
  pila.pop();
  pila.print();
  return 0;
}
