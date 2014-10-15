#include<iostream>
#include<vector>
#include<queue>

using namespace std;

  struct ListNode {

     int val;

     ListNode *next;

     ListNode(int x) : val(x), next(NULL) {}

 };


    struct DT{

        ListNode * node;

        int idx;

        DT(ListNode * n):node(n){}

        bool operator<(const DT&r) const{

            return node->val>r.node->val;

        }

    };

    ListNode *mergeKLists(vector<ListNode *> &lists) {

        priority_queue<DT> pq;

        ListNode*head=NULL,*curr=NULL;

        for(auto*node:lists)

            if(node)

            pq.push(DT(node));

        while(pq.size()){

            auto dt=pq.top();

            pq.pop();

            if(curr)

                curr=curr->next=dt.node;

            else

                head=curr=dt.node;


            if(dt.node->next)

                pq.push(DT(dt.node->next));

		cout<<pq.size()<<" xx "<<endl;

        }

        return head;

    }

int main(){
	ListNode A(1);
	ListNode B(2);
	vector<ListNode*> C={&A,&B};
	mergeKLists(C);

}
