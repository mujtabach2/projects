#include <iostream>
#include <string>
#include <vector>

using namespace std;

// take q a m q-1
// q = multipler
// m = multiplcand
//q-1 = l = order
// A = portion of result


 // booths step by step . amount of steps == # of bits , recursivley 
 // function to shift
 //function to add and to subtract
  //twos complement fucntion

vector<string> arthimeticShift(vector<string>& v){
    vector<string> temp;

    temp.push_back("");
    temp[0].push_back(v[0][0]);
    for (int i = 1 ; i < 4; i++){
        temp[0].push_back(v[0][i - 1]);
    }

    temp.push_back("");
    temp[1].push_back(v[0][3]);
    for (int i = 1 ; i < 4; i++){
       temp[1].push_back(v[1][i - 1]);
    }

    temp.push_back("");
    temp[2].push_back(v[1][3]);

    temp.push_back(v[3]);

    return temp;
}
vector<string> add(vector<string>& v){
    string temp;
    bool carry;
    int toadd;
    for(int i = 0; i < 4; i++){
        if(carry == true){
             toadd = 1;   
        }
        else{
            toadd = 0;
        }
        //CASES TO DO 
        // CARRY FALSE  1 1 
        // CARRY TRUE 0 1, 
        //CARRY FALSE 0,1 
        // CARRY TRUE 0.0 
        //CARRY FALSE 0.0 
        if (v[0][i] = '1' & v[3][i] = '1')
        {
            temp+="0"+toadd;
            carry = true;
        }
        if(((v[0][i] = '0' & v[3][i] = '1')|| (v[0][i] = '1' & v[3][i] = '0')) & carry == true)
        {
            temp+="0";
        }
    }
    v[1] = reverse(temp.begin(), temp.end()); 
    
}
vector<string> boothAlg(vector<string>& v, int n){
    vector<string> res;
    // 0,0 arthimetic shift (right shift)
    if(v[1][3] == '0' & v[2][0] == '0' ){
       res= arthimeticShift(v);  
    }
    // 0,1 add, right shift
    if(v[1][3] == '0' & v[2][0] == '0' ){
       res = arthimeticShift(v);
       res = add(res);
    }

    
    // 1, 0 subtract shift
    // 1,1 shift   

    //recursion end case
    if(n == 4){
        return res;
    }
    //recursion
    return boothAlg(res,n+1);
}

    
int main(){
    string q, a;

    cout<< "only enter 4 bits (1,0 only)"<< endl;
    cout << "enter a multiplier";
    cin >> q;
    cout << "enter a multiplicant";
    cin >> a;

    vector<string> booths;
    booths.push_back("0000");
    booths.push_back(q);
    booths.push_back("0");
    booths.push_back(a);
    
    vector<string> halal = boothAlg(booths,0);
    for (int i = 0; i < 4;i++){
        cout << halal[i] << ' ';
    }
    
    return 0;
}