/*
 * list.h
 *
 *  Created on: May 17, 2011
 *      Author: andre
 */

#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include <fstream>
using namespace std;

template <class T>
	class list {
	private:
		class node{
		public:
			T info;
			node* next;

		};
	private:
		node* first;
		node* last;
		int size;
	public:
		list();
		int isEmpty();
		int getSize();
		void insertList(T);
		void insertList(T inf,int(*cmp)(T inf, T inf2,char c),char c);
		void insertList(T inf,int(*cmp)(T inf, T inf2,char c),char c,int sign);
		int seek(T info, int(*cmp)(T info1,T info2));
		int getNid(T info,int(*cmp)(T info1,T info2));
		T seek(string tag,int(*cmp)(string t,T info2));
		T seek(int);
		void setCh(int(*cmp)(T inf, T inf2),void (*func)(T inf,char c),char c);
		void updateCh(int(*cmp)(T inf, T inf2),void (*func)(T inf,char c),char c);
		void action(void(*funcao)(T info));
		void action(ofstream &out,void(*funcao)(ofstream &out,T info,int i));
		void action(ofstream &out,void(*funcao)(ofstream &out,T info,int i,char),char c);
		void action(ofstream &out,void(*funcao)(ofstream &out,T info));
		//T copyNode(T* n,void(*copyFunction)(T info));
		//void secondaryList(list<T>* l,void(*copyFunction)(T info),int(*condition)(T info));
		void secondaryList(list<T>* l,int(*condition)(T info));
		void secondaryList(list<T>* l,int(*condition)(T info),int(*cmp)(T,T,char));
		void secondaryList(list<T>* l,int(*condition)(T info),int (*cmp)(T,T,char),int sign);
		void secondaryList(list<T>* l,int(*condition)(T info,int n),int (*cmp)(T,T,char),int sign,int n);
		~list();
};

template <class T>
list<T>::list() {
	first = NULL;
	last=first;
	size=0;
}

template <class T>
int list<T>::getSize() {
	return size;
}

template <class T>
int list<T>::isEmpty() {
	return (!first);
}

template <class T>
void list<T>::insertList(T inf) {
	int i;
	node *aux = new node();
	aux->info = inf;
	if(size==0) {
		first = aux;
		last = first;
		size++;
		return;
	}
	node* aux2 = first;
	for(i=0;i<size-1;i++) aux2 = aux2->next;
	aux2->next = aux;
	last = aux;
	size++;
}

template <class T>
void list<T>::setCh(int(*cmp)(T inf, T inf2),void (*func)(T inf,char c),char c) {

	char a,b;
	a = 'a';
	node *aux,*aux2;
	aux = first;
	while(aux->next) {
		aux2 = aux->next;
		b = 'b';
		while(aux2) {
			if(cmp(aux->info,aux2->info)==0) {
				func(aux->info,a);
				func(aux2->info,b);
				b++;
			}
			aux2=aux2->next;
		}
		aux = aux->next;
	}
}

template <class T>
void list<T>::updateCh(int(*cmp)(T inf, T inf2),void (*func)(T inf,char c),char c) {

	char a,b;
	int i;
	a = 'a';
	node *aux,*aux2;
	aux = first;
	while(aux) {
		aux2 = first;
		b = 'b';
		while(aux2) {
			if(cmp(aux->info,aux2->info)==0) {
				func(aux->info,a);
				func(aux2->info,b);
				b++;
			}
			aux2=aux2->next;
		}
		if(b=='c') func(aux->info,0);
		for(i='a';(aux)&&i<b;i++) aux = aux->next;
	}

	aux = first;
	while(aux->next) {
		aux2 = aux->next;
		b = 'b';
				while(aux2) {
					if(cmp(aux->info,aux2->info)==0) {
						func(aux->info,a);
						func(aux2->info,b);
						b++;
					}
					aux2=aux2->next;
				}
				for(i=0;i<(b-a);i++) aux=aux->next;
			}

}

template <class T>
void list<T>::insertList(T inf,int(*cmp)(T inf, T inf2,char c),char c) {
	node *aux = new node();
	aux->info = inf;
	if(size==0) {
		first = aux;
		last = first;
		size++;
		return;
	}
	node *iterator = first;
	if(cmp(inf,iterator->info,c) == -1) { //Nesse caso, precisamos inserir no first
		aux->next = first;
		first = aux;
		size++;
		return;
	}
	while(iterator->next) {
		if(cmp(inf,iterator->next->info,c) == -1) { //Menor que o proximo
			aux->next = iterator->next;
			iterator->next = aux;
			size++;
			return;
		}
		iterator = iterator->next;
	}
	iterator->next = aux;
	size++;
}


template <class T>
void list<T>::action(void(*funcao)(T info)){
  node *aux;
  for(aux=first;aux!=NULL;aux=aux->next) funcao(aux->info);
}

template <class T>
void list<T>::action(ofstream &out,void(*funcao)(ofstream &out0,T info,int i)){
  node *aux;
  int i=1;
  for(aux=first;aux!=NULL;aux=aux->next,i++) funcao(out,aux->info,i);

}

template <class T>
void list<T>::action(ofstream &out,void(*funcao)(ofstream &out,T info,int i,char),char c) {
	node *aux;
	  int i=1;
	  for(aux=first;aux!=NULL;aux=aux->next,i++) funcao(out,aux->info,i,c);
}

template <class T>
void list<T>::action(ofstream &out,void(*funcao)(ofstream &out,T info)) {
	node *aux;
	int i;
	aux = first;
	for(i=0;i<size-1;i++,aux=aux->next) {funcao(out,aux->info); out << ", ";}
	funcao(out,aux->info);
	out << endl;
}

template <class T>
int list<T>::seek(T info,int(*cmp)(T info1,T info2)) {
	node *aux;
	int i=0;
	for(aux=first;aux!=NULL && i==0;aux=aux->next) i+= cmp(aux->info,info);
	return i;
}

template <class T>
int list<T>::getNid(T info,int(*cmp)(T info1,T info2)) {
	node *aux;
	int i=0,cont=0;
	for(aux=first;aux!=NULL && i==0;aux=aux->next,cont++) i+= cmp(aux->info,info);
	return cont;
}

template <class T>
T list<T>::seek(string tag,int(*cmp)(string t,T info2)) {
	node *aux;
	int i=0,j;
	for(aux=first,j=0;j<size;aux=aux->next,j++) {
		i+= cmp(tag,aux->info);
		if(i!=0) break;//return aux->info;
	}
	return aux->info;
}

template <class T>
void list<T>::secondaryList(list<T>* l,int(*condition)(T info)) {
	node *aux2;
	aux2 = l->first;
	while(aux2) {
		if(condition(aux2->info)) {
			insertList(aux2->info);
		}
		aux2=aux2->next;
	}
}

template <class T>
void list<T>::secondaryList(list<T>* l,int(*condition)(T),int (*cmp)(T,T,char),int sign) {
	node *aux2;
	aux2 = l->first;
	while(aux2) {
		if(condition(aux2->info)) {
			insertList(aux2->info,cmp,'h',sign);
		}
		aux2=aux2->next;
	}
}

template <class T>
void list<T>::secondaryList(list<T>* l,int(*condition)(T,int),int (*cmp)(T,T,char),int sign,int n) {
	node *aux2;
	aux2 = l->first;
	while(aux2) {
		if(condition(aux2->info,n)) {
			insertList(aux2->info,cmp,'h',sign);
		}
		aux2=aux2->next;
	}
}


template <class T>
void list<T>::insertList(T inf,int(*cmp)(T inf, T inf2,char c),char c, int sign) {
	node *aux = new node();
	aux->info = inf;
	if(size==0) {
		first = aux;
		last = first;
		size++;
		return;
	}
	node *iterator = first;
	if((sign * cmp(inf,iterator->info,c)) == -1) { //Nesse caso, precisamos inserir no first
		aux->next = first;
		first = aux;
		size++;
		return;
	}
	while(iterator->next) {
		if((sign * cmp(inf,iterator->next->info,c)) == -1) { //Menor que o proximo
			aux->next = iterator->next;
			iterator->next = aux;
			size++;
			return;
		}
		iterator = iterator->next;
	}
	iterator->next = aux;
	size++;
}

template <class T>
T list<T>::seek(int i) {
	if(i > size || i==0) return NULL;
	node *aux = first;
	int j;
	for(j=0;j<(i-1);j++) aux = aux->next;
	return aux->info;
}

template <class T>
list<T>::~list() {
	node *auxprev,*aux;
	aux = first;
	auxprev = aux;
	while(aux) {
		aux = aux->next;
		delete auxprev;
		auxprev = aux;
	}
}
#endif /* LIST_H_ */
