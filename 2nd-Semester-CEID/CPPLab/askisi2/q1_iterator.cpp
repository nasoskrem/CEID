#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> vec;
    int i;
    cout << "Vector size: " << vec.size() << endl;

    for(i = 0; i < 7; i++){
        vec.push_back((rand() % 100 + 1));
    }

    cout << "Extented vector size: " << vec.size() << endl;
    vector<int>::iterator v = vec.begin();
    int index = 0;
    while(v != vec.end()){
	cout << "Value of Vector[" << index << "]: " << *v << endl;
	v++;
	index++;
    }

    vec.resize(5);
    
    cout << "\nResized vector size: " << vec.size() << endl;
    
    v = vec.begin();
    index = 0;
    while(v != vec.end()){
        cout << "Value of Vector[" << index << "]: " << *v << endl;
        v++;
        index++;
    }
	
    cout << "\nAn vec.resize(10,5) tote ginetai to size 10 kai ta vec[7,..,9] = 5" << endl;

    return 0;
}

