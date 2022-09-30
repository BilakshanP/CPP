// #include <iostream>
// 
// int main(){
//     {
//         using namespace std;
// 
//         int a, i{1}, fact{1};
//
//         cout << "Enter the number to find factorial of: ";
//         cin >> a;
// 
//         for(i; i <= a; i++){
//             fact = fact * i;
//         }
// 
//         cout << "The factorial of " << a << " is: " << fact << endl;
//     }
//     return 0;
// }

#include <iostream>

int factorial(int n){
    if(n < 2){
        return 1;
    }
    return n * factorial(n-1);
}

int main(){
    {
        using namespace std;

        int a;

        cout << "Enter the number to find factorial of: ";
        cin >> a;
        cout << "Factorial of " << a << " is: " << factorial(a) << endl;
    }
    return 100;
}