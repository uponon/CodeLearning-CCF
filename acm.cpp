#include <bits/stdc++.h>
using namespace std;
/***********************class**********************************/
class Action {
    public:
        int room;//钥匙号
        int time;//归还事件发生的时间
        int type;// 0:还钥匙, 1:借钥匙
        //构造函数（初始化列表）进行类的初始化 
        Action(int room_,int time_,int type_):room(room_),time(time_),type(type_){}
/********************重载operator<函数 *******************************/      
        bool operator<(const Action &other) const 
        {
            if(time<other.time) return true;
            else if(time==other.time && type<other.type) return true;
            else if(time==other.time && type==other.type && room<other.room) return true;
            return false;
        }
};
/*********************重写operator<函数 ******************
小于号时升序排序 
int cmp(Action action1,Action action2)
{
    if(action1.time<action2.time)
    {
        return 1;
    }
    else if(action1.time == action2.time && action1.type < action2.type)
    {
        return 1;
    }
    else if(action1.time == action2.time && action1.type == action2.type&& action1.room < action2.room)
    {
            return 1;   
    }
    return 0;
}
*/
int main() {
    int N, K;
    cin>>N>>K;
    //创建Action类型的Vector数组 
    vector<Action> actions;
    //钥匙的初始化排序 
    vector<int> result(N+1);
    for(int n=1;n<=N; n++) result[n] = n;
    for(int k=0;k<K; k++) 
    {
        int room, begin, length;
        cin>>room>>begin>>length;
        actions.push_back(Action(room, begin, 1));//借钥匙 
        actions.push_back(Action(room, begin+length, 0));
    }
/*************sort利用operator<重写函数进行排序 ******************/
    sort(actions.begin(),actions.end());
/***********************取放操作**********************************/   
    for(int i=0;i<actions.size();i++) 
    {
        Action &act = actions[i];//引用(别名) 
        if(act.type == 0) //put放（后） 
        { 
            for(int n=1; n<=N; n++) 
            {
                if(result[n] == -1) 
                {
                    result[n] = act.room;
                    break;
                }
            }
        }
        else //get取（先）
        { 
            for(int n=1; n<=N; n++) 
            {
                if(result[n] == act.room) 
                {
                    result[n] = -1;
                    break;
                }
            }
        }
    }
/***********************结果输出**********************************/   
    for(int n=1; n<=N; n++) 
    {
        cout<<result[n]<<" ";
    }
}