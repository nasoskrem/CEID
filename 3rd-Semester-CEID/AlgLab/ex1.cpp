///////////////////////////////////////////////////////////////////////////////////
//
// ONOMA:   ΑΘΑΝΑΣΙΟΣ
// ΕΠΩΝΥΜΟ: ΚΡΕΜΑΝΤΑΛΑΣ
// ΑΜ:      1115512
// ΕΤΟΣ:    2ο ΕΤΟΣ
// ΑΣΚΗΣΗ ΕΡΓΑΣΤΗΡΙΟΥ |1|
//
///////////////////////////////////////////////////////////////////////////////////

// ΣΧΟΛΙΑΣΜΟΣ ΛΥΣΗΣ
/*

Χρησιμοποίησα vector για να εκμεταλευτώ τον δυναμικό του χαρακτήρα, δημιούργησα
μια συνάρτηση swap για το vector για λόγους ευαναγνωσίας του κώδικα και έλεγξα
τις περιπτώσεις μη ύπαρξης άρτιου ή περιττού. Η εγγραφή του προγράμματος μου στο
output.txt είναι σωστή για το συγκεκριμένο input.

*/

// ΚΩΔΙΚΑΣ ΛΥΣΗΣ //

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

void swapPositions(vector<int> &v, int i, int j);

class answer 
{
private:
    vector<int> numbers;
public:
    void readFile()
    {
        int current_number;
        ifstream inputFile("input.txt");

        if (inputFile.good())
        {
            while (inputFile >> current_number)
                numbers.push_back(current_number);

            inputFile.close();
        }
        else
        {
            cout << "Αποτυχία ανοίγματος input.txt" << endl;
            return;
        }
    }

    void applyAlgorithm(){

        if(numbers.size() == 0){
            cout << "Δεν υπάρχει κανένας αριθμός στο vector" << endl;
            return;
        }

        // Max Άρτιος:
        int max_even_index = -1; // Αρχικοποίηση με -1 σε περίπτωση που δεν υπάρχει άρτιος
        int max_even_value = INT_MIN;

        // Min Περιττός:
        int min_odd_index = -1; // Αρχικοποίηση με -1 σε περίπτωση που δεν υπάρχει περιττός
        int min_odd_value = INT_MAX;

        for(int i = 0; i < numbers.size(); i++)
            if (numbers[i] % 2 == 0 && numbers[i] > max_even_value){
                max_even_value = numbers[i];
                max_even_index = i;
            }

        if(max_even_index != -1) 
        {
            cout << "Ο μεγαλύτερος άρτιος είναι το " << numbers[max_even_index] << " και βρίσκεται, πριν την αλλαγή, στην " << max_even_index << "η του διανύσματος" << endl;
            swapPositions(numbers, 0, max_even_index);
        }
        else
        {
            cout << "Δεν υπάρχει κανένας άρτιος στο vector." << endl;
        }

        for(int i = 0; i < numbers.size(); i++)
            if (numbers[i] % 2 != 0 && numbers[i] < min_odd_value){
                min_odd_value = numbers[i];
                min_odd_index = i;
            }

        if(min_odd_index != -1)
        {
            cout << "Ο μικρότερος περιττός είναι το " << numbers[min_odd_index] << " και βρίσκεται, πριν την αλλαγή, στην " << min_odd_index << "η του διανύσματος" << endl;
            swapPositions(numbers, 1, min_odd_index);
        }
        else
        {
            cout << "Δεν υπάρχει κανένας περιττός στο vector." << endl;
        }

    }

    void writeFile(){
        ofstream outputfile;
        outputfile.open("output.txt");
        for(int i = 0; i < numbers.size(); i++)
            outputfile << numbers[i] << " ";
        outputfile.close();
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
    answer myanswer;
    myanswer.readFile();
    myanswer.applyAlgorithm();
    myanswer.writeFile();
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////
//
// ΑΠΟΤΕΛΕΣΜΑ ΕΚΤΕΛΕΣΗΣ
/*  
Ο μεγαλύτερος άρτιος είναι το 100 και βρίσκεται, πριν την αλλαγή, στην 91η του διανύσματος
Ο μικρότερος περιττός είναι το 11 και βρίσκεται, πριν την αλλαγή, στην 50η του διανύσματος
*/
