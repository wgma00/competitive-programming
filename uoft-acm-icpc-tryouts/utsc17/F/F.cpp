#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#define needforspeed ios::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define mp make_pair
#define mp3(a,b,c) make_pair(a,make_pair(b,c))
#define mp4(a,b,c,d) make_pair(make_pair(a,b),make_pair(c,d))
#define trace1(a) cout << (#a) << ":" << (a);
#define trace2(a,b) trace1(a); cout << " "; trace1(b); cout << endl; 
#define trace3(a,b,c) trace1(a); cout << " "; trace1(b); cout << " "; trace1(c); cout << endl;  
#define trace4(a,b,c,d) trace1(a); cout << " "; trace1(b); cout << " "; trace1(c); cout << " "; trace1(d); cout << endl;  
#define ms(a,b) memset( (a), (b), sizeof(a))
#define Fill(a,b) fill((a), (a)+sizeof(a)/sizeof((a)[0]), (b));
#define Fill2D(a,b) fill(&(a)[0][0], &(a)[0][0]+sizeof(a)/sizeof((a)[0][0]), (b))
#define Fill3D(a,b) fill(&(a)[0][0][0],&(a)[0][0][0]+sizeof(a)/sizeof((a)[0][0][0]), (b))
#define all(x) (x).begin(),(x).end()
#define len(x) (int)(x).size()
#define xx first
#define yy second
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MAXN (int)1e9
#define MOD 1000000007
#define inf 0x3f3f3f3f
#define db 0
using namespace std;

int string_to_int(string s);
string int_to_string(int i);
vector<string>split(string s, char delim);
template< class T>
void print_vec(vector<T>vec, bool new_line=false);

int x,y,n;


enum dir{NORTH, WEST, SOUTH, EAST};
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};


pair<int,int> simulate(vector<string>ins){
    int cx = 0, cy = 0, dir = NORTH;
    for(int i = 0;i < len(ins);i++){
        if(ins[i] == "Forward"){
            cx += dx[dir];
            cy += dy[dir];
        } else{
            if(ins[i] == "Right") dir = (dir+1)%4;
            else if(ins[i] == "Left") dir = dir-1 >= 0 ? dir-1 : 3;
        }
    }
    return mp(cx, cy);
}

pair<bool, string> brute_force(vector<string>ins, int inst_num){
    string moves[] = {"Forward", "Left", "Right"};
    string past_inst = ins[inst_num];
    for(int i = 0;i < 3;i++){
        ins[inst_num] = moves[i];
        pair<int,int>result = simulate(ins);
        if(result == mp(x,y)){
            return mp(true, moves[i]);
        }
        ins[inst_num] = past_inst;
    }
    return mp(false, "");
}

int main() {
    needforspeed;
    cin >> x >> y;
    cin >> n;
    vector<string>ins;
    for(int i = 0;i < n;i++){
        string s;
        cin >> s;
        ins.pb(s);
    }
    pair<int,int> orig = simulate(ins);
    for(int i = 0;i < n;i++){
        pair<bool, string>result = brute_force(ins, i);
        if(result.first){
            cout << i+1 << " " << result.second << endl;
            break;
        }
    }

    return 0;
}

template< class T>
void print_vec(vector<T>vec, bool new_line){
    for(int i = 0;i < len(vec);i++){
        cout << vec[i] << ((new_line) ? '\n' : ' ');
    }
    cout << endl;
}

int string_to_int(string s){
    int ret;
    stringstream ss;
    ss << s;
    ss >> ret;
    return ret;
}

string int_to_string(int i){
    string ret;
    stringstream ss;
    ss << i;
    ss >> ret;
    return ret;
}

vector<string>split(string s, char delim){
    stringstream ss(s);
    vector<string>ret;
    string temp;
    while(getline(ss, temp, delim)){
        ret.push_back(temp);
    }
    return ret;
}
