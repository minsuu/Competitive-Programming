#include <bits/stdc++.h>
using namespace std;
const int ALPHABETS=26;
const int INF = 987654321;
inline int toNumber(char k){
	return k-'A';
}

struct TrieNode{
	int terminal,no, val;
	TrieNode* fail;
	vector<TrieNode*> children;
	vector<TrieNode*> next;
	TrieNode():terminal(-1), val(0), children(ALPHABETS,0),
				next(ALPHABETS,0) { }
	~TrieNode(){
		for(int i=0;i<children.size();i++)
			if(children[i])
				delete children[i];
	}
	void insert(const char* key, int id){
		if(*key=='0'){
			terminal=id;
		}else{
			int next=toNumber(*key);
			if(children[next]==NULL)
				children[next]=new TrieNode();
			children[next]->insert(key+1,id);
		}
	}
	TrieNode* find(const char* key){
		if(*key==0) return this;
		int next=toNumber(*key);
		if(children[next]==NULL) return NULL;
		return children[next]->find(key+1);
	}
};

void computeFailFunc(TrieNode* root){
	queue<TrieNode*> q;
	root->fail=root;
	q.push(root);
	while(!q.empty()){
		TrieNode* here=q.front(); q.pop();
		for(int edge=0;edge<here->children.size();edge++){
			TrieNode* child=here->children[edge];
			if(!child) continue;
			if(here==root) child->fail=root;
			else{
				TrieNode* t=here->fail;
				while(t!=root && !(t->children[edge]))
					t=t->fail;
				if(t->children[edge]) t=t->children[edge];
				child->fail=t;
			}
			child->val = child->fail->val;
			if(child->terminal!=-1)
				child->val += child->terminal;
			q.push(child);
		}
	}
}

const int MOD=10007;
int wei[30];
int cache[101][1001];
int count(int length, TrieNode* state){
	if(length==0) return 1;
	int& ret=cache[length][state->no];
	if(ret!=-1) return ret;
	ret=0;
	for(int letter=0;letter<(state->children.size());letter++){
		ret+=count(length-1, state->next[letter]);
		ret%=MOD;
	}
	return ret;
}
void computeNext(TrieNode* root,int& cnt){
	root->no=cnt++;
	for(int letter=0;letter<(root->children.size());letter++){
		TrieNode* state=root;
		while(state!=state->fail && !(state->children[letter]))
			state=state->fail;
		if(state->children[letter]) state=state->children[letter];
		root->next[letter]=state;
		
		if(root->children[letter])
			computeNext(root->children[letter],cnt);
	}
}

int main() {
	int T,N,M,B, val;
	char buf[1024];
	scanf("%d",&T);
	for(int t=1; t<=T; t++){
		memset( cache, -1, sizeof cache );
		scanf("%d%d%d",&N,&M,&B);
		for(int i=0; i<N; i++){
			scanf("%s%d",buf,&val);
			wei[ toNumber(buf[0]) ] = val;
		}
		TrieNode* trie = new TrieNode;
		for(int i=0; i<M; i++){
			scanf("%s%d",buf,&val);
			trie->insert( buf, val );
		}
		computeFailFunc( trie );
		int i=0; computeNext( trie, i );
		printf("%d\n",i);
		delete trie;
	}
	return 0;
}
