#include <bits/stdc++.h>
#include <dirent.h>
using namespace std;

std::string exec(const char* cmd) {
    FILE* pipe = popen(cmd, "r");
    if (!pipe) return "ERROR";
    char buffer[128];
    std::string result = "";
    while (!feof(pipe)) {
        if (fgets(buffer, 128, pipe) != NULL)
            result += buffer;
    }
    pclose(pipe);
    return result;
}

long long expected;
vector<string> TCS;

int main(){

	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir ("C:\\Users\\Minsu\\Documents\\Competitive-Programming\\ICPC_Regionals\\NWERC2014")) != NULL) {
	  /* print all the files and directories within directory */
	  while ((ent = readdir (dir)) != NULL) {
	  	string d(ent->d_name);
	  	if( d.find(".in") != string::npos )
	  		TCS.push_back(d);
	  }
	  closedir (dir);
	} else {
	  /* could not open directory */
	  perror ("");
	  return EXIT_FAILURE;
	}

	for( auto in : TCS ){
		string res = exec( ( "G.exe < " + in ).c_str() );
		long long myans;
		if( sscanf(res.c_str(), "%lld", &myans) == 0 ) myans = -1;

		FILE *ans = fopen( ( string( in.begin(), in.end() - 3 ) + ".ans" ).c_str(), "r" );
		if( fscanf(ans, "%lld", &expected ) == 0 ) expected = -1;
		fclose(ans);

		cout<<myans << " "<< expected <<"\n";
	}
	return 0;
}