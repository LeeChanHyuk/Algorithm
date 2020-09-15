#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

// 야매 링크드 리스트 ㅎㅎ

const int MX=1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num)
{
    int cur=nxt[0];
    int prev=nxt[0];
    while(cur!=-1)
    {
        prev = cur;
        cur = nxt[cur];
    }
    // 여기 오면 prev에는 제일 마지막에 저장한 곳이 들어있게 된다.
    if(nxt[addr] == -1 && pre[addr] == -1) // 지정하고자 하는 주소가 비어있다면 (-1 이라면)
    {
        nxt[prev] = addr; // 마지막에 저장된 곳 다음 순서는 이번에 저장할 주소
        dat[addr] = num; // 매개변수로 넘겨받은 num을 이번에 저장할 주소에 저장
        pre[addr] = prev;
    }
    else
    {
        cout<<"The array is not empty. Please pick other addr"<<"\n";
    }
    
}

void erase(int addr)
{
    dat[addr] = -1;
    nxt[pre[addr]] = nxt[addr]; // 이전 배열의 다음으로가는 포인터 인덱스
    if(nxt[addr] != -1)
        pre[nxt[addr]] = pre[addr];
}

void traverse()
{
    int cur = nxt[0];
    while(cur!= -1)
    {
        cout<<dat[cur]<<" ";
        cur = nxt[cur];
    }
    cout<<'\n\n';
}

int main()
{
    fill(pre,pre+MX,-1);
    fill(nxt,nxt+MX,-1);

}