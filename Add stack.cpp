#include <iostream>
#include <stack>
#include <string>
using namespace  std;
string addLargeInteger(string num1,string num2)
{
    stack<int> s;
    int carry=0;
    int i=num1.size()-1;
    int j=num2.size()-1;
    while(i>=0 || j>=0 || carry!=0)
    {
        int sum=carry;
        if(i>=0)
        {
            sum+=num1[i]-'0';
            i--;
        }
        if(j>=0)
        {
            sum+=num2[j]-'0';
            j--;
        }
        s.push(sum%10);
        carry=sum/10;
    }
    string result;
    while(!s.empty())
    {
        result.push_back(s.top()+'0');
        s.pop();
    }
    return result;
}
int main()
{
    string num1,num2;
    cout << "Enter 1st Integer";
    cin >> num1;
    cout << "Enter 2nd Integer";
    cin >> num2;

    string sum=addLargeInteger(num1,num2);
    cout << "Sum of Two Integer is :"<< sum << endl;
    return 0;
}


