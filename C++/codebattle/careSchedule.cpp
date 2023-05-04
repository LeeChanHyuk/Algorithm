//void mstrcpy(char dst[], const char src[]) {
//	int c = 0;
//	while ((dst[c] = src[c]) != 0) ++c;
//}

//int mstrcmp(const char str1[], const char str2[]) {
//	int c = 0;
//	while (str1[c] != 0 && str1[c] == str2[c]) ++c;
//	return str1[c] - str2[c];
//}

#include <string>
#include <vector>
#include <unordered_map>
#include <string.h>

using namespace std;

struct Event
{
	int group_id;
	vector<int> uid_list;
};

unordered_map<string, Event> uid_um; // <uid_eventname, Event>
unordered_map<string, Event> groupid_um; // <group_eventname, Event>
int uid_event_count_arr[1000];

void init()
{
	uid_um.clear();
	groupid_um.clear();
	memset(uid_event_count_arr, 0, sizeof(uid_event_count_arr));
	return;
}

void addEvent(int uid, char ename[], int groupid)
{
	string ename_string(ename);
	string uid_name = to_string(uid) + "_" + ename_string;
	string groupid_name = to_string(groupid) + "_" + ename_string;
	// For uid_um
	Event uid_tempEvent;
	uid_tempEvent.group_id = groupid;
	uid_event_count_arr[uid] += 1;
	uid_um.insert(make_pair(uid_name, uid_tempEvent));
	// For groupid_um
	Event groupid_tempEvent;
	groupid_tempEvent.uid_list.push_back(uid);
	if (groupid_um.find(groupid_name) != groupid_um.end())
		groupid_um[groupid_name].uid_list.push_back(uid);
	else
		groupid_um.insert(make_pair(groupid_name, groupid_tempEvent));
}

int deleteEvent(int uid, char ename[])
{
	string ename_string(ename);
	string uid_name = to_string(uid) + "_" + ename_string;
	int group_id = uid_um[uid_name].group_id;
	string groupid_name = to_string(group_id) + "_" + ename_string;
	vector<int>* uids_pointer = &(groupid_um[groupid_name].uid_list); // uid를 삭제하지 않거나, Groupid를 하나만 추가하거나.
	if ((*uids_pointer)[0] == uid) // if the event is master
	{
		int delete_count = 0;
		for (int i = 0; i < uids_pointer->size(); i++)
		{
			if ((*uids_pointer)[i] >= 0)
			{
				string uid_name = to_string((*uids_pointer)[i]) + "_" + ename_string;
				uid_um.erase(uid_name);
				uid_event_count_arr[(*uids_pointer)[i]] -= 1;
				delete_count += 1;
			}
		}
		groupid_um.erase(groupid_name);
		return delete_count;
	}
	else
	{
		uid_um.erase(uid_name);
		uid_event_count_arr[uid] -= 1;
		for (int i = 0; i < 5; i++)
			if ((*uids_pointer)[i] == uid)
			{
				(*uids_pointer)[i] = -1;
				break;
			}
		return 1;
	}
}

int changeEvent(int uid, char ename[], char cname[])
{
	string ename_string(ename);
	string cname_string(cname);
	string uid_name = to_string(uid) + "_" + ename_string;
	int group_id = uid_um[uid_name].group_id;
	string groupid_name = to_string(group_id) + "_" + ename_string;
	vector<int>* uids_pointer = &(groupid_um[groupid_name].uid_list);
	if ((*uids_pointer)[0] == uid) // if the event is master
	{
		int change_count = 0;
		for (int i = 0; i < uids_pointer->size(); i++)
		{
			if ((*uids_pointer)[i] >= 0)
			{
				string uid_name = to_string((*uids_pointer)[i]) + "_" + ename_string;
				string new_uid_name = to_string((*uids_pointer)[i]) + "_" + cname_string;
				uid_um.erase(uid_name);
				addEvent((*uids_pointer)[i], cname, group_id);
				uid_event_count_arr[(*uids_pointer)[i]] -= 1;
				change_count += 1;
			}
		}
		groupid_um.erase(groupid_name);
		return change_count;
	}
	else
	{
		uid_um.erase(uid_name);
		addEvent(uid, cname, group_id);
		uid_event_count_arr[uid] -= 1;
		for (int i = 0; i < 5; i++)
			if ((*uids_pointer)[i] == uid)
			{
				(*uids_pointer)[i] = -1;
				break;
			}
		return 1;
	}
}

int getCount(int uid)
{
	return uid_event_count_arr[uid];
}