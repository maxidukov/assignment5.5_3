#include <iostream>
#include <vector>
#include <sstream>

class Sum_or_count{
  std::vector<int> v_;
  int call_count{};
  public:
  Sum_or_count(std::vector<int> v): v_(v){}
  int get_sum(){
    std::cout<<"get_sum() = ";
    int sum = 0;
    for(int el:v_){
      if(!(el%3)){
        sum += el;
      }
    }
    return sum;
  }
  int get_count(){
    std::cout<<"get_count() = ";
    int count = 0;
    for(int el:v_){
      if(!(el%3)){
        count++;
      }
    }
    return count;
  }
  int operator()(){
     int retval{};
     if(!(call_count%2)){
       retval = get_sum();
     }else
       retval = get_count();
     call_count++;
     if(call_count==100)
       call_count=0;
     return retval;
  }
  int operator()(bool is_sum){
     int retval{};
     if(is_sum){
       retval = get_sum();
     }else
       retval = get_count();
     call_count++;
     if(call_count==100)
       call_count=0;
     return retval;
  }
};

int main() {
  //std::cout << "Hello World!\n";
  std::vector<int> v;
  std::string line;
  int n{};
  std::cout<<"[IN]: ";
  getline(std::cin,line);
  std::istringstream iss(line);
  while(iss>>n){
      v.push_back(n);
  }
  /*while(std::cin>>n) {
    v.push_back(n);
  }*/
  /*std::vector<int>::iterator it;
  for(it=v.begin();it!=v.end();it++)
        std::cout<<*it<<std::endl;
  for(const int& el:v){
    std::cout<<el<<std::endl;
  }*/
  Sum_or_count sum_or_count(v);
  std::cout<<"[OUT]: "<<sum_or_count()<<std::endl;
  std::cout<<"[OUT]: "<<sum_or_count()<<std::endl;
  std::cout<<"[OUT]: "<<sum_or_count(0)<<std::endl;

}
