#include<iostream>
#include<vector>

using namespace std;

int main(){
	vector<int> vec;
	int i;
 	cout << "Vector size: " << vec.size() << endl;

 	for(i = 0; i < 7; i++){
 		vec.push_back(rand() % 100 + 1);
    	}

    	cout << "Extented vector size: " << vec.size() << endl;
    	
	for(i = 0; i < vec.size(); i++){
        	cout << "Vector[" << i << "] = " << vec[i] << endl;
    	}
	return 0;
}


