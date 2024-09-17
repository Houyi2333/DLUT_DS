// Stack.h: interface for the Stack class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STACK_H__318C7505_4109_42F0_8C2C_BFD6A005065C__INCLUDED_)
#define AFX_STACK_H__318C7505_4109_42F0_8C2C_BFD6A005065C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

template <class T>
class Stack{
public:
	Stack(int MaStackSize=10);
	~Stack() { delete [] stack;}
	bool IsEmpty() const {return top==-1;}
	bool IsFull() const {return top==MaxTop;}
	T Top() const;
	Stack<T>& push(const T& x);
	Stack<T>& pop(T& x);
	void MakeEmpty(){top=-1;} //���ջ
private:
	int top;//ջ��
	int MaxTop;//����ջ��ֵ
	T *stack;//��ջԪ������
};
template<class T>
Stack<T>::Stack(int MaxStackSize)
{
	MaxTop=MaxStackSize-1;
	stack=new T[MaxStackSize];
	top=-1;
}

template<class T>
T Stack<T>::Top() const
{
	if(IsEmpty())
	{cout<<"no element";return -1;}
	else
		return stack[top];
}
template<class T>
Stack<T>& Stack<T>::push(const T& x)
{
	if(IsFull())
	{cout<<"no memory;"<<endl;return *this;}
	top=top+1;
	stack[top]=x;
	return *this;
}
template<class T>
Stack<T>& Stack<T>::pop(T& x)
{
	if(IsEmpty())
	{cout<<"no element"<<endl;return *this;}
	x=stack[top];
	top=top-1;
	return *this;
}

#endif // !defined(AFX_STACK_H__318C7505_4109_42F0_8C2C_BFD6A005065C__INCLUDED_)
