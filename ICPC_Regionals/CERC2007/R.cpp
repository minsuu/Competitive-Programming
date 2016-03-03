#include <bits/stdc++.h>
using namespace std;
int score[3][3] = { {0,1,0}, {0,0,1}, {1,0,0} };
map<string, int> words;
string rock[] = { "Kamen", "Rock", "Pierre", "Stein", "Ko", "Koe", "Sasso", "Roccia", "Guu", "Kamien", "Piedra" };
string sci[] = { "Nuzky", "Scissors", "Ciseaux", "Schere", "Ollo", "Olloo", "Forbice", "Choki", "Nozyce", "Tijera" };
string pap[] = { "Papir", "Paper", "Feuille", "Papier", "Papir", "Carta", "Rete", "Paa", "Papier", "Papel" };

string buf, A, B, C, D;
int main(){
	for( auto it : rock )
		words[it] = 0;
	for( auto it : sci )
		words[it] = 1;
	for( auto it : pap )
		words[it] = 2;

	ios::sync_with_stdio(false);
	for( int tt=1; ; tt++ ){
		cin >> buf >> A;
		cin >> buf >> B;
		int as = 0, bs = 0;
		bool ended = false;
		while( 1 ){
			cin>>C;
			if( C == "-" ) break;
			if( C == "." ) { ended = true; break; }
			cin>>D;
			int c = words[C], d = words[D];
			as += score[c][d];
			bs += score[d][c];
		}
		cout<<"Game #"<<tt<<":\n";
		if( as == 1 )
			cout<<A<<": "<<as<<" point\n";
		else
			cout<<A<<": "<<as<<" points\n";
		if( bs == 1 )
			cout<<B<<": "<<bs<<" point\n";
		else
			cout<<B<<": "<<bs<<" points\n";

		if( as == bs ) cout<<"TIED GAME\n\n";
		else{
			cout<<"WINNER: "<<( as>bs ? A : B )<<"\n\n";
		}
		if( ended ) break;
	}
	return 0;
}
