#define MAXM	3
#include <unordered_map>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int human_number;

struct Message {
	int mID;
	int sendPerson;
	int recvPerson;
	int sendTime;
	int read;
};

struct compare
{
	bool operator()(pair<int, Message>& a, pair<int, Message>& b)
	{
		if (a.first == b.first)
			return a.second.mID > b.second.mID;
		return a.first > b.first;
	}
};

struct Human {
	unordered_map<int, Message> send_message_storage;
	unordered_map<int, Message> recv_message_storage;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> recentSendMessage;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> recentRecvMessage;
}humans[1001];


priority_queue<pair<int, Message>, vector<pair<int, Message>>, compare> wait_message;
unordered_map<int, Message> wait_message_hash;
int deleted_message_index[100001];
int deleted_send_message_index[100001];
int deleted_recv_message_index[100001];

void init(int N)
{
	human_number = N;
	memset(deleted_message_index, 0, sizeof(deleted_message_index));
	memset(deleted_send_message_index, 0, sizeof(deleted_message_index));
	memset(deleted_recv_message_index, 0, sizeof(deleted_message_index));
	while (!wait_message.empty()) wait_message.pop();
	wait_message_hash.clear();
	for (int i = 0; i < 1001; i++)
	{
		humans[i].send_message_storage.clear();
		humans[i].recv_message_storage.clear();
		while (!humans[i].recentSendMessage.empty()) humans[i].recentSendMessage.pop();
		while (!humans[i].recentRecvMessage.empty()) humans[i].recentRecvMessage.pop();
	}

}

void sendMessage(int cTimestamp, int uID1, int uID2, int mID, int scheduleTimestamp);
bool wait_message_sending = false;

void sendWaitingMessage(int cTimestamp)
{
	// 가장 앞쪽부터 보면서 보내고, 현재 시간보다 메세지의 시간이 더 늦을 때, break
	Message currentMessage;
	int timeStamp;
	while (wait_message.size()>0)
	{
		currentMessage = wait_message.top().second;
		if (currentMessage.sendTime <= cTimestamp)
		{
			if (deleted_message_index[currentMessage.mID] == 1)
			{
				wait_message.pop();
				continue;
			}
			wait_message.pop();
			wait_message_hash.erase(currentMessage.mID);
			wait_message_sending = true;
			sendMessage(cTimestamp, currentMessage.sendPerson, currentMessage.recvPerson, currentMessage.mID, currentMessage.sendTime);
			wait_message_sending = false;
		}
		else
			break;
	}
}

void updateRecentSendMessage(int uID, int mID, int scheduleTimestamp)
{
	humans[uID].recentSendMessage.push(make_pair(scheduleTimestamp, mID));
}

void updateRecentRecvMessage(int uID, int mID, int scheduleTimestamp)
{
	humans[uID].recentRecvMessage.push(make_pair(scheduleTimestamp, mID));
}

void sendMessage(int cTimestamp, int uID1, int uID2, int mID, int scheduleTimestamp)
{
	sendWaitingMessage(cTimestamp);
	// 현재 메세지 작성
	Message currentMessage;
	currentMessage.mID = mID;
	currentMessage.read = 0;
	currentMessage.sendPerson = uID1;
	currentMessage.recvPerson = uID2;
	currentMessage.sendTime = scheduleTimestamp;
	// 현재 시간보다 보낼 시간이 이를 때는 발송하고 보낸 편지함 및 받은 편지함 갱신 / 최근에 보낸 편지 및 받은 편지 갱신
	if (cTimestamp == scheduleTimestamp & wait_message_sending == false)
	{
		humans[uID1].send_message_storage.insert(make_pair(mID, currentMessage));
		updateRecentSendMessage(uID1, mID, scheduleTimestamp);
		humans[uID2].recv_message_storage.insert(make_pair(mID, currentMessage));
		updateRecentRecvMessage(uID2, mID, scheduleTimestamp);
	}
	else if (cTimestamp >= scheduleTimestamp)
	{
		humans[uID1].send_message_storage.insert(make_pair(mID, currentMessage));
		humans[uID2].recv_message_storage.insert(make_pair(mID, currentMessage));
		updateRecentRecvMessage(uID2, mID, scheduleTimestamp);
	}
	// 현재 시간보다 보낼 시간이 느릴 때는 wait_message에 message 넣기
	else
	{
		wait_message.push(make_pair(scheduleTimestamp, currentMessage));
		wait_message_hash.insert(make_pair(mID, currentMessage));
		updateRecentSendMessage(uID1, mID, scheduleTimestamp);
	}
}

int retrieveSentbox(int cTimestamp, int uID, int mIDList[MAXM], int uIDList[MAXM], int readList[MAXM])
{
	sendWaitingMessage(cTimestamp);
	vector<pair<int, int>> temp_vec;
	while (humans[uID].recentSendMessage.size())
	{
		int temp_mid = humans[uID].recentSendMessage.top().second;
		int temp_time = humans[uID].recentSendMessage.top().first;
		if (deleted_send_message_index[temp_mid])
		{
			humans[uID].recentSendMessage.pop();
			continue;
		}
		temp_vec.push_back(make_pair(temp_time, temp_mid));
		humans[uID].recentSendMessage.pop();
	}
	if (!temp_vec.empty())
	{
		for (int i = 0; i<temp_vec.size(); i++)
		{
			mIDList[i] = temp_vec[temp_vec.size() - 1 - i].second;
			uIDList[i] = humans[uID].send_message_storage[temp_vec[temp_vec.size()-1-i].second].recvPerson;
			readList[i] = humans[uID].send_message_storage[temp_vec[temp_vec.size()-1-i].second].read;
			if (i == 3)
				break;
		}
	}
	for (int i = 0; i < temp_vec.size(); i++)
		humans[uID].recentSendMessage.push(temp_vec[i]);
	if (temp_vec.size() > 2)
		return 3;
	else
		return temp_vec.size();
}

int retrieveInbox(int cTimestamp, int uID, int mIDList[MAXM], int uIDList[MAXM], int readList[MAXM])
{
	sendWaitingMessage(cTimestamp);
	vector<pair<int, int>> temp_vec;
	while (humans[uID].recentRecvMessage.size())
	{
		int temp_mid = humans[uID].recentRecvMessage.top().second;
		int temp_time = humans[uID].recentRecvMessage.top().first;
		if (deleted_recv_message_index[temp_mid])
		{
			humans[uID].recentRecvMessage.pop();
			continue;
		}
		humans[uID].recentRecvMessage.pop();
		temp_vec.push_back(make_pair(temp_time, temp_mid));
	}
	if (!temp_vec.empty())
	{
		for (int i = 0; i<temp_vec.size(); i++)
		{
			if (i == 3)
				break;
			mIDList[i] = temp_vec[temp_vec.size() - 1 - i].second;
			uIDList[i] = humans[uID].recv_message_storage[temp_vec[temp_vec.size()-1-i].second].sendPerson;
			readList[i] = humans[uID].recv_message_storage[temp_vec[temp_vec.size()-1-i].second].read;
		}
	}
	for (int i = 0; i < temp_vec.size(); i++)
		humans[uID].recentRecvMessage.push(temp_vec[i]);
	if (temp_vec.size() > 2)
		return 3;
	else
		return temp_vec.size();
}

int readMessage(int cTimestamp, int uID, int mID)
{
	sendWaitingMessage(cTimestamp);
	if (humans[uID].send_message_storage.find(mID) != humans[uID].send_message_storage.end())
	{
		return 1;
	}
	if (humans[uID].recv_message_storage.find(mID) != humans[uID].recv_message_storage.end())
	{
		humans[uID].recv_message_storage[mID].read = 1;
		humans[humans[uID].recv_message_storage[mID].sendPerson].send_message_storage[mID].read = 1;
		return 1;
	}
	else
		return 0;
}

int deleteMessage(int cTimestamp, int uID, int mID)
{
	sendWaitingMessage(cTimestamp);
	if (humans[uID].send_message_storage.find(mID) != humans[uID].send_message_storage.end())
	{
		humans[uID].send_message_storage.erase(mID);
		deleted_send_message_index[mID] = 1;
		return 1;
	}
	else if (humans[uID].recv_message_storage.find(mID) != humans[uID].recv_message_storage.end())
	{
		humans[uID].recv_message_storage.erase(mID);
		deleted_recv_message_index[mID] = 1;
		return 1;
	}
	else if (wait_message_hash.find(mID) != wait_message_hash.end())
	{
		wait_message_hash.erase(mID);
		deleted_message_index[mID] = 1;
		deleted_send_message_index[mID] = 1;
		return 1;
	}
	return 0;
}