///////////////////////////////////////////////////////////////////////////////////
//
// ONOMA:   ΑΘΑΝΑΣΙΟΣ
// ΕΠΩΝΥΜΟ: ΚΡΕΜΑΝΤΑΛΑΣ
// ΑΜ:      1115512
// ΕΤΟΣ:    2ο ΕΤΟΣ
// ΑΣΚΗΣΗ ΕΡΓΑΣΤΗΡΙΟΥ |2|
//
///////////////////////////////////////////////////////////////////////////////////

// ΚΩΔΙΚΑΣ ΛΥΣΗΣ //

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void swapPositions(vector<int> &v, int i, int j);

class myHeap
{
private:
    vector<int> myHeapVector;
    int heapsize;
    void dispWithMove(int movedValue, int finalPos) {
        cout << "Το στοιχείο [" << movedValue << "] μετακινήθηκε στη θέση [" << finalPos << "]\n";
        disp();
    }
public:
    myHeap() : heapsize(0) {}; // Constructor

    void loadVector(){
        int current_number;
        ifstream inputFile("Heap.txt");
        if(inputFile.is_open()){
            myHeapVector.push_back(0); // Dummy element στην θέση 0 αφού θέλουμε το πρώτο στοιχείο στη θέση 1
            while (inputFile >> current_number){
                myHeapVector.push_back(current_number);
                heapsize++;
            }
            inputFile.close();
            cout << "Διαβάστηκαν συνολικά " << heapsize << " στοιχεία." << endl;
        }
        else{
            cout << "Αποτυχία ανοίγματος input.txt." << endl;
            return;
        }
    }

    void insert(int value){
        cout << "\n===== Προσθήκη στοιχείου [" << value << "] ===== " << endl;
        myHeapVector.push_back(value);
        heapsize++;
        heapifyUp(heapsize);
    }

    void extractMax(){
        cout << "\n===== Εξαγωγή της κορυφής του σωρού (μέγιστου στοιχείου) =====" << endl;
        cout << "Το στοιχείο είναι το [" << myHeapVector[1] << "]. Στην συνέχεια, μεταφέρουμε το τελευταίο στοιχείο στην ρίζα και κάνουμε Heapify Down."<< endl;
        swapPositions(myHeapVector, 1, heapsize);
        myHeapVector.pop_back();
        heapsize--;
        heapifyDown();
    }

    void replaceMax(int value){
        cout << "\n===== Αντικατάσταση κορυφής [" << myHeapVector[1] << "] με [" << value << "] =====" << endl;
        myHeapVector[1] = value;
        heapifyDown();
    }

    void heapifyUp(int index){
        int current = index;
        int movedValue = myHeapVector[current];

        cout << "Το στοιχείο [" << movedValue << "] ξεκινά από τη θέση [" << current << "]\n";
        
        bool moved = false;

        while(current > 1){
            int parent = current / 2;
            
            if(myHeapVector[parent] >= myHeapVector[current]) break;

            swapPositions(myHeapVector, current, parent);
            dispWithMove(movedValue, parent);
            current = parent;
            moved = true;
        }

        if(!moved) {
            cout << "Το στοιχείο [" << movedValue << "] δεν χρειάστηκε μετακίνηση.\n";
            disp();
        }
    }

    void heapifyDown(int index = 1) {
        int current = index;
        int movedValue = myHeapVector[current];

        // Εμφάνιση αρχικής θέσης
        cout << "Το στοιχείο [" << movedValue << "] ξεκινά από τη θέση [" << current << "]\n";

        while(true){
            int left  = 2 * current;
            int right = 2 * current + 1;
            int largest = current;
            bool moved = false;

            if(left <= heapsize && myHeapVector[left] > myHeapVector[largest])
                largest = left;
            if(right <= heapsize && myHeapVector[right] > myHeapVector[largest])
                largest = right;

            if(largest == current) break;

            swapPositions(myHeapVector, current, largest);
            dispWithMove(movedValue, largest);  // κάθε ενδιάμεση κίνηση
            current = largest;
            moved = true;

            if(!moved) {
                cout << "Το στοιχείο [" << movedValue << "] δεν χρειάστηκε μετακίνηση.\n";
                disp();
            }
        }
    }   

    void disp(){
        cout << "Current heap: "; 
        int i = 1;

        for(int i = 1; i <= heapsize; i++){
            cout << myHeapVector[i]<< " ";
        }
        cout << endl;
    }

    bool isEmpty(){
        return heapsize < 1;
    }
};  

void swapPositions(vector<int> &v, int i, int j)
{
   if (i < 0 || j < 0 || i >= v.size() || j >= v.size()) { 
        cout << "Μη έγκυρες θέσεις για swap: " << i << " και " << j << endl;
        return;
    }

    if (i != j) {            
        
        int temp = v[i];     
        v[i] = v[j];
        v[j] = temp;
    }
    // Αν i == j δεν χρειάζεται αλλαγή
}

int main(){
    myHeap answer;
    answer.loadVector();

    if(!answer.isEmpty()){
        
        answer.disp(); // Αρχικό heap
        answer.extractMax();

        answer.insert(3);

        answer.replaceMax(4);

        answer.replaceMax(8);

    }
    else
        cout << "Δεν υπάρχουν στοιχεία για επεξεργασία";

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////
//
// ΑΠΟΤΕΛΕΣΜΑ ΕΚΤΕΛΕΣΗΣ
/*  
Διαβάστηκαν συνολικά 15 στοιχεία.
Current heap: 90 85 75 70 80 65 60 50 45 55 70 40 30 25 20 

===== Εξαγωγή της κορυφής του σωρού (μέγιστου στοιχείου) =====
Το στοιχείο είναι το [90]. Στην συνέχεια, μεταφέρουμε το τελευταίο στοιχείο στην ρίζα και κάνουμε Heapify Down.
Το στοιχείο [20] ξεκινά από τη θέση [1]
Το στοιχείο [20] μετακινήθηκε στη θέση [2]
Current heap: 85 20 75 70 80 65 60 50 45 55 70 40 30 25 
Το στοιχείο [20] μετακινήθηκε στη θέση [5]
Current heap: 85 80 75 70 20 65 60 50 45 55 70 40 30 25 
Το στοιχείο [20] μετακινήθηκε στη θέση [11]
Current heap: 85 80 75 70 70 65 60 50 45 55 20 40 30 25 

===== Προσθήκη στοιχείου [3] ===== 
Το στοιχείο [3] ξεκινά από τη θέση [15]
Το στοιχείο [3] δεν χρειάστηκε μετακίνηση.
Current heap: 85 80 75 70 70 65 60 50 45 55 20 40 30 25 3 

===== Αντικατάσταση κορυφής [85] με [4] =====
Το στοιχείο [4] ξεκινά από τη θέση [1]
Το στοιχείο [4] μετακινήθηκε στη θέση [2]
Current heap: 80 4 75 70 70 65 60 50 45 55 20 40 30 25 3 
Το στοιχείο [4] μετακινήθηκε στη θέση [4]
Current heap: 80 70 75 4 70 65 60 50 45 55 20 40 30 25 3 
Το στοιχείο [4] μετακινήθηκε στη θέση [8]
Current heap: 80 70 75 50 70 65 60 4 45 55 20 40 30 25 3 

===== Αντικατάσταση κορυφής [80] με [8] =====
Το στοιχείο [8] ξεκινά από τη θέση [1]
Το στοιχείο [8] μετακινήθηκε στη θέση [3]
Current heap: 75 70 8 50 70 65 60 4 45 55 20 40 30 25 3 
Το στοιχείο [8] μετακινήθηκε στη θέση [6]
Current heap: 75 70 65 50 70 8 60 4 45 55 20 40 30 25 3 
Το στοιχείο [8] μετακινήθηκε στη θέση [12]
Current heap: 75 70 65 50 70 40 60 4 45 55 20 8 30 25 3 
*/