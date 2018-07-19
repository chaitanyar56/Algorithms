#include <iostream>
#include <string>


using namespace std;

//pad zeros behind
string padZeros(string a, int n){
  string b(n,'0');
  return a+b;
}

//adding two numbers
string addString(string a, string b){
  int n1 = a.length();
  int n2 = b.length();

  if(n1 > n2){

    string temp(n1-n2,'0');
    b = temp + b;

  }else if (n1 < n2){
    string temp(n2 - 1,'0');
    a = temp + a;
  } else {

  }

  int carry = 0;
  string result(a.length(),'0');

  for(int i = a.length()-1; i >= 0; i--){
    int val =  a[i] + b[i] -'0'-'0' + carry;

    carry = 0;

    if (val < 10){
      result[i] += val;
    } else {
      carry = val / 10;
      result[i] += val % 10 ;
    }
  }
  if (carry == 1){
    result = "1" + result;
    return result;
  }else {
    return result;
  }
}

// substract strings assuming a > b
string substractString(string a, string b){
  int n1 = a.length();
  int n2 = b.length();

  if(n1 > n2){

    string temp(n1-n2,'0');
    b = temp + b;

  }else {

  }

  int carry = 0;
  string result(a.length(),'0');

  for(int i = a.length()-1; i >= 0; i--){

    int val;

    if (carry == 1){
      a[i] -= 1;
    }

    if(a[i] < b[i]) {
      val =  a[i] - b[i] + 10;
      carry = 1;
    } else {
      val =  a[i] - b[i];
      carry = 0;
    }

    result[i] += val;

  }

  result.erase(0, result.find_first_not_of('0'));

  return result;

}

//karatsuba multiplication

string karatsubaMultiply(string m1, string m2) {

  string result;

  int n1 = m1.length();
  int n2 = m2.length();

  if(n1 > n2){

    string temp(n1-n2,'0');
    m2 = temp + m2;

  }else if (n1 < n2){
    string temp(n2 - 1,'0');
    m1 = temp + m1;
  } else {

  }


  int n = m1.length();

  if (n == 1){
    int val = (m1[0] - '0') * (m2[0] - '0');

    if (val < 10){
      result = val + '0';
      return result;
    } else {
      result = val / 10 + '0';
      result += val % 10 + '0';
      return result;
    }
  } else {

    string a;
    string b;
    string c;
    string d;

    if (n % 2 != 0) {

      m1 = "0" + m1;
      m2 = "0" + m2;
      n = n+1;
    }

    a = m1.substr(0, n/2) ;
    b = m1.substr(n/2,n/2);
    c = m2.substr(0, n/2);
    d = m2.substr(n/2,n/2);

    string ac = karatsubaMultiply(a,c);
    string bd = karatsubaMultiply(b,d);

    string ab_p = addString(a,b);
    string cd_p = addString(c,d);
    string ab_p_cd_p = karatsubaMultiply(ab_p,cd_p);

    string ad_p_bc_p = substractString(ab_p_cd_p,ac);
    ad_p_bc_p = substractString(ad_p_bc_p,bd);

    result = addString(padZeros(ac,n), padZeros(ad_p_bc_p, n/2));
    result = addString(result,bd);

    result.erase(0, result.find_first_not_of('0'));

    return result;

  }

}



int main(){

  string a("3141592653589793238462643383279502884197169399375105820974944592");
  string b("2718281828459045235360287471352662497757247093699959574966967627");

  cout<< karatsubaMultiply("5678","1234") << endl;
  cout<< karatsubaMultiply(a,b) << endl;

  return 0;

}
