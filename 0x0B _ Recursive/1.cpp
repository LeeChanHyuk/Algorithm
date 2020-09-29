#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

long long pow(long long a, long long b, long long c)
{
    if(b==1) return a%c;
    long long val = pow(a,b/2,c);
    val=val*val%c; // 이거 자체가 제곱후에 나눈 나머지가 된다.
    if(b%2==0) return val; // 짝수일 경우 ab mod n = (a mod n)(b mod n) mod n이 이미 계산되어서 반환하면 끝이지만
    return val*a%c; // 홀수일 경우 만약 a^7을 저렇게 한다치면 (7/2 = 3) 이므로 b가 3이 되어서
    // 결국에는 (a^6)mod n을 계산한 결과값이 되어 버린다. 그래서 a를 한번 더 곱해주고 c로 나눠주는 과정이 필요하다.
}

int main(void)
{
    ios::sync_with_stdio(0);
	cin.tie(0);
    long long a,b,c;
    cin>>a>>b>>c;
    cout<<pow(a,b,c);
	return 0;
}