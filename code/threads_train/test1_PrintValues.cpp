#include <iostream>
#include <numeric>
#include <vector>
#include <thread>

using namespace std;

void print_range(int thread_id, const vector<int>&v, int start, int end){
  cout << " thread_id : " << thread_id << " : ";
  for(int i = start; i < end; i++){
    cout << "v[" << i << "] = " << v[i] << " \n"[i==end-1];
  }
}

int main(){
  vector<int>v(20);
  std::iota(begin(v), end(v), 1);

  //cria 4 threads
  vector<thread>t;
  for(int i = 0; i < 4; i++){
    int st = i * 5;
    int fi = st + 5;
    t.push_back(thread(print_range, i+1, ref(v), st, fi));
  }

  //espera as threads terminarem
  for(auto &i: t){
    i.join();
  }
}

