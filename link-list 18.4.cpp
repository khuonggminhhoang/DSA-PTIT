	#include<iostream>
	
	using namespace std;
	
	struct Node {
		int data;
		Node* next;
	};
	
	typedef Node* node;
	
	int size(node a){
		int cnt=0;
		while(a != nullptr){
			cnt++;
			a=a->next;
		}
		return cnt;
	}
	
	node makeNode(int x){
		node res = new Node;
		res->data=x;
		res->next= nullptr;
		return res;
	}
	
	void insert_last(node &a, int  new_data){
		node tmp = makeNode(new_data);
		if(a == nullptr){
			a=tmp;
		}
		else{
			node p = a;
			while(p->next != nullptr){
				p = p->next;
			}
			p->next = tmp;
		}
	}
	
	void insert_first(node &a, int new_data){
		node tmp = makeNode(new_data);
		if(a== nullptr) a=tmp;
		else{
			tmp->next = a;
			a = tmp;
		}
	}
	
	void insert_middle(node &a, int pos ,int data){
		int n = size(a);
		if( pos <=0 || pos > n+1) return;
		else{
			node cur = a;
			int i=1;
			if(pos ==1){
				insert_first(a,data);
				return;
			}
			else{
				for(int i=1; i<pos-1; ++i){
					cur = cur->next;
				}
				node tmp = new Node;
				tmp->data = data;
				tmp->next = cur->next;
				cur->next = tmp;
			}
		}
	}
	
	void delete_first( node &a){
		if( a == nullptr) return;
		a = a->next;
	}
	
	void delete_last(node &a){
		if(a== nullptr) return;
		if( a->next == nullptr) a = nullptr;
		else{
			node cur = a;
			node pre = new Node;
			while(cur->next != nullptr){
				pre = cur;
				cur = cur->next;
			}
			pre->next = nullptr;
		}
	}
	
	void delete_middle(node &a, int pos){
		int n=size(a);
		if(pos <=0 || pos > n+1) return;
		if(pos == 1) delete_first(a);
		else{
			node pre = new Node;
			node cur = new Node;
			pre = nullptr;
			cur = a;
			for(int i=1; i<pos; ++i){
				pre = cur;
				cur = cur->next;
			}
			pre->next = cur->next;
		}
	}
	
	void fix(node &a, int pos, int data){
		int n = size(a);
		if( pos <=0 || pos > n+1) return;
		else{
			node cur = a;
			for(int i=1; i< pos; ++i){
				cur = cur->next;
			}
			cur->data = data;
		}
	}
	
	void display(node a){
		while(a != nullptr){
			cout<<a->data<<" ";
			a=a->next;
		}
	}
	
	main(){
		node head = nullptr;
		insert_last(head,2);			// chen cuoi list
		insert_last(head,3);			
		insert_first(head,1);			// chen dau list
		insert_first(head,100);
		insert_middle(head,1,0);		// chen giua 
		delete_last(head);				// xoa cuoi
		delete_first(head);				// xoa dau
		delete_middle(head,5);			// xoa giua
		fix(head,1,10);					// sua tai vi tri 1
		display(head);
	}
	

